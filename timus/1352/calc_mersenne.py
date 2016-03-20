#!/usr/bin/env python

import math

def is_prime_slow(num):
    maxDiv = int( math.sqrt(num) )
    for div in xrange(2, maxDiv +1):
        if num % div == 0:
            return False
    return True

def _split_p(p):
    k = 0
    q = p
    while (q % 2 == 0):
        k += 1
        q /= 2
    return (q, k)

def power(num, p, base):
    res = num % base
    for _ in xrange(p):
        res = res * num
        res = res % base
    return res

def _is_prime_by_rabin_miller(p, a):
    (q, k) = _split_p(p)
    g = power(a, q, p)
    if g == 1 or g == -1:
        return None

    for i in xrange(k):
        g = g * g
        g = g % p

        if i == (k-1): # last
            if g != 1:
                return False
            return None
        else:
            if g == -1:
                return None
            if g == 1:
                return False

    return None

def is_prime_by_rabin_miller(num):
    if num < 50:
        return is_prime_slow(num)

    maxa = 20
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
            print '%d\t%d' % (p, N)

if __name__ == '__main__':
    main()
