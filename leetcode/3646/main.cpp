#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> digits;


static void CalcDigits(uint64_t num)
{
    //cout << "DIGITS[]:" << endl;
    digits.clear();
    while (num) {
        digits.push_back(num % 10);
        num /= 10;
        //cout << "\t" << digits.back() << endl;
    }
}


static bool IsPalindrome()
{
    for (int i = 0, j = digits.size() - 1; i < j; ++i, --j)
    {
        if (digits[i] != digits[j])
            return false;
    }
    return true;
}


static bool CheckDigitsRule()
{
    array<int, 10> digit2cnt = {0};
    for (auto d : digits)
    {
        ++digit2cnt[d];
    }

    for (auto d : digits)
    {
        if (digit2cnt[d] != d)
        {
            //cout << "FAIL: d=" << d << " cnt=" << digit2cnt[d] << endl;
            return false;
        }
    }

    return true;
}


static bool IsSpecial(uint64_t num)
{
    CalcDigits(num);
    //cout << "\tis palindrome: " << IsPalindrome() << endl;
    //cout << "\tdigits ok: " << CheckDigitsRule() << endl;
    return IsPalindrome() && CheckDigitsRule();
}


int main()
{
    int special_numbers_found = 0;
    for (uint64_t n = 0; n <= 213; ++n)
    {
        if (IsSpecial(n))
        {
            ++special_numbers_found;
            cout << "Special number found: " << n << " (total found: " << special_numbers_found << ")" << endl;
        }
    }
    return 0;
}

