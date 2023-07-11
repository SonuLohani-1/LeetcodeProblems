#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        for(int i = 0; i < 8; i++)
        {
            if(startGene[i] != endGene[i])
            {
                string mutation = startGene.substr(0, i-1) + endGene[i] + startGene.substr(i+1);
                
            }
        }
    }
};
int main()
{
    return 0;
}