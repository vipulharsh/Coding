#include <iostream>
#include <algorithm>
#include <iomanip> 
using namespace std;

struct block{
			
	int colour;
	int size;
};


bool compareBlocks (block b1, block b2) { 
	return (b1.colour<b2.colour); 
}


int colourfulness[11][11][201]; //10 is the maxsize of a block
int N,K;
int currColour;
int ways[201][21][21]; //20 is the max. number of blocks
block blocks[21];




//((x * y * p! * q!)/n!)
long double multiplyWithoutOverflow(int x, int y, int p, int q, int n){ 
	
	int a = max(p,q);
	int b = min(p,q);
	long long ret = x;
	ret *= y;
	
	for(int i=1;i<=b;i++){
		ret *= i;
	}
	
	long double ret1 = ret;
	for(int i=n;i>a;i--){
		ret1 /= i;
	}
	return ret1;
}


int getcolourfulness(int blockSize1, int blockSize2, int distance){
	
	if(colourfulness[blockSize1][blockSize2][distance] != -1)
		return colourfulness[blockSize1][blockSize2][distance];
				
	int leftEndBlock2 = blockSize1 + distance;
	int rightEndBlock2 = leftEndBlock2 + blockSize2 - 1;	
	int _colourfulness = 0;
	
	for(int i=0;i<blockSize1;i++){
		if((i+K >= leftEndBlock2) && (i+K <= rightEndBlock2))
			_colourfulness++;
	}	
	colourfulness[blockSize1][blockSize2][distance] = _colourfulness;
	return _colourfulness;	
}



inline int getcolourfulness1Block(int blockSize){
	return max(0, blockSize - K);
}




int obtainWays(int distance, int nMidBlocks, int startBlock){
	
	if(distance<0) return 0;	
	if((distance==0) && (nMidBlocks > 0)) return 0;	
	if((distance==0) && (nMidBlocks == 0)) return 1;	
	if((distance>0) && (nMidBlocks == 0)) return 0;
	
	//From now on assume distance>0 & nMidBlocks>0
	if(startBlock == N) return 0;	
	if(ways[distance][nMidBlocks][startBlock] != -1) return ways[distance][nMidBlocks][startBlock];
	
	int ret=0;	
	ret += obtainWays(distance, nMidBlocks, startBlock+1);
		
	if((blocks[startBlock].colour != currColour) && (distance >= blocks[startBlock].size)){	
		ret += obtainWays(distance - blocks[startBlock].size, nMidBlocks-1, startBlock+1);
	}
	
	ways[distance][nMidBlocks][startBlock] = ret;	
//	cout<<"ret for "<<distance<<" , "<<nMidBlocks<<" , "<<startBlock<<" is "<<ret<<endl;
	return ret;
}


int main(){
	
	int T;
	cin>>T;
	while(T-->0){
		cin>>N>>K;		
		
		for(int i=0;i<11;i++)
			for(int j=0;j<11;j++)
				for(int t=0;t<201;t++)
					colourfulness[i][j][t] = -1;
		
	
		for(int i=0;i<N;i++){
			cin>>blocks[i].size>>blocks[i].colour;
		}
		sort(blocks, blocks + N, compareBlocks);
		int currentColour = blocks[0].colour;
		int currentIndex = 0;
		long double answer = 0;
		while(currentIndex < N){
			
			if((currentIndex == N-1) || (blocks[currentIndex+1].colour != currentColour)){
				currentIndex++;
				currentColour = blocks[currentIndex].colour;
				continue;
			}
			
			for(int i=0;i<201;i++)
				for(int j=0;j<21;j++)
					for(int t=0;t<21;t++)
						ways[i][j][t] = -1;
			
			currColour = currentColour;			
			for(int distance=0; distance<201; distance++){
				for(int nMidBlocks=0; nMidBlocks<=N-2; nMidBlocks++){ //2 blocks have already been used.
					answer  += 	2 * 
								multiplyWithoutOverflow(obtainWays(distance, nMidBlocks, 0), 
								getcolourfulness(blocks[currentIndex].size, blocks[currentIndex+1].size, distance),	
							    nMidBlocks, N-(nMidBlocks+1), N);							  
				}
			}			
			currentIndex += 2;
			currentColour = blocks[currentIndex].colour;
		}

//add values within a block		
		for(int i=0;i<N;i++)
			answer += getcolourfulness1Block(blocks[i].size);
		
		cout << fixed;	
		cout << setprecision(18)<< answer << endl;	
	}
	return 0;
}
