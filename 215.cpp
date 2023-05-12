// Finding the Kth largest element in an array
// There could be repeating character as well and they will be counted as different

#include <iostream>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    int arr[int(2 * 1e4 + 2)] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        arr[int(nums[i] + 1e4)]++;
    }
    for (int i = 2 * 1e4 + 1; i >= 0; i--)
    {
        k = k - arr[i];
        if (k <= 0)
            return i - 1e4;
    }
}
return 0;
}
int main()
{

    return 0;
}
