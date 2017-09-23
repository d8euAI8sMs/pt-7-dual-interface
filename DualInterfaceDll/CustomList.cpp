// CustomList.cpp : Implementation of CCustomList

#include "stdafx.h"
#include "CustomList.h"


// CCustomList

HRESULT STDMETHODCALLTYPE CCustomList::Add( 
    int item)
{
    m_BackingCollection.push_back(item);
    m_cSum += item;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CCustomList::Remove( 
    int item)
{
    for (size_t i = 0; i < m_BackingCollection.size(); ++i)
    {
        if (m_BackingCollection[i] == item)
        {
            m_cSum -= m_BackingCollection[i];
            m_BackingCollection.erase(m_BackingCollection.begin() + i);
            break;
        }
    }
    return S_OK;
}

HRESULT /* [propget] */ STDMETHODCALLTYPE CCustomList::get_Count( 
    /* [retval][out] */ unsigned int *pcCount)
{
    if (!pcCount) return E_POINTER;
    *pcCount = m_BackingCollection.size();
    return S_OK;
}

HRESULT /* [propget] */ STDMETHODCALLTYPE CCustomList::get_Sum( 
    /* [retval][out] */ int *pcSum)
{
    if (!pcSum) return E_POINTER;
    *pcSum = m_cSum;
    return S_OK;
}

HRESULT /* [propget] */ STDMETHODCALLTYPE CCustomList::get_At( 
    unsigned int cPos,
    /* [retval][out] */ int *pItem)
{
    if (!pItem) return E_POINTER;
    if (cPos >= m_BackingCollection.size()) return E_INVALIDARG;
    *pItem = m_BackingCollection[cPos];
    return S_OK;
}

HRESULT /* [propput] */ STDMETHODCALLTYPE CCustomList::put_At( 
    unsigned int cPos,
    int item)
{
    if (cPos >= m_BackingCollection.size()) return E_INVALIDARG;
    m_cSum -= m_BackingCollection[cPos];
    m_BackingCollection[cPos] = item;
    m_cSum += item;
    return S_OK;
}