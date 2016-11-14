#include "BDChain_API.h"

HRESULT BDCHAIN_CREATE(BD_CHAIN **ppBDChain)
{
	CHK_PARAM(ppBDChain);
	BD_CHAIN *pBDChainTmp = NULL;

	pBDChainTmp = (BD_CHAIN *)BUFAlloc(sizeof(BD_CHAIN));
	if (NULL == pBDChainTmp) {
		printf("Alloc BD chain fail\n");
		return ERR_NOMEM;
	}
	pBDChainTmp->pHead = NULL;
	pBDChainTmp->pTail = NULL;
	pBDChainTmp->uiTotalNum = 0;

	*ppBDChain = pBDChainTmp;
	return SUCCESS;
}

HRESULT BDCHAIN_DESTROY(BD_CHAIN *pBDChain)
{
	CHK_PARAM(pBDChain);
	HRESULT uiRc = SUCCESS;

	for (; pBDChain->pHead != NULL; pBDChain->pHead = pBDChain->pHead->pNext) {
		uiRc = InterDestroyNode(pBDChain->pHead);
		CHK_RC(uiRc);
	}

	BUFFree(pBDChain);
	return SUCCESS;
}

HRESULT InterCreateNode(BD_NODE **ppBDNode, BD_HANDLE hBD)
{
	CHK_PARAM(ppBDNode);
	BD_NODE *pBDNode = NULL;

	pBDNode = BUFAlloc(sizeof(BD_NODE));
	if (NULL == pBDNode) {
		printf("Alloc BD node fail\n");
		return ERR_NOMEM;
	}
	pBDNode->pPre = NULL;
	pBDNode->pNext = NULL;
	pBDNode->hBD = hBD;
		
	*ppBDNode = pBDNode;
	printf("Create BD node[0x%x] with BD ID[%u]\n", *ppBDNode, hBD->uiBDID);
	return SUCCESS;
}

HRESULT InterDestroyNode(BD_NODE *pBDNode) {
	CHK_PARAM(pBDNode);
	HRESULT uiRc = SUCCESS;

	printf("Destroy BD node[0x%x] with BD ID[%u]\n", pBDNode, pBDNode->hBD->uiBDID);
	BUFFree(pBDNode);
	return uiRc;
}

HRESULT BDCHAIN_PUSH_BACK(BD_CHAIN *pBDChain, BD_HANDLE hBD)
{
	CHK_PARAM(pBDChain);
	HRESULT uiRc = SUCCESS;
	BD_NODE *pBDNode = NULL;

	uiRc = InterCreateNode(&pBDNode, hBD);
	CHK_RC(uiRc);

	if (NULL == pBDChain->pHead) {
		pBDChain->pHead = pBDNode;
	}
	else {
		pBDChain->pTail->pNext = pBDNode;
		pBDNode->pPre = pBDChain->pTail;
	}

	pBDChain->pTail = pBDNode;
	pBDChain->uiTotalNum++;

	return uiRc;
}

HRESULT BDCHAIN_POP_FRONT(BD_CHAIN *pBDChain, BD_HANDLE *hBD)
{
	CHK_PARAM(pBDChain);
	CHK_PARAM(hBD);
	HRESULT uiRc = SUCCESS;
	BD_NODE *pBDNode = NULL;

	if (pBDChain->pHead) {
		pBDNode = pBDChain->pHead;
		*hBD = pBDNode->hBD;
		uiRc = InterDestroyNode(pBDNode);
		CHK_RC(uiRc);

		pBDChain->pHead = pBDChain->pHead->pNext;
		if (pBDChain->pHead) {
			pBDChain->pHead->pPre = NULL;
		}
		else
		{
			pBDChain->pTail = NULL;
		}
	}
	else
	{
		*hBD = NULL;
		return ERR_ERRPARAM;
	}

	pBDChain->uiTotalNum--;
	return uiRc;
}

HRESULT BDCHAIN_GET_ITEM_NUM(BD_CHAIN *pBDChain, UINT *pNum)
{
	CHK_PARAM(pBDChain && pNum);

	*pNum = pBDChain->uiTotalNum;
	return SUCCESS;
}
