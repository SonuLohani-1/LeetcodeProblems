#include <bits/stdc++.h>
using namespace std;
bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;
    int freq1[26] = {0};
    int freq2[26] = {0};
    for (int i = 0; i < word1.length(); i++)
    {
        freq1[word1[i] - 'a']++;
    }
    for (int i = 0; i < word1.length(); i++)
    {
        freq2[word2[i] - 'a']++;
    }

    int myXor = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] > 0 && freq2[i] > 0)
        {
            myXor ^= freq1[i];
            myXor ^= freq2[i];
        }
        else if (freq1[i] > 0 || freq2[i] > 0)
            return false;
    }

    return myXor == 0;
}

int main()
{
    string word1 = "aaabbbbccddeeeeefffff";
    string word2 = "aaaaabbcccdddeeeeffff";
    cout << closeStrings(word1, word2) << endl;
    return 0;
}