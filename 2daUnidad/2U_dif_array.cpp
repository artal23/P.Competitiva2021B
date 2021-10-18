#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cout<<"Ingrese nros: \n";
	cin >> n >> k;
	vector<int> arr_dif(n + 1);
	
	int sol[1000000];
	int total = 0;
	
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		arr_dif[l]++;
		arr_dif[r + 1]--;
	}
	for (int i = 0; i < n; i++) { 
		total += arr_dif[i];
		sol[i] = total;
		cout<<i<<": "<<arr_dif[i]<<"***";
		cout<<sol[i]<<"***\n";
	}
	sort (sol, sol + n); 
	cout << sol[n / 2] << '\n'; 
}