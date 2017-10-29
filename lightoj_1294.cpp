#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=0;
    scanf("%d",&t);
    while(t--)
    {
        ks++;
        long m,n;
        scanf("%ld %ld",&m,&n);
        int s=(m*n)/2;
        printf("Case %d: %ld\n",ks,s);
    }
    return 0;
}

