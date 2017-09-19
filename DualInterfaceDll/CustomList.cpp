// CustomList.cpp : Implementation of CCustomList

#include "stdafx.h"
#include "CustomList.h"


// CCustomList

HRESULT STDMETHODCALLTYPE CCustomList::Add( 
    int item)
{
    m_BackingCollection.push_back(item);
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CCustomList::Remove( 
    int item)
{
    for (size_t i = 0; i < m_BackingCollection.size(); ++i)
    {
        if (m_BackingCollection[i] == item)
        {
            m_BackingCollection.erase(m_BackingCollection.begin() + i);
            break;
        }
    }
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CCustomList::GetCount( 
    /* [retval][out] */ unsigned int *pcCount)
{
    if (!pcCount) return E_POINTER;
    *pcCount = m_BackingCollection.size();
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CCustomList::GetAt( 
    unsigned int cPos,
    /* [retval][out] */ int *pItem)
{
    if (!pItem) return E_POINTER;
    if (cPos >= m_BackingCollection.size()) return E_INVALIDARG;
    *pItem = m_BackingCollection[cPos];
    return S_OK;
}