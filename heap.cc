/* Heap sort */

#include "Sort.h"

void sort(Elements& A, int execflag)
{
	int i, j, k, x;
	int n = A;

	for (k = n/2; k >= 1; k--) {
		i = k;  x = A[i-1];
		while ((j = 2 * i) <= n) {
			if (j < n && A[j-1] < A[j]) j++;
			if (x >= A[j-1]) break;
			A[i-1]= A[j-1];
			i = j;
		}
		A[i-1] = x;
	}
	while (n > 1) {
		x = A[n-1];  A[n-1]= A[0];  n--;
		i = 1;
		while ((j = 2 * i) <= n) {
			if (j < n && A[j-1] < A[j]) j++;
			if (x >= A[j-1]) break;
			A[i-1]= A[j-1];  i = j;
		}
		A[i-1] = x;
	}
}
