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
处理每个数字部分和特殊单词部分出现的概率 
并生成PCFG规则（如D1 -> 0,1,2,3,4,5,6,7,8,9） 
*/
const int MAX = 1e7 + 10;
const int MAXX =  1e7 + 10; 
const int MOD = 1e9+7;
struct node
{
	string ss;
	double pos;
};
vector<node>D[55];
vector<node>S[55]; 
int n;
string s; 
bool cmp(node a,node b)
{
	return a.pos > b.pos;
}
int D_totalnum,S_totalnum;
int D_typenum,S_typenum;
map<string,int>p_D,p_S;
string s1[MAXX],s2[MAXX];
double D_pos[MAX],S_pos[MAX];
int D_PCFGnum[55],S_PCFGnum[55];
int js1[55],js2[55];
int js[MAX];
void cz(int now_place,int len,int type,string a)
{
	if(type == 1)return;
	string sss;
	//password!123  123password! 
	for(int i = now_place - len;i < now_place;i++)sss += a[i];
	if(type == 2)
	{
		++js1[sss.size()];
		p_D[sss]++;
		if(p_D[sss] == 1)s1[++D_typenum] = sss;		
	}
	else 
	{
		++js2[sss.size()];
		p_S[sss]++;
		if(p_S[sss] == 1)s2[++S_typenum] = sss;
	}
	return;
}
void trans(string a)
{
	string sss;
	int type;int len = 1;
	if((a[0] >= 'A' && a[0] <= 'Z') || (a[0] >= 'a' && a[0] <= 'z'))type = 1,sss += 'L';
	else if(a[0] >= '0' && a[0] <= '9')type = 2,sss += 'D';
	else type = 3,sss += 'S';
	for(int i = 1;i < a.size();i++)
	{
		if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
		{
			if(type != 1)
			{
				cz(i,len,type,a);
				len = 1;
				type = 1;
			}
			else len++;
		}
		else if(a[i] >= '0' && a[i] <= '9')
		{
			if(type != 2)
			{
				cz(i,len,type,a);
				len = 1;
				type = 2;
			}
			else len++;
		}
		else
		{
			if(type != 3)
			{
				cz(i,len,type,a);
				len = 1;
				type = 3;
			}
			else len++;
		}
	}
	cz(a.size(),len,type,a);
	return;
}
int main()
{
	freopen("rockyou.out","r",stdin);
	freopen("PCFGrule_DS.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>s;
		trans(s);
	}
	int D_minn = 0x3f3f3f,D_maxx = 0;
	int S_minn = 0x3f3f3f,S_maxx = 0;
	int tot = 0;
	for(int i = 1;i <= D_typenum;i++)
	{
		int w = s1[i].size();//长度为w 
		if(js[w] == 0)tot++;
		js[w]++;
		D_minn = min(D_minn,w);
		D_maxx = max(D_maxx,w);
		node aaa;
		aaa.pos = 1.0 * p_D[s1[i]] / js1[s1[i].size()];
		aaa.ss = s1[i];
		D[w].push_back(aaa);
	}
	memset(js,0,sizeof(js));
	for(int i = 1;i <= S_typenum;i++)
	{
		int w = s2[i].size();
		if(js[w] == 0)tot++;
		js[w]++;	
		S_minn = min(S_minn,w);
		S_maxx = max(S_maxx,w);
		node aaa;
		aaa.pos = 1.0 * p_S[s2[i]] / js2[s2[i].size()];
		aaa.ss = s2[i];
		S[w].push_back(aaa);
	}
	cout<<tot<<endl;
	for(int i = D_minn;i <= D_maxx;i++)
	{
		if(D[i].size() == 0)continue;
		cout<<"D"<<i<<" "<<D[i].size()<<endl;
		sort(D[i].begin(),D[i].end(),cmp);
		for(int j = 0;j < D[i].size();j++)
		{
			cout<<D[i][j].ss<<" "<<D[i][j].pos<<endl;	
		} 
	}
	for(int i = S_minn;i <= S_maxx;i++)
	{
		if(S[i].size() == 0)continue;
		cout<<"S"<<i<<" "<<S[i].size()<<endl;
		sort(S[i].begin(),S[i].end(),cmp);
		for(int j = 0;j < S[i].size();j++)
		{
			cout<<S[i][j].ss<<" "<<S[i][j].pos<<endl;	
		} 
	}
	return 0;
}
