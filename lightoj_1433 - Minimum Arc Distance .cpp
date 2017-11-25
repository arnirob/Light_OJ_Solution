#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ks;
    double ox,oy,ax,ay,bx,by;
    scanf("%d",&ks);
    for(int t=1;t<=ks;t++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        double OA=sqrt(((ox-ax)*(ox-ax))+((oy-ay)*(oy-ay)));
        double OB=sqrt(((ox-bx)*(ox-bx))+((oy-by)*(oy-by)));
        double AB=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
        double angle=acos((OA*OA + OB*OB - AB*AB)/(2.00*OA*OB))*(180.0/M_PI);
        double arc=2.00*M_PI*OA*(angle/360.0);
        printf("Case %d: %.9lf\n",t,arc);
    }

    return 0;
}
