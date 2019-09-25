#include<bits/stdc++.h>
#define Max 600000
using namespace std;

struct node
{
    int mx,mn;

}tree[Max*4];

int arr[Max];

void mk_tree(int curr, int bg, int ed)
{
    if(bg==ed)
    {
        tree[curr].mx = arr[bg];
        tree[curr].mn = arr[bg];
        return;
    }
    int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1;    
    mk_tree(left,bg,mid);
    mk_tree(right,mid+1,ed);

    tree[curr].mx = max(tree[left].mx,tree[right].mx);
    tree[curr].mn = min(tree[left].mn,tree[right].mn);
}

node query(int curr, int bg, int ed, int i, int j)
{    
    if(i>ed || j<bg)
    {
        node outer_point;
        outer_point.mx = 0;
        outer_point.mn = INT_MAX;
        return outer_point;
    }
    if(i<=bg && j>=ed) return tree[curr];

    int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1;
    node q1 = query(left,bg,mid,i,j);
    node q2 = query(right,mid+1,ed,i,j);

    node newNode;
    newNode.mx = max(q1.mx, q2.mx);
    newNode.mn = min(q1.mn, q2.mn);

    return newNode;
}

void clr( int n ){
    for( int i=0; i<=n; i++ )
        arr[i] = 0;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt","rt",stdin);
    //     freopen("out.txt","wt",stdout);
    // #endif

    int ts;
    scanf("%d",&ts);
    for(int ks=1; ks<=ts; ks++)
    {       
        int n,d;
        scanf("%d %d",&n, &d);
        for(int i=1; i<=n; i++) scanf("%d",arr+i);
        mk_tree(1,1,n);

        int boro_ta = INT_MIN;
        for(int i=1; (i+d-1)<=n; i++)
        {
            node mxi = query(1,1,n,i,(i+d-1));                     
            boro_ta = max(boro_ta,mxi.mx-mxi.mn);        
        }
        
        printf("Case %d: %d\n",ks,boro_ta);
        clr(n);
    }
    return 0;
}