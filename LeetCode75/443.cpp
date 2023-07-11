#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    int count = 0;
    int compressedLen = 0;
    for (int i = 0; i < chars.size(); i++)
    {
        if (i != 0 && chars[i] == chars[i - 1])
            count++;
        else if (count > 1)
        {
            chars[compressedLen++] = chars[i - 1];
            while (count)
            {
                chars[compressedLen++] = count % 10 + '0';
                count /= 10;
            }
            count = 1;
        }
        else // when count = 1
        {
            chars[compressedLen++] = chars[i];
            count = 1;
        }
    }
    if (count > 1)
    {
        chars[compressedLen++] = chars[chars.size() - 1];
        while (count)
        {
            chars[compressedLen++] = count % 10 + '0';
            count /= 10;
        }
    }

    chars.erase(chars.begin() + compressedLen, chars.end());
    return compressedLen;
}
int main()
{
    vector<char> arr = {'a', 'b', 'c', 'd', 'd', 'd', 'd', 'e', 'e', 'e', 'e'};
    int a = compress(arr);
    cout << a << endl;
    for (auto it : arr)
    {
        cout << it << endl;
    }

    return 0;
}