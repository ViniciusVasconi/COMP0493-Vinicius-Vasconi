from collections import deque

class Dinic:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0] * vertices for _ in range(vertices)]  # Matriz de adjacência

    def add_edge(self, u, v, capacity):
        """Adiciona uma aresta ao grafo (e cria a aresta reversa com capacidade 0)"""
        self.graph[u][v] = capacity  # Capacidade original
        self.graph[v][u] = 0  # Aresta reversa inicial

    def bfs(self, source, sink, level):
        """Construção dos níveis do grafo residual via BFS"""
        queue = deque([source])
        level[source] = 0

        while queue:
            u = queue.popleft()
            for v in range(self.V):
                if level[v] == -1 and self.graph[u][v] > 0:  # Existe caminho e não visitado
                    level[v] = level[u] + 1
                    queue.append(v)

        return level[sink] != -1  # Retorna True se o sink for alcançável

    def dfs(self, u, flow, sink, level, start):
        """Encontra e envia fluxo nos caminhos disponíveis"""
        if u == sink:
            return flow  # Chegamos ao destino, retornamos o fluxo

        while start[u] < self.V:
            v = start[u]
            if level[v] == level[u] + 1 and self.graph[u][v] > 0:
                min_flow = min(flow, self.graph[u][v])
                pushed = self.dfs(v, min_flow, sink, level, start)

                if pushed > 0:
                    self.graph[u][v] -= pushed  # Reduzimos no grafo residual
                    self.graph[v][u] += pushed  # Criamos fluxo reverso
                    return pushed  # Fluxo encontrado

            start[u] += 1  # Tentamos a próxima aresta

        return 0  # Nenhum fluxo possível

    def max_flow(self, source, sink):
        """Executa o algoritmo de Dinic para encontrar o fluxo máximo"""
        total_flow = 0

        while True:
            level = [-1] * self.V  # Inicializa os níveis
            if not self.bfs(source, sink, level):  # Se não há mais caminhos, paramos
                break

            start = [0] * self.V  # Array para controlar progresso na DFS
            while True:
                flow = self.dfs(source, float('Inf'), sink, level, start)
                if flow == 0:
                    break
                total_flow += flow

        return total_flow  # Retorna o fluxo máximo encontrado


