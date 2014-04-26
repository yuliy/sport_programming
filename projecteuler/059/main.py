#!/usr/bin/env python

def try_hack(numbers, key):
    #dnumbers = [chr(num ^ key) for num in numbers]
    dnumbers = []
    pos = 0
    for num in numbers:
        dn = numbers[pos] ^ ord(key[pos % 3])
        dnumbers.append(chr(dn))
        pos += 1

    #alpha_count = 0
    #for num in dnumbers:
    #    if num.isalpha():
    #        alpha_count += 1
    #ratio = 100.0 * alpha_count / len(dnumbers)

    text = ''.join(dnumbers)
    #if ratio > 70.0:
    if 'the' in text and 'a ' in text and 'of' in text and 'was' in text:
        print '_______________________________'
        #print 'ratio: %f' % ratio
        print 'key=%s' % key
        print text

def main():
    f = open('cipher1.txt', 'r')
    s = f.read()
    numbers = [int(num) for num in s.split(',')]

    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    for a in alphabet:
        for b in alphabet:
            for c in alphabet:
                key = [a, b, c]
                try_hack(numbers, key)

if __name__ == '__main__':
    main()
