#include "Sort.h"

#include "swap.h"

// O(n^2)

proc(Elements& A, int flag)
{
	PRELUDE;

	for (int i = 0; i< flag; i++) {
		tmp = A[0];
		for (int j = 0; j< A-1; j++) {
			A[j] = A[j+1];
		}
		A[A-1] = tmp;
	}
}
