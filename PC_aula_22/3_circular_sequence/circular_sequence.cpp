#include"stdio.h"
#include"string.h"
#define maxn 100

int judge (char * s, int p, int q) 
{
    int m=strlen(s);
    for(int i=0; i<m; i++)
        if(s[(p+i)%m]!=s[(q+i)%m])
            return s[(p+i)%m]<s[(q+i)%m];
    return 0;
}

int main()
{
    int T,i,m,result;
    char s[maxn];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        m=strlen(s);
        for(i=0; i<m; i++)
            if(judge (s, i, result)) result = i; 
        for(i=0; i<m; i++)
            printf("%c",s[(result+i)%m]);
        printf("\n");
    }
    return 0;
}