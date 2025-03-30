#include <vector>
#include <algorithm>
#include "Union_find.cpp"

// Representa uma aresta
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

std::vector<Edge> kruskal(int n, std::vector<Edge>& edges) {
    UnionFind uf(n);
    std::vector<Edge> mst;  
    
    // Ordena as arestas pelo peso (menor para o maior)
    std::sort(edges.begin(), edges.end());

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // Se os vértices 'u' e 'v' não estão no mesmo conjunto, adicionamos a aresta
        // Pois não estão conectados por nenhum ponto, mas a aresta que estamos avaliando é
        // a menor por hipótese
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mst.push_back(edge);  
            // Se já tivermos n-1 arestas, a MST está completa
            if (mst.size() == n - 1) {
                break;
            }
        }
    }
    return mst;
}

