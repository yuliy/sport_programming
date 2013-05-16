#!/usr/bin/env python

"""
In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card:          Highest value card.
One Pair:           Two cards of the same value.
Two Pairs:          Two different pairs.
Three of a Kind:    Three cards of the same value.
Straight:           All cards are consecutive values.
Flush:              All cards of the same suit.
Full House:         Three of a kind and a pair.
Four of a Kind:     Four cards of the same value.
Straight Flush:     All cards are consecutive values of same suit.
Royal Flush:        Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
"""

HIGH_CARD = 0
ONE_PAIR = 1
TWO_PAIRS = 2
THREE_OF_A_KIND = 3
STRAIGHT = 4
FLUSH = 5
FULL_HOUSE = 6
FOUR_OF_A_KIND = 7
STRAIGHT_FLUSH = 8
ROYAL_FLUSH = 9

rank2name = {
    0: 'HIGH_CARD',
    1: 'ONE_PAIR',
    2: 'TWO_PAIRS',
    3: 'THREE_OF_A_KIND',
    4: 'STRAIGHT',
    5: 'FLUSH',
    6: 'FULL_HOUSE',
    7: 'FOUR_OF_A_KIND',
    8: 'STRAIGHT_FLUSH',
    9: 'ROYAL_FLUSH',
}

name2cost = {
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'T': 10,
    'J': 11,
    'Q': 12,
    'K': 13,
    'A': 14,
}

def convert_hand(hand):
    res = [(name2cost[card[0]], card[1]) for card in hand]
    return sorted(res, key = lambda c: c[0], reverse = True)

def IsStraight(hand):
    first = hand[0][0]
    for i in xrange(1, 5):
        if hand[i][0] != (first+i):
            return False
    return True

def IsFlush(hand):
    first = hand[0][1]
    for i in xrange(1, 5):
        if hand[i][1] != first:
            return False
    return True

def IsFourOfAKind(h):
    f = h[0][0]
    if f == h[1][0] and f == h[2][0] and f == h[3][0]:
        return True

    f = h[1][0]
    if f == h[2][0] and f == h[3][0] and f == h[4][0]:
        return True

    return False

def IsFullHouse(h):
    # 2 and 3
    if h[0][0] == h[1][0] and h[2][0] == h[3][0] and h[3][0] == h[4][0]:
        return True

    # 3 and 2
    if h[0][0] == h[1][0] and h[1][0] == h[2][0] and h[3][0] == h[4][0]:
        return True

    return False

def IsThreeOfAKind(h):
    if h[0][0] == h[1][0] and h[1][0] == h[2][0]:
        return True
    if h[1][0] == h[2][0] and h[2][0] == h[3][0]:
        return True
    if h[2][0] == h[3][0] and h[3][0] == h[4][0]:
        return True
    return False

def IsTwoPairs(h):
    if h[0][0] == h[1][0] and h[2][0] == h[3][0]:
        return True
    if h[0][0] == h[1][0] and h[3][0] == h[4][0]:
        return True
    if h[1][0] == h[2][0] and h[3][0] == h[4][0]:
        return True
    return False

def IsPair(h):
    if h[0][0] == h[1][0]:
        return True
    if h[1][0] == h[2][0]:
        return True
    if h[2][0] == h[3][0]:
        return True
    if h[3][0] == h[4][0]:
        return True
    return False

def CalcCombination(hand):
    fl = IsFlush(hand)
    st = IsStraight(hand)

    if fl and st:
        return (ROYAL_FLUSH, hand) if hand[0] == 14 else (STRAIGHT_FLUSH, hand)

    if IsFourOfAKind(hand):
        #if hand[0][0] != hand[1][0]:
        #    h = hand[1:]
        #    h.append(h[0])
        #    return (FOUR_OF_A_KIND, h)
        return (FOUR_OF_A_KIND, hand)

    if IsFullHouse(hand):
        #if hand[1][0] != hand[2][0]:
        #    h = hand[2:] + h[0:3]
        #    return (FULL_HOUSE, h)
        return (FULL_HOUSE, hand)

    if fl:
        return (FLUSH, hand)

    if st:
        return (STRAIGHT, hand)

    if IsThreeOfAKind(hand):
        return (THREE_OF_A_KIND, hand)

    if IsTwoPairs(hand):
        return (TWO_PAIRS, hand)

    if IsPair(hand):
        return (ONE_PAIR, hand)

    return (HIGH_CARD, hand)

def SolveCollision(r, h1, h2):
    if r == STRAIGHT_FLUSH:
        pass

def main():
    ifile = open('poker.txt', 'r')
    for line in ifile:
        cards = line.split('\n')[0].split(' ')
        hand1 = cards[0:5]
        hand2 = cards[5:]

        print '============================================'
        print 'src="%s"' % line.split('\n')[0]
        print 'hand1: %r' % hand1
        print 'hand2: %r' % hand2

        print '--------------------------------------------'
        hand1 = convert_hand(hand1)
        hand2 = convert_hand(hand2)
        print 'hand1: %r' % hand1
        print 'hand2: %r' % hand2
        print '--------------------------------------------'
        (r1, h1) = CalcCombination(hand1)
        (r2, h2) = CalcCombination(hand2)
        print (rank2name[r1], h1)
        print (rank2name[r2], h2)

        winner = None
        if r1 != r2:
            winner = 1 if r1 > r2 else 2
        winner = SolveCollision(r1, hand1, hand2)
        print 'winner: %d' % winner
        print ''

if __name__ == '__main__':
    main()
