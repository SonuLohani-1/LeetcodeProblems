#include <bits/stdc++.h>
using namespace std;
void mySwap(int ptr1 , int ptr2, string &s)
{
    char temp = s[ptr1];
    s[ptr1] = s[ptr2];
    s[ptr2] = temp;
}
string reverseVowels(string s)
{
    int ptr1 = 0;
    int ptr2 = s.length() - 1;
    unordered_map<char, bool> vowel =
        {
            {'a', true},
            {'e', true},
            {'i', true},
            {'o', true},
            {'u', true}
        };
    while(ptr1<ptr2)
    {
        if(vowel[s[ptr1]] && vowel[s[ptr2]])
            mySwap(ptr1++, ptr2--, s);

        else if(!vowel[s[ptr1]] && !vowel[s[ptr2]])
        {
            ptr1++;
            ptr2--;
        }
        else if(!vowel[s[ptr1]])
            ptr1++;
        else
            ptr2--;
    }
    return s;
}
int main()
{
    // string s;
    // getline(cin, s);
    cout << reverseVowels("hello") << endl;
    return 0;
}