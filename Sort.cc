#include <iostream>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <X11/Xlib.h>
#define __SORT_MAIN
#include "Sort.h"

//#define usleep(d)	{for(int i =0; i< d; i++) ;}

Display *d;
Window w;
int	arraysize  =  300;
int	maxvalue   =  256;
int	interval   =    0;
int	Line = 0, Flush = 0, Perm = 0;
int	grid     =  2;

GC	green, red, black, white;

#define DrawPoint(x,y,c)	XDrawRectangle(d, w, c,\
					x*grid,y*grid+10, grid-1,grid-1)
#define DrawLine(a,c)		XFillRectangle(d, w, c, a*grid, \
					0, grid, maxvalue*grid+20);
#define Pt(a)	(maxvalue-a)

Node& Node::operator = (Node& n)
{
	if (Line) {
		DrawLine(index, red);
	}
	DrawPoint(index, Pt(n.value), green);
	DrawPoint(index, Pt(value), white);

	if(Flush)XFlush(d);

	value = n.value;
	readcount--; writecount++;
	usleep(interval);
	if (Line) {
		DrawLine(index, white);
	}
	DrawPoint(index, Pt(value), black);
	return *this;
}

Node& Node::operator = (int n)
{
	if (Line) {
		DrawLine(index, red);
	}
	DrawPoint(index, Pt(n), green);
	DrawPoint(index, Pt(value), white);

	if(Flush)XFlush(d);

	value = n;
	readcount--; writecount++;
	usleep(interval);
	if (Line) {
		DrawLine(index, white);
	}
	DrawPoint(index, Pt(value), black);
	return *this;
}

Node& Elements::operator [] (int ind)
{
	readcount++;
	if (Line) {
		DrawLine(ind, green);
		DrawPoint(ind, Pt(array[ind].value), red);
	}

	if (Flush) XFlush(d);
	usleep(interval);

	if (Line) {
		DrawLine(ind, white);
		DrawPoint(ind, Pt(array[ind].value), black);
	}
	return array[ind];
}


main(int argc, char *argv[])
{
	int ch;
	XEvent ev;
	XColor dummy, c;
	struct timeval before, after;
	int interval_t=0, Line_t=0, Flush_t=0;
	int initial  =-1, execflag = -1;

	while ((ch = getopt(argc, argv, "g:hd:lr:n:m:fpt:x:")) != -1) {
		switch(ch) {
		case 'd':
			interval_t = atoi(optarg);
			break;
		case 'f':
			Flush_t = 1;
			break;
		case 'l':
			Line_t = 1;
			break;
		case 'r':
			srand(atoi(optarg));
			break;
		case 't':
			initial = atoi(optarg);
			break;
		case 'x':
			execflag = atoi(optarg);
			break;
		case 'm':
			maxvalue = atoi(optarg);
			break;
		case 'g':
			grid = atoi(optarg);
			break;
		case 'n':
			arraysize = atoi(optarg);
			break;
		case 'h':
		default:
			{
			char *s;
			for (s = argv[0]+strlen(argv[0]); *s != '/'; s--) ;
			printf(
			"Usage: %s [-lf] [-d delay] [-r seed] [-n itemsize]\n"
			"       -l ... Enable access animation\n"
			"       -f ... Flush everytime\n"
			"       -d ... Delay count\n"
			"\n"
			"       -g ... Grid size\n"
			"       -n ... Number of items\n"
			"       -m ... Maximum number of random values\n"
			"       -r ... Random seed\n"
			"\n"
			"       -t ...    data flag (defined by makedat())\n"
			"       -x ... execute flag (defined by proc())\n"
			, s+1);
			exit(1);
			}
		}
	}
	if ((d = XOpenDisplay(NULL))== NULL) {
		fprintf(stderr, "Can't Open DISPLAY\n");
		exit(1);
	}
	printf("%d\n", interval_t);
	if (!Perm) maxvalue = arraysize;
	w = XCreateSimpleWindow(d, RootWindow(d,0),
				0, 0, arraysize*grid, maxvalue*grid+20,
				1, BlackPixel(d,0), WhitePixel(d,0));
	XSelectInput(d, w, ExposureMask);
	XMapWindow(d, w);
	XNextEvent(d, &ev);

	red  =XCreateGC(d, w, 0L, NULL);
	black=XCreateGC(d, w, 0L, NULL);
	white=XCreateGC(d, w, 0L, NULL);
	green=XCreateGC(d, w, 0L, NULL);
	if(XParseColor(d, DefaultColormap(d, 0), "red", &c) == 0 ||
		XAllocColor(d, DefaultColormap(d, 0), &c) == 0){
		c.pixel=BlackPixel(d, 0);
	}
	XSetForeground(d, red, c.pixel);
	if(XParseColor(d, DefaultColormap(d, 0), "green", &c) == 0 ||
		XAllocColor(d, DefaultColormap(d, 0), &c) == 0){
		c.pixel=BlackPixel(d, 0);
	}
	XSetForeground(d, green, c.pixel);
	XSetForeground(d, black, BlackPixel(d, 0));
	XSetForeground(d, white, WhitePixel(d, 0));

	Elements e(arraysize);

	makedat(e, initial, maxvalue);

	writecount=0;

	interval = interval_t;
	Flush = Flush_t;
	Line = Line_t;

	XFlush(d);
	printf("RETURN to continue:");
	getchar();

	gettimeofday(&before, (struct timezone *)NULL);
	proc(e, execflag);
	gettimeofday(&after, (struct timezone *)NULL);

	XFlush(d);
	after.tv_sec -= before.tv_sec;
	after.tv_usec -= before.tv_usec;
	if (after.tv_usec < 0)
		after.tv_sec--, after.tv_usec += 1000000;

	printf( "Total read  count = %d\n", readcount);
	printf( "Total write count = %d\n"
		"    ( swap  count = %d )\n\n",
			writecount, swapcount);
	printf( "Total spent time  = %ds (+%dus)\n",
			(int)after.tv_sec, (int)after.tv_usec);
	printf("RETURN to continue:");
	getchar();
}
