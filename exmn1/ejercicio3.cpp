#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
typedef long long ll;

int main()
{
	int tam,a,b;
	cin>>tam>>a>>b;
	vector<ll> valores(tam+1);
	for (int i = 1; i <= tam; ++i){
		cin>>valores[i];
	}
	for (int i = 1; i <= tam; ++i)
		valores[i] += valores[i-1];
	
	set<pair<ll,int>> limit;

	for (int i = a; i <= b; ++i)
		limit.insert({valores[i],i});
	
	ll sum_max = -INF;

	for (int i = 1; i <= tam-a+1; ++i)
	{
		sum_max = max(sum_max,limit.rbegin()->first-valores[i-1]);
		limit.erase({valores[i+a-1],i+a-1});
		if (i+b <= tam)
			limit.insert({valores[i+b],i+b});
	}
	cout<< sum_max;

}