#!/usr/bin/env python

import math

def IsPrime(num):
    max = int(math.sqrt(num)) + 1
    for i in xrange(2, max + 1):
        if num % i == 0:
            return False
    return True

def IsSuper(number):
    num = int(number)
    res = False
    while True:
        #print num
        if not IsPrime(num):
            return False
        if num < 10:
            res = True
            break
        num = str(num)
        num = num[1:]
        num = int(num)

    if res == False:
        return False

    num = int(number)
    while True:
        #print num
        if not IsPrime(num):
            return False
        if num < 10:
            return True
        num = str(num)
        num = num[:-1]
        num = int(num)

def main():
    res = 0
    cnt = 0
    #IsSuper(739397)
    #return
        
    for num in xrange(8, 1000 * 1000 * 1000):
        if IsSuper(num):
            res += num
            cnt += 1
            print "cnt=", cnt, 'res=', res, 'num=', num
            #if cnt == 100:
            #    print 'Result: ', res
            #    return

if __name__ == '__main__':
    main()
