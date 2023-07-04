#include <bits/stdc++.h>
using namespace std;
/* Noting down the steps to solve this problem:
1. Check if the element has been encountered before if not make a map from s -> t and t -> s
    if yes then check they were before also pointing like this if yes continue else return false;

*/
bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int n = s.length();
    unordered_map<char, char> map1, map2;
    for (int i = 0; i < s.length(); i++)
    {
        if(map1.find(s[i]) == map1.end()) // means we didn't find the element
        {
            map1[s[i]] = t[i];
            if(map2.find(t[i]) == map2.end()) // we didn't find in map2
                map2[t[i]] = s[i];
            else
            {
                if(map2[t[i]] != s[i])
                return false;
            }
        }
        else // means we find the element in map1
        {
            if(map1[s[i]] != t[i]) return false;
        }
    }
    return true;
}

int main()
{
    cout << isIsomorphic("badc", "baba") << endl;
    return 0;
}