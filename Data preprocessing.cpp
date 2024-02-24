#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int main()
{
    freopen("rockyou.txt","r",stdin);
    freopen("rockyou.out","w",stdout);
    char s[MAX];
    while(cin.getline(s,100000))
    {
        int len  = strlen(s);
        if(len < 4 || len > 40)continue;
        bool flag = 0;
        for(int i = 0;i < len && s[i] != '\0';i++)
        {
            int c = (int)(s[i]);
            if(c > 32 && c < 127)continue;
            else 
            {
                flag = 1;break;
            }
        }
        if(flag == 1)continue;
        for(int i = 0;i < len ;i++)
        {
            if(s[i] == '\0')break;
            cout<<s[i];
        }
        puts("");
    }
    return 0;
}
