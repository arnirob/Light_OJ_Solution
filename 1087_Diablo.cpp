#include<bits/stdc++.h>
#define mx 200009
using namespace std;

int arr_trk[mx], arr[mx], tree[mx*4];

void mk_tree(int curr, int bg, int ed)
{
    if(bg==ed)
    {
        tree[curr] = arr_trk[bg];
        return;
    }    
    int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1;  
    mk_tree(left,bg,mid);
    mk_tree(right,mid+1,ed);
    tree[curr] = tree[left]+tree[right];
}

int query(int curr, int bg, int ed, int i, int j)
{
    if(i>ed || j<bg) return 0;
    if(i<=bg && j>=ed) return tree[curr];    
    int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1;
    int q1 = query(left,bg,mid,i,j);
    int q2 = query(right,mid+1,ed,i,j);
    return q1+q2;
}

void update(int curr, int bg, int ed, int pos, int val)
{
    if(pos>ed || pos<bg) return;
    if(pos<=bg && pos>=ed)
    {
        tree[curr] = val;
        return;
    }        
    int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1;
    update(left,bg,mid,pos,val);
    update(right,mid+1,ed,pos,val);
    tree[curr] = tree[left]+tree[right];
}

int main()
{   
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt","rt",stdin);
    //     freopen("out.txt","wt",stdout);
    // #endif

    int ks;
    scanf("%d",&ks);
    for(int tc=1; tc<=ks; tc++)
    {   
        int n, q;
        scanf("%d %d",&n, &q);        
        for(int i=1; i<=n; i++)
        {
            scanf("%d",arr+i);
            arr_trk[i] = 1;
        }
        getchar();
        int ed = n+q;
        mk_tree(1,1,ed);
        printf("Case %d:\n",tc);
        while(q--)
        {
            char ch;   
            ch = getchar();
            if(ch == 'c')
            {
                int pos;
                scanf("%d",&pos); 
                getchar();
                int lw = 1, hi = n, mid, ans = 0;
                for(int i=1; i<=20; i++)
                {
                    mid = (lw+hi)/2;
                    int ttl = query(1,1,ed,1,mid);
                    if(ttl >= pos)
                    {
                        hi = mid-1;
                        ans = mid;
                    }
                    else lw = mid+1;
                }
                if(ans)
                { 
                    printf("%d\n",arr[ans]);
                    update(1,1,ed,ans,0); 
                }
                else printf("none\n");
            }
            else
            {
                int val;
                scanf("%d",&val);
                getchar();
                ++n;
                arr[n] = val;
                update(1,1,ed,n,1);
            }    
        }
        for(int i=0; i<=ed; i++)
        {
            arr[i] = 0;
            arr_trk[i] = 0;        
        }    
    }
    return 0;
}