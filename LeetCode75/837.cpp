#include <bits/stdc++.h>
using namespace std;

void f(int n, int k, int maxPts, int currSum, int &count_n, int &count_k)
{
    if (currSum >= k && currSum > n)
    {
        count_k++;
        count_n++;
        return;
    }

    if (currSum >= k)
    {
        count_k++;
        return;
    }

    for (int i = 1; i <= maxPts && currSum < k; i++)
    {
        f(n, k, maxPts, currSum + i, count_n, count_k);
    }
    return;
}

double new21Game(int n, int k, int maxPts)
{
    int count_n = 0;
    int count_k = 0;
    f(n, k, maxPts, 0, count_n, count_k);
    return 1.00000 - double(count_n) / double(count_k);
}

int main()
{
    int count_n = 0;
    int count_k = 0;
    f(10, 1, 10, 0, count_n, count_k);
    double x = 1.00000 - double(count_n) / double(count_k);
    cout << x << endl;
    return 0;
}
