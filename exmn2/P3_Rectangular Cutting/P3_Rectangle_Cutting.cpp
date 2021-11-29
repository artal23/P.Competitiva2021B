/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> minM(a+1,vector<int>(b+1));
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j) {
	            minM[i][j] = 0;
            } else {
	            minM[i][j] = 1e9;
	            for (int k = 1; k < i; k++) {
	                minM[i][j] = min(minM[i][j], minM[k][j]+minM[i-k][j]+1);
	            }
	            for (int k = 1; k < j; k++) {
	                minM[i][j] = min(minM[i][j], minM[i][k]+minM[i][j-k]+1);
	            }
            }
        }
    }
    cout << minM[a][b] << endl;
}