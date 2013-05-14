#!/usr/bin/env python

"""
In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
"""

def Is

def main():
    ifile = open('poker.txt', 'r')
    for line in ifile:
        cards = line.split('\n')[0].split(' ')
        hand1 = sorted(cards[0:5])
        hand2 = sorted(cards[5:])

        print '-----------------'
        print 'src="%s"' % line.split('\n')[0]
        print 'hand1: %r' % hand1
        print 'hand2: %r' % hand2

if __name__ == '__main__':
    main()
