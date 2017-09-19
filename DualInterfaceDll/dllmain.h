// dllmain.h : Declaration of module class.

class CDualInterfaceDllModule : public ATL::CAtlDllModuleT< CDualInterfaceDllModule >
{
public :
	DECLARE_LIBID(LIBID_DualInterfaceDllLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DUALINTERFACEDLL, "{38E7256E-6894-431D-ACB7-EEDC4BE601F5}")
};

extern class CDualInterfaceDllModule _AtlModule;
