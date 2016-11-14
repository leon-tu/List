#include "BDChain_API.h"

#define BD_NUM (6)

int main() {
	HRESULT uiRc = SUCCESS;
	BD_CHAIN *pBDChain = NULL;
	INT i = 0;
	UINT uiNum = 0;

	char *str = "string";

	printf("sizeof %s is %u\n", str, sizeof(str));

	struct BD_ST stBD[BD_NUM] = { {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6} };
	uiRc = BDCHAIN_CREATE(&pBDChain);
	if (SUCCESS != uiRc) {
		printf("Create BD chain fail, rc[0x%x]\n", uiRc);
		return 0;
	}

	for (i = 0; i < BD_NUM; i++) {
		uiRc = BDCHAIN_PUSH_BACK(pBDChain, &stBD[i]);
		if (SUCCESS != uiRc) {
			printf("Push BD fail, rc[0x%x]\n", uiRc);
			return 0;
		}
	}

	uiRc = BDCHAIN_GET_ITEM_NUM(pBDChain, &uiNum);
	printf("Push finished, node num[%u]\n", uiNum);

	for (i = 1; i <= uiNum; i++) {
		BD_HANDLE hBD = NULL;
		uiRc = BDCHAIN_POP_FRONT(pBDChain, &hBD);
		printf("The %dst ID is [%u]\n", i , hBD->uiBDID);
	}

	//sleep(5000);
	return 0;
}