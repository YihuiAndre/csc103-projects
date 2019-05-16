#include<iostream>
#include<stdio.h>
using namespace std;
/*
unsigned int gcd(unsigned int a, unsigned int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}
*/

# define RTRACE_BEGIN(format,...) \
	static size_t __id=0; \
	static size_t __p=-1; \
	size_t __t = __id++; \
	if (__p == (size_t)-1) { \
		fprintf(stderr,"digraph rtree {\n"); \
		fprintf(stderr,"  edge [color=black fontcolor=black];\n"); \
		fprintf(stderr,"  node [style=filled shape=circle];\n"); \
	} \
	fprintf(stderr,"%lu [label=\"" format "\"]\n",__t,__VA_ARGS__); \
	if (__p != (size_t)-1) fprintf(stderr,"%lu -> %lu\n",__p,__t); \
	size_t __op = __p; /* save old value */ \
	__p = __t;
# define RTRACE_RET(x) \
{ \
	auto __rtrace_rv = x; \
	__p = __op; /* restore for next call */ \
	if (__p == (size_t)-1) { \
		fprintf(stderr,"}\n"); \
	} \
	return __rtrace_rv; \
}

unsigned int gcd(unsigned int a, unsigned int b)
{
	RTRACE_BEGIN("%u,%u",a,b);
	/* setup formatting for nodes */
	if (b == 0) RTRACE_RET(a);
	/* replace return with RTRACE_RET */
	RTRACE_RET(gcd(b,a%b));
}
unsigned int xgcd(int& x, int& y, unsigned int a, unsigned int b)
{
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int xx,yy;
	unsigned int q = a/b, r = a%b;
	unsigned int d = xgcd(xx,yy,b,r);
	x = yy;
	y = xx - yy*q;
	return d;
}

int main()
{
	int x,y;
	unsigned int a = 23, b = 13;
	unsigned int d = xgcd(x,y,a,b);
	//printf("gcd(%i,%i) = %i = %i*%i + %i*%i\n", a,b,d,x,a,y,b);
	printf("gcd(%i,%i) == %i\n", a,b,d);

}



