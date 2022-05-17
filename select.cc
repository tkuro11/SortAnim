/* select sort */

#include "Sort.h"

void sort(Elements& A, int flag)
{
	int i,j,min;

	for (i = 0; i< A; i++) {
		min = i;
		for (j = i+1; j< A; j++) {
			if ( A[j]<A[min] ){
				min = j;
			}
		}
		swap(A[i],A[min]);
	}
}
