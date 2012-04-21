#pragma once

#include <vector>
#include <list>

namespace NGraphLib {
    template<typename T> class TALGraph;

    template<typename T>
    class TALGVertexDescriptor {
    private:
        int Index;
        friend class TALGraph<T>;
    public:
        TALGVertexDescriptor()
            : Index(-1) {
        }

        TALGVertexDescriptor(int index)
            : Index(index) {
        }
    };

    template<typename T>
    class TALGEdgeDescriptor {
    private:
        int FromIndex;
        int ToIndex;
        friend class TALGraph<T>;
    public:
        TALGEdgeDescriptor()
            : FromIndex(-1)
            , ToIndex(-1) {
        }

        TALGEdgeDescriptor(int fromIndex, int toIndex)
            : FromIndex(fromIndex)
            , ToIndex(toIndex) {
        }
    };

    template<typename T, typename TListIter, typename TListVertexIter >
    class TALGEdgeIterator {
    private:
        TALGEdgeIterator();
    private:
        TListIter ListIter;
        TListIter ListEnd;
        TListVertexIter ListVertexIter;
        TListVertexIter ListVertexEnd;
    public:
        TALGEdgeIterator(TListIter lIter, TListIter lEnd, TListVertexIter lvIter, TListVertexIter lvEnd)
            : ListIter(lIter)
            , ListEnd(lEnd)
            , ListVertexIter(lvIter)
            , ListVertexEnd(lvEnd) {
        }

        T& operator*() {
            return *ListVertexIter;
        }

        const T& operator*() const {
            return *ListVertexIter;
        }

        bool operator==(const TALGEdgeIter &other) const {
            return (ListIter == other.ListIter) && (ListVertexIter == other.ListVertexIter);
        }

        bool operator!=(const TALGEdgeIter &other) const {
            return !(*this == other);
        }

        TALGEdgeIterator& operator++() {
            if (ListVertexIterator != ListVertexEnd)
                ++ListVertexIter;
            else
                ++ListIter;
            return *this;
        }
    };

    template<typename T>
    class TALGraph {
    private:
        typedef std::vector<T> TVertices;
        typedef std::list<int> TAdjList;
        typedef std::vector< TAdjList > TAdjLists;
    private:
        TVertices Vertices;
        TAdjLists AdjLists;
    public:
        typedef TVertices::const_iterator TConstVertexIterator;
        typedef TVertices::iterator TVertexIterator;

        typedef TALGVertexDescriptor<T> TVertexDescriptor;
        typedef TALGEdgeDescriptor<T> TEdgeDescriptor;

        TALGraph() {
        }

        TVertexDescriptor AddVertex(const T& v) {
            Vertices.push_back(v);
            return TVertexDescriptor(Vertices.size() - 1);
        }

        T& GetVertex(TVertexDescriptor d) {
            return Vertices[d.Index];
        }

        const T& GetVertex(TVertexDescriptor d) const {
            return Vertices[d.Index];
        }

        TEdgeDescriptor AddEdge(TVertexDescriptor from, TVertexDescriptor to) {
            AdjLists[from.Index].push_back(to.Index);
            return TEdgeDescriptor(from.Index, to.Index);
        }

        bool CheckEdge(TVertexDescriptor from, TVertexDescriptor to) {
            const TAdjList &l = AdjLists[from.Index];
            for (TAdjList::const_iterator iter = l.begin(), end = l.end(); iter != end; ++iter)
                if (*iter == to.Index)
                    return true;
            return false;
        }

        std::pair< TVertexIterator, TVertexIterator> GetVertices() {
            return std::make_pair(Vertices.begin(), Vertices.end());
        }

        std::pair< TConstVertexIterator, TConstVertexIterator > GetVertices() const {
            return std::make_pair(Vertices.begin(), Vertices.end());
        }

        //
    };
}; // namespace NGraphLib
