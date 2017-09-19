// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "DualInterfaceDll_i.h"
#include "dllmain.h"

CDualInterfaceDllModule _AtlModule;

class CDualInterfaceDllApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CDualInterfaceDllApp, CWinApp)
END_MESSAGE_MAP()

CDualInterfaceDllApp theApp;

BOOL CDualInterfaceDllApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CDualInterfaceDllApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
