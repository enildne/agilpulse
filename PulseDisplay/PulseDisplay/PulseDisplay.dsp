# Microsoft Developer Studio Project File - Name="PulseDisplay" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PulseDisplay - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PulseDisplay.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PulseDisplay.mak" CFG="PulseDisplay - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PulseDisplay - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "PulseDisplay - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PulseDisplay - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_MBCS" /Yu"stdafx.h" /GZ /c
# ADD CPP /nologo /MTd /W3 /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_MBCS" /Yu"stdafx.h" /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x412 /i "$(IntDir)" /d "_DEBUG"
# ADD RSC /l 0x412 /i "$(IntDir)" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib visa32.lib /nologo /subsystem:windows /debug /machine:IX86 /out:"..\bin\$(ProjectName).exe" /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib visa32.lib /nologo /subsystem:windows /debug /machine:IX86 /out:"..\bin\PulseDisplay.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "PulseDisplay - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /GX /Zi /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /GX /Zi /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_MBCS" /Yu"stdafx.h" /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x412 /i "$(IntDir)" /d "NDEBUG"
# ADD RSC /l 0x412 /i "$(IntDir)" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib visa32.lib /nologo /subsystem:windows /debug /machine:IX86 /out:"..\bin\$(ProjectName).exe" /pdbtype:sept /opt:ref /opt:icf
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib visa32.lib /nologo /subsystem:windows /debug /machine:IX86 /out:"..\bin\PulseDisplay.exe" /pdbtype:sept /opt:ref /opt:icf

!ENDIF 

# Begin Target

# Name "PulseDisplay - Win32 Debug"
# Name "PulseDisplay - Win32 Release"
# Begin Group "소스 "

# PROP Default_Filter "cpp;c;cxx;def;odl;idl;hpj;bat;asm;asmx"
# Begin Source File

SOURCE=.\DevList.cpp
DEP_CPP_DEVLI=\
	".\DefineAndSize.h"\
	".\DevList.h"\
	".\PulseDisplay.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"visa.h"\
	{$(INCLUDE)}"visatype.h"\
	
# End Source File
# Begin Source File

SOURCE=.\DrawRect.cpp
DEP_CPP_DRAWR=\
	".\DrawRect.h"\
	".\PulseDisplay.h"\
	".\stdafx.h"\
	
# End Source File
# Begin Source File

SOURCE=.\PulseDisplay.cpp
DEP_CPP_PULSE=\
	".\DefineAndSize.h"\
	".\DevList.h"\
	".\DrawRect.h"\
	".\PulseDisplay.h"\
	".\PulseDisplayDlg.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"visa.h"\
	{$(INCLUDE)}"visatype.h"\
	
# End Source File
# Begin Source File

SOURCE=.\PulseDisplayDlg.cpp
DEP_CPP_PULSED=\
	".\DefineAndSize.h"\
	".\DevList.h"\
	".\DrawRect.h"\
	".\PulseDisplay.h"\
	".\PulseDisplayDlg.h"\
	".\stdafx.h"\
	{$(INCLUDE)}"visa.h"\
	{$(INCLUDE)}"visatype.h"\
	
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	{$(INCLUDE)}"strsafe.h"\
	

!IF  "$(CFG)" == "PulseDisplay - Win32 Debug"

# ADD CPP /nologo /GX /Yc"stdafx.h" /GZ

!ELSEIF  "$(CFG)" == "PulseDisplay - Win32 Release"

# ADD CPP /nologo /GX /Yc"stdafx.h"

!ENDIF 

# End Source File
# End Group
# Begin Group "헤더 "

# PROP Default_Filter "h;hpp;hxx;hm;inl;inc;xsd"
# Begin Source File

SOURCE=.\DefineAndSize.h
# End Source File
# Begin Source File

SOURCE=.\DevList.h
# End Source File
# Begin Source File

SOURCE=.\DrawRect.h
# End Source File
# Begin Source File

SOURCE=.\PulseDisplay.h
# End Source File
# Begin Source File

SOURCE=.\PulseDisplayDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# End Group
# Begin Group "리소스"

# PROP Default_Filter "rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx"
# Begin Source File

SOURCE=.\res\PulseDisplay.ico
# End Source File
# Begin Source File

SOURCE=.\PulseDisplay.rc
# End Source File
# Begin Source File

SOURCE=.\res\PulseDisplay.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\PulseDisplay.manifest
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
