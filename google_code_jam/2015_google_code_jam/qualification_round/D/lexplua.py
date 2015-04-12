#!/usr/bin/env python

import sys
filename = sys.argv[1]

in_f = open(filename)
T = int(in_f.readline().strip())

for t in xrange(T):
    x, r, c = [int(x) for x in in_f.readline().strip().split()]
    c, r = sorted((r, c))

    if x > r or (r * c) % x != 0:
        print "Case #{}: RICHARD".format(t + 1)
        continue
    if int(x / 2.0 + .5) > c:
        print "Case #{}: RICHARD".format(t + 1)
        continue
    if x == 4 and r == 4 and c == 2:
        print "Case #{}: RICHARD".format(t + 1)
        continue
    if x > 4 and r == x and c < x - 2:
        print "Case #{}: RICHARD".format(t + 1)
        continue
    if x > 6:
        print "Case #{}: RICHARD".format(t + 1)
        continue

    print "Case #{}: GABRIEL".format(t + 1)
