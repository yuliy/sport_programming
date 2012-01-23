#!/usr/bin/env python

import math

#PrimeNumbers = {2: None, 3: None, 5: None, 7: None}

def IsPrime(num):
    #if (num, None) in PrimeNumbers:
    #    return True

    if num <= 1:
        return False
    if num == 2:
        return True
    max = int(math.sqrt(num)) + 1
    for i in xrange(2, max + 1):
        if num % i == 0:
            return False

    #PrimeNumbers.update( [(num, None)] )
    return True

def IsSuper(number):
    num = str(number)
    numLen = len(num)
    res = False

    for i in xrange(0, numLen):
        t = int(num[i:])
        if not IsPrime(t):
            return False
        
        if i != 0:
            t = int(num[:-i])
            if not IsPrime(t):
                return False
    return True

def main():
    res = 0
    cnt = 0

    for num in xrange(8, 1000 * 1000 * 1000):
        #if num % 100000 == 0:
        #    print '\tcurrent number = %d; primesDicLen = %d' % (num, len(PrimeNumbers))

        if IsSuper(num):
            res += num
            cnt += 1
            print "cnt=", cnt, 'res=', res, 'num=', num
            if cnt == 11:
                print 'Result: ', res
                return

if __name__ == '__main__':
    main()
