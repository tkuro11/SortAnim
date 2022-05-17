/* quick sort */

#include "Sort.h"

int q_sort(Elements&, int, int);

void sort(Elements& A, int flag)
{
	q_sort(A, 0, A-1);
}

int q_sort(Elements& A, int first, int last)
{
	int i,j,basis;
	if (last-first <= 0) return 0;
	basis = A[first];
	i= first; j = last;
	do {
		while(A[i] < basis) i++;
		while(A[j] > basis) j--;
		if (i <= j) {swap(A[i],A[j]);i++;j--;}
	} while (i <= j);
	q_sort(A, first, j);
	q_sort(A, i,last);
}
