#include <iostream>
#include <map>
#include <cassert>

using namespace std;

map<pair<int,int>, int> increments;


int getval(int i, int j){
	
	map<pair<int,int>,int>::iterator it;
	it = increments.find(pair<int, int>(i, j));
	if(it == increments.end())
		return j;
	else return (*it).second + j;
}


int main(){
	
	map<pair<int,int>,int>::iterator it;
	
	
	int n,m,p;
	cin>>n>>m>>p;
	
	
	int hurdles[100001];
	for(int i=1;i<=n;i++){
		hurdles[i] = 0;
	}	
		
	for(int k=0;k<p;k++){
		int i,j;
		cin>>i>>j;
		pair<int, int> pairij;
		pairij.first = i;
		pairij.second = j;
		it=increments.find(pairij);
		if(it == increments.end()){
			increments.insert(pair<pair<int, int>, int>(pairij, 1));
		}
		else{
			increments[pairij] = (*it).second + 1;
			
		}
		
		//Now update hurdles
		if(j>1){  //check if hurdles to be decreased
			int a1 = getval(i, j-1);
			int a2 = getval(i, j);
			if(a2 == a1){
				assert(hurdles[i]);
				hurdles[i]--;
			}
		}
		
		if(j<m){ //check if hurdles to be increased
			int a1 = getval(i, j);
			int a2 = getval(i, j+1);
			if(a1 == (a2 + 1)){
				hurdles[i]++;
			}
		}
	}
	
	
	for (int i=1;i<=n;i++){
		if(hurdles[i] != 0) cout<<"-1"<<endl;
		else cout<<getval(i,m) - getval(i,1)<<endl;
	}
	return 0;

}
