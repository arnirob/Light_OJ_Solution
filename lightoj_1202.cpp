#include<bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    scanf("%ld",&t);
    int ks=0;
    while(t--)
    {
        ks++;
        long r1,c1,r2,c2;
        int n1=r1>r2? r1: r2;
        int n2=c1>c2? c1: c2;
        int n=n1+n2;
        scanf("%ld %ld %ld %ld",&r1,&c1,&r2,&c2);
        if(((r1+c1)==(r2+c2)) || ((n+r1-c1)==(n+r2-c2)))  printf("Case %d: 1\n",ks);
        else if(((r1+c1)&1 && (r2+c2)%2==0) || ((r1+c1)%2==0 && (r2+c2)&1)) printf("Case %d: impossible\n",ks);
        else printf("Case %d: 2\n",ks);
    }
    return 0;
}

