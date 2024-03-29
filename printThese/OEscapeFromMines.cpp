#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
 
#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int,int >
#define REP(i,a,n) for(i=a;i<n;i++)
#define sc scanf
#define pt printf
#define big long long
#define VI vector <int>
 
using namespace std;
 
const int NMAX=100005;
 
struct node
{
int X,Y,YY,check,ind;
};
 
bool cmp(node P,node Q)
{
return P.X<Q.X;
}
 
struct Tree
{
int l,r,sum,num,look;
};
 
int ans[NMAX];
Tree g[8*NMAX];
int N,raod,len,i,j,xx1,xx2,yy1,yy2;
node A[4*NMAX];
int ord[NMAX*4];
map <int,int> M;
 
void build(int a,int b,int u)
{
g[u]=(Tree){a,b,0,0,0};
if (a==b) return;
int mid=(a+b)>>1;
build(a,mid,2*u);
build(mid+1,b,2*u+1);
}
 
void decrease(int pos,int u)
{
int left=g[u].l;
int right=g[u].r;
 
if (pos<left || pos>right) return;
if (left==right)
{
g[u].sum=0;
return;
}
decrease(pos,2*u);
decrease(pos,2*u+1);
g[u].sum=g[2*u].sum+g[2*u+1].sum;
}
 
int getsum(int a,int b,int u)
{
int left=g[u].l;
int right=g[u].r;
 
if (a>b) return 0;
if (a>right || left>b) return 0;
if (a<=left && right<=b) return g[u].sum;
 
return getsum(a,b,2*u)+getsum(a,b,2*u+1);
}
 
void update(int pos,int number,int which,int u)
{
int left=g[u].l;
int right=g[u].r;
 
if (left>pos || pos>right) return;
if (left==right)
{
g[u].sum=1;
g[u].num=number;
g[u].look=which;
return;
}
update(pos,number,which,2*u);
update(pos,number,which,2*u+1);
g[u].sum=g[2*u].sum+g[2*u+1].sum;
}
 
 
void go(int pos,int u)
{
int left=g[u].l;
int right=g[u].r;
 
if (left>pos || right<pos) return;
 
if (left==right)
{
if (g[u].look==1)
ans[A[i].ind]=ans[g[u].num]; else
ans[A[i].ind]=g[u].num;
return;
}
 
if (g[2*u+1].l<=pos && getsum(g[2*u+1].l,pos,1)>0)
go(pos,2*u+1); else
if (g[2*u].r<=pos)
go(g[2*u].r,2*u); else
go(pos,2*u);
}
 
main()
{
// freopen("text.in","r",stdin); freopen("text.out","w",stdout);
 
scanf("%d",&N);
for (i=0;i<N;i++)
{
scanf("%d %d %d %d",&xx1,&yy1,&xx2,&yy2);
A[len++]=(node){xx1,yy1,yy2,1,i};
A[len++]=(node){xx2,yy1,yy2,0,i};
if (!M[yy1])
{
ord[raod++]=yy1;
M[yy1]=1;
}
if (!M[yy2])
{
ord[raod++]=yy2;
M[yy2]=1;
}
}
 
sort(A,A+len,cmp);
 
sort(ord,ord+raod);
 
for (i=0;i<raod;i++)
M[ord[i]]=i+1;
 
build(1,raod,1);
 
for (i=0;i<len;i++){
A[i].Y=M[A[i].Y];
A[i].YY=M[A[i].YY];
}
 
for (i=0;i<len;i++)
if (!A[i].check)
{
decrease(A[i].Y,1);
decrease(A[i].YY,1);
}else
{
// cout<<1<<"-"<<A[i].Y-1<<"="<<getsum(1,A[i].Y-1,1)<<endl;
 
if (getsum(1,A[i].Y-1,1)==0)
{
// cout<<"upd "<<A[i].Y<<" "<<A[i].YY<<endl;
 
update(A[i].Y,A[i].ind,0,1);
update(A[i].YY,A[i].ind,1,1);
 
ans[A[i].ind]=-1;
 
continue;
}
 
//count the ans
 
go(A[i].Y-1,1);
 
// cout<<"upd "<<A[i].Y<<" "<<A[i].YY<<endl;
 
update(A[i].Y,A[i].ind,0,1);
update(A[i].YY,A[i].ind,1,1);
}
 
for (i=0;i<N;i++)
printf("%d\n",ans[i]);
}
