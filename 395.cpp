// Longest Substring with atleast K repeating Characters
#include <bits/stdc++.h>
using namespace std;
// This is the implementation of Sliding window approach for this problem
// The idea behind the problem is that longest substring can contain characters from 1 to maxnumber of distinct characters

// Function to calculate the distinct elements in windows
int countDist(string s, int windowStart, int windowEnd)
{
    
}

int valid(vector<int> &freq)
{

}

int longestSubstring(string s, int k)
{
    // counting the maximum number of distinct characters
    int len = s.length();
    unordered_map<char, int> u;
    int maxDist = countDist(s, 0, len-1);
    // Ans to be returned storing the maximum ans till now
    int ans = 0;

    for(int currDist = 1; currDist <= maxDist; currDist++)
    {
        vector<int> freq(26, 0);
        int windowStart = 0;
        int windowEnd = 0;
        while(windowStart <= windowEnd && windowEnd < len)
        {
            // checking the distinct the distinct character in the window;
            for(int i = windowStart; i<=windowEnd; i++)
            {
                freq[s[i] - 'a']++;
            }

            // checking the validity if it is valid then changing the answer;
            if(valid(freq))
            {
                ans = max(ans, windowEnd-windowStart);
            }

            // Counting the distinct char in currWindow
            int distInWindow = countDist(s, windowStart, windowEnd);

            
            // Expanding the window
            if(distInWindow <= currDist)
            {
                windowEnd++;
            }

            // Shrinking the window
            else
            {
                windowStart--;
            }
        }

    }
    
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << longestSubstring(s, k) << endl;
    return 0;
}