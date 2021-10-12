#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


signed main(){
	int n,m,k,a,b;

	cin>>n>>m;

	vector<int> valores(n);

	for(int i = 0 ; i < n ; i++){
		cin>>valores[i];
	}
	for(int i = 0 ; i < m ; i++){
	
		cin>>k>>a>>b;
		if(k == 1){
		    vector<int> temp(b-a+1);
		    for(int i=a-1, j=0 ; i<b ; i++,j++){
            		temp[j] = valores[i]; 
            		//cout<<valores[i]<<" ";
            		
            		//cout<<temp[j]<<" ";
            	}
            	//cout<<"\n";
            for(int i = a-1, j=b-a ; i<b ; i++,j--){
            	valores[i] = temp[j];
            	//cout<<valores[i]<<" ";
            }
		}
		//cout<<"\n";
		if(k == 2){
			int suma = 0;
		    for(int i=a-1 ; i<b ; i++){
                	suma = suma + valores[i];
                	//cout<< valores[i];
                }
            cout<<suma<<endl;
		}
		    
	}
	//return 0;
}