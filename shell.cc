/* shell sort */

#include "Sort.h"

int sort(Elements& A, int flag)
{
	int h=1, i, j, x;

	while (h <= A) h = 3 * h + 1;
	h /= 9;
	while (h > 0) {
		for (i = h; i < A; i++) {
			x = A[i];
			for (j = i - h; j >= 0 && A[j] > x; j -= h)
				A[j+h] = A[j];
			A[j+h] = x;
		}
		h /= 3;
	}
}
