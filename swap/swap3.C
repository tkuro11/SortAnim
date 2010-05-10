#include "Sort.h"
#include "swap.h"

// O(n)

proc(Elements& A, int flag)
{
	PRELUDE;

	for (int i = 0; i<  A/2; i++) swap(A[i], A[A-i-1]);
	for (int i = 0; i< (A-flag+1)/2; i++) swap(A[i], A[(A-flag-1)-i]);
	for (int i = 0; i< (flag+1)/2; i++) swap(A[(A-flag-1)+i], A[(A-1)-i]);
}
