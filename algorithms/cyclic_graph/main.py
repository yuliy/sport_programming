#!/usr/bin/env python

def visit(jid):
    q = [jid]
    while q:
        nid = q.pop(0)
        if nid not in discovered:
            discovered.add(nid)
            hasUndiscoveredNeighbour = False
            for neighbour in edges[nid]:
                if neighbour in discovered:
                    if neighbour not in finished:
                        raise RuntimeError('cycle found!')
                else:
                    hasUndiscoveredNeighbour = True
            if not hasUndiscoveredNeighbour:
                finished.add(nid)
            q = edges[nid] + q

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
