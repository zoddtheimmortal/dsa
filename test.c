#include<stdio.h>

int main(int argc, char const *argv[])
{
	int a,b,c,d;
	a=3; b=5;
c=a,b;
	d=(a,b);
	printf("%d %d\n",c,d );
}