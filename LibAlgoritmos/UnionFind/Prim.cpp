#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // pii == pair int int, nesse caso "{peso, vertice}"

vector<int> prim(int n, vector<vector<pii>> &adj, int raiz) {
    vector<int> key(n, numeric_limits<int>::max());      // Peso mínimo para chegar no vértice
    vector<int> parent(n, -1);                           // Árvore geradora mínima
    vector<bool> visited(n, false);                      // Para verificar se o vértice já foi incluído
    priority_queue<pii, vector<pii>, greater<pii>> pq;   // Min-heap
    
    key[raiz] = 0;
    pq.push({0, raiz});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto &[peso, v] : adj[u]) {
            if (!visited[v] && peso < key[v]) {
                key[v] = peso;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    return parent; // Retorna a MST na forma de vetor de pais
}

