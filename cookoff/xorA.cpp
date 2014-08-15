#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#define ll long long int
#define mod 1000000009
using namespace std;
     
ll a[100010];
     
ll s[100010];
     
     
int main() {
    // freopen("C:\\Users\\jack\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\jack\\Desktop\\out.txt","w",stdout);
    int test;
    scanf("%d",&test);
    while(test--)
    {
     
		int n;
		scanf("%d",&n);
		s[0]=0;
		for(int i=1;i<=n;i++){	
		  scanf("%lld",&a[i]);s[i]=a[i]^s[i-1];
		}

		ll pos=1,ans=0,one=0;
		

		for(int i=0;i<32;i++){
			one=0;
			for(int j=1;j<=n;j++)
				if(s[j]&pos)one++;
			ans+=(one*(n-one)+one)*pos;
			pos<<=1;
		}
     
    printf("%lld\n",ans);
     
    }
     
}
