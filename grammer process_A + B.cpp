#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
inline int read()
{
	int s = 0,w = 1;
	char c = getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';c=getchar();
	}
	return s*w;
}
/*
字典的导入和概率计算 
*/
const int MAX = 1e7 + 10;
const int MOD = 1e9+7;
int n;
string s;
int len_word;
int js[MAX],jss[MAX];
int js1[MAX],js2[MAX];
map<int,map<int,string> >w,q; 
int main()
{
	int minn1 = 0x3f3f3f;
	int maxx1 = 0;
	int maxx2 = 0;
	int minn2 = 0x3f3f3f;
	freopen("generate-dic.out","r",stdin);
	freopen("PCFGrule_AB.out","w",stdout); 
	n = read();
	int tot1 = 0,tot2 = 0;
	for(int i = 1;i <= n;i++)
	{
		cin>>s;
		len_word = s.size();
		if(s[0] >= 'A' && s[0] <= 'Z')
		{
			if(js1[len_word] == 0 && len_word != 0)tot1++;
			js1[len_word]++;
			w[len_word][++js[len_word]] = s;
			maxx1 = max(maxx1,len_word);
			minn1 = min(minn1,len_word);
		}
		else
		{
			if(js2[len_word] == 0 && len_word != 0)tot2++;
			js2[len_word]++;
			q[len_word][++jss[len_word]] = s;
			maxx2 = max(maxx2,len_word);
			minn2 = min(minn2,len_word);
		}
	}
	cout<<tot1 + tot2<<endl;
	for(int i = 1;i <= maxx1;i++)
	{
		if(js[i] == 0)continue;
		cout<<"A"<<i<<" "<<js[i]<<" "<<(double)1.0 / js[i]<<endl;
		for(int j = 1;j <= js[i];j++)
		{
			cout<<w[i][j]<<endl;
		}
	}
	for(int i = 1;i <= maxx2;i++)
	{
		if(jss[i] == 0)continue;
		cout<<"B"<<i<<" "<<jss[i]<<" "<<(double)1.0 / jss[i]<<endl;
		for(int j = 1;j <= jss[i];j++)
		{
			cout<<q[i][j]<<endl;
		}
	}
	return 0;
}

