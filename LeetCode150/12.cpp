#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    cout << intToRoman(2799) << endl;
    return 0;
}