#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>


#define INFI 1000000000

using namespace std;

int N,M;

class mycomparison
{
public:
 bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const
  {
		return (lhs.second>rhs.second);
  }
};


int main(){
	
	vector<int> edges[100001];
	vector<int> redges[100001];
	
	set<pair<int, int> > checkDuplicateEdges;
	int visited[100001];
	int cost[100001];
	
	scanf("%d", &N);
	scanf("%d", &M);

	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d", &a);
		scanf("%d", &b);
		a--;
		b--;
		if(a!=b && (checkDuplicateEdges.find(pair<int, int>(a,b)) == checkDuplicateEdges.end())){
			edges[a].push_back(b);
			redges[b].push_back(a);
			checkDuplicateEdges.insert(pair<int , int>(a, b));
		}
	}
	
	for(int i=0;i<N;i++){
		visited[i] = 0;
		cost[i] = INFI;
	}
	
	priority_queue <pair<int, int>, vector<pair<int, int> >, mycomparison> nodes;
	nodes.push(pair<int, int>(0, 0));
	while(!nodes.empty()){		
		pair<int, int> p = nodes.top();
		int i = p.first;
		
		nodes.pop();
		
		if(visited[i] == 1) continue;		
		
		cost[i] = p.second;
		visited[i] = 1;
		
		for(vector<int> :: iterator it = edges[i].begin(); it != edges[i].end(); it++){
			if(visited[*it] == 0)
				nodes.push(pair<int, int>(*it, cost[i]));
		}
		for(vector<int> :: iterator it = redges[i].begin(); it != redges[i].end(); it++){
			if(visited[*it] == 0)
				nodes.push(pair<int, int>(*it, cost[i]+1));
		}
	}
	
	
	if(cost[N-1] == INFI)
		printf("-1\n");
	else	
		printf("%d\n", cost[N-1]);
	
	return 0;
}
