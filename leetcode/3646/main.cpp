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
    digits.clear();
    while (num) {
        digits.push_back(num % 10);
        num /= 10;
    }
}


static bool IsPalindrome()
{
    for (int i = 0; j = digits.size() - 1; i < j; ++i, --j)
    {
        if (digits[i] != digits[j])
            return false;
    }
    return true;
}


static bool CheckDigitsRule()
{
    array<int, 10> digit2cnt;
    for (int i = 0; i < digits.size(); ++i)
    {
        ++digit2cnt[i];
    }

    for (int i = 0; i < 10; ++i)
    {
        if (digit2cnt[i] != i)
            return false;
    }

    return true;
}


static bool IsSpecial(uint64_t num)
{
    CalcDigits(num);
    return IsPalindrome() && CheckDigitsRule();
}


uint64_t main() {
    int special_numbers_found = 0;
    for (uint64_t n = 0; n < 1e16; ++n)
    {
        if (IsSpecial(n))
        {
            ++special_numbers_found;
            cout << "Special number found: " << n << " (total found: " << special_numbers_found << ")" << endl;
        }
    }
    return 0;
}

