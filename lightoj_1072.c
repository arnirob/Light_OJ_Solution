#include<stdio.h>
#define pi acos(-1.0)
int main()
{
    int n,i,t;
    double R;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %d",&R,&n);
        printf("Case %d: %.10lf\n",i,((R*sin(pi/n))/(1.0+sin(pi/n))));
    }
    return 0;
}
