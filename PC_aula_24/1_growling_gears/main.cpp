#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin>>n;;
    while(n--)
    {
        int k;
        cin>>k;

        double max = -INFINITY;
        int max_i = 0;

        for (int i = 1; i <= k; i++)
        {

            int a, b, c;
            cin>>a>>b>>c;

            // f(x) = -ax^2+bx+c => f'(x) = -2ax+b => [ f'(x) = 0 <=> x = b/(2a) ] 
            // and -a < 0 for all a > 1 so max in b/(2a)
            double der = (double)b/(a<<1);
            double val = -a * der * der + b * der + c;

            if (val > max)
            {
                max = val;
                max_i = i;
            }
        }

        cout<<max_i;
    }
    return 0;
}