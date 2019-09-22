#include<bits/stdc++.h>
#define mx 100009
using namespace std;

struct info
{
	long long prop,sum;
}tree[mx*4];

void update(int curr, int bg, int ed, int i, int j, int val)
{
	if(i>ed || j<bg) return;
	if(bg>=i && ed<=j)
	{
		tree[curr].sum += ((ed-bg+1)*val);
		tree[curr].prop += val;
		return;
	}
	int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1 ;
	update(left,bg,mid,i,j,val);
	update(right,mid+1,ed,i,j,val);
	tree[curr].sum = tree[left].sum+tree[right].sum+(ed-bg+1)*tree[curr].prop;
}

long long query(int curr, int bg, int ed, int i, int j, long long crry)
{ 
	if(i>ed || j<bg) return 0;
	if(bg>=i && ed<=j)
		return tree[curr].sum+(crry*(ed-bg+1));

	int left = curr<<1, right = (curr<<1)+1, mid = (bg+ed)>>1 ;
	long long q1 = query(left,bg,mid,i,j,crry+tree[curr].prop);
	long long q2 = query(right,mid+1,ed,i,j,crry+tree[curr].prop);
	return q1+q2;
}

int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("in.txt","rt",stdin);
	// 	freopen("out.txt","wt",stdout);
	// #endif	

	int ks,tc=0;
	scanf("%d",&ks);
	while(ks--)
	{		
		int n,q;
		scanf("%d %d",&n, &q);
		printf("Case %d:\n", ++tc);
		while(q--)
		{
			int f, x, y, v;
			scanf("%d",&f);
			if(f)
			{
				scanf("%d %d",&x, &y);
				printf("%lld\n", query(1,1,n,x+1,y+1,0));
			}
			else
			{
				scanf("%d %d %d", &x, &y, &v);
				update(1,1,n,x+1,y+1,v);
			}

		}		
		for(int i=0; i<=n*4; i++)
		{
			tree[i].sum = 0;
			tree[i].prop = 0;
		}
	}
	return 0;
}