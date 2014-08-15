#include <iostream>
#include <vector>
using namespace std;

#define MODBASE 1000000007

bool checked[100001];
int A[100001];


int gcd(int x, int y){
	
	if(y > x) return gcd(y, x);
	return ((y==0)? x : gcd(y, x%y));
}




int main(){
	
	int T;
	int N;
	cin>>T;
	while(T-->0){
		cin>>N;
		vector<int> permGroups;
		for(int i=0;i<N;i++){
			cin>>A[i];
			A[i]--; //0 indexed
			checked[i] = false;
		}
		
		int checkIndex = 0;
		while(checkIndex < N){
			
			if(checked[checkIndex]) {
				checkIndex++;
				continue;
			}			
			int i = checkIndex;
			int length = 0;			
			while(!checked[i]){
				length++;
				checked[i] = true;
				i = A[i];
			}
			
			if(length > 1)
				permGroups.push_back(length);
			checkIndex++;
		}
		
		int ret = 1;
		while(!permGroups.empty()){
			
			int l = permGroups.size();
			int longestPerm = -1;
			for(int i=0; i<l; i++)
				longestPerm = max(longestPerm, permGroups[i]);			
			ret = ((long long) ret * longestPerm) % MODBASE;
			
			vector<int> temp;
			for(int i=0;i<l;i++){
				int rem = longestPerm % permGroups[i];
				if(rem != 0){
					int g = gcd(rem, permGroups[i]);
					if(permGroups[i]/g != 1)
						temp.push_back(permGroups[i]/g);
					 
				}
			}
			permGroups.clear();
			permGroups = temp;
		}
		cout<<ret<<endl;
	}
	return 0;
}
