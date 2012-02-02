#!/usr/bin/env python

import math

def IsLychrelNumber(number):
    num = str(number)
    for i in xrange(0, 51):
        t = int(num) + int(num[::-1])
        num = str(t)
        if num == num[::-1]:
            return False
    return True

def main():
    res = 0
    for i in xrange(11, 10001):
        if IsLychrelNumber(i):
            res += 1
    print 'Result = %d' % res

if __name__ == '__main__':
    main()
