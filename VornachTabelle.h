// VornachTabelle.h : header file
//
#ifndef _VORNACHTABELLE_H_
#define _VORNACHTABELLE_H_

struct VORNACH_STRUCT { int Vor; int Nach;};

static const char VornachTabelleHId[] = "$Id: VornachTabelle.h,v 1.2 2003-06-22 19:16:46 wobansa Exp $";

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