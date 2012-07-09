#!/usr/bin/env python

DEBUG_LOG = True
#DEBUG_LOG = False

def HasCycle(edges):
    discovered = set()
    finished = set()

    def visit(startJID):
        st = [[startJID, 0]]
        discovered.add(startJID)
        if DEBUG_LOG:
            print '>>> d:', startJID

        while st:
            """if DEBUG_LOG:
                print '------------------'
                print 'discovered=', discovered
                print 'finished=', finished"""
            # num - number of neighbours discovered
            jid, num = st[-1]
            adj = edges[jid]
            if num < len(adj):
                st[-1][1] += 1
                nid = adj[num]
                if nid not in discovered:
                    discovered.add(nid)
                    st.append([nid, 0])
                    if DEBUG_LOG:
                        print '>>> d:', nid
            else:
                st.pop()
                finished.add(jid)
                if DEBUG_LOG:
                    print '>>> f:', jid
        return False

    for v in edges.iterkeys():
        if v not in discovered:
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

def test5():
    edges = {
        1: [2, 3],
        2: [],
        3: [5],
        4: [3],
        5: [6],
        6: [4],
    }
    test(edges)

def main():
    #test1()
    #test2()
    #test3()
    #test4()
    test5()

if __name__ == '__main__':
    main()
