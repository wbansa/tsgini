// CZeitenDialog.cpp : implementation file
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

static char ZeitenDialogId[] = "$Id: ZeitenDialog.cpp,v 1.3 2003-06-25 17:39:55 wobansa Exp $";
/////////////////////////////////////////////////////////////////////////////
// CZeitenDialog dialog


CZeitenDialog::CZeitenDialog(CVornachTabelle* pTabelle, CWnd* pParent /*=NULL*/)
	: CDialog(CZeitenDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZeitenDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pVornachZeiten = pTabelle;
}


void CZeitenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZeitenDialog)
	DDX_Control(pDX, IDC_LIST1, m_Liste);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZeitenDialog, CDialog)
	//{{AFX_MSG_MAP(CZeitenDialog)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZeitenDialog message handlers

void CZeitenDialog::OnDblclkList1() 
{

	int nZuaendern = m_Liste.GetCurSel();
	if (nZuaendern != LB_ERR)
	{
		CString Mannsch, Zeile;
		VORNACH_STRUCT Vornach;
		m_Liste.GetText(nZuaendern, Zeile);
		ZerlegeZeile(&Zeile, &Mannsch, &Vornach);

		CPropertySheet ZeitPropSheet;
		CZeitPropDialog ZeitPropPage1;
		ZeitPropPage1.m_Mannsch = Mannsch;
		ZeitPropPage1.m_nVor = Vornach.Vor;
		ZeitPropPage1.m_nNach = Vornach.Nach;
		ZeitPropSheet.AddPage(&ZeitPropPage1);

		ZeitPropSheet.DoModal();

		Mannsch = ZeitPropPage1.m_Mannsch;
		Vornach.Vor = ZeitPropPage1.m_nVor;
		Vornach.Nach = ZeitPropPage1.m_nNach;

		MacheZeile(&Zeile, &Mannsch, &Vornach);

		m_Liste.DeleteString(nZuaendern);
		m_Liste.InsertString(nZuaendern, Zeile);


	}
}

BOOL CZeitenDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CString mannsch, text;
	VORNACH_STRUCT vornach = {-1,-1};
	
	POSITION vnpos = m_pVornachZeiten->GetStartPosition();
	while (vnpos)
	{
		m_pVornachZeiten->GetNextAssoc(vnpos, mannsch, vornach);
		MacheZeile(&text, &mannsch, &vornach);
		m_Liste.AddString(text);
	};
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

	
}

void CZeitenDialog::MacheZeile(CString* zeile, CString* pMannsch, VORNACH_STRUCT* pVornach)
{
	CString text1;
	CDC* pDC = GetDC();
	zeile->Format("%-20s",*pMannsch);

	// Für eine kurze Mannschaftsbezeichung sitzt der erste Tabstop zu weit links
	// 96 Einheiten scheinen das Minimum, um den richtigen Tabstop zu erreichen
	CSize ms = pDC->GetTextExtent(*zeile);
	while (ms.cx < 96)
	{
		*zeile += "  ";
		ms = pDC->GetTextExtent(*zeile);
	}
	if (pVornach->Vor != -1)
	{
		text1.Format("\t%d", pVornach->Vor);
		*zeile += text1;
	}
	else
	{
		*zeile += "\t";
	}
	if (pVornach->Nach !=-1)
	{
		text1.Format("\t%d", pVornach->Nach);
		*zeile += text1;
	}

}

void CZeitenDialog::ZerlegeZeile(CString* zeile, CString* pMannsch, VORNACH_STRUCT* pVornach)
{
	int nLaengeZeile = zeile->GetLength();
	int nEndeMannsch = zeile->Find(9);
	*pMannsch =  zeile->Left(nEndeMannsch);
	pMannsch->TrimRight();
	int nAnfangNach = zeile->ReverseFind(9);
	if (nAnfangNach < nLaengeZeile - 1)
	{
		pVornach->Nach = atoi(zeile->Right(nLaengeZeile - 1 - nAnfangNach));
	}
	else
	{
		pVornach->Nach = -1;
	}
	if (nEndeMannsch < nAnfangNach - 1)
	{
		pVornach->Vor = atoi(zeile->Mid(nEndeMannsch + 1, nAnfangNach));
	}
	else
	{
		pVornach->Vor = -1;
	}
}

void CZeitenDialog::OnOK() 
{
	CString Mannsch, Zeile;
	VORNACH_STRUCT Vornach;	
	int nAnz = m_Liste.GetCount();

	for (int i = 0; i < nAnz; i++) 
	{
		m_Liste.GetText(i, Zeile);
		ZerlegeZeile(&Zeile, &Mannsch, &Vornach);
		m_pVornachZeiten->SetAt((LPCSTR)Mannsch, Vornach);
	}
	
	CDialog::OnOK();
}
