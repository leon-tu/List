#ifndef __BDCHAIN_API__
#define __BDCHAIN_API__

#include "stdio.h"
#include "com_type.h"
#include "buf_list.h"

HRESULT BDCHAIN_CREATE(BD_CHAIN **ppBDChain);
HRESULT BDCHAIN_DESTROY(BD_CHAIN *pBDChain);
HRESULT BDCHAIN_PUSH_BACK(BD_CHAIN *pBDChain, BD_HANDLE hBD);
HRESULT BDCHAIN_POP_FRONT(BD_CHAIN *pBDChain, BD_HANDLE *hBD);
HRESULT BDCHAIN_GET_ITEM_NUM(BD_CHAIN *pBDChain, UINT *pNum);
HRESULT InterCreateNode(BD_NODE **ppBDNode, BD_HANDLE hBD);
HRESULT InterDestroyNode(BD_NODE *pBDNode);

#endif