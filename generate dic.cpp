#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
/*
由于先前存在从字典中提取语法的脚本
因此只考虑从所有口令中提取单词（大小写分开如PAssword记作PA与ssword） 
*/
const int MAX = 1;
const int MOD = 1e9+7;
int n;
map<string,bool>q; 
inline int get_type(char a)
{
	if(a >= 'A' && a <= 'Z')return 1;
	if(a >= 'a' && a <= 'z')return 2;
	if(a >= '0' && a <= '9')return 3;
	else return 4;
}
inline char out_type(int x)
{
	if(x == 1)return 'A';
	if(x == 2)return 'B';
	if(x == 3)return 'D';
	else return 'S';
}
inline void process(string s)
{
	int flag = get_type(s[0]);
	int len = s.size();
	string ss;
	ss += s[0];
	for(int i = 1;i <= len;i++)
	{
		if(get_type(s[i]) != flag || i == len)
		{
			if((flag == 1 || flag == 2) && q[ss] == 0)
			{
				q[ss] = 1;
				cout<<ss<<endl;
			}
			flag = get_type(s[i]);
			ss.clear();
			ss += s[i];
		}
		else
			ss += s[i];
	}
}
int main()
{
	freopen("rockyou.out","r",stdin);
	freopen("generate-dic.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		string s;cin>>s;
		process(s);
	}
	return 0;
}

