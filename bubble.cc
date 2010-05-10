/* bubble sort */

#include "Sort.h"

int sort(Elements& A, int execflag)
{
	int i,j;

	for (i = 0; i< A-1; i++) {
		for (j = A-1; j >=i+1; j--){
			if (A[j-1]>A[j]){
				swap(A[j-1],A[j]);
			}
		}
	}
}
