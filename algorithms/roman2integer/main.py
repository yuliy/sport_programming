#!/usr/bin/env python3

#
# Solution for leetcode problem:
# https://leetcode.com/problems/roman-to-integer/
#

class Solution:
    def romanToInt(self, s: str) -> int:
        s2r = {
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000,
        }
        r = [s2r[ch] for ch in s]

        if len(r)==1:
            return r[0]

        result = 0
        for i in range(len(r)-1):
            if r[i+1] > r[i]:
                result -= r[i]
            else:
                result += r[i]

        result += r[-1]
        return result
