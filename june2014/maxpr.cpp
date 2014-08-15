#include <iostream>
#include <stdio.h>
using namespace std;
#define MODBASE 1000000007


int main(){
	
	int T;
	scanf("%d", &T);
	int frequencies[101];
	int aps[101][200];
	int a[200001];
	int exp2N[200001];
	
	exp2N[0] = 1;
	for(int i=1;i<200001;i++)
		exp2N[i] = (exp2N[i-1] * 2)%MODBASE;
	
	while(T-->0){
		int N;
		scanf("%d", &N);
		for(int i=0;i<N;i++){
			scanf("%d", &a[i]);
		}
		
		for(int i=0;i<101;i++){
			frequencies[i] = 0;
			for(int j=0;j<200;j++)
				aps[i][j] = 0;
		}
		
		int index = N-1;
		int num,next,diffIndex;
		while(index>=0){
			num = a[index];
			for(int diff=1-num; diff<=100-num; diff++){ 
				next = num + diff;
				diffIndex = diff + 100;
				aps[num][diffIndex] = (aps[num][diffIndex] + aps[next][diffIndex])%MODBASE;
				aps[num][diffIndex] = (aps[num][diffIndex] + frequencies[next]) % MODBASE; 
			}
			frequencies[num]++; 
			index--;
	    }
		
	   int total = 0;
	   for(int i=0;i<101;i++)
			total += frequencies[i];
	   for(int i=0;i<101;i++){
			for(int j=0;j<200;j++)
				total = (total + aps[i][j])%MODBASE;
	   }
	   total = (total + 1)%MODBASE;
 /*  
	   for(int i=0;i<20000000;i++){
			frequencies[i%100]++;
			int num  = 1;
			int diff = 2;
			int next = num + diff;
			aps[num][diff+100] = (aps[num][diff+100] + aps[next][diff+100])%MODBASE;
			aps[num][diff+100] = (aps[num][diff+100] + frequencies[next]) % MODBASE; 
		} 
 */	   
	   cout<<((exp2N[N] - total)%MODBASE + MODBASE)%MODBASE<<endl;
	}
	
	return 0;
}
