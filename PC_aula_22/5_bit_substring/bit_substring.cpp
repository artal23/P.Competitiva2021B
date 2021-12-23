#include<bits/stdc++.h>

using namespace std;
//----------TEMPLATES----------
template<typename T>
void see(T& args) { (cin >> args);}
template<typename T>
void put(T&& args) { (cout << args << " ");}
/*
#define int long long
#define ll long long
#define ld long double

const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
*/
int exp(int x, unsigned int y, int p){
	int res=1; x=x%p;
	while(y>0){
		if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
	}
	return res;
}

void solve(){
	int n; see(n);
	put(exp(2,n,md));
}	

signed main(){

    int t=1;
    //cin>>t;
    while(t--){
    	solve();
    	//cout<<'\n';
    }
}