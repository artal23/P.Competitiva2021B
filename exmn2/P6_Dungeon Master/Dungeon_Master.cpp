#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int l, r, c;
char map[31][31][31];
int visit[31][31][31];
int sti, stj, stk;
int mov[][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

struct node
{
	int i, j, k;
	int ruta;
};

int valid(int i,int j,int k)
{
	if(i<0||i>=l||j<0||j>=r||k<0||k>=c)
		return 0;
	return 1;
}

void bfs()
{
	int i, j, k;
	int l;
	node t, p;
	queue <node> que;

	memset(visit,0,sizeof(visit));
	visit[sti][stj][stk] = 1;
	t.i = sti;t.j = stj;t.k = stk;t.ruta = 0;
	que.push(t);
	while(!que.empty())
	{
		t = que.front();
		que.pop();
		for(l = 0; l < 6; l++)
		{
			i = t.i + mov[l][0];
			j = t.j + mov[l][1];
			k = t.k + mov[l][2];
			if (valid(i,j,k)&&!visit[i][j][k]&&map[i][j][k]!='#')
			{
				p.i = i;p.j = j;p.k = k;p.ruta = t.ruta+1;
				visit[i][j][k] = 1;
				if(map[i][j][k]=='E')
				{
					printf("Escaped in %d minute(s).\n",p.ruta);
					return ;
				}
				que.push(p);
			}
		}
	}
	puts("Trapped!");
}

int main()
{
	int i, j, k;

	while(scanf("%d%d%d",&l,&r,&c),l)
	{
		for(i = 0; i < l; i++)
		{
			for(j = 0; j < r; j++)
			{
				scanf("%s",map[i][j]);
				for(k = 0; k < c; k++)
					if(map[i][j][k]=='S')
						sti = i,stj = j,stk = k;
			}
		}
		bfs();
	}
	return 0;
}