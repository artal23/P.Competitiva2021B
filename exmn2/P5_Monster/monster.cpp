#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char goal[] = {'U', 'D', 'R', 'L'};
int nex[1005][1005];

void funcion(){
    int n,m; 
    cin>>n>>m;

    vector<string> grid(n);
    for (auto &i: grid)
        cin>>i;
    queue<pair<int,int>> q;
    int x,y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'M')
                q.push({i,j});
            else if (grid[i][j] == 'A')
                x = i, y = j;
    q.push({x,y});
    nex[x][y] = -1;

    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (grid[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1)) {
            cout<<"YES"<<endl;
            string ans;
            int d = nex[x][y];
            while(d != -1) {
                ans += goal[d];
                x -= fx[d];
                y -= fy[d];
                d = nex[x][y];
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.size()<<endl;
            cout<<ans;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + fx[i], 
            yy = y + fy[i];
            if (xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy] != '.' ) continue;
            else {
                grid[xx][yy] = grid[x][y];
                if (grid[xx][yy] == 'A') nex[xx][yy] = i;
                q.push({xx,yy});
            }
        }
    }
    cout<<"NO";
}    
signed main(){
    funcion();
}