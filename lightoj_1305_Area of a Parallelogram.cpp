#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,area;
    int ks;
    scanf("%d",&ks);
    for(int i=1; i<=ks; i++)
    {
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        area = (ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
        dx=ax+cx-bx;
        dy=ay+cy-by;
        printf("Case %d: %d %d %d\n",i,dx,dy,abs(area));
    }
    return 0;
}
