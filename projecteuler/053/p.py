#!/usr/bin/env python

import math

Factorial = []

def Init():
    t = 1
    Factorial.append(t)
    for i in xrange(1, 101):
        t *= i
        Factorial.append(t)

def CalcC(n, r):
    return Factorial[n] / (Factorial[r] * Factorial[n-r])

def main():
    Init()
    res = 0
    for n in xrange(1, 101):
        print 'n=', n, 'res=', res
        for r in xrange(0, n+1):
            if CalcC(n, r) > 1000000:
                res += 1
    print res

if __name__ == '__main__':
    main()
