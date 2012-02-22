#!/usr/bin/env python

import math

def Fact(k):
    res = 1
    for i in xrange(2, k+1):
        res *= i
    return res

def P(n, k):
    return Fact(n) / Fact(n-k)

def Solve(N):
    res = 0
    for i in xrange(2, N+1):
        res += P(N, i)
    return res

def main():
    for N in xrange(1, 22):
        #print "%d\t%d" % (N, Solve(N))
        print '"%d",' % Solve(N)

if __name__ == '__main__':
    main()
