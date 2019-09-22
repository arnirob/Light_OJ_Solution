#include<bits/stdc++.h>
#define mx 30009
using namespace std;

struct info
{
	int data, pos;
}tree[mx*4];

int arr[mx],n;

void mk_tree(int curr, int bg, int ed)
{
	if(bg==ed)
	{
		tree[curr].data = arr[bg];
		tree[curr].pos = bg;
		return;
	}
	int left = 2*curr;
	int right = (2*curr)+1;
	int mid = (bg+ed)/2;
	mk_tree(left,bg,mid);
	mk_tree(right,mid+1,ed);
	tree[curr].data = min(tree[left].data,tree[right].data);
	tree[left].data > tree[right].data ? tree[curr].pos = tree[right].pos : tree[curr].pos = tree[left].pos;
}

info query(int curr, int bg, int ed, int i, int j)
{
	if(i>ed || j<bg){
		info xyx;
		xyx.pos = 0, xyx.data = INT_MAX;
		return xyx;
	}
	if(i<=bg && j>=ed) return tree[curr];
	int left = 2*curr;
	int right = (2*curr)+1;
	int mid = (bg+ed)/2;
	
	info q1 = query(left,bg,mid,i,j);
	info q2 = query(right,mid+1,ed,i,j);
	
	if(q1.data <= q2.data) return q1;
	else return q2;
}

int maxi(int bg, int ed)
{
	if( bg >= ed ) return arr[bg];	 
	info qr = query(1,1,n,bg,ed);
	int idx = qr.pos;
	int val = qr.data;
	int resp = (ed-bg)+1;
	return max( arr[idx]*resp, max(maxi(bg,idx-1), maxi(idx+1,ed)));
}

int main()
{	
	// #ifndef ONLINE_JUDGE
	// 	freopen("in.txt","rt",stdin);
	// 	freopen("out.txt","wt",stdout);
	// #endif

	int tc,w=0;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",arr+i);
		mk_tree(1,1,n);
		printf("Case %d: %d\n",++w, maxi(1,n));
	}
	return 0;
}