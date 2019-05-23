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
    tree[curr] = tree[left]+tree[right];
}
int ttl;
void update1(int curr, int bg, int ed, int pos)
{
    if(pos>ed || pos<bg) return;
    if (bg>=pos && ed<=pos)
    {
        ttl = tree[curr];
        tree[curr] = 0;
        return;
    }
    int left = 2*curr;
    int right = (2*curr)+1;
    int mid = (bg+ed)/2;
    update1(left,bg,mid,pos);
    update1(right,mid+1,ed,pos);
    tree[curr] = tree[left]+tree[right];
}

void update2(int curr, int bg, int ed, int pos, int val)
{
    if(pos>ed || pos<bg) return;
    if (bg>=pos && ed<=pos)
    {
        tree[curr] += val;
        return;
    }
    int left = 2*curr;
    int right = (2*curr)+1;
    int mid = (bg+ed)/2;
    update2(left,bg,mid,pos,val);
    update2(right,mid+1,ed,pos,val);
    tree[curr] = tree[left]+tree[right];
}

int qurey(int curr, int bg, int ed, int i, int j)
{
    if(i>ed || j<bg) return 0;
    if (bg>=i && ed<=j) return tree[curr];
    int left = 2*curr;
    int right = (2*curr)+1;
    int mid = (bg+ed)/2;
    int q1 = qurey(left,bg,mid,i,j);
    int q2 = qurey(right,mid+1,ed,i,j);
    return q1+q2;
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
            int st,i,j;
            scanf("%d",&st);
            if(st == 1)
            {
                scanf("%d",&i);
                update1(1,1,n,i+1);
                printf("%d\n",ttl);
            }
            else if(st == 2)
            {
                scanf("%d %d",&i, &j);
                update2(1,1,n,i+1,j);
            }
            else
            {
                scanf("%d %d",&i, &j);
                printf("%d\n",qurey(1,1,n,i+1,j+1));
            }
        }
        for(int i=0; i<=n; i++)
            arr[i]=0;
        for(int i=0; i<=n*3; i++)
            tree[i]=0;
    }
    return 0;
}
