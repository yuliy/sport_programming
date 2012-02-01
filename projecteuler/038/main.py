#!/usr/bin/env python

import math

Factorial = []

def Init():
    Factorial = [1, 1]
    t = 1
    for i in xrange(2, 1001):
        t *= i
        Factorial.append(t)

Digits = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

def IsPandigital(s):
    if len(s) != 9:
        return False

    for d in Digits:
        if d not in s:
            return False
    return True

def CalcPandigital(num):
    idx = 1
    s = str(num)
    while True:
        if IsPandigital(s):
            return int(s)
        idx += 1
        t = num * idx
        s += str(t)
        if len(s) > 9:
            break
    return -1


def main():
    Init()

    res = -1
    for i in xrange(1, 1000*1000*1000):
        if i % 1000000 == 0:
            print 'i =', i, 'Result =', res
        curRes = CalcPandigital(i)
        if curRes > res:
            res = curRes

    print 'Result =', res

if __name__ == '__main__':
    main()
