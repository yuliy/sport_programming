#!/usr/bin/env python

def visit(startJID):
    import collections
    q = collections.deque([startJID])
    while q:
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
                        raise RuntimeError('cycle found!')
                else:
                    hasUndiscoveredNeighbour = True
                    q.appendleft(nid)
            if not hasUndiscoveredNeighbour:
                finished.add(jid)

edges = {
    1: [2, 5],
    2: [3, 4],
    3: [],
    4: [],
    5: [4],
}

#visited = set()
#order = {}
discovered = set()
finished = set()

def main():
    for i in xrange(1, 6):
        visit(i)

if __name__ == '__main__':
    main()
