#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int n,tot;
map<string,int>p;
string type[MAX];
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
inline string process(string s)
{
    string sss;
    int len = s.size();
    int flag = get_type(s[0]);
    sss += out_type(flag);
    int num = 1;
    for(int i = 1;i <= len;i++)
    {
        if(i == len || get_type(s[i]) != flag)
        {
            string k;
            while(num)
            {
                k += num % 10 + '0';
                num = num / 10;
            }
            for(int j = k.size() - 1;j >= 0;j--)sss += k[j];
            flag = get_type(s[i]);
            if(i != len)sss += out_type(flag);
            num = 1;
        }
        else num++;
    }
    return sss;
}
int main()
{
    freopen("rockyou.out","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        string s,op;
        cin>>s;
        op = process(s);
        p[op]++;
        if(p[op] == 1)type[++tot] = op;
    }
    cout<<tot<<endl;
    for(int i = 1;i <= tot;i++)
    {
        double pos = 1.0 * p[type[i]] / n;
        cout<<type[i]<<" "<<pos<<endl;
    }
    return 0;
}