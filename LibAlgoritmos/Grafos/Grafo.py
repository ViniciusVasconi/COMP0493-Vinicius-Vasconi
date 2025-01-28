import random
from collections import deque

class Grafo:
    def __init__(self, v):
        self.v = v
        self.adjacentMatrix = [[0 for _ in range(v)] for _ in range(v)]

    def __str__(self):
        return "\n".join(" ".join(map(str, row)) for row in self.adjacentMatrix)

    def gerar_matriz_adj(self):
        for i in range(self.v):
            for j in range(i + 1, self.v):  # Garante que a matriz seja simétrica
                aresta = random.choice([0, 1])
                self.adjacentMatrix[i][j] = aresta
                self.adjacentMatrix[j][i] = aresta  # Para grafos não direcionados

    def DFS(self, start):
        visited = set()  # Usa um conjunto para armazenar nós visitados
        stack = [start]  # Pilha para DFS (LIFO)

        while stack:
            node = stack.pop()  # Remove o último elemento (LIFO)
            
            if node not in visited:  # Evita visitar um nó mais de uma vez
                print(node, end=" -> ")
                visited.add(node)

                # Adiciona os vizinhos não visitados na pilha
                for i in range(self.v):  # Percorre na ordem natural
                    if self.adjacentMatrix[node][i] == 1 and i not in visited:
                        stack.append(i)
        print("FIM")


    def BFS(self, start):
        visited = [False] * self.v
        queue = deque([start])  # Fila para BFS (FIFO)

        while queue:
            node = queue.popleft()  # Remove o primeiro elemento (FIFO)

            if visited[node]:
                continue  # Se já foi visitado, pula para o próximo

            print(node, end=" -> ")
            visited[node] = True

            # Adiciona os vizinhos não visitados na fila
            for i in range(self.v):  
                if self.adjacentMatrix[node][i] == 1 and not visited[i]:
                    queue.append(i)  

        print("FIM")

def GerarGrafos(numeroGrafos=5, numVerticesMax=20):
    return [Grafo(random.randint(10, numVerticesMax)) for _ in range(numeroGrafos)]  # Retorna uma lista concreta

# Gera grafos aleatórios
grafos = GerarGrafos()

# Inicializa as matrizes de adjacência
for grafo in grafos:
    grafo.gerar_matriz_adj()

# Executa DFS em cada grafo a partir do vértice 0 (se existir)
for idx, grafo in enumerate(grafos):
    print(" ".join(chr(c) for c in range(ord('a'), ord('a') + grafo.v)))
    print(grafo)
    print(f"\nDFS no Grafo {idx + 1}:")
    grafo.DFS(0)
    print(f"\nBFS no Grafo {idx + 1}:")
    grafo.BFS(0)
    print()
