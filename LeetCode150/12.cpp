#include<bits/stdc++.h>
using namespace std;

// This is the solution to the problem integer to roman on leetcode.
// https://leetcode.com/problems/integer-to-roman/
// The solution is very simple. We just need to make a lookup table for the roman numerals and then we can just divide the number into its digits and then use the lookup table to get the roman numerals.
string intToRoman(int num)
{
    string thousands[] = {"", "M", "MM", "MMM"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    // Given constraint that num <= 3999;
    int num_thousands = num/1000; num = num%1000;
    int num_hundreds = num/100; num = num%100;
    int num_tens = num/10; num = num%10;
    int num_units = num;
    string ans = thousands[num_thousands] + hundreds[num_hundreds] + tens[num_tens] + units[num_units];
    return ans;
}

// Another optimized solution is to use a single lookup table and then use the same logic as above.
string intToRoman2(int num)
{
    string ans = "";
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX", "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10 , 9, 5, 4, 1};
    for(int i = 0; i < 13; i++)
    {
        while(num >= value[i])
        {
            ans += roman[i];
            num -= value[i];
        }
    }
    return ans;
}
int main()
{
    cout << intToRoman(2799) << endl;
    return 0;
}