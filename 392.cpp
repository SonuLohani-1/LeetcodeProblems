#include <bits/stdc++.h>
/*
This is the Recursion Solution: 
class Solution {
private:
    bool checkSubsequence(string s, string t, int i, int j)
    {
        if(i >= s.length()) return true;
        if(j >= t.length()) return false;

        if(s[i] == t[j])
        return checkSubsequence(s, t, i+1, j+1);

        return checkSubsequence(s, t, i, j+1);
    }
public:
    bool isSubsequence(string s, string t) {
        return checkSubsequence(s, t, 0, 0);
    }
};
*/
using namespace std;
bool isSubsequence(string s, string t)
{
    // solving using two pointers approach
    int ptr1 = 0;
    for(int i = 0; i<t.size(); i++)
    {
        if(s[ptr1] = t[i])
        {
            ptr1++;
            if(ptr1 >= s.length())
            return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}