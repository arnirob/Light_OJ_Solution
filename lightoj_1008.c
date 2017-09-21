#include<stdio.h>
#include<math.h>
int main()
{
    long long int x,n,a,y,clm,rw;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    scanf("%lld",&a);
    n=ceil(sqrt(a));
    y=pow((n-1),2);
    x=abs(y-a);
    if(n&1)
    {
        if(x<n)
        {
            clm=n;
            rw=x;
            printf("Case %d: %lld %lld\n",i,clm,rw);
        }
        else
        {
            clm=(n*n)-a+1;
            rw=n;
            printf("Case %d: %lld %lld\n",i,clm,rw);
        }
    }
    else
    {
        if(x>n)
        {
            rw=(n*n)-a+1;
            clm=n;
            printf("Case %d: %lld %lld\n",i,clm,rw);
        }
        else
        {
            clm=a-pow((n-1),2);
            rw=n;
            printf("Case %d: %lld %lld\n",i,clm,rw);
        }
    }
    }

    return 0;
}

