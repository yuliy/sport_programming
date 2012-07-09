#!/usr/bin/env python

#DEBUG_LOG = True
DEBUG_LOG = False

def HasCycle(edges):
    discovered = set()
    finished = set()

    def visit(startJID):
        st = [startJID]
        while len(st):
            if DEBUG_LOG:
                print '----------------------'
                print 'st=', st
                print 'discovered=', discovered
                print 'finished=', finished
            jid = st[-1]
            if jid not in finished:
                if jid not in discovered:
                    discovered.add(jid)
                    if DEBUG_LOG:
                        print '>>>d:', jid

                hasUndiscoveredNeighbour = False
                for nid in edges[jid]:
                    if nid in discovered:
                        if nid not in finished:
                            print 'reverse edge: (%s, %s)' % (jid, nid)
                            return True
                    else:
                        hasUndiscoveredNeighbour = True
                        st.append(nid)

                if not hasUndiscoveredNeighbour:
                    st.pop()
                    finished.add(jid)
                    if DEBUG_LOG:
                        print '>>>f:', jid
            else:
                st.pop()
        return False

    for v in edges.iterkeys():
        if visit(v):
            return True
    return False


def test(graph):
    print '-----------'
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
    test(edges)

def main():
    test1()
    test2()
    test3()
    test4()

if __name__ == '__main__':
    main()
