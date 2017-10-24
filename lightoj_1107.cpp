#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,kase=0;
    scanf("%d",&t);
    while(t--)
    {
        kase++;
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("Case %d:\n",kase);
        int fuck;
        scanf("%d",&fuck);
        while(fuck--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
