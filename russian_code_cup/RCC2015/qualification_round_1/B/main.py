#!/usr/bin/env python

def main():
    t = int(raw_input())
    for _ in xrange(0, t):
        x = int(raw_input())
        y = int(raw_input())
        z = int(raw_input())
        if x*y == z:
            print('Infinity')
        else:
            print('Finite')

if __name__ == '__main__':
    main()
