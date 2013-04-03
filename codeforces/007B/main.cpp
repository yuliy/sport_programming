#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

struct TMemBlock {
    int Ptr;
    int Size;
    int ID;
    static int NewID;

    TMemBlock()
        : Ptr(0)
        , Size(0)
        , ID(++NewID) {
    }

    TMemBlock(int ptr, int size)
        : Ptr(ptr)
        , Size(size)
        , ID(++NewID) {
    }
};

int TMemBlock::NewID = 0;

typedef list<TMemBlock> TMemBlocks;

class TMemManager {
private:
    TMemBlocks Blocks;
    int MemSize;
private:
    TMemManager();
    TMemManager(const TMemManager&);
    TMemManager& operator=(const TMemManager&);
private:
    TMemBlocks::iterator FindBlockByPtr(int ptr) {
        for (TMemBlocks::iterator iter = Blocks.begin(); iter != Blocks.end(); ++iter) {
            if (iter->Ptr == ptr)
                return iter;
        }
        return Blocks.end();
    }
public:
    explicit TMemManager(int memSize);
    int Alloc(int size);
    bool Erase(int ptr);
    void Defragment();
};

TMemManager::TMemManager(int memSize)
    : MemSize(memSize) {
}

int TMemManager::Alloc(int size) {
    if (Blocks.empty()) {
        if (size > MemSize)
            return 0;
        TMemBlock b(1, size);
        Blocks.push_front(b);
        return b.ID;
    }

    if (size < Blocks.front().Ptr) {
        TMemBlock b(1, size);
        Blocks.push_front(b);
        return b.ID;
    }

    TMemBlocks::iterator pos = ++Blocks.begin();
    for (; pos != Blocks.end(); ++pos) {
        TMemBlocks::iterator prev = pos;
        --prev;

        const int gap = pos->Ptr - prev->Ptr - prev->Size;
        if (gap >= size) {
            const int ptr = pos->Ptr + pos->Size;
            TMemBlock b(ptr, size);
            Blocks.insert(pos, b);
            return b.ID;
        }
    }

    const TMemBlock &last = Blocks.back();
    const int gap = MemSize - last.Ptr - last.Size + 1;
    if (gap >= size) {
        const int ptr = last.Ptr + last.Size;
        TMemBlock b(ptr, size);
        Blocks.push_back(b);
        return b.ID;
    }

    return 0;
}

bool TMemManager::Erase(int ptr) {
    TMemBlocks::iterator iter = FindBlockByPtr(ptr);
    if (iter != Blocks.end()) {
        Blocks.erase(iter);
        return true;
    }
    return false;
}

void TMemManager::Defragment() {
    if (Blocks.empty())
        return;

    Blocks.front().Ptr = 0;
    if (Blocks.size() < 2)
        return;

    TMemBlocks::iterator prev = Blocks.begin();
    TMemBlocks::iterator iter = prev;
    ++iter;

    for (; iter != Blocks.end(); prev=iter,++iter) {
        iter->Ptr = prev->Ptr + prev->Size;
    }
}

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    TMemManager mm(m);

    for (int i = 0; i < t; ++i) {
        char buf[32];
        scanf("%s", buf);
        const char fch = buf[0];
        switch(fch) {
        case 'a': {
            int sz;
            scanf("%d", &sz);
            const int p = mm.Alloc(sz);
            if (p == 0)
                printf("NULL\n");
            else
                printf("%d\n", p);
        } break;
        case 'e': {
            int ptr;
            scanf("%d", &ptr);
            if (!mm.Erase(ptr))
                printf("ILLEGAL_ERASE_ARGUMENT\n");
        } break;
        case 'd': {
            mm.Defragment();
        } break;
        default: {
        } break;
        }
    }

    return 0;
}
