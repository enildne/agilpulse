; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPage1
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "agilpulse.h"
LastPage=0

ClassCount=4
Class1=CAgilPulseApp
Class2=CAgilPulseDlg

ResourceCount=2
Class3=CPulseSheet
Resource1=IDD_AGILPULSE_DIALOG
Class4=CPage1
Resource2=IDD_DIALOG1

[CLS:CAgilPulseApp]
Type=0
BaseClass=CWinApp
HeaderFile=AgilPulse.h
ImplementationFile=AgilPulse.cpp
Filter=N
LastObject=CAgilPulseApp

[CLS:CAgilPulseDlg]
Type=0
BaseClass=CDialog
HeaderFile=AgilPulseDlg.h
ImplementationFile=AgilPulseDlg.cpp
Filter=D
LastObject=CAgilPulseDlg

[DLG:IDD_AGILPULSE_DIALOG]
Type=1
Class=CAgilPulseDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CPulseSheet]
Type=0
HeaderFile=PulseSheet.h
ImplementationFile=PulseSheet.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CPulseSheet

[DLG:IDD_DIALOG1]
Type=1
Class=CPage1
ControlCount=1
Control1=IDC_PAGE1,static,1342308352

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CPropertyPage
Filter=D

