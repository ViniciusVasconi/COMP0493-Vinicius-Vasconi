from collections import deque

def main():
    num_entradas = int(input())  # Número de casos de teste

    for _ in range(num_entradas):
        Documentos, Dependencias = map(int, input().split())  # Número de documentos e dependências

        # Lista de adjacência para representar o grafo
        listaAdj = [[] for _ in range(Documentos + 1)]  # +1 para indexação baseada em 1

        # Ler as dependências e construir o grafo
        for _ in range(Dependencias):
            arquivoA, arquivoB = map(int, input().split())
            listaAdj[arquivoA].append(arquivoB)

        # Função para detectar ciclos usando DFS
        def tem_ciclo(v, visitado, em_processamento):
            visitado[v] = True
            em_processamento[v] = True

            for vizinho in listaAdj[v]:
                if not visitado[vizinho]:
                    if tem_ciclo(vizinho, visitado, em_processamento):
                        return True
                elif em_processamento[vizinho]:
                    return True

            em_processamento[v] = False
            return False

        # Verificar ciclos para cada componente do grafo
        visitado = [False] * (Documentos + 1)
        em_processamento = [False] * (Documentos + 1)
        cycle = False

        for i in range(1, Documentos + 1):
            if not visitado[i]:
                if tem_ciclo(i, visitado, em_processamento):
                    cycle = True
                    break

        print("SIM" if cycle else "NAO")

if __name__ == "__main__":
    main()
