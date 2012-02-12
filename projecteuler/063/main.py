#!/usr/bin/env python

import math

def main():
    res = 0
    """
    for i in xrange(1, 11):
        print 'i=%s\tres=%s' % (i, res)
        for p in xrange(1, 1001):
            num = i ** p
            d = math.log10(num)
            d = int(math.floor(d)) + 1

            if d == p:
                res += 1

            print '----'
            if d == p:
                print '!!!'
            print 'i=%s\tp=%s\tnum=%s\td=%s' % (i, p, num, d)
    """

    l = [math.log10(i) for i in xrange(1, 10)]

    for lg in l:
        print 'lg=%s' % (lg, )
        for n in xrange(1, 10000):
            t = n * lg
            t = math.floor(t)
            if t == (n - 1):
                res += 1
                print '\tn=%s' % (n, )
            elif t > (n-1):
                break

    """
    for n in xrange(1, 100):
        if n % 1000000 == 0:
            print 'n=%s\tres=%s' % (n, res)
        t = (n-1) / n
        if t in l:
            res += 1
            print 'n=%s' % (n,)
    """

    print 'Result:', res

if __name__ == '__main__':
    main()
