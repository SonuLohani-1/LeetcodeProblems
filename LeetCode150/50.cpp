#include <bits/stdc++.h>
using namespace std;

// Constraints:
//     -100.0 < x < 100.0
//     -2^31 <= n <= 2^31-1
//     n is an integer.
//     Either x is not zero or n > 0.
//     -10^4 <= x^n <= 10^4
class Solution
{
public:
    double myPow(double x, int n)
    {
        // since Either x is not zero or n > 0. that is 0^0 is not possible
        if (x == 0)
            return 0; // since n is not zero when this is the case
        if (n == 0 || x == double(1))
            return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        
        double ans;
        if (n % 2 == 0)
        {
            ans = myPow(x, n / 2);
            return ans * ans;
        }
        if (n % 2 == 1)
        {
            ans = myPow(x, n / 2);
            return ans * ans * x;
        }
        if (n % 2 == -1)
        {
            ans = myPow(x, n/2);
            return ans*ans*(1/x);
        }
        return -1;
    }
};
int main()
{
    int x = (-5)%2;
    cout << x << endl;
    return 0;
}