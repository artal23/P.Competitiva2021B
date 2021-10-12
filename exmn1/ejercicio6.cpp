#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;
int B = 73; 
const int mxN = 1e6+6;
int pB[mxN];
struct {
    int bit[mxN] = {0};

    void update(int k, int x) {
        x %= md;
        if (x < md) x += md;
        for (; k < mxN; k += k&-k) {
            (bit[k] += x) %= md;
        }
    }

    int query(int k) {
        int s = 0;
        for (; k > 0; k -= k&-k)
            (s += bit[k]) %= md;
        return s;
    }
} prefijo, sufijo;

signed main(){
   
    int n, t; cin>>n>>t;
    string s; cin>>s;
    pB[0] = 1;
    for (int i = 1; i < mxN; i++) 
        pB[i] = pB[i-1] * B % md;

    for (int i = 0; i < n; i++) {
        prefijo.update(i+1, (s[i]-'a'+1) * pB[i]);
        sufijo.update(i+1, (s[i]-'a'+1) * pB[n-i-1]);
    }
    while (t--) {
        int ch; cin>>ch;
        if (ch == 1) {
            int k; char x;
            cin>>k>>x; k--;
            prefijo.update(k+1, -(s[k]-'a'+1) * pB[k]);
            prefijo.update(k+1, (x-'a'+1) * pB[k]);
            sufijo.update(k+1, -(s[k]-'a'+1) * pB[n-k-1]);
            sufijo.update(k+1, (x-'a'+1) * pB[n-k-1]);
            s[k] = x;
        }
        else {
            int x, y; cin>>x>>y;
            int h1 = (prefijo.query((x+y)/2) - prefijo.query(x-1) + md) % md;
            int m1 = pB[x-1];
            int h2 = (sufijo.query(y) - sufijo.query((x+y-1)/2) + md) % md;
            int m2 = pB[n-y];
            cout << (h1 * m2 % md == h2 * m1 % md ? "YES" : "NO" ) << endl;            
        }
    }
}