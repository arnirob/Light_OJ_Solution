#include<bits/stdc++.h>
using namespace std;
int main()
{
    double v1,v2,v3,a1,a2;
    int ks;
    scanf("%d",&ks);
    for(int t=1;t<=ks;t++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        double s1=(v1*v1)/(2.0*a1);
        double s2=(v2*v2)/(2.0*a2);
        double D=s1+s2;
        double t1=v1/a1;
        double t2=v2/a2;
        double bird=(t1>t2?t1:t2)*v3;
        printf("Case %d: %lf %lf\n",t,D,bird);
    }
    return 0;
}
