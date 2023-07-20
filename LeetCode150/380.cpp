#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 380 on leetcode Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/

// The intution for this problem is that we can use a vector to store the elements and a map to store the index of the elements in the vector
// The time complexity of this solution is O(1) and space complexity is O(n)
class RandomizedSet 
{
    vector<int> v;
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    // We can insert the element in the vector and the index of the element in the map
    bool insert(int val) 
    {
        if(m.find(val) != m.end())
        {
            return false;
        }
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // We can swap the element to be deleted with the last element in the vector and then we can pop the last element in the vector and update the index of the element to be deleted in the map
    bool remove(int val) 
    {
        if(m.find(val) == m.end())
        {
            return false;
        }
        int index = m[val];
        swap(v[index], v[v.size() - 1]);
        // now v[index] is the last element in the vector and v[v.size() - 1] is the element to be deleted
        m[v[index]] = index;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    // We can generate a random number between 0 and the size of the vector and return the element at that index
    int getRandom() 
    {
        int index = rand() % v.size();
        return v[index];
    }
};
int main()
{
    return 0;
}