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

        TALGVertexDescriptor<T> From() const {
            return TALGVertexDescriptor<T>(FromIndex);
        }

        TALGVertexDescriptor<T> To() const {
            return TALGVertexDescriptor<T>(ToIndex);
        }
    };

    template<typename TVDescriptorType >
    class TALGVertexIterator {
    private:
        TALGVertexIterator();
    private:
        int Index;
    public:
        TALGVertexIterator(int index)
            : Index(index) {
        }

        TVDescriptorType operator*() const {
            return TVDescriptorType(Index);
        }

        TALGVertexIterator &operator++() {
            ++Index;
            return *this;
        }

        bool operator==(const TALGVertexIterator &other) const {
            return Index == other.Index;
        }

        bool operator!=(const TALGVertexIterator &other) const {
            return !(*this == other);
        }
    };

    template<typename TLists, typename TListVertexIter, typename TEDescriptorType >
    class TALGEdgeIterator {
    private:
        TALGEdgeIterator();
    private:
        int Index;
        const TLists &Lists;
        TListVertexIter ListVertexIter;
    public:
        TALGEdgeIterator(const TLists &lists, int index, TListVertexIter lvIter)
            : Lists(lists)
            , Index(index)
            , ListVertexIter(lvIter) {
        }

        TEDescriptorType operator*() const {
            //std::cout << ">>>\t" << (Index + 1) << "\t" << (*ListVertexIter + 1) << std::endl;
            return TEDescriptorType(Index, *ListVertexIter);
        }

        bool operator==(const TALGEdgeIterator &other) const {
            return (Index == other.Index) && (ListVertexIter == other.ListVertexIter);
        }

        bool operator!=(const TALGEdgeIterator &other) const {
            return !(*this == other);
        }

        TALGEdgeIterator& operator++() {
            ++ListVertexIter;
            if (ListVertexIter == Lists[Index].end()) {
                ++Index;
                while (Index < Lists.size() && Lists[Index].size() == 0)
                    ++Index;

                if (Index < Lists.size())
                    ListVertexIter = Lists[Index].begin();
                else
                    ListVertexIter = Lists[Index-1].end();
            }
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
        typedef TALGVertexDescriptor<T> TVertexDescriptor;
        typedef TALGEdgeDescriptor<T> TEdgeDescriptor;

        typedef TALGVertexIterator<TVertexDescriptor > TVertexIterator;
        typedef TALGEdgeIterator<TAdjLists, TAdjList::const_iterator, TEdgeDescriptor > TEdgeIterator;

        TALGraph() {
        }

        TVertexDescriptor AddVertex(const T& v) {
            Vertices.push_back(v);
            AdjLists.push_back( TAdjList() );
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

        std::pair< TVertexIterator, TVertexIterator > GetVertices() const {
            return std::make_pair( TVertexIterator(0), TVertexIterator(Vertices.size()) );
        }

        std::pair< TEdgeIterator, TEdgeIterator > GetEdges() const {
            const int lastIndex = AdjLists.size() - 1;
            return std::make_pair(  TEdgeIterator(AdjLists, 0, AdjLists[0].begin()),
                                    TEdgeIterator(AdjLists, lastIndex + 1, AdjLists[lastIndex].end())   );
        }
    };
}; // namespace NGraphLib
