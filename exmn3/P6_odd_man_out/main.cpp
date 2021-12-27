/* LINK ----> https://open.kattis.com/problems/oddmanout */

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int G;
	cin>>N;

	for(int i = 0; i < N; i++){
		map<long long int, int> v;
		cin>>G;
		for(int j = 0; j < G; j++){
			long long int t;
			cin>>t;
			v[t]++;
		}
		for(auto x:v){
			if(x.second==1)
				cout<<"Case #"<<i+1<<": "<<x.first<<"\n";
		}
	}

}