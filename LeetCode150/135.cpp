
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // This is the logic behind solving candy problem on leetcode
    // This is a very good problem to understand the logic of two pass algo
    // The logic is to first assign 1 candy to each child
    // Then we traverse from left to right and check if the current child has more rating than the previous child
    // If yes then we assign the current child 1 more candy than the previous child
    // Then we traverse from right to left and check if the current child has more rating than the next child
    // If yes then we assign the current child 1 more candy than the next child
    // This way we ensure that the current child has more candies than both the previous and the next child

public:
    int candy(vector<int> &ratings)
    {
        // giving 1 candy to each of the child
        vector<int> candies_distribution(ratings.size(), 1);

        // left to right
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies_distribution[i] = candies_distribution[i - 1] + 1;
            }
        }

        // right to left
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies_distribution[i] = candies_distribution[i + 1] + 1;
            }
        }

        int total = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            total += candies_distribution[i];
        }

        return total;
    }
};
int main()
{

    return 0;
}