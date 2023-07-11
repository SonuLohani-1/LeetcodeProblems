#include<bits/stdc++.h>
using namespace std;
string gcdOfStrings(string str1, string str2) {
        if(str1[0] != str2[0])
            return "";

        int m = str1.length();
        int n = str2.length();
        string ans;
        string currGCD = "";
        for(int i = 0; i < min(m, n); i++)
        {
            if(str1[i] == str2[i])
            {
                currGCD += str1[i];
                string s1;
                string s2;
                for(int i = 0; i<str1.length(); i+=currGCD.length())
                {
                    s1 += currGCD;
                }

                for(int i = 0; i<str2.length(); i+=currGCD.length())
                {
                    s2 += currGCD;
                }

                if(s1 == str1 && s2 == str2)
                ans = currGCD;

            }
            else
                return "";
        }
        return ans;
    }
int main()
{
    string s1 = "abcabc";
    string s2 = "abc";
    string ans = gcdOfStrings(s1, s2);
    cout << ans << endl;
    return 0;
}