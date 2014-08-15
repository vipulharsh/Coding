#include <iostream>
#include <stdio.h>
#include <map>
#include <assert.h>
using namespace std;

#define MODBASE 1000000007


int N,Q;
int A[10001];
long long cumA[10001];
map<long long, int> powerMaps[62];
long long ten18 = 1000000000000000000;



int root(long long x, int powRoot){
	
	map<long long,int>::iterator it;
	it = powerMaps[powRoot].upper_bound(x);
	
	int resultRoot;
	if(it == powerMaps[powRoot].end()) resultRoot = powerMaps[powRoot].rbegin()->second;
	else if(it != powerMaps[powRoot].begin()){
		 it--;
		 resultRoot = it->second;
	 }
	return resultRoot; 
}


//binary Search
int squareRoot(long long x){
	
	int l,u,mid;
	l = 1;
	u = 1000000000;
	mid = (l+u)/2;
	while(l<=u){
		//cout<<l<<" : "<<u<<endl;
		mid = (l+u)/2;
		if(((long long)mid*mid <= x) && ((long long)(mid+1)*(mid+1) > x)) return mid;
		
		if((long long)mid*mid > x){
				u = mid - 1;
		}
		
		else{ 
			l = mid + 1;
		}
	}
	
	assert(false);
	return -1;	
}
	
	
	
	
	



int main(){
	int T;
	scanf("%d", &T);
	//Pre-processing
	for(int i=3;i<62;i++){
		powerMaps[i].insert(pair<long long,int>(1,1));
	}
	
	for(int i=2;i<=1000000;i++){
		long long currPower = (long long)i * (long long)i * i;
		int currExp = 3;
		powerMaps[currExp].insert(pair<long long, int>(currPower, i));
		while(1){
			
			if(ten18/i < currPower){
				break;
			}
			else{
				currExp++;
				currPower = currPower * i;
				powerMaps[currExp].insert(pair<long long, int>(currPower, i));
			}
		}
	}
	

	while(T-->0){
		scanf("%d", &N);
		scanf("%d", &Q);
		for(int i=0;i<N;i++){
			scanf("%d", &A[i]);
		}
		cumA[0] = A[0];		
		for(int i=1;i<N;i++){
			cumA[i] = cumA[i-1] + A[i];
		}
		
		for(int qq=0;qq<Q;qq++){
			long long x;
			scanf("%lld", &x);
			int ind=0;
			long long sum = ((x%MODBASE) * (long long)A[ind])%MODBASE;
			ind++;
			sum = (sum + ((int)(squareRoot(x)) * (long long)A[ind])%MODBASE)%MODBASE;  
			ind++;
			//cout<<"Sqrt("<<x<<") = "<<squareRoot(x)<<endl;
			while(ind<N){
				
				int resultRoot = root(x, ind+1);
				//printf("resultRoot is : %d for index : %d \n", resultRoot, ind);
				if(resultRoot == 1){
					sum = ((sum + cumA[N-1])%MODBASE - cumA[ind-1])%MODBASE;
					break;
				}
				else
				{
					sum = (sum + (resultRoot * (long long)A[ind])%MODBASE)%MODBASE;
				}
				ind++;
			}
			printf("%d\n", (int)(sum + MODBASE)%MODBASE);
		}
	}
	
	return 0;
}
