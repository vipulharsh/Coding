#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 1000000



int main(){
	
	int T;
	int a,b,c,d,N,p;
	scanf("%d", &T);
	long long Si;
	
	bool* A;
	A = new bool[MOD];

	long long difference;	
	
	for(int i=0;i<MOD;++i)
		A[i] = false;
		
	while(T-->0){
		scanf("%d%d%d%d%d",&N,&a,&b,&c,&d);
		Si = d;
		A[Si] = (!A[Si]);
		for(int i=1;i<N;++i){
			Si =  ((((a * Si)%MOD) * Si)%MOD + (b * Si)%MOD + c) % MOD;
			A[Si] = (!A[Si]);
		}
		difference=0;
		p = 1;
		for(int i=MOD-1;i>=0;--i){
			if(A[i]){
				difference += p * i;
				p = -p;
				A[i] = false;
			}
		}
		printf("%lld\n", ((difference>0)? difference : -difference));
	}
	return 0;
}
