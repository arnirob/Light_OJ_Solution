#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ks,cs=0;
    scanf("%d",&ks);
    while(ks--)
    {
        int n,p,q;
        scanf("%d %d %d",&n,&p,&q);
        int arr[n+4];
        for(int i=0; i<n; i++)
            scanf("%d",arr+i);

        sort(arr,arr+n);
        int c=0,gm=0,cunt=0;
        for(int i=0; i<n; i++)
        {
            gm+=arr[i];
            c++;
            if(c<=p && gm<=q) cunt++;
            else break;
        }
        printf("Case %d: %d\n",++cs,cunt);
    }
    return 0;
}
