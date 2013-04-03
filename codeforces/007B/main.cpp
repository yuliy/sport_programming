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

    TMemBlock()
        : Ptr(0)
        , Size(0) {
    }

    TMemBlock(int ptr, int size)
        : Ptr(ptr)
        , Size(size) {
    }
};

class TMemManager {
private:
    list<TMemBlock> Blocks;
private:
    TMemManager(const TMemManager&);
    TMemManager& operator=(const TMemManager&);
public:
    TMemManager();
    int Alloc(int size);
    void Erase(int ptr);
    void Defragment();
};

TMemManager::TMemManager() {
}

int TMemManager::Alloc(int size) {

}

void TMemManager::Erase(int ptr) {

}

void TMemManager::Defragment() {

}

int main() {
    
    return 0;
}
