#include <iostream>

using namespace std;

int main(){
	long long f_digits[3] = {0};
	string st;
	cin>>st;
	long long swp = 0;
	for(auto &&c : st){
		long long v = c - '0';
		for(int i = v + 1; i<3; i++)
			swp = swp+f_digits[i];
	++f_digits[v];
	}
	cout<<swp<<endl;
	return 0;
}