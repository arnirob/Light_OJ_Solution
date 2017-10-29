#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);
    int t;
    scanf("%d",&t);
    int kase=0;
    while(t--)
    {
        int m,n,x;
        kase++;
        int ans;
        scanf("%d %d",&m,&n);
        int mn=m*n;
        if(m==1 || n==1) ans=mn;
        else if(m==2 || n==2)
        {
            if(m==2) x = n;
            else     x = m;
            if(x%4 == 1)      ans = x+1;
            else if(x%4 == 2) ans = x+2;
            else if(x%4 == 3) ans = x+1;
            else if(x%4 == 0) ans = x;
        }
        else if((m*n)&1) ans=(mn/2)+1;
        else ans=mn/2;

        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
