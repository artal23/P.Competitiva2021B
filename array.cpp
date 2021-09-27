#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int A[5] = {-1,1,2,3,5};
	int nro;

	cin>>nro;
	for (int i=0 ; i< sizeof A/sizeof A[0] ; i++){
		for(int j =0 ; j<sizeof A/sizeof A[0] ; j++){
			if(A[i]+A[j] == nro){
				cout<<"["<<i<<","<<j<<"]"<<" positions";
				return 0;
			    
			}
		}
	}
	return 0;
} 