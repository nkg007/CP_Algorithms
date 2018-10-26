
const int N=100005;
vector<long long>arr;
struct node
{
    long long count;
    node()
    {
        count=0;
    }
    node(int a)
    {
        this->count=a;
    }
    void combine(node lf,node rt)
    {
        this->count=(lf.count+rt.count)%10000000007;
    }
}s[4*N];
void build(int id,int l,int r)
{
    if(l+1==r)
    {
        s[id]=node(arr[l]);
        return;
    }
    long long mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid,r);
    s[id]=node();
    s[id].combine(s[2*id],s[2*id+1]);
}
long long check(long long value)
{
    int counter=sqrt(value);
    if((counter*counter)==value)
    {
        return 0;
    }
    long long tt=counter+1;
    long long aa=value-((long long)counter*counter);
    long long bb=(tt*tt)-value;
    return min(aa,bb);
    
}
void modify(long long x,long long value,long long id,long long l,long long r)
{
  if(l+1==r)
  {
      arr[l]=check(value);
      s[id]=arr[l];
      return;
  }
  long long mid=(l+r)/2;
  if(x<mid)
  modify(x,value,2*id,l,mid);
  else
  modify(x,value,2*id+1,mid,r);
  s[id]=node();
  s[id].combine(s[2*id],s[2*id+1]);
}
node query(int x,int y,int id,int l,int r)
{
    if(l>=y  || x>=r)
    return node();
    else if(l>=x && y>=r)
    {
        //cout<<"id "<<id<<" "<<s[id].count<<endl;
    return s[id];
    }
    int mid=(l+r)/2;
    node lnode=query(x,y,2*id,l,mid);
    node rnode=query(x,y,2*id+1,mid,r);
    node parent =node();
    parent.combine(lnode,rnode);
    return parent;
}
/*void display(){
for(int i=1;i<4*n;i++)
cout<<s[i].count<<" ";}*/
int Solution::solve(vector<int> &A, vector<vector<int> > &B)
{
    long long int  tot_ans=0;
     int n=A.size();
     arr.clear();
     //cout<<" n"<<n<<endl;
     for(int i=0;i<n;i++)
     {
         arr.push_back(A[i]);
     }
     for(int i=0;i<n;i++)
     {
         arr[i]=check(arr[i]);
     }
     build(1,0,n);
    // display();
    // cout<<"ansns"<<endl;
     int sz=B.size();
    // cout<<"sz "<<sz<<endl;
     for(int i=0;i<sz;i++)
     {
             long long ind=B[i][0];
             long long l=B[i][1];
             long long r=B[i][2];
            /* cout<<ind<<" ind "<<endl;
             cout<<l<<" l "<<endl;
             cout<<r<<" r "<<endl;*/
             if(ind==1)
             {
                 l--;
                 modify(l,r,1,0,n);
             }
             else
             {
                 l--;
                 node ans=query(l,r,1,0,n);
                 long long an=ans.count;
                // cout<<" ans is "<<an<<endl;
                 tot_ans=(tot_ans+an)%1000000007;
             }
     }
     return (int)tot_ans;
     
    
    
}
