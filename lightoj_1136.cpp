#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=0;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int mx=0,x=0,y=0,rem1=0,rem2=0;
        x=(a/3)*2;
        rem1=a%3;
        y=(b/3)*2;
        rem2=b%3;
        if(rem2==2) y+=1;
        mx=y-x;
        if(rem1==0) mx+=1;
        printf("Case %d: %d\n",++ks,mx);
    }
    return 0;
}
