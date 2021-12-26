
#include <iostream>
#include <math.h>

using namespace std;

double long potencia (long n, long x){
    double long r = 1;
    while(n>0){
        if((n&1) != 0)
            r*=x;
        x*=x;
        n >>= 1;
    }
    return r;
}

void solve(long n){
    long shift = 0;
    int ele = 0;
    cout << "{";
    while(n>0){
        if(n&1 == 1){
            if (ele == 0){
                cout<<potencia(shift,3);
            }
            else 
                cout<<","<<potencia(shift,3);
            ele = ele + 1;
        }
        n >>= 1;
        shift = shift + 1;
    }
    cout<<"}";
}

int main()
{
    long n;
    while(true){
        cin>>n;
        if(n==0)
           break; 
        solve(n-1);
    }
    return 0;
}