#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // We see that the when we do a & a-1 number beyond least significant bit gets reversed so we will do this till right > left;
        // because only those bits should remain which are not changing and same in both left and right;
        int result = right;
        while(right > left)
        {
            result = right & (right - 1);
            right = result;
        }
        return result;
    }
};
int main()
{
    Solution solution;
    int ans = solution.rangeBitwiseAnd(16, 17);
    cout << ans << endl;
    return 0;
}