#!/usr/bin/env python

import math

def calcSumOfDigits(num):
    res = 0
    while num:
        res += (num % 10)
        num /= 10
    return res

def main():
    res = 0
    for a in xrange(0, 100):
        print 'a = %d' % a
        for b in xrange(0, 100):
            curRes = calcSumOfDigits(a ** b)
            if curRes > res:
                res = curRes
    print 'Result = %d' % res

if __name__ == '__main__':
    main()
