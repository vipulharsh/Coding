#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define replace(r) ((r.a==1)? r.b : r.c)

struct s{
	int a;
	int b;
	int c;
};

int main(){
	
	s x;
	x.a = 1;
	x.b = 0;
	x.c = 0;
	
	replace(x) = replace(x);
	cout<<x.a <<x.b<<x.c<<endl;
	
	return 0;
} 
