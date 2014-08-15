#include <iostream>
#include <stdio.h>

using namespace std;

#define in(x) scanf("%d", &x) 
#define inLL(x) scanf("%lld", &x)

int main(){
	
	int T;
	input(T);
	
	int N;
	int digits[20];
	
	
	
	while(T--0){
		
		inLL(N);
		
		for(int i=0;i<20;i++)
			digits[i] = 0;
			
			
		int index = 0;
		int temp = N;
		while(temp > 0){
			digits[index] = temp % 10;
			temp = temp/10
			index++
		}	
		
		
		
	}	
	return 0;
}
