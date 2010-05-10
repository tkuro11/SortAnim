#include <stdlib.h>
#include "Sort.h"

int makedat(Elements& e, int initial, int maxvalue)
{
	int arraysize = e;

	switch (initial) {
	default:
		maxvalue = arraysize;

		int* r;
		r = new int[arraysize];

		for (int i=0; i< arraysize; i++) r[i] = i;

		for (int i=0; i< arraysize; i++) {
			int index = rand() % (arraysize-i), t = r[i];

			r[i] = e[i] = r[i + index];
			r[i + index] = t;
		}

		break;

	case  0:
		maxvalue = arraysize;
		for (int i=0; i< arraysize; i++)
			e[i] = rand() % maxvalue;
		break;

	case  1:
		for (int i=0; i< arraysize; i++)
			e[i] = i;
		break;

	case  2:
		for (int i=0; i< arraysize; i++)
			e[i] = maxvalue - i;
		break;
	}
}
