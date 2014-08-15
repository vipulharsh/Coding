#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
using namespace std;

#define readint(n) scanf("%d",&n)
#define readull(n) scanf("%llu",&n)
#define readll(n) scanf("%lld",&n)
#define readf(n) scanf("%f",&n)
#define readlf(n) scanf("%lf",&n)
#define init(mem) memset(mem,0,sizeof(mem))
#define ull unsigned long long int
#define ll long long int
#define setmax(a,b) a=max(a,b)
#define setmin(a,b) a=min(a,b)


#define ld long double
#define poly vector<ld>

poly mult(poly& p1,poly& p2){
	poly ret(p1.size()+p2.size()-1,0);
	for(int i=0;i<p1.size();i++){
		for(int j=0;j<p2.size();j++){
			ret[i+j]+=p1[i]*p2[j];
		}
	}
	return ret;
}

poly add(poly p1,poly p2){
	if(p1.size()>=p2.size()){
		for(int i=0;i<p2.size();i++){
			p1[i]+=p2[i];
		}
		return p1;
	}
	else{
		for(int i=0;i<p1.size();i++){
			p2[i]+=p1[i];
		}
		return p2;
	}
}

poly subt(poly p1,poly p2){
	if(p1.size()>=p2.size()){
		for(int i=0;i<p2.size();i++){
			p1[i]-=p2[i];
		}
		return p1;
	}
	else{
		for(int i=0;i<p1.size();i++){
			p2[i]=p1[i]-p2[i];
		}
		for(int i=p1.size();i<p2.size();i++){
			p2[i]=-p2[i];
		}

		return p2;
	}
}

void printpoly(poly p){
	for(int i=0;i<p.size();i++){
		cout<<" + "<<p[i]<<"x^"<<i;
	}
	cout<<endl;
}

poly X;
int ptr;
char* str;

poly solve(){
	if(str[ptr]=='\0') assert(false);
	if(str[ptr]=='m'){
		ptr++;
		poly left=solve();
		poly right=solve();
		return mult(left,right);
	}
	else if(str[ptr]=='M'){
		ptr++;
		poly left=solve();
		poly right=solve();
		return subt(add(left,right),mult(left,right));
	}
	else{
		ptr++;
		return X;
	}
}

ld integrate(poly p){
	ld res=0;
	for(int i=0;i<p.size();i++){
		res+=(p[i]/(i+1));
	}
	return res;
}

int main(){
	X.push_back(0);
	X.push_back(1);

	str=new char[101];
	int t;

	readint(t);
	while(t--){
		scanf("%s",str);
		ptr=0;
		poly res=solve();
		printpoly(res);
		printf("%.19Lf\n",integrate(res));
	}
	return 0;
}
