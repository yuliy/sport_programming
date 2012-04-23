#pragma once

#include <vector>
#include <list>
#include <deque>

namespace NGraphLib {
    /// Graph Descriptors

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

    /// Graph Iterators

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

    template<typename TListVertexIter, typename TVDescriptorType >
    class TALGAdjVertexIterator {
    private:
        TALGAdjVertexIterator();
    private:
        TListVertexIter Iter;
    public:
        TALGAdjVertexIterator(TListVertexIter iter)
            : Iter(iter) {
        }

        TVDescriptorType operator*() const {
            return TVDescriptorType(*Iter);
        }

        TALGAdjVertexIterator &operator++() {
            ++Iter;
        }

        bool operator==(const TALGAdjVertexIterator &other) const {
            return Iter == other.Iter;
        }

        bool operator!=(const TALGAdjVertexIterator &other) const {
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

    /// Graph Classes

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
        typedef T TVertex;

        typedef TALGVertexDescriptor<T> TVertexDescriptor;
        typedef TALGEdgeDescriptor<T> TEdgeDescriptor;

        typedef TALGVertexIterator<TVertexDescriptor > TVertexIterator;
        typedef TALGEdgeIterator<TAdjLists, TAdjList::const_iterator, TEdgeDescriptor > TEdgeIterator;
        typedef TALGAdjVertexIterator<TAdjList::const_iterator, TVertexDescriptor > TAdjVertexIterator;

        template<typename TVDescriptor, typename TProperty >
        class TVertexPropertyMap {
        private:
            TVertexPropertyMap();
            explicit TVertexPropertyMap(int verticesCount, TProperty defaultValue)
                : Properties(verticesCount, defaultValue) {
            }

            friend class TALGraph<T>;
        private:
            typedef std::deque<TProperty> TProperties;
            TProperties Properties;
        public:
        };

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

        bool CheckEdge(TVertexDescriptor from, TVertexDescriptor to) const {
            const TAdjList &l = AdjLists[from.Index];
            for (TAdjList::const_iterator iter = l.begin(), end = l.end(); iter != end; ++iter)
                if (*iter == to.Index)
                    return true;
            return false;
        }

        std::pair< TVertexIterator, TVertexIterator > GetVertices() const {
            return std::make_pair(  TVertexIterator(0),
                                    TVertexIterator(Vertices.size()) );
        }

        std::pair< TEdgeIterator, TEdgeIterator > GetEdges() const {
            const int lastIndex = AdjLists.size() - 1;
            return std::make_pair(  TEdgeIterator(AdjLists, 0, AdjLists[0].begin()),
                                    TEdgeIterator(AdjLists, lastIndex + 1, AdjLists[lastIndex].end())   );
        }

        std::pair< TAdjVertexIterator, TAdjVertexIterator > GetAdjVertices(TVertexDescriptor d) const {
            const TAdjList &l = AdjLists[d.Index];
            return std::make_pair(  TAdjVertexIterator(l.begin()),
                                    TAdjVertexIterator(l.end()) );
        }

        template<typename TProperty >
        TVertexPropertyMap<TVertexDescriptor, TProperty > CreateVertexPropertyMap(TProperty defaultValue = TProperty()) const {
            return TVertexPropertyMap<TVertexDescriptor, TProperty>(Vertices.size(), defaultValue);
        }

        template<typename TProperty >
        TProperty &GetVertexProperty(TVertexPropertyMap<TVertexDescriptor, TProperty> &vpMap, TVertexDescriptor vd) const {
            return vpMap.Properties[vd.Index];
        }

        template<typename TProperty >
        const TProperty &GetVertexProperty(const TVertexPropertyMap<TVertexDescriptor, TProperty> &vpMap, TVertexDescriptor vd) const {
            return vpMap.Properties[vd.Index];
        }

    };

    /// Algorithms

    template<typename TGraphType, typename TBFSHandlerType >
    void BFS(const TGraphType &g, TBFSHandlerType &h) {
        std::pair< typename TGraphType::TVertexIterator,
                    typename TGraphType::TVertexIterator > vIters = g.GetVertices();

        typedef std::vector< typename TGraphType::TVertexDescriptor > TVDescriptors;
        TVDescriptors vdescriptors;
        for (; vIters.first != vIters.second; ++(vIters.first))
            vdescriptors.push_back(*(vIters.first));

        typedef typename TGraphType::template TVertexPropertyMap< typename TGraphType::TVertexDescriptor, bool > TVPMap;
        TVPMap exploredMap = g.CreateVertexPropertyMap(false);

        typedef std::deque< typename TGraphType::TVertexDescriptor > TVQueue;
        TVQueue q;
        q.push_back(vdescriptors.front());
        h.DiscoverVertex(0, vdescriptors.front());
        g.GetVertexProperty(exploredMap, vdescriptors.front()) = true;

        while (!q.empty()) {
            typename TGraphType::TVertexDescriptor vd = q.front();
            q.pop_front();

            std::pair< typename TGraphType::TAdjVertexIterator,
                        typename TGraphType::TAdjVertexIterator > adjIters = g.GetAdjVertices(vd);
            for (; adjIters.first != adjIters.second; ++(adjIters.first)) {
                typename TGraphType::TVertexDescriptor ud = *(adjIters.first);
                if (g.GetVertexProperty(exploredMap, ud) == false) {
                    h.DiscoverVertex(&vd, ud);
                    q.push_back(ud);
                    g.GetVertexProperty(exploredMap, ud) = true;
                }
            }
        }
    }
}; // namespace NGraphLib
