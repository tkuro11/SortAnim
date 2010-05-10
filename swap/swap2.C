#include "Sort.h"

#include "swap.h"


// O(n) ??

proc(Elements& A, int flag)
{
	PRELUDE;

	int size = A, head = 0;
	int div = flag;

	while(size != div) {
	    if (div > (size-div)) {
		for (int i = head; i< head + (size-div); i++) {
			swap(A[i], A[div+i]);
		}
		head += (size-div);
		div -= (size-div);
		size = (div+size)/2;
	    } else {
		for (int i = head; i< head + div; i++) {
			swap(A[i], A[size-div+i]);
		}
		size -= div;
	    }
	    cout << "head = " << head << " size = " << size
			 << " div = " << div << endl ;
	}
}
