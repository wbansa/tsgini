// VornachTabelle.h : header file
//
#ifndef _VORNACHTABELLE_H_
#define _VORNACHTABELLE_H_

struct VORNACH_STRUCT { int Vor; int Nach;};

static char VornachTabelleHId[] = "$Id: VornachTabelle.h,v 1.3 2003-06-25 17:39:55 wobansa Exp $";

/////////////////////////////////////////////////////////////////////////////
// CVornachTabelle 

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CVornachTabelle : public 	CMap< CString, LPCSTR, VORNACH_STRUCT, VORNACH_STRUCT& >
{
public:
	void Lade();
	void DoZeitenDialog();
	void SetAt(LPCSTR Mannsch, VORNACH_STRUCT &Vornach);
	~CVornachTabelle();
	CVornachTabelle();
// Operations
public:
	BOOL LookupExt(LPCSTR Mannsch, VORNACH_STRUCT& Vornach);
private:
	CString m_strIniName;
	CString m_strVorSection;
	CString m_strNachSection;
	CString m_strKeineMannsch;
};

#endif