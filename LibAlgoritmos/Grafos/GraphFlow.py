from collections import deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices  # Número de vértices
        self.graph = [[0] * vertices for _ in range(vertices)]  # Matriz de adjacência (capacidade)
    
    def add_edge(self, u, v, capacity):
        """ Adiciona uma aresta direcionada com capacidade """
        self.graph[u][v] = capacity

    def bfs(self, source, sink, parent):
        """ Executa BFS para encontrar um caminho aumentante no grafo residual """
        visited = [False] * self.V
        queue = deque([source])
        visited[source] = True
        
        while queue:
            u = queue.popleft()
            for v in range(self.V):
                if not visited[v] and self.graph[u][v] > 0:  # Aresta com capacidade restante
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u
                    if v == sink:  # Se alcançar o sink, encontrou um caminho aumentante
                        return True
        return False

    def dfs(self, source, sink, parent):
        """ Executa DFS para encontrar um caminho aumentante no grafo residual """
        visited = [False] * self.V
        stack = [(source, None)]  # (nó, pai)
        
        while stack:
            u, u_parent = stack.pop()
            if visited[u]:
                continue
            visited[u] = True
            parent[u] = u_parent  # Atualiza o pai apenas quando o nó é visitado
            
            if u == sink:
                return True  # Caminho aumentante encontrado
            
            for v in range(self.V):
                if not visited[v] and self.graph[u][v] > 0:  # Aresta com capacidade residual
                    stack.append((v, u))  # Empilha (vizinho, nó atual como pai)
        
        return False  # Não encontrou caminho até o sink


    def FordFulkerson(self, source, sink):
        """ Implementa o algoritmo Ford-Fulkerson usando BFS (Edmonds-Karp) """
        parent = [-1] * self.V
        max_flow = 0

        while self.dfs(source, sink, parent):
            # Encontra a capacidade mínima do caminho aumentante encontrado
            path_flow = float("Inf")
            v = sink
            while v != source:
                u = parent[v]
                path_flow = min(path_flow, self.graph[u][v])
                v = parent[v]

            # Atualiza as capacidades residuais das arestas e reversas
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

            max_flow += path_flow

        return max_flow

    def EdmonsKarp(self, source, sink):
        """ Implementa o algoritmo Ford-Fulkerson usando BFS (Edmonds-Karp) """
        parent = [-1] * self.V
        max_flow = 0

        while self.bfs(source, sink, parent):
            # Encontra a capacidade mínima do caminho aumentante encontrado
            path_flow = float("Inf")
            v = sink
            while v != source:
                u = parent[v]
                path_flow = min(path_flow, self.graph[u][v])
                v = parent[v]

            # Atualiza as capacidades residuais das arestas e reversas
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

            max_flow += path_flow

        return max_flow



