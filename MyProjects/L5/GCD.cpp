#include<iostream>
#include<stdio.h>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
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
	printf("gcd(%i,%i) = %i = %i*%i + %i*%i\n", a,b,d,x,a,y,b);
}



