#include<stdio.h>
#define getcx getchar_unlocked
inline void inp( int &n )
{
n=0;
int ch=getcx();
while( ch < '0' || ch > '9' ){ ch=getcx();}
 
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}
int main()
{
int t,n,x,y,c[1000004],fl,i,m;
inp(t);
while(t--)
{fl=0;
//scanf("%d%d",&n,&m);
inp(n);inp(m);
for(i=0;i<=n;i++)
c[i]=0;
for(i=0;i<m;i++)
{
//scanf("%d%d",&x,&y);
inp(x);inp(y);
{c[x]++;c[y]--;}
}
if(c[n]==0)
{printf("2 %d\n",n);continue;}
for(i=1;i<=n;i++)
if(c[i]==(n-i))
{fl=i;break;}
if(fl!=0)
{printf("2 %d\n",fl);continue;}
printf("1\n");
}
return(0);
}
