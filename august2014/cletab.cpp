#include <iostream>
#include <stdio.h>
#include <queue>

#define INFI 1000000000
using namespace std;

class mycomparison{
public:
	bool myoperator(const int&lhs, const int&rhs){
		return (lhs>rhs);
	}
};



int main(){
	
	int T,N,M,C;
	bool status[401];
	int customerList[401];
	int firstArrivals[401];
	scanf("%d", &T);
	
	while(T-->0){
		scanf("%d", &N);
		scanf("%d", &M);
		for(int i=0;i<M;i++){
			scanf("%d", &customerList[i]);
		}	
		
		int cleanTables = N;
		int count=0;
		for(int i=1;i<=400;i++)
			status[i] = false; //not eating
		
		for(int i=0;i<M;i++){
			C = customerList[i];
			if(status[C]) continue;
			
			if(cleanTables>0){
				count++;
				cleanTables--;
				status[C] = true;
				continue;
			}
			
			count++;
			for(int k=0;k<=400;k++)
				firstArrivals[k] = INFI;
			
			for(int j=i;j<M;j++)
				firstArrivals[customerList[j]] = min(firstArrivals[customerList[j]], j); 
			
			int farthest = C;
			int farthestI = i;
			for(int k=1;k<=400;k++){
				if(status[k]){
					if(farthestI < firstArrivals[k]){
						farthest = k;
						farthestI = firstArrivals[k];
					}
				}
			}
			status[farthest] = false; //removed
			status[C] = true;	
		}
			
		printf("%d\n", count);
		
	}
	return 0;
}
