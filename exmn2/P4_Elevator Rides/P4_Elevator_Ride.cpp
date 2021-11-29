#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){

    int n, k; cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    pair<int, int> dp[1<<n];
    dp[0] = {0, k+1};
    for (int s = 1; s < (1<<n); s++) {
        dp[s] = {25, 0};
        for (int i = 0; i < n; i++) {
            if (s>>i&1){
                auto [c, w] = dp[s^(1<<i)];
                if (w + a[i] > k) {
                    c++;
                    w = min(a[i], w);
                }
                else
                    w += a[i];
                dp[s] = min(dp[s], {c, w});
            }
        }
        // cerr<<s<<' '<<dp[s].first<<' '<<dp[s].second<<endl;
    }
    cout<<dp[(1<<n)-1].first;
}










/*











#iclude <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int nro_persons[n];
    for (int i = 0; i < n; i++)
    {
        cin>>nro_persons[i];
        while(nro_persons[i]>x){
            cout<<"ERROR ";
            cin>>nro_persons[i];
        }
    }
    sort(nro_persons,nro_persons+n, greater<int>());
    for (int i = 0; i < n; i++){
        for (int j = n-1; j >= 0; i--)
        {

        }
    }

}*/