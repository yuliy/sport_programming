#!/usr/bin/env python

import math

def is_prime(num):
    if num in [2, 3, 5, 7, 11, 13]:
        return True
    if num % 2 == 0:
        return False

    max_div = math.trunc(num ** .5)
    for divisor in xrange(3, max_div + 1, 2):
        if num % divisor == 0:
            return False
    return True

def find_nth_prime(index_of_prime_to_find):
    cur_idx = 1
    num = 2
    while (cur_idx < index_of_prime_to_find):
        num += 1
        if is_prime(num):
            cur_idx += 1
    return num

def main():
    res = find_nth_prime(10001)
    print 'Answer: %s' % res

if __name__ == '__main__':
    main()
