/* odd-even transposition sort */

#include "Sort.h"

void sort(Elements& a, int n)
{
  int i,j,o=1;

  for (i=1;i<a/2;i++) {
    do {
      for (j=0+o;j<a-1;j+=2) {
	if (a[j]>a[j+1]) {
	  swap(a[j],a[j+1]);
	}
      }
      o=o^1;
    } while (o==0);
  }
}
    
