#!/usr/bin/env python

def visit(jid):
    q = [jid]
    while q:
        nid = q.pop(0)
        #self.waitJobs[nid].add(jid)
        if nid not in visited:
            visited.add(nid)
            if nid not in order:
                raise RuntimeError('job dependencies cycle exists')
            order[jid] = len(order)
            q = edges[nid] + q

edges = {
    1: [2, 5],
    2: [3, 4],
    3: [],
    4: [],
    5: [],
}

visited = set()

order = {}

def main():
    for i in xrange(1, 6):
        visit(i)

if __name__ == '__main__':
    main()
