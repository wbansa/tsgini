// tsgini.h : main header file for the TSGINI DLL
//

#ifndef _TSGINI_H_
#define _TSGINI_H_

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "VornachTabelle.h"

static const char tsginiHId[] = "$Id: tsgini.h,v 1.2 2003-06-22 19:16:46 wobansa Exp $";

 void __stdcall LiesZeiten(LPTSTR pZeit1, LPTSTR pZeit2, LPCSTR pMannsch);
 void __stdcall LiesVornach(VORNACH_STRUCT* pVN, CString* pMannsch);
 void __stdcall ZeitenDialog();

/////////////////////////////////////////////////////////////////////////////
// CTsginiApp
// See tsgini.cpp for the implementation of this class
//

class CTsginiApp : public CWinApp
{
public:
	CTsginiApp(LPCTSTR pszAppName) : CWinApp(pszAppName) 
	{TRACE("Construct %s\n", pszAppName);}
	
	~CTsginiApp() {TRACE("Destruct %s\n", m_pszAppName);}
	CVornachTabelle m_VNT;
	virtual BOOL InitInstance();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTsginiApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CTsginiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////



#endif