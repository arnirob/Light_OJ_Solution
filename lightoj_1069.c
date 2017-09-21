#include<stdio.h>
int main()
{
    int a,b,c,x,t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
    if(a>b)
        {
            c=a-b;
            x=(c*4)+19+(a*4);
            printf("Case %d: %d\n",i,x);
        }
    else
        {
            c=b-a;
            x=(c*4)+19+(a*4);
            printf("Case %d: %d\n",i,x);
        }
    }
    return 0;
}
