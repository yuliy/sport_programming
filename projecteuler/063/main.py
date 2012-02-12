#!/usr/bin/env python

import math

def main():
    res = 0
    for i in xrange(1, 101):
        print 'i=%s' % i
        for p in xrange(1, 101):
            num = i ** p
            print num
            d = len(str(num))
            if d == p:
                ++res

    print 'Result:', res

if __name__ == '__main__':
    main()
