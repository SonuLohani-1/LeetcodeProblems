#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        // creating an array for which index each line will start and varialbe for extra amount of spaces
        vector<int> start_idx;
        start_idx.push_back(0); // first line will start at zero index;
        vector<int> extra_spaces;
        vector<string> ans;
        int curr_width = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (curr_width + words[i].size() > maxWidth)
            {
                start_idx.push_back(i);
                extra_spaces.push_back(maxWidth - curr_width + 1); // extra 1 is for the fact that we are adding words[i].size() + 1 but last one is a space it should be counted in the extra space
                curr_width = 0;
            }
            curr_width += words[i].size() + 1;
        }

        for (int i = 0; i < start_idx.size() - 1; i++)
        {
            string curr_line;
            int num_words = start_idx[i + 1] - start_idx[i];
            if (num_words == 1)
            {
                curr_line = words[start_idx[i]];
                while (extra_spaces[i]--)
                {
                    curr_line += " ";
                }
            }
            else
            {
                int spaces = 1 + extra_spaces[i] / (num_words - 1);
                int left = extra_spaces[i] % (num_words - 1);
                for (int j = start_idx[i]; j < start_idx[i + 1] - 1; j++)
                {
                    curr_line += words[j];
                    for (int k = 0; k < spaces; k++)
                    {
                        curr_line += " ";
                    }
                    if (left != 0)
                    {
                        curr_line += " ";
                        left--;
                    }
                }
                curr_line += words[start_idx[i + 1] - 1];
            }
            ans.push_back(curr_line);
        }

        string last_line = "";
        for (int i = start_idx[start_idx.size() - 1]; i < words.size(); i++)
        {
            last_line += words[i];
            if (last_line.size() < maxWidth)
                last_line += " ";
            else
                break;
        }
        while (last_line.size() < maxWidth)
        {
            last_line += " ";
        }
        ans.push_back(last_line);
        return ans;
    }
};

// A better solution for this problem is to use the concept of dynamic programming.
// The time complexity is O(n^2) and the space complexity is O(n^2).

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    Solution s;
    vector<string> ans = s.fullJustify(words, maxWidth);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}