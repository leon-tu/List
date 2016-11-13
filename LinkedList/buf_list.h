#ifndef __BUF_LIST__
#define __BUF_LIST__

#include "com_type.h"

struct BD_ST {
	UINT uiBDID;
	UINT uiBDVirtAddr;
};

typedef struct BD_ST* BD_HANDLE;

typedef struct _BD_NODE_ {
	struct _BD_NODE_ *pPre;
	struct _BD_NODE_ *pNext;
	BD_HANDLE hBD;
} BD_NODE;

typedef struct _BD_CHAIN_ {
	BD_NODE *pHead;
	BD_NODE *pTail;
	UINT uiTotalNum;
} BD_CHAIN;

#endif
