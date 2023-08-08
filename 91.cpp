#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Decode(string s, int i, vector<int> &memo)
{
    // If we reached at the end and no red flags so we traversed correctly
    if (i >= s.length())
        return 1;

    // If we encounted the current char as 0 then the current traversal is not correct return 0;
    if (s[i] == '0')
        return 0;

    if(memo[i] != -1) return memo[i];

    // move one step forward
    int count = Decode(s, i + 1, memo);

    // For moving two step forward we will have to check if it is feasable or not
    if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2') && s[i + 1] - '0' < 7))
        count += Decode(s, i + 2, memo);

    return memo[i] = count;
}


int numDecodings(string s)
{
    int n = s.length();
    vector<int> dp(n+1, 0);
    dp[n-1] = s[n-1] != '0';// for assigning 0 or 1 to dp[n-1];
    //dp[i] denotes the substring starting from i and stores number of ways to decode it.
    
    for(int i = n-1; i>= 0; i--)
    {
        if(s[i] != '0')
        {
            // moving one step forward
            dp[i] += dp[i+1];

            // moving two steps if allowed
            if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            dp[i] += dp[i+2];
        }
    }
    return dp[0];
}
int main()
{
    string s = "2611055971756562";
    cout << numDecodings(s) << endl;
    return 0;
}