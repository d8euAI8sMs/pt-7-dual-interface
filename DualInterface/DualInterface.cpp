// DualInterface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#import "DualInterfaceDll.tlb"

#include "dualinterfacedll.tlh"

#include <iostream>

static const UUID CLSID_CLIST = __uuidof(DualInterfaceDllLib::CustomList);
static const UUID IID_IList   = __uuidof(DualInterfaceDllLib::ICustomList);

int _tmain(int argc, _TCHAR* argv[])
{
    CoInitialize(NULL);
    DualInterfaceDllLib::ICustomListPtr list(CLSID_CLIST);

    std::cout << "Add 3 items" << std::endl;

    list->Add(25);
    list->Add(26);
    list->Add(27);

    std::cout << "Iterate" << std::endl;

    unsigned size = list->GetCount();

    std::cout << "The size is " << size << std::endl;

    for (int i = 0; i < size; ++i)
    {
        int item = list->GetAt(i);
        std::cout << "\tItem at position " << i << " is " << item << std::endl;
    }

    std::cout << "Remove 3 items" << std::endl;

    list->Remove(25);
    list->Remove(26);
    list->Remove(27);

    size = list->GetCount();

    std::cout << "The size is " << size << std::endl;

    std::cout << std::endl << std::endl << std::endl;
    std::cout << "The same using Invoke" << std::endl;
    std::cout << std::endl << std::endl << std::endl;

    OLECHAR *name;
    DISPID dispid;
    VARIANTARG args[2];
    DISPPARAMS dispParams;

    std::cout << "Add 3 items" << std::endl;

    name = L"Add";
    list->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);

    args[0].vt = VT_INT;
    args[0].intVal = 25;
    dispParams = { args, NULL, 1, 0 };
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, NULL, NULL, NULL);
    args[0].intVal = 26;
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, NULL, NULL, NULL);
    args[0].intVal = 27;
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, NULL, NULL, NULL);

    std::cout << "Iterate" << std::endl;

    name = L"GetCount";
    HRESULT rc = list->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);

    dispParams = { NULL, NULL, 0, 0 };
    rc = list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, &args[0], NULL, NULL);
    size = args[0].uintVal;

    std::cout << "The size is " << size << std::endl;

    for (int i = 0; i < size; ++i)
    {
        int item;

        name = L"GetAt";
        HRESULT rc = list->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);

        args[0].vt = VT_UINT;
        args[0].uintVal = i;
        dispParams = { args, NULL, 1, 0 };
        list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, &args[1], NULL, NULL);
        item = args[1].intVal;

        std::cout << "\tItem at position " << i << " is " << item << std::endl;
    }

    std::cout << "Remove 3 items" << std::endl;

    name = L"Remove";
    list->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);

    args[0].vt = VT_INT;
    args[0].intVal = 25;
    dispParams = { args, NULL, 1, 0 };
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, NULL, NULL, NULL);
    args[0].intVal = 26;
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, NULL, NULL, NULL);
    args[0].intVal = 27;
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, NULL, NULL, NULL);

    name = L"GetCount";
    list->GetIDsOfNames(IID_NULL, &name, 1, GetUserDefaultLCID(), &dispid);

    dispParams = { NULL, NULL, 0, 0 };
    list->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &dispParams, &args[0], NULL, NULL);
    size = args[0].uintVal;

    std::cout << "The size is " << size << std::endl;

    system("pause");

	return 0;
}
