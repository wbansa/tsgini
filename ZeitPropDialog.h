// ZeitPropDialog.h : header file
//
#ifndef _ZEITPROPDIALOG_H_
#define _ZEITPROPDIALOG_H_

#include "resource.h"

static const char ZeitPropDialogHId[] = "$Id: ZeitPropDialog.h,v 1.2 2003-06-22 19:16:46 wobansa Exp $";

/////////////////////////////////////////////////////////////////////////////
// CZeitPropDialog dialog

class CZeitPropDialog : public CPropertyPage
{
	DECLARE_DYNCREATE(CZeitPropDialog)

// Construction
public:
	CZeitPropDialog();
	~CZeitPropDialog();

// Dialog Data
	//{{AFX_DATA(CZeitPropDialog)
	enum { IDD = IDD_ZEITPROP };
	int		m_nNach;
	CString	m_Mannsch;
	int		m_nVor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CZeitPropDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CZeitPropDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
#endif