#include<stdio.h>
#include<math.h>
int main()
{
    int x,i,a,b,c,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(c>a&&c>b)
        {
        x=sqrt(pow(a,2)+pow(b,2));
        if(c==x) printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);
        }
        if(c<a&&a>b)
        {
        x=sqrt(pow(c,2)+pow(b,2));
        if(a==x) printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);
        }
        if(c<b&&a<b)
        {
        x=sqrt(pow(a,2)+pow(c,2));
        if(b==x) printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);
        }
    }
    return 0;
}

