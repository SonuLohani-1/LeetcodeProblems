#include <bits/stdc++.h>
using namespace std;
string predictPartyVictory(string senate)
{
    queue<char> q;
    for (int i = 0; i < senate.size(); i++)
        q.push(senate[i]);
        
    int D_count = 0;
    int R_count = 0;
    while (true)
    {
        
        if(q.front() == 'R' && R_count < 0)
        {
            q.pop();
            R_count++;
        }
        else if(q.front() == 'R')
        {
            q.pop();
            q.push('R');
            D_count--;
        }
        else if(q.front() == 'D' && D_count < 0)
        {
            q.pop();
            D_count++;
        }
        else if(q.front() == 'D')
        {
            q.pop();
            q.push('D');
            R_count--;
        }

        if(q.size() == -D_count)
            return "Radiant";
        if(q.size() == -R_count)
            return "Dire";
    }
    return "Dire";
}
int main()
{
    string senate = "RDDDRR";
    cout << predictPartyVictory(senate) << endl;
    return 0;
}