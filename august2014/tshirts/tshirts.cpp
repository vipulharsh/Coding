#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

#define MODBASE 1000000007
#define INFI 2000000000

int N;
bool A[10][101];


int ways[2050][100];


inline int getbit(int i, int bit){  //0 indexed

	return (i>>bit)%2;
}



int getWays(int pattern, int index){
	
	if(index>100)
		return (bool)(pattern%(1<<11)==0);
		
	if(ways[pattern][index] != -1) return ways[pattern][index];
		
	bool alignA[10];
	bool patt[10];
	
	for(int i=0;i<N;i++){
		alignA[i] = A[i][index];
		patt[i] = getbit(pattern, i);
	}
		
	int ret = getWays(pattern, index+1);
	
	for(int i=0;i<N;i++){
		if(patt[i] && alignA[i]){
			int nextPattern = pattern - (1<<i);
			ret = (ret+getWays(nextPattern, index+1))%MODBASE; 	
		}
	}
	
	ways[pattern][index] = ret;
	
	return ret;
}








int main(){
	
	int T;
	scanf("%d", &T);
	while(T-->0){
		scanf("%d\n", &N);
		
		for (int i = 0; i<N; i++) {
			string line;
			getline(cin, line);
			istringstream this_line(line);
			istream_iterator<int> begin(this_line), end;
			vector<int> values(begin, end);
			sort(values.begin(),values.end());
			vector<int>::iterator it = values.begin();		
			int nextTrueValue = *it;
			for(int j=0;j<=100;j++){
				if(j<nextTrueValue)
					A[i][j] = false;
				else{
					A[i][j] = true;
					it++;
					if(it==values.end())
						nextTrueValue = INFI;
					else
						nextTrueValue = *it;
				 }
			}
		}
		for(int i=0;i<=(1<<10);i++)
			for(int j=0;j<=100;j++)
				ways[i][j] = -1;
		
		printf("%d\n", getWays((1<<N) - 1, 0)); 
	}
	return 0;
}
