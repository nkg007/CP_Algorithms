#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=100005;
int arr[N];
int n;

struct node
{
	int sum;
	node()
	{
		sum=0;
	}
	node(int a)
	{
		sum=a;
	}
	void combine(node lf,node rt)
	{
		this->sum=lf.sum+rt.sum;
	}
};


struct node s[N<<2];
struct node lazy[N<<2];

void init()
{
	for(int i=1;i<(4*n);i++)
	lazy[i]=node();
}

void build(int id,int l,int r)
{
	if(l+1==r)
	{
		s[id]=node(arr[l]);
		return ;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid,r);
	s[id]=node();
	s[id].combine(s[id<<1],s[id<<1|1]);
}

void upd(int id,int l,int r,int x)
{
	lazy[id].sum+=x;
	s[id].sum+=(r-l)*x;
}

void shift(int id,int l,int r)
{
	int mid=(l+r)/2;
	upd(id<<1,l,mid,lazy[id].sum);
	upd(id<<1|1,mid,r,lazy[id].sum);
	lazy[id].sum=0;
}

node query(int id,int l,int r,int x,int y)
{
	cout<<"here 1"<<endl;
	if(x>=r || l>=y)
	return node();
	if(l>=x && y>=r)
	return s[id];
	shift(id,l,r);
	int mid=(l+r)/2;
	node lchild=query(id<<1,l,mid,x,y);
	node rchild=query(id<<1|1,mid,r,x,y);
	node parent=node();
	parent.combine(lchild,rchild);
	return parent;
}

void modify(int id,int l,int r,int x,int y,int val)
{
	cout<<"here 4"<<endl;
	if(x>=r || l>=y)
	return;
	if(l>=x && y>=r)
	{
		upd(id,l,r,val);
		return;
		
	}
	shift(id,l,r);
	int mid=(l+r)/2;
	modify(id<<1,l,mid,x,y,val);
	modify(id<<1|1,mid,r,x,y,val);
	s[id].combine(s[id<<1],s[id<<1|1]);
}






int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	init();
	build(1,0,n);
	for(int i=1;i<4*n;i++)
	cout<<s[i].sum<<" ";
	cout<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int choice ,l,r,x;
		cin>>choice;
		if(choice==1)
		{
			cin>>l>>r;
			node ans=query(1,0,n,l,r);
			cout<<ans.sum<<"\n";
		}
		if(choice ==2)
		{
			cin>>l>>r>>x;
			modify(1,0,n,l,r,x);
		}
		for(int i=1;i<4*n;i++)
	cout<<s[i].sum<<" ";
	}
}
