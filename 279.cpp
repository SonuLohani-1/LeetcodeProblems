#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &squares, int n, int i)
{
    if(n < 0) return 10000;
    if(n == 0) return 1;

    if(squares[i] > n)
    return f(squares, n, i-1);

    return min(1 + f(squares, n-squares[i], i), f(squares, n, i-1));
}
int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i*i < 1e4; i++)
        {
            squares.push_back(i*i);
        }
        return f(squares, n, squares.size()-1);
    }
int main()
{
    return 0;
}