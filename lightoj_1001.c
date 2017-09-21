#include<stdio.h>
int main()
{
    int t,x,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&x);
        if(x>10) printf("%d %d\n",x-10,x-(x-10));
        else printf("%d %d\n",x-x,x);
    }
    return 0;
}

