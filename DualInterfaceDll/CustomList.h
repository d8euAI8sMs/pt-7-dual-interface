// CustomList.h : Declaration of the CCustomList

#pragma once
#include "resource.h"       // main symbols



#include "DualInterfaceDll_i.h"

#include <vector>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CCustomList

class ATL_NO_VTABLE CCustomList :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCustomList, &CLSID_CustomList>,
	public IDispatchImpl<ICustomList, &IID_ICustomList, &LIBID_DualInterfaceDllLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCustomList()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CUSTOMLIST)


BEGIN_COM_MAP(CCustomList)
	COM_INTERFACE_ENTRY(ICustomList)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

    virtual HRESULT STDMETHODCALLTYPE Add( 
        int item);
    
    virtual HRESULT STDMETHODCALLTYPE Remove( 
        int item);
        
    virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
        /* [retval][out] */ unsigned int *pcCount);
    
    virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Sum( 
        /* [retval][out] */ int *pcSum);
        
    virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_At( 
        unsigned int cPos,
        /* [retval][out] */ int *pItem);
    
    virtual /* [propputref] */ HRESULT STDMETHODCALLTYPE put_At( 
        unsigned int cPos,
        int pItem);

protected:

    std::vector < int > m_BackingCollection;
    int m_cSum;

};

OBJECT_ENTRY_AUTO(__uuidof(CustomList), CCustomList)
