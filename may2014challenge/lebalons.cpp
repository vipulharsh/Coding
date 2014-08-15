#include <iostream>
#include <algorithm>
#include <cassert>
#include <stdio.h>
using namespace std;

struct balloon{
	int cost;
	int colour;
};

bool operator<(balloon b1, balloon b2){
	return (b1.colour < b2.colour);
}



int N,M;
balloon balloons[41];
long long ways[41][41][2];
long double expectation[41][41][2];





//flag = 0 --> fresh colour
//flag = 1 --> colour is being continud

long long getWays(int i, int j, int flag){
	
	
	//cout<<"there : "<<ways[i][j][flag]<<" : "<<i<<" : "<<j<<" :"<<flag<<" : "<<N<<endl;
	j = max(0, j);
	
	if(i>=N && j==0) return 1;

	if(i>=N) return 0;
	
	
	if(ways[i][j][flag] != -1) return ways[i][j][flag];
	
	
	
	ways[i][j][flag] = getWays(i+1, j, ((balloons[i+1].colour == balloons[i].colour)? flag : 0)); //this one is not selected
	//cout<<"here : "<<ways[i][j][flag]<<" : "<<i<<" : "<<j<<" :"<<flag<<endl;
	//this one is selected
	if(flag){
		ways[i][j][flag] += getWays(i+1, j, ((balloons[i+1].colour == balloons[i].colour)?1:0));
	}
	
	
	else{
		ways[i][j][flag] += getWays(i+1, j-1, ((balloons[i+1].colour == balloons[i].colour)?1:0));
	}
	
	return ways[i][j][flag];
}



long double getExpectation(int i, int j, int flag){
	
	j = max(0, j);
	if(i>=N && j==0) return 0;
	if(i>=N) return -1;
	
	if(expectation[i][j][flag] != -1) return expectation[i][j][flag];
	
	long long w1 = getWays(i+1, j, ((balloons[i+1].colour == balloons[i].colour)? flag : 0));
	long long w2 = getWays(i+1, j - 1 + flag, ((balloons[i+1].colour == balloons[i].colour)?1:0));
	
	if((w1+w2) == 0) return -1;
	
	long double res;
	
	res = (long double)w2/(w1 + w2) * 
			(balloons[i].cost + getExpectation(i+1, j - 1 + flag, ((balloons[i+1].colour == balloons[i].colour)?1:0)));
	
	
	//cout<<"param "<<i<<" : "<<j<<" : "<<flag<<endl;
	//cout<<"res"<<" : "<<res<<" : "<<w1<<" :"<<w2<<" : "<<endl;
	//cout<<getExpectation(i+1, j - flag, ((balloons[i+1].colour == balloons[i].colour)?1:0))<<endl;
	
	//assert(w2==0 || getExpectation(i+1, j - 1 + flag, ((balloons[i+1].colour == balloons[i].colour)?1:0)) >= 0);
	res += (long double)w1/(w1 + w2) * getExpectation(i+1, j, ((balloons[i+1].colour == balloons[i].colour)? flag : 0));	 
	
	expectation[i][j][flag] = res;
	return res;
}




int main(){
	
	int T;
	cin>>T;
	while(T-->0){
		cin>>N>>M;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=M;j++){
				ways[i][j][1] = (ways[i][j][0] = -1);
				expectation[i][j][1] = (expectation[i][j][0] = -1);
			}
		}
		
		for(int i=0;i<N;i++){
			cin>>balloons[i].colour>>balloons[i].cost;
		}
		sort(balloons, balloons + N);
		
		//cout<<getWays(0, M, 0)<<endl;
		printf("%Lf\n", getExpectation(0, M, 0));
	}
	return 0;
}
