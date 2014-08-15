#include <iostream>
#include <stdio.h>
using namespace std;

int N;
int *H;
int *ways;

#define OFFSET 4000000
#define MODBASE 1000000009


inline void in(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked()); 
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    } 
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    } 
    if(neg)
        x = -x;
}

int main(){
	
	int T;
	
	H = new int[1000001];
	ways = new int[8000001];
	for(int i=0;i<=8000000; i++)
		ways[i] = 0;
	
	in(T);
	while(T-->0){
		int diff;
		in(N);
		in(diff);
		for(int i=1;i<N;i++){
			in(H[i-1]);
			H[i-1] = H[i-1] - diff;
			diff = H[i-1] + diff;
		}
		N--;
		int total = 0;
		for(int i=N-1;i>=0;i--){
			int x0 = ways[OFFSET + H[i]];
			ways[OFFSET + H[i]] = (total + 1)%MODBASE;
			total = (total + (ways[OFFSET + H[i]] - x0)%MODBASE)%MODBASE;
			printf("%d ",total);
		}
		
		for(int i=N-1;i>=0;i--){
			ways[OFFSET + H[i]] = 0;
		}
		 
		printf("%d\n", (total+MODBASE)%MODBASE);	
	}
	return 0;
}
