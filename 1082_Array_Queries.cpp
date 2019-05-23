#include<bits/stdc++.h>
#define mx 100001
using namespace std;

int arr[mx], tree[mx*3];

void mk_tree(int curr, int bg, int ed)
{
    if(bg==ed)
    {
        tree[curr] = arr[bg];
        return;
    }
    int left = 2*curr;
    int right = (2*curr)+1;
    int mid = (bg+ed)/2;
    mk_tree(left,bg,mid);
    mk_tree(right,mid+1,ed);
    tree[curr] = min(tree[left],tree[right]);
}

int qurey(int curr, int bg, int ed, int i, int j)
{
    if(i>ed || j<bg) return arr[i];
    if (bg>=i && ed<=j) return tree[curr];
    int left = 2*curr;
    int right = (2*curr)+1;
    int mid = (bg+ed)/2;
    int q1 = qurey(left,bg,mid,i,j);
    int q2 = qurey(right,mid+1,ed,i,j);
    return min(q1,q2);
}

int main()
{
    int v;
    scanf("%d",&v);
    for(int tc=1; tc<=v; tc++)
    {
        int n,ks;
        scanf("%d %d",&n,&ks);
        arr[n+4], tree[n*3];
        for(int i=1; i<=n; i++)
            scanf("%d",arr+i);
        mk_tree(1,1,n);
        printf("Case %d:\n",tc);
        for(int c=0; c<ks; c++)
        {
            int i, j;
            scanf("%d %d",&i,&j);
            if(i==j) printf("%d\n",arr[i]);
            else printf("%d\n",qurey(1,1,n,i,j));
        }        
        for(int i=0; i<=n; i++)
            arr[i]=0;
        for(int i=0; i<=n*3; i++)
            tree[i]=0;        
    }
    return 0;
}