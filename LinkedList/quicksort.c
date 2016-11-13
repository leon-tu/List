#include "QuickSort.h"

INT ArrayAdjust(INT *pArray, INT iL, INT iR) 
{
	INT iFixValue = pArray[iL];
	INT i = iL, j = iR;
	while (i < j)  // when i == j, exit the loop
	{
		while (i < j && pArray[j] >= iFixValue)
		{
			j--;
		}

		if (i < j) {	
			pArray[i] = pArray[j];
			i++;
		}

		while (i < j && pArray[i] < iFixValue) 
		{
			i++;
		}

		if (i < j) {
			pArray[j] = pArray[i];
			j--;
		}
	}
	
	pArray[i] = iFixValue;
	//printf("i %d, j %d\n", i, j);
	return i;
}

void QuickSortFun(INT *pArray, INT iL, INT iR)
{
	INT iIdx = 0;
	if (iL < iR)
	{
		iIdx = ArrayAdjust(pArray, iL, iR);
		QuickSortFun(pArray, iL, iIdx -1);
		QuickSortFun(pArray, iIdx + 1, iR);
	}

	return;
}