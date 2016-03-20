#!/usr/bin/env python

import math

def is_prime_slow(num):
    maxDiv = int( math.sqrt(num) )
    for div in xrange(2, maxDiv +1):
        if num % div == 0:
            return False
    return True

def _split_p(p):
    (k, q) = (0, p)
    while (q % 2 == 0):
        (k, q) = (k+1, q/2)
    return (q, k)

def power(num, p, base):
    res = 1
    for _ in xrange(p):
        res *= num
        res %= base
    return res

def _is_prime_by_rabin_miller(p, a):
    (q, k) = _split_p(p)
    g = power(a, q, p)
    if g in (1, p-1):
        return None

    for i in xrange(1, k+1): # iterating i in range [1, k]
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

    return None

def is_prime_by_rabin_miller(num, maxa=20):
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
    #return True
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
