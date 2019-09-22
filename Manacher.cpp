#include<bits/stdc++.h>
using namespace std;

void buildmanacherodd(string &str)
{
	int n=str.size();
	vector<int>oddlength(n);
	int l=0 ,r=-1;
	for(int i=0;i<n;i++)
	{
		int k=(i>r)?1:min(oddlength[l+r-i],r-i+1);  // Here if i>r we apply normal brute force but if less we know that a mirror image exist of i at just othher side of current center
		while(i-k>=0 && i+k<n && str[i-k]==str[i+k])// so current center is at (r-l)/2 so ditsnce from right side is i-(r-l)/2;so if we (r-l)/2-(i-(r-l)/2) we got l+r-i 
		k++;                                        // for other r-i+1 it represent the granted length does not crosses computed boundary i.e r
		oddlength[i]=k;
		if(i+k-1>r)
		{
			r=i+k-1;      // update r 
			l=i-k-1;
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<oddlength[i]<<" ";
//	}
//	cout<<endl;
}

void buildmanachereven(string &str)
{
	int n=str.size();
	vector<int>evenlength(n);
	int l=0,r=-1;
	for(int i=0;i<n;i++)
	{
		int k=(i>r)?0:min(evenlength[l+r-i+1],r-i+1);
		while(i-k-1>=0 && i+k<n && str[i-k-1]==str[i+k])
		k++;
		evenlength[i]=k;
		if(i+k-1>r)
		{
			l=i-k-2;
			r=i+k-1;
		}
	}
//	for(int i=0;i<n;i++)
//	cout<<evenlength[i]<<" ";
//	cout<<endl;
}
void buildevenpalindrome(string &str)
{
	int n=str.size();
	vector<int>evenlength(n);
	for(int i=0;i<n;i++)
	{
		evenlength[i]=0;
		while(i-evenlength[i]-1>=0 && i+evenlength[i]<n && str[i-evenlength[i]-1]==str[i+evenlength[i]])
		{
			evenlength[i]++;
		}
	}
//	for(int i=0;i<n;i++)
//	cout<<evenlength[i]<<" ";// for every index i,i+1 we rooted the even lenngth palindrome at i+1 .  *** here it tell us no. of even length palindrome rooted at i+1; 
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		evenlength[i]*=2;
	}
////		for(int i=0;i<n;i++)
////	cout<<evenlength[i]<<" ";// here it tells us no of longest length palindrome centred at i+1;
	
}

void buildoddpalindrome(string &str)
{
	int n=str.size();
	vector<int>oddlength(n);
	for(int i=0;i<n;i++)
	{
		oddlength[i]=1;
		while(i-oddlength[i]>=0 && i+oddlength[i]<n && str[i-oddlength[i]]==str[i+oddlength[i]])
		{
			oddlength[i]++;
		}
	}
//	for(int i=0;i<n;i++)
//	cout<<oddlength[i]<<" ";  //THese are the count of odd  length palindrome centered at index i
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		oddlength[i]=(oddlength[i]-1)*2+1;    // For every index if it has x palindrome max length palindrome is (x-1)*2+1 as one for center and x-1 for both side
	}
//	for(int i=0;i<n;i++)
//	cout<<oddlength[i]<<" ";
}



int main()
{
	string str;
	cin>>str;
//	buildoddpalindrome(str);
   buildevenpalindrome(str);
//    Manacher's algorithm optimization complexity brouught down from o(n2) to O(2*n)


     buildmanacherodd(str);
     buildmanachereven(str);

    
     
}
