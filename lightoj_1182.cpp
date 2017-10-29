#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ks=0;
    scanf("%d",&t);
    while(t--)
    {
        ks++;
        int c=0,num,x;
        scanf("%d",&num);
        x=num;
        while(x!=0)
        {
            if(x%2) c++;
            x=x/2;
        }
        if(c&1) printf("Case %d: odd\n",ks);
        else printf("Case %d: even\n",ks);
    }

    return 0;
}
