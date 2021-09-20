#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k,nro,ct = 0;
	cin>>n>>k;
	for(int i=0 ; i<n ; i++ ){
		cin>>nro;
		if(nro%k == 0){
			ct ++;
		}
	}
	cout<<"\n"<<ct;
	return 0;

}
