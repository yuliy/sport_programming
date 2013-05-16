#!/usr/bin/env python

DEBUG_LOG = False

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
        if hand[i][0] != (first-i):
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
        return (FOUR_OF_A_KIND, hand)

    if IsFullHouse(hand):
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

def Hand2Str(hand):
    cost2char = {
        2: '2',
        3: '3',
        4: '4',
        5: '5',
        6: '6',
        7: '7',
        8: '8',
        9: '9',
        10: 'A',
        11: 'B',
        12: 'C',
        13: 'D',
        14: 'E',
    }
    return [cost2char[card[0]] for card in hand]

def NormalizeHand(r, h):
    if r in [STRAIGHT_FLUSH, FLUSH, STRAIGHT, HIGH_CARD]:
        return h[:]

    if r == FOUR_OF_A_KIND:
        if h[0][0] == h[1][0]:
            return h[:]
        return h[1:] + h[0:1]

    if r == FULL_HOUSE:
        return h[:]
        if h[1][0] == h[2][0]:
            return h[:]
        return h[2:] + h[0:2]

    if r == THREE_OF_A_KIND:
        if h[1][0] == h[2][0] and h[2][0] == h[3][0]:
            return h[1:4] + h[0:1] + h[4:]
        if h[2][0] == h[3][0] and h[3][0] == h[4][0]:
            return h[2:] + h[0:2]
        return h[:]

    if r == TWO_PAIRS:
        if h[0][0] == h[1][0] and h[3][0] == h[4][0]:
            return h[0:2] + h[3:] + h[2:3]
        if h[1][0] == h[2][0] and h[3][0] == h[4][0]:
            return h[1:] + h[0:1]
        return h[:]

    if r == ONE_PAIR:
        if h[1][0] == h[2][0]:
            return h[1:3] + h[0:1] + h[3:]
        if h[2][0] == h[3][0]:
            return h[2:4] + h[0:2] + h[4:]
        if h[3][0] == h[4][0]:
            return h[3:] + h[0:3]
        return h[:]

    raise Exception('Failed normalizing hand!')

def SolveCollision(r, h1, h2):
    h1 = NormalizeHand(r, h1)
    h2 = NormalizeHand(r, h2)
    s1 = Hand2Str(h1)
    s2 = Hand2Str(h2)
    if DEBUG_LOG:
        print 'normalized h1: %r' % h1
        print 'normalized h2: %r' % h2
        print 's1=%s' % s1
        print 's2=%s' % s2

    return 1 if s1 > s2 else 2

def main():
    ifile = open('poker.txt', 'r')
    p1wins = 0
    num = 0
    for line in ifile:
        cards = line.split('\n')[0].split(' ')
        hand1 = convert_hand(cards[0:5])
        hand2 = convert_hand(cards[5:])
        (r1, h1) = CalcCombination(hand1)
        (r2, h2) = CalcCombination(hand2)

        if DEBUG_LOG:
            print '============================================'
            print 'num=%d' % num
            print 'src="%s"' % line.split('\n')[0]
            print 'hand1: %r' % hand1
            print 'hand2: %r' % hand2

            print '--------------------------------------------'
            print 'hand1: %r' % hand1
            print 'hand2: %r' % hand2
            print '--------------------------------------------'
            print (rank2name[r1], h1)
            print (rank2name[r2], h2)

        winner = None
        if r1 != r2:
            winner = 1 if r1 > r2 else 2
        else:
            if DEBUG_LOG:
                print 'INFO: collision!'
            winner = SolveCollision(r1, hand1, hand2)
        if winner == 1:
            p1wins += 1
        print 'winner: %d' % winner
        num += 1

    print '\n\tAnswer: %d' % p1wins

if __name__ == '__main__':
    main()
