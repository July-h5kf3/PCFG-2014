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
const int MAX = 1e6;
const int MOD = 1e9+7;
//²úÉú×îÖÕ²Â²â 
int n,m;
struct PCFG_rule
{
	string s;
	double pos;
};
vector<PCFG_rule>L[3][55];
int js[2][55];
void input_ABrule()
{
	freopen("PCFGrule_AB.out","r",stdin);
	cin>>m;
	for(int i = 1;i <= m;i++)
	{
		string s;cin>>s;
		int num = 0;
		int type = s[0] == 'B';
		for(int j = 1;j < s.size();j++)num = num * 10 + s[j] - '0';
		cin>>js[type][num];
		double pos_L;cin>>pos_L;
		for(int j = 1;j <= js[type][num];j++)
		{
			PCFG_rule aaa;cin>>aaa.s;
			aaa.pos = pos_L;
			L[type][num].push_back(aaa);
		}
	}
}
int guess_num;
int cnt;
void dfs(string nows,string pre_terminal,string base,int max_pivot,int now_pivot,int bnow_place,int pnow_place,double pos)
{
	//if(cnt >= guess_num)return;
	if(now_pivot == max_pivot)
	{
		cnt++;
		cout<<nows<<" "<<pos<<endl;
		return;
	}
	int flag = (base[bnow_place] == 'A' || base[bnow_place] == 'B');
	int num = 0;
	int jl = 0;
	string xxx = nows;
	int cd = flag;
	for(int i = bnow_place + 1;i <= base.size();i++)
	{
		if(base[i] >= 'A' && base[i] <= 'Z' || i == base.size())
		{
			if(flag  == 0)
			{
				string linshi;
				for(int j = pnow_place;j < pnow_place + num;j++)linshi += pre_terminal[j];
				nows += linshi;
			}
			jl = i;
			break;
		}
		else
		{
			num = num * 10 + base[i] - '0';
			cd++;
		}
	}
//	cout<<"num = "<<num<<" cd = "<<cd<<endl;
	if(flag == 0)dfs(nows,pre_terminal,base,max_pivot,now_pivot + 1,jl,pnow_place + num,pos),nows = xxx;
	else
	{
		int type = base[bnow_place] == 'B';
		for(int i = 0;i < L[type][num].size();i++)
		{
			nows += L[type][num][i].s;
			dfs(nows,pre_terminal,base,max_pivot,now_pivot + 1,jl,pnow_place + cd,pos);
			nows = xxx;
		}
	}
}
int main()
{
	input_ABrule();
	freopen("preterminal_struct.out","r",stdin);
	freopen("guess.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2,s3;
		double pos;int max_pivot;
		cin>>s1>>pos>>s2>>max_pivot;
		dfs(s3,s1,s2,max_pivot,0,0,0,pos);
	}
	return 0;
}
/*
10
2
B1 5 0.2
a
b
c
d
e
A1 10 0.1
A
B
C
D
E
E
F
G
H
I
1
6A123B1 1 D1A1D2B1
4
*/
