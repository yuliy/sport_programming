#!/usr/bin/env python

import sys

def foo(n, k):
    if n == 0:
        return 1
    if k == 0:
        return n
    return foo(n, k-1) * foo(n-1, k)

def main():
    n = sys.argv[1]
    k = sys.argv[2]
    print foo(int(n), int(k))

if __name__ == '__main__':
    main()
