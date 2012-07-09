#!/usr/bin/env python

DEBUG_LOG = True

def HasCycle(edges):
    discovered = set()
    finished = set()

    def visit(startJID):
        import collections
        q = collections.deque([startJID])
        while q:
            if DEBUG_LOG:
                print '----------------------'
                print 'q=', q
                print 'discovered=', discovered
                print 'finished=', finished
            jid = q.popleft()
            if jid not in discovered:
                discovered.add(jid)
                hasUndiscoveredNeighbour = False
                for nid in edges[jid]:
                    if nid in discovered:
                        if nid not in finished:
                            #raise RuntimeError('cycle found!')
                            return True
                    else:
                        hasUndiscoveredNeighbour = True
                        q.appendleft(nid)
                if not hasUndiscoveredNeighbour:
                    finished.add(jid)
        return False

    for v in edges.iterkeys():
        if visit(v):
            return True
    return False


def test(graph):
    if HasCycle(graph):
        print 'cycle'
    else:
        print 'no cycles'

def test1():
    edges = {
        1: [2, 5],
        2: [3, 4],
        3: [],
        4: [],
        5: [4],
    }
    test(edges)

def test2():
    edges = {
        1: [2, 5],
        2: [3, 4],
        3: [1],
        4: [],
        5: [4],
    }
    test(edges)

def test3():
    edges = {
        1: [2, 3],
        2: [4],
        3: [],
        4: [3],
    }
    test(edges)

def test4():
    """
    edges = {
        1: [2, 3],
        2: [6, 7],
        3: [4, 5],
        4: [],
        5: [],
        6: [7, 8],
        7: [],
        8: [3],
    }
    """
    edges = {
        1: [2, 3],
        2: [3],
        3: [4],
        4: [],
    }
    test(edges)

def main():
    test1()
    test2()
    test3()
    test4()

if __name__ == '__main__':
    main()
