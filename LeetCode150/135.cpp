// We will be going down while the the points of children decreasing and stop at a point where it starts increasing
// from the lower point (we give one candy to child at the lower point)
// we will keep moving backwards until points are increasing(obviously in backward direction and keep on increasing one candy)
// we will keep following this while all the children are assigned with at least one candy
#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int ans = 0;
    if (n == 0 || n == 1)
        return n;

    int low_going_count = 0;
    int up_going_count = 0;
    for (int i = 0; i <= n-1; i++)
    {
        if(i == 0) // only comparing with the next element
        {
            if(ratings[1] < ratings[0]) low_going_count++;
            else if(ratings[1] > ratings[0]) up_going_count++;
            else ans++;
        }
        else if(i == n-1) // only comparing it with term before it
        {
            if(ratings[n-1] < ratings[n-2]) low_going_count++;
            else if(ratings[n-1] > ratings[n-2]) up_going_count++;
            else ans++;
        }
        else
        {
            // going on upper_slope
            if(ratings[i] > ratings[i-1] && ratings[i] <= ratings[i+1])
            {
                up_going_count++;
            }
            // going down the slope
            else if(ratings[i] < ratings[i-1] && ratings[i] >= ratings[i+1])
            {
                low_going_count++;
            }
            // if it is a valley
            else if(ratings[i] < ratings[i-1] && ratings[i] < ratings[i+1])
            {
                ans++;
                ans += (low_going_count + 1)*(low_going_count)/2 - 1;
                low_going_count = 0;
            }

            // if it is a hill
            else if(ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1])
            {
                up_going_count++;
                ans += up_going_count*(up_going_count+1)/2 - 1;
                up_going_count = 0;
            }

            // if it is a plane
            else
            {
                while(i < n-1 && ratings[i] == ratings[i-1] && ratings[i] == ratings[i+1])
                {
                    ans++;
                    i++;
                }
                if(up_going_count>0)
                {
                    up_going_count++;
                    ans += up_going_count*(up_going_count+1)/2;
                }
                else if(low_going_count>0)
                {
                    low_going_count++;
                    ans += low_going_count*(low_going_count+1)/2;
                }   

            }

        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 0, 2};
    cout << candy(arr) << endl;
    return 0;
}