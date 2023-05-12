#include<bits/stdc++.h>
using namespace std;
 int nCr(int n, int r){
        // code here
        vector<int> prevRow = {1};
        vector<int> currRow = {1, 1};
        
        for(int i = 2; i<n; i++)
        {
           vector<int> prevRow = currRow;
           vector<int> currRow(i+1, 1);
           for(int j = 1; j<i; j++)
           {
               currRow[j] = prevRow[j-1] + prevRow[j];
           }
        }
        return currRow[r-1];
    }
int main()
{
    cout << nCr(3, 2) << endl;
}