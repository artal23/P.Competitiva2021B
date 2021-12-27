
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define F0R(i, a) for (int i=0; i<(a); i++)

const int MOD = 1000000007;

int n;
ll hi[100000], lo[100000];
vi z;
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; z.resize(n);
	F0R(i,n) cin >> z[i];

	Tree<pii> T1;
	F0R(i,n) {
		hi[i] = T1.size()-T1.order_of_key({z[i],MOD});
		T1.insert({z[i],i});
	}
	Tree<pii> T2;
	F0Rd(i,n) {
		lo[i] = T2.order_of_key({z[i],-MOD});
		T2.insert({z[i],i});
	}
	F0R(i,n)ans += lo[i]*hi[i];
	cout << ans;
}