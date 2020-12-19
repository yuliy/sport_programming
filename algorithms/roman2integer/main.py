#!/usr/bin/env python3

#
# Solution for leetcode problem:
# https://leetcode.com/problems/roman-to-integer/
#

class Solution:
    def Solution(self):
        self.res = 0
        self.s = None

    def applyRules(self, rules):
        for rule in rules:
            prefix, value = rule
            if self.s.startswith(prefix):
                self.res += value
                prefixLen = len(prefix)
                self.s = self.s[prefixLen:]
                break

    def romanToInt(self, s: str) -> int:
        self.res = 0
        self.s = s

        self.applyRules((
            ('MMMCM', 3900),
            ('MMCM',  2900),
            ('MMM',   3000),
            ('MCM',   1900),
            ('MM',    2000),
            ('CM',     900),
            ('M',     1000),
        ))

        self.applyRules((
            ('DCCC', 800),
            ('DCC',  700),
            ('DC',   600),
            ('CD',   400),
            ('D',    500),
        ))

        self.applyRules((
            ('CCCXC', 390),
            ('CCC',   300),
            ('CCXC',  290),
            ('CC',    200),
            ('CXC',   190),
            ('C',     100),
            ('XC',     90),
        ))

        self.applyRules((
            ('LXXX', 80),
            ('LXX',  70),
            ('LX',   60),
            ('XL',   40),
            ('L',    50),
        ))

        self.applyRules((
            ('XXX', 30),
            ('XX',  20),
        ))

        d = {
            'XIX':   19,
            'XVIII': 18,
            'XVII':  17,
            'XVI':   16,
            'XV':    15,
            'XIV':   14,
            'XIII':  13,
            'XII':   12,
            'XI':    11,
            'X':     10,
            'IX':     9,
            'VIII':   8,
            'VII':    7,
            'VI':     6,
            'V':      5,
            'IV':     4,
            'III':    3,
            'II':     2,
            'I':      1,
            '':       0,
        }

        return self.res + d[self.s]
