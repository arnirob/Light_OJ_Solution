#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ks;
    double r1,r2,h,p;
    scanf("%d",&ks);
    for(int i=1;i<=ks;i++)
    {
        scanf (" %lf %lf %lf %lf", &r1, &r2, &h, &p);
        double R= r2 +(r1-r2)*(p/h);
        double v = (M_PI*p*( R*R+r2*r2+R*r2))/3.0;
        printf("Case %d: %lf\n",i,v);
    }
    return 0;
}
