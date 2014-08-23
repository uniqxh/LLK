; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWndDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wnd.h"

ClassCount=3
Class1=CWndApp
Class2=CWndDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WND_DIALOG
Resource4=IDR_MAIN_MENU

[CLS:CWndApp]
Type=0
HeaderFile=wnd.h
ImplementationFile=wnd.cpp
Filter=N

[CLS:CWndDlg]
Type=0
HeaderFile=wndDlg.h
ImplementationFile=wndDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CWndDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=wndDlg.h
ImplementationFile=wndDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WND_DIALOG]
Type=1
Class=CWndDlg
ControlCount=0

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=ID_new_game
CommandCount=1

