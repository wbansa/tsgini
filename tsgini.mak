# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=tsgini - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to tsgini - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "tsgini - Win32 Release" && "$(CFG)" != "tsgini - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "tsgini.mak" CFG="tsgini - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tsgini - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "tsgini - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "tsgini - Win32 Debug"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "tsgini - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "e:\entw-obj+exec\tsgini\Release"
# PROP Intermediate_Dir "e:\entw-obj+exec\tsgini\release"
# PROP Target_Dir ""
OUTDIR=e:\entw-obj+exec\tsgini\Release
INTDIR=e:\entw-obj+exec\tsgini\release

ALL : "$(OUTDIR)\tsgini.dll"

CLEAN : 
	-@erase "d:\entw-obj+exec\Release\tsgini.lib"
	-@erase "..\..\entw-obj+exec\tsgini\release\tsgini.obj"
	-@erase "..\..\entw-obj+exec\tsgini\release\StdAfx.obj"
	-@erase "..\..\entw-obj+exec\tsgini\release\ZeitPropDialog.obj"
	-@erase "..\..\entw-obj+exec\tsgini\release\ZeitenDialog.obj"
	-@erase "..\..\entw-obj+exec\tsgini\release\VornachTabelle.obj"
	-@erase "..\..\entw-obj+exec\tsgini\release\tsgini.res"
	-@erase "d:\entw-obj+exec\Release\tsgini.exp"
	-@erase "..\..\entw-obj+exec\release\tsgini.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/tsgini.pch" /YX /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS="e:\entw-obj+exec\tsgini\release/"
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x407 /fo"$(INTDIR)/tsgini.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/tsgini.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"e:\entw-obj+exec\release\tsgini.dll" /implib:"e:\entw-obj+exec\Release/tsgini.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/tsgini.pdb" /machine:I386 /def:".\tsgini.def"\
 /out:"e:\entw-obj+exec\release\tsgini.dll"\
 /implib:"e:\entw-obj+exec\Release/tsgini.lib" 
DEF_FILE= \
	".\tsgini.def"
LINK32_OBJS= \
	"$(INTDIR)/tsgini.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/ZeitPropDialog.obj" \
	"$(INTDIR)/ZeitenDialog.obj" \
	"$(INTDIR)/VornachTabelle.obj" \
	"$(INTDIR)/tsgini.res"

"$(OUTDIR)\tsgini.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "tsgini - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "e:\entw-obj+exec\tsgini\Debug"
# PROP Intermediate_Dir "e:\entw-obj+exec\tsgini\Debug"
# PROP Target_Dir ""
OUTDIR=e:\entw-obj+exec\tsgini\Debug
INTDIR=e:\entw-obj+exec\tsgini\Debug

ALL : "$(OUTDIR)\tsgini.dll"

CLEAN : 
	-@erase "d:\entw-obj+exec\Debug\tsgini.lib"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\tsgini.obj"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\StdAfx.obj"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\ZeitPropDialog.obj"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\ZeitenDialog.obj"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\VornachTabelle.obj"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\tsgini.res"
	-@erase "d:\entw-obj+exec\Debug\tsgini.exp"
	-@erase "..\..\entw-obj+exec\Debug\tsgini.dll"
	-@erase "..\..\entw-obj+exec\Debug\tsgini.ilk"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\tsgini.pdb"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\vc40.pdb"
	-@erase "..\..\entw-obj+exec\tsgini\Debug\vc40.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/tsgini.pch" /YX\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS="e:\entw-obj+exec\tsgini\Debug/"
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x407 /fo"$(INTDIR)/tsgini.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/tsgini.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"e:\entw-obj+exec\Debug/tsgini.dll" /implib:"e:\entw-obj+exec\Debug/tsgini.lib"
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/tsgini.pdb" /debug /machine:I386 /def:".\tsgini.def"\
 /out:"e:\entw-obj+exec\Debug/tsgini.dll"\
 /implib:"e:\entw-obj+exec\Debug/tsgini.lib" 
DEF_FILE= \
	".\tsgini.def"
LINK32_OBJS= \
	"$(INTDIR)/tsgini.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/ZeitPropDialog.obj" \
	"$(INTDIR)/ZeitenDialog.obj" \
	"$(INTDIR)/VornachTabelle.obj" \
	"$(INTDIR)/tsgini.res"

"$(OUTDIR)\tsgini.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "tsgini - Win32 Release"
# Name "tsgini - Win32 Debug"

!IF  "$(CFG)" == "tsgini - Win32 Release"

!ELSEIF  "$(CFG)" == "tsgini - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\tsgini.cpp
DEP_CPP_TSGIN=\
	".\StdAfx.h"\
	".\tsgini.h"\
	".\VornachTabelle.h"\
	

!IF  "$(CFG)" == "tsgini - Win32 Release"


"$(INTDIR)\tsgini.obj" : $(SOURCE) $(DEP_CPP_TSGIN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "tsgini - Win32 Debug"


"$(INTDIR)\tsgini.obj" : $(SOURCE) $(DEP_CPP_TSGIN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\tsgini.def

!IF  "$(CFG)" == "tsgini - Win32 Release"

!ELSEIF  "$(CFG)" == "tsgini - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ZeitPropDialog.cpp
DEP_CPP_ZEITP=\
	".\StdAfx.h"\
	".\ZeitPropDialog.h"\
	

"$(INTDIR)\ZeitPropDialog.obj" : $(SOURCE) $(DEP_CPP_ZEITP) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ZeitenDialog.cpp
DEP_CPP_ZEITE=\
	".\StdAfx.h"\
	".\VornachTabelle.h"\
	".\ZeitenDialog.h"\
	".\ZeitPropDialog.h"\
	

"$(INTDIR)\ZeitenDialog.obj" : $(SOURCE) $(DEP_CPP_ZEITE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\VornachTabelle.cpp

!IF  "$(CFG)" == "tsgini - Win32 Release"

DEP_CPP_VORNA=\
	".\StdAfx.h"\
	".\VornachTabelle.h"\
	".\ZeitenDialog.h"\
	".\ZeitPropDialog.h"\
	

"$(INTDIR)\VornachTabelle.obj" : $(SOURCE) $(DEP_CPP_VORNA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "tsgini - Win32 Debug"

DEP_CPP_VORNA=\
	".\StdAfx.h"\
	".\VornachTabelle.h"\
	".\ZeitenDialog.h"\
	".\ZeitPropDialog.h"\
	
NODEP_CPP_VORNA=\
	".\BEL"\
	

"$(INTDIR)\VornachTabelle.obj" : $(SOURCE) $(DEP_CPP_VORNA) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\tsgini.rc
DEP_RSC_TSGINI=\
	".\res\tsgini.rc2"\
	

"$(INTDIR)\tsgini.res" : $(SOURCE) $(DEP_RSC_TSGINI) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
