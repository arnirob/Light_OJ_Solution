#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int v;
char str[mx];
struct info
{
	int val,prop;
} tree[mx*4];

void mk_tree(int curr, int bg, int ed)
{
	if(bg==ed)
	{
		tree[curr].val = str[bg-1]-'0';
		return;
	}
	int left = 2*curr;
	int right = (2*curr)+1;
	int mid = (bg+ed)/2;
	mk_tree(left,bg,mid);
	mk_tree(right,mid+1,ed);
}

void update(int curr, int bg, int ed, int i, int j)
{
	if(i>ed || j<bg) return;
	if(bg>=i && ed<=j)
	{
		tree[curr].prop += 1;
		return;
	}
	int left = 2*curr;
	int right = (2*curr)+1;
	int mid = (bg+ed)/2;
	update(left,bg,mid,i,j);
	update(right,mid+1,ed,i,j);
}

int query(int curr, int bg, int ed, int pos, int carry)
{
	if(pos>ed || pos<bg) return 0;
	if(pos<=bg && pos>=ed)
	{
		v = tree[curr].val;
		return tree[curr].prop+carry;
	}
	int left = 2*curr;
	int right = (2*curr)+1;
	int mid = (bg+ed)/2;
	int q1 = query(left,bg,mid,pos,carry+tree[curr].prop);
	int q2 = query(right,mid+1,ed,pos,carry+tree[curr].prop);
	return q1+q2;
}

int main()
{
	int ks;
	scanf("%d",&ks);	
	for(int i=1; i<=ks; i++)
	{		
		printf("Case %d:\n", i);
		scanf("%s",str);
		int n = strlen(str);
		mk_tree(1,1,n);
		int qur;		
		scanf("%d",&qur);
		for(int f=1; f<=qur; f++)
		{
			char ch[5];		
			scanf("%s",ch);			
			if(ch[0] == 'I')
			{
				int x,y;
				scanf("%d %d",&x, &y);
				update(1,1,n,x,y);
			}
			else
			{
				int x;
				scanf("%d",&x);			
				if(query(1,1,n,x,0)&1) printf("%d\n", v^1);				
				else printf("%d\n", v);				
			}
		}
		for(int d=0; d<=n; d++)
			str[d] = '\0';

		for(int d=0; d<(n*4); d++)
		{
			tree[d].val = 0;
			tree[d].prop = 0;
		}
	}
	return 0;
}