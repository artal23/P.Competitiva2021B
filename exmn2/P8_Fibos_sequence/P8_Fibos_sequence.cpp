#include <bits/stdc++.h>
using namespace std;
 
int a, b, c, d;
#define MOD 1000000007

void fibo_(int n, int res[])
{
    if (n == 0) {
        res[0] = 0;
        res[1] = 1;
        return;
    }
    fibo_((n / 2), res);
 
    //  a = F(n)
    a = res[0];
 
    //  b = F(n+1)
    b = res[1];
 
    c = 2 * b - a;
 
    if (c < 0)
        c += MOD;
 
    c = (a * c) % MOD;
 
    d = (a * a + b * b) % MOD;
 
    if (n % 2 == 0) {
        res[0] = c;
        res[1] = d;
    }
    else {
        res[0] = d;
        res[1] = c + d;
    }
}

int main(){
    int A, B, N, a, b;
    int res[2] = {0};
    cin>>A>>B>>N;
    while(A!=0 && B!=0 && N!=0){
        int temp = 0;
        for(int i = 0; i<N ; i++){
            fibo_(A+i,res);
            a = res[0];
            fibo_(B+i,res);
            b= res[0];
            temp = temp + a*b;
        }
        cout<<temp%MOD<<endl;
        cin>>A>>B>>N;
    }
}