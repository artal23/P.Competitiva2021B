
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>

 
using namespace std;
const int max_=10000000;
char str[max_];
int vis[1000];
 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        getchar();
        gets(str);
        int L=strlen(str);
        int st=0,ed=0;
        memset(vis,0,sizeof(vis));
        int m=0;
        int ans=0;
        while(ed<L)
        {
            if(vis[str[ed]]==0) m++;
            vis[str[ed]]++;
            while(m>n)
            {
                if(vis[str[st]]-1>0)
                {
                    vis[str[st]]--;
                }
                else if(vis[str[st]]-1==0)
                {
                    vis[str[st]]--;
                    m--;
                }
                st++;
            }
            ed++;
            ans=max(ans,ed-st);
        }
        cout<<"\n"<<ans;
    }
    return 0;
}