// ZeitPropDialog.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ZeitPropDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static char ZeitPropDialogId[] = "$Id: ZeitPropDialog.cpp,v 1.3 2003-06-25 17:39:55 wobansa Exp $";

/////////////////////////////////////////////////////////////////////////////
// CZeitPropDialog property page

IMPLEMENT_DYNCREATE(CZeitPropDialog, CPropertyPage)

CZeitPropDialog::CZeitPropDialog() : CPropertyPage(CZeitPropDialog::IDD)
{
	//{{AFX_DATA_INIT(CZeitPropDialog)
	m_nNach = 0;
	m_Mannsch = _T("");
	m_nVor = 0;
	//}}AFX_DATA_INIT
}

CZeitPropDialog::~CZeitPropDialog()
{
}

void CZeitPropDialog::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZeitPropDialog)
	DDX_Text(pDX, IDC_IDC_ZEITPROP_NACH, m_nNach);
	DDV_MinMaxInt(pDX, m_nNach, 0, 600);
	DDX_Text(pDX, IDC_ZEITPROP_MANNSCH, m_Mannsch);
	DDX_Text(pDX, IDC_ZEITPROP_VOR, m_nVor);
	DDV_MinMaxInt(pDX, m_nVor, 0, 120);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZeitPropDialog, CPropertyPage)
	//{{AFX_MSG_MAP(CZeitPropDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZeitPropDialog message handlers
