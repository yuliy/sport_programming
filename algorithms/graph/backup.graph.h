#pragma once

#include <vector>
#include <list>

namespace NGraphLib {
    template<typename T, typename TGraphType >
    class TALGVertexDescriptor {
    private:
        TGraphType *Graph;
        int Index;

        //friend class TGraphType;
    public:
        TALGVertexDescriptor()
            : Graph(0)
            , Index(-1) {
        }

        TALGVertexDescriptor(TGraphType &g, int index)
            : Graph(&g)
            , Index(index) {
        }

        T& Get() {
            return Graph->Vertices[Index];
        }

        const T& Get() const {
            return Graph->Vertices[Index];
        }
    };

    template<typename T, typename TGraphType >
    class TALGEdgeDescriptor {
    private:
        TGraphType *Graph;
        int FromIndex;
        int ToIndex;

        //friend class TGraphType;
    public:
        TALGEdgeDescriptor()
            : Graph(0)
            , FromIndex(-1)
            , ToIndex(-1) {
        }

        TALGEdgeDescriptor(TGraphType &g, int fromIndex, int toIndex)
            : Graph(&g)
            , FromIndex(fromIndex)
            , ToIndex(index) {
        }

        T& From() {
            return Graph->Vertices[FromIndex];
        }

        const T& From() const {
            return Graph->Vertices[FromIndex];
        }

        T& To() {
            return Graph->Vertices[ToIndex];
        }

        const T& To() const {
            return Graph->Vertices[ToIndex];
        }
    };

    template<typename T>
    class TALGraph {
    private:
        typedef std::vector<T> TVertices;
        typedef std::list<int> TAdjList;
        typedef std::list< TAdjList > TAdjLists;

        friend class TALGVertexDescriptor<T, TALGraph<T> >;
        friend class TALGEdgeDescriptor<T, TALGraph<T> >;
    private:
        TVertices Vertices;
        TAdjLists AdjLists;
    public:
        typedef TALGVertexDescriptor<T, TALGraph<T> > TVertexDescriptor;
        typedef TALGEdgeDescriptor<T, TALGraph<T> > TEdgeDescriptor;

        TALGraph() {
        }

        TVertexDescriptor AddVertex(const T& v) {
            Vertices.push_back(v);
            return TVertexDescriptor(*this, Vertices.size() - 1);
        }

        TEdgeDescriptor AddEdge(TVertexDescriptor from, TVertexDescriptor to) {
            //
        }

        bool CheckEdge(TVertexDescriptor from, TVertexDescriptor to) {
            //
        }


    };
}; // namespace NGraphLib
