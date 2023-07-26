#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 202, Happy numbers on leetcode.
// https://leetcode.com/problems/happy-number/

// The idea is to use a set to store the numbers that we have already seen.
// If we see a number that we have already seen, then we will return false.
// If we see 1, then we will return true.
// time complexity: O(logn)
// space complexity: O(logn)

class Solution
{
    public:
        bool isHappy(int n)
        {
            set<int> s;
            while (n != 1)
            {
                int sum = 0;
                while (n)
                {
                    sum += (n % 10) * (n % 10);
                    n /= 10;
                }
                n = sum;

                // There is a loop going on here.
                if (s.find(n) != s.end())
                    return false;

                s.insert(n);
            }
            return true;
        }
};

// A more efficient solution is to use the Floyd Cycle Detection Algorithm.
// We will use two pointers, one slow and one fast.
// The slow pointer will move one step at a time, while the fast pointer will move two steps at a time.
// If the fast pointer reaches 1, then we will return true.
// If the fast pointer and the slow pointer meet, then we will return false.
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution
{
    public:
        int getNext(int n)
        {
            int sum = 0;
            while (n)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            return sum;
        }

        bool isHappy(int n)
        {
            int slow = n, fast = getNext(n);
            while (fast != 1 && slow != fast)
            {
                slow = getNext(slow);
                fast = getNext(getNext(fast));
            }
            return fast == 1;
        }
};

int main()
{
    return 0;
}