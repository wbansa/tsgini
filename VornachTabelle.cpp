// VornachTabelle.cpp : implementation file
//

#include "stdafx.h"
#include "VornachTabelle.h"
#include "ZeitenDialog.h"
#include "ZeitPropDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVornachTabelle

CVornachTabelle::CVornachTabelle()
{	
	m_strIniName = "Spielplan.ini";
	m_strVorSection = "Vorlaufzeiten";
	m_strNachSection = "Spieldauern";
}
	
void CVornachTabelle::Lade()
{
	DWORD Anzahl, MaxLaenge=10000;
	char pPuffer[10000];
	char* pLfdMannsch, * pLfdZeit;
	int lLfdEintrag;
	VORNACH_STRUCT Vornach;

	Anzahl = GetPrivateProfileSection(
		m_strVorSection,	// address of section name 
		pPuffer,	// address of return buffer 
		MaxLaenge,	// size of return buffer 
		m_strIniName 	// address of initialization filename  
	   );	
	
	pLfdMannsch = pPuffer;
	while (*pLfdMannsch != NULL)
	{
		lLfdEintrag = strlen(pLfdMannsch) + 1;
		for (pLfdZeit=pLfdMannsch;*pLfdZeit!='=' && *pLfdZeit!=0; pLfdZeit++);// Suche '='
		*pLfdZeit = 0;
		pLfdZeit++;
		Vornach.Vor = atoi(pLfdZeit);
		Vornach.Nach = 0;
		CMap<CString, LPCSTR, VORNACH_STRUCT, VORNACH_STRUCT&>::SetAt(pLfdMannsch, Vornach);


		pLfdMannsch += lLfdEintrag;
	}

	Anzahl = GetPrivateProfileSection(
		m_strNachSection,	// address of section name 
		pPuffer,	// address of return buffer 
		MaxLaenge,	// size of return buffer 
		m_strIniName 	// address of initialization filename  
	   );	
	pLfdMannsch = pPuffer;

	while (*pLfdMannsch != NULL)
	{
		lLfdEintrag = strlen(pLfdMannsch) + 1;
		for (pLfdZeit=pLfdMannsch;*pLfdZeit!='=' && *pLfdZeit!=0; pLfdZeit++);// Suche '='
		*pLfdZeit = 0;
		pLfdZeit++;	
		if (!Lookup(pLfdMannsch, Vornach))
		{
			Vornach.Vor = 0;
		}
		Vornach.Nach = atoi(pLfdZeit);
		CMap<CString, LPCSTR, VORNACH_STRUCT, VORNACH_STRUCT&>::SetAt(pLfdMannsch, Vornach);

		pLfdMannsch += lLfdEintrag;
	}


}
CVornachTabelle::~CVornachTabelle()
{
}

/////////////////////////////////////////////////////////////////////////////
// Operations

BOOL CVornachTabelle::LookupExt(LPCSTR Mannsch, VORNACH_STRUCT& Vornach)
{
	CString M(Mannsch);
	M.MakeUpper();
	if (M == "BEL" || M == "")
	{
		// interessiert ganz und gar nicht
		Vornach.Vor = 0;
		Vornach.Nach = 0;
		return TRUE;
	}
	// Wenn eine Mannschaftsbezeichnung mit einer Zifffer aufhört,
	//   ignoriere ich die Ziffer beim suchen
	M = Mannsch;
	int i = M.GetLength();
	if (M[M.GetLength() - 1] >= '0' && M[M.GetLength() - 1] <= '9')
		M = M.Left(M.GetLength() - 1);

	if (Lookup(M, Vornach))
		return TRUE;
	else
	{
		//diese Mannschaft fehlt, in .ini brauch ich sie nicht zu suchen, 
		// denn die sind alle schon gelesen
		CPropertySheet ZeitPropSheet;
		CZeitPropDialog ZeitPropPage1;
		ZeitPropPage1.m_Mannsch = Mannsch;
		ZeitPropPage1.m_nVor = 0;
		ZeitPropPage1.m_nNach = 0;
		ZeitPropSheet.AddPage(&ZeitPropPage1);

		if (ZeitPropSheet.DoModal() == IDOK)
		{
			// eingegeben, in Tabelle und ggf Registry speichern
			Mannsch = ZeitPropPage1.m_Mannsch;
			Vornach.Vor = ZeitPropPage1.m_nVor;
			Vornach.Nach = ZeitPropPage1.m_nNach;
			SetAt((LPCSTR)Mannsch, Vornach);
			return TRUE;
		}
	}
	return FALSE;
}

void CVornachTabelle::SetAt(LPCSTR Mannsch, VORNACH_STRUCT &Vornach)
{
	CString M(Mannsch);
	M.MakeUpper();
	if (M == "BEL") 
	{
		// interessiert ganz und gar nicht
		return;
	}

	char pZeit[30];
	if (Vornach.Vor >= 0 && Vornach.Nach >= 0)
	{
		// nur solche gehen in .ini
		sprintf(pZeit,"%u",Vornach.Vor);
		WritePrivateProfileString(
			m_strVorSection,	// pointer to section name 
			Mannsch,	// pointer to key name 
			pZeit,	// pointer to string to add 
			m_strIniName 	// pointer to initialization filename 
		);
		sprintf(pZeit,"%u",Vornach.Nach);
		WritePrivateProfileString(
			m_strNachSection,	// pointer to section name 
			Mannsch,	// pointer to key name 
			pZeit,	// pointer to string to add 
			m_strIniName 	// pointer to initialization filename 
		);
	}
	CMap<CString, LPCSTR, VORNACH_STRUCT, VORNACH_STRUCT&>::SetAt((LPCSTR)Mannsch, Vornach);
}

void CVornachTabelle::DoZeitenDialog()
{
	CZeitenDialog dlg(this);
	dlg.DoModal();
}

