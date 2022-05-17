/* Merge sort */

#include "Sort.h"

int *work;

void mergesort(Elements&, int, int);

void sort(Elements& A, int execflag)
{
	work = new int[A/2+1];
	mergesort(A, 0, A-1);
}

void mergesort(Elements& A, int first, int last)
{
	int middle;
	static int i, j, k, p;
	if (first < last) {
		middle = (first + last) / 2;
		mergesort(A, first, middle);
		mergesort(A, middle + 1, last);
		p = 0;
		for (i = first; i <= middle; i++) work[p++] = A[i];
		i = middle + 1;  j = 0;  k = first;
		while (i <= last && j < p)
			if (work[j] <= A[i]) A[k++] = work[j++];
			else                         A[k++] = A[i++];
		while (j < p) A[k++] = work[j++];
	}
}
