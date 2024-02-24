#include<bits/stdc++.h>
using namespace std;
map<string,double>k;
int main()
{
	freopen("guess.out","r",stdin);
	int n;cin>>n;
//	cout<<n<<endl;
	for(int i = 1;i <= n;i++)
	{
		string s;cin>>s;
		double pos;cin>>pos;
		k[s] = pos;	
	}
	freopen("phpbb+yahoo.txt","r",stdin);
	freopen("pos.out","w",stdout);
	int m;cin>>m;
	for(int i = 1;i <= m;i++)
	{
		string s;cin>>s;
		cout<<k[s]<<endl;
	}
	return 0;
}
