// tsgini.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "tsgini.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static char tsginiId[] = "$Id: tsgini.cpp,v 1.3 2003-06-25 17:39:55 wobansa Exp $";
/////////////////////////////////////////////////////////////////////////////
// CTsginiApp

BEGIN_MESSAGE_MAP(CTsginiApp, CWinApp)
	//{{AFX_MSG_MAP(CTsginiApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTsginiApp construction

BOOL CTsginiApp::InitInstance()
{
	// any DLL initialization goes here
	TRACE0("tsgini.DLL initializing\n");
	m_VNT.Lade();
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CTsginiApp object

CTsginiApp theApp("SPIELPLA");

/////////////////////////////////////////////////////////////////////////////
void _stdcall LiesVornach(VORNACH_STRUCT* pVN, CString* pMannsch)
{
	// All DLL entry points should have a top-level TRY/CATCH block.
	// Otherwise, it would be possible to throw an uncaught exception from
	//  a DLL.  This would most likely cause a crash.

	TRACE("LiesVornach %s\n", *pMannsch);
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ))

	TRY
	{
		VORNACH_STRUCT VN;
		CTsginiApp* pApp = (CTsginiApp*)AfxGetApp();
		ASSERT_VALID(pApp);
		pApp->m_VNT.LookupExt(*pMannsch, VN);
		*pVN = VN;
	}
	CATCH_ALL(e)
	{
		// a failure caused an exception.
	}
	END_CATCH_ALL
}

void __stdcall LiesZeiten(LPTSTR pZeit1, LPTSTR pZeit2, LPCSTR pMannsch)
{
	// All DLL entry points should have a top-level TRY/CATCH block.
	// Otherwise, it would be possible to throw an uncaught exception from
	//  a DLL.  This would most likely cause a crash.

	TRACE("LiesZeiten %s\n", pMannsch);
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ))

	TRY
	{
		VORNACH_STRUCT VN;
		CTsginiApp* pApp = (CTsginiApp*)AfxGetApp();
		ASSERT_VALID(pApp);
		pApp->m_VNT.LookupExt(pMannsch, VN);
		sprintf(pZeit1, "%02d:%02d", VN.Vor / 60, VN.Vor % 60);
		sprintf(pZeit2, "%02d:%02d", VN.Nach / 60, VN.Nach % 60);
	}
	CATCH_ALL(e)
	{
		// a failure caused an exception.
	}
	END_CATCH_ALL
}

void __stdcall ZeitenDialog()
{
	// All DLL entry points should have a top-level TRY/CATCH block.
	// Otherwise, it would be possible to throw an uncaught exception from
	//  a DLL.  This would most likely cause a crash.

	TRACE0("ZeitenDialog");
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ))
	TRY
	{
		CTsginiApp* pApp = (CTsginiApp*)AfxGetApp();
		ASSERT_VALID(pApp);
		pApp->m_VNT.DoZeitenDialog();
	}
	CATCH_ALL(e)
	{
		// a failure caused an exception.
	}
	END_CATCH_ALL
}

