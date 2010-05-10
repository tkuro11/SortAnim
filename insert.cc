/* insertion sort */

#include "Sort.h"

int sort(Elements& A, int execflag)
{
	int i,j,s;

	for (i = 1; i< A; i++) {
		s = A[i];
		for (j = i - 1; j >=0; j--) {
			if (A[j] > s)
				A[j+1] = A[j];
			else
				break;
		}
		A[j+1] = s;
	}
}
