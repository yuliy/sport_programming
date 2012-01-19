#!/usr/bin/env python

Values = [
    1,
    2,
    5,
    10,
    20,
    50,
    100,
    200
]

ValuesCnt = 8

def main():
    d = []
    for i in xrange(0, 251):
        d.append(0)
    d[0] = d[1] = 1

    for v in xrange(2, 201):
        for coin in Values:
            if (v - coin) >= 1:
                #d[v] += d[v-coin]
                #if (v-coin) > coin:
                d[v] += (d[v-coin] * d[coin])

    for i in xrange(0, 201):
        print i, d[i]

if __name__ == '__main__':
    main()
