#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int KMP(string &text,string &pattern,vector<int>&lps)
{
	int n=text.size();
	int m=pattern.size();
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(text[i]==pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				int previndex=lps[j-1];
				j=previndex;
			}
			else
			{
				i++;
			}
		}
		if(j==m)
		{
			return i-m;
		}
	}
	if(j==m)
	return i-m;
	return -1;
	
}

vector<int> ConstructLPSarray(string &str)
{
	int n=str.size();
	vector<int>lps(n);
	lps[0]=0;//first element has no prefix suffix
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(str[i]==str[j])  
		{
			lps[i]=j+1;
			j++;
		}
		else
		{
			while(j>=0)
			{
				int prev=j-1;
				if(prev>=0)
				{
					int value=lps[prev];
					j=value;
					if(str[i]==str[j])
					{
						lps[i]=j+1;   //most important part
						break;
					}
				}
				else
				{
					lps[i]=0;
					break;
				}
			}
		}
	}
	return lps;
}
int main()
{
	string text;
	string pattern;
	cin>>text>>pattern;
	vector<int>lps=ConstructLPSarray(pattern);
	int index=KMP(text,pattern,lps);
	cout<<index<<"\n";
}
