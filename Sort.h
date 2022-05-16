#ifdef __SORT_MAIN
int readcount = 0;
int writecount = 0;
int swapcount = 0;
#else
extern int readcount;
extern int writecount;
extern int swapcount;
#endif

class Elements;

class Node {
public:
	int	value;
	int	index;
	//friend	Elements;
public:
	Node() { value = 0; };
	Node(int a) { value = a; };
	void setindex(int a){index = a;};
	Node& operator =  (Node& ) ;
	Node& operator =  (int ) ;
	operator int(){return value;} ;
};

class Elements {
	Node*	array;
	int	N;
public:
	Elements(int n) {
		array= new Node[N=n];
		for (int i=0; i< N; i++)
			array[i].setindex(i);
	};
	~Elements() {delete[] array;};
	Node& operator [] (int i);
	operator int(){return N;}
};

#define swap(A, B) {int t = A; A=B;B=t; swapcount++;}

void proc(Elements&, int);
void makedat(Elements&, int, int);	/* Elements,  flag,   maxvalue */

#define sort proc

const int DEFAULT = -1;
