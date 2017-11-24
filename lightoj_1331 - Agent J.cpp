#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ks;
    double R1,R2,R3;
    scanf("%d",&ks);
    for(int t=1; t<=ks; t++)
    {
        scanf("%lf %lf %lf",&R1,&R2,&R3);
        double a=R1+R2;
        double b=R2+R3;
        double c=R3+R1;
        double S=(a+b+c)/2;
        double triangle_area=sqrt(S*(S-a)*(S-b)*(S-c));
        double alfa = acos((a * a + c * c - b * b) / (2.0 * a * c));
        double beta = acos((a * a + b * b - c * c) / (2.0 * a * b));
        double gamma = acos((c * c + b * b - a * a) / (2.0 * b * c));
        double area1=0.5*alfa*R1*R1;
        double area2=0.5*beta*R2*R2;
        double area3=0.5*gamma*R3*R3;
        double circle_area=area1+area2+area3;
        double area=triangle_area-circle_area;
        printf("Case %d: %.9lf\n",t,area);
    }
    return 0;
}
