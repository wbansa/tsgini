// CZeitenDialog.h : header file
//
#ifndef _ZEITENDIALOG_H_
#define _ZEITENDIALOG_H_
#include "resource.h"

static const char ZeitenDialogHId[] = "$Id: ZeitenDialog.h,v 1.2 2003-06-22 19:16:46 wobansa Exp $";
 
/////////////////////////////////////////////////////////////////////////////
// CZeitenDialog dialog

class CZeitenDialog : public CDialog
{
// Construction
public:
	CZeitenDialog(CVornachTabelle* pTabelle, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZeitenDialog)
	enum { IDD = IDD_ZEITENDIALOG };
	CListBox	m_Liste;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZeitenDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ZerlegeZeile(CString* zeile, CString* pMannsch, VORNACH_STRUCT* pVornach);
	void MacheZeile(CString* zeile, CString* pMannsch, VORNACH_STRUCT* pVornach);
	CVornachTabelle* m_pVornachZeiten;
	// Generated message map functions
	//{{AFX_MSG(CZeitenDialog)
	afx_msg void OnDblclkList1();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif