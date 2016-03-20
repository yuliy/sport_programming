#!/usr/bin/env python

import math

def is_prime_slow(num):
    print '\tis_prime_slow (num=%d)' % num
    maxDiv = int( math.sqrt(num) )
    for div in xrange(2, maxDiv +1):
        if num % div == 0:
            return False
    return True

def _split_p(p):
    print '\t_split_p'
    (k, q) = (0, p)
    while (q % 2 == 0):
        (k, q) = (k+1, q/2)
    return (q, k)

def _power(num, p, base):
    if p == 0:
        return 1
    if p == 1:
        return num % base
    if p == 2:
        return (num * num) % base

    if p % 2 == 0:
        return power(num, p/2, base) * power(num, p/2, base) % base
    return power(num, p/2, base) * power(num, p/2 + 1, base) % base

def power(num, p, base):
    #print '\tpower (%d, %d, %d)' % (num, p, base)
    #res = _power(num, p, base)
    res = (num ** p) % base
    #print '\tpower (end)'
    return res

def _is_prime_by_rabin_miller(num, a):
    #print '\t_is_prime_by_rabin_miller a=%d' % a
    p = num - 1
    (q, k) = _split_p(p)
    #print '\tp=%d\tq=%d\tk=%d' % (p, q, k)
    if k == 0:
        return None

    g = power(a, q, p)
    #print '\t\tq=%d\tk=%d\tg=%d' % (q, k, g)
    if g in (1, p-1):
        return None

    for i in xrange(1, k+1): # iterating i in range [1, k]
        #print '\titeration start'
        g = power(g, 2, p)

        if i == k: # last
            if g != 1:
                return False
            return None
        else:
            if g == (p-1):
                return None
            if g == 1:
                return False
        #print '\titeration end'

    return None

def is_prime_by_rabin_miller(num, maxa=10):
    #print '\tis_prime_by_rabin_miller (num=%d)' % num
    if num < (maxa + 5):
        return is_prime_slow(num)

    for a in xrange(2, maxa+1):
        res = _is_prime_by_rabin_miller(num, a)
        if res is False:
            return False

    return None

def is_prime(num):
    res = is_prime_by_rabin_miller(num)
    if res is not None:
        return res
    return is_prime_slow(num)

def main():
    p = 0
    base = 2
    N = 1
    while (True):
        N += 1
        base *= 2
        num = base - 1

        if not is_prime(N):
            continue

        print '\tN=%d' % N
        if is_prime(N) and is_prime(num):
            p += 1
            print '#%d\tN=%d\tnum=%d' % (p, N, num)

if __name__ == '__main__':
    main()
