#include "Sort.h"

makedat(Elements& A, int flag, int maxval)
{
	for (int i =0; i< A; i++){
		A[i] = i*maxval/A;
	}
}
