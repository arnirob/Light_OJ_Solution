#include<bits/stdc++.h>
using namespace std;
int main()
{
    int csNo=0,ks,sz,cunt;
    scanf("%d",&ks);
    while(ks--)
    {
        scanf("%d %d",&sz,&cunt);
        int arr[sz+4];
        for(int i=0; i<sz; i++)
            scanf("%d",arr+i);

        while(cunt--)
        {
//            getchar();
            char ch;
            scanf("\n%c",&ch);
            if(ch=='S')
            {
                int d;
                scanf("%d",&d);
                for(int i=0;i<sz;i++)
                    arr[i]+=d;
            }
            else if(ch=='M')
            {
                int d;
                scanf("%d",&d);
                for(int i=0;i<sz;i++)
                    arr[i]*=d;
            }
            else if(ch=='D')
            {
                int k;
                scanf("%d",&k);
                for(int i=0;i<sz;i++)
                    arr[i]/=k;
            }
            else if(ch=='R')
            {
                int x=sz-1;
                for(int i=0; i<sz/2; i++)
                {
                    int temp=arr[i];
                    arr[i]=arr[x];
                    arr[x]=temp;
                    x--;
                }
            }
            else if(ch=='P')
            {
                int y,z;
                scanf("%d %d",&y,&z);
                swap(arr[y],arr[z]);
            }
        }
        printf("Case %d:\n",++csNo);
        for(int i=0; i<sz; i++)
        {
            if(i==sz-1)
                printf("%d\n",arr[i]);
            else
                printf("%d ",arr[i]);
        }
    }
    return 0;
}
