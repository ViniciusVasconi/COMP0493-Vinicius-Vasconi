#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>

// Identificador do motorista, horário, e tipo de evento (entrada ou saída)
using tuplaCarro = std::tuple<int, int, bool>; // (motorista, horário, entrada=true/saída=false)
struct Comparador {
    bool operator()(const tuplaCarro& a, const tuplaCarro& b) {
        if (std::get<1>(a) == std::get<1>(b)) {
            return std::get<2>(a) > std::get<2>(b); // Saídas têm prioridade em caso de empate no horário
        }
        return std::get<1>(a) > std::get<1>(b); // Ordem crescente por horário
    }
};
using estacionamento = std::priority_queue<tuplaCarro, std::vector<tuplaCarro>, Comparador>;

bool verificar_validade(estacionamento& park, long int capacidade) {
    std::stack<int> pilha;
    int carros_no_estacionamento = 0; // Número de carros no estacionamento

    while (!park.empty()) {
        auto evento = park.top();
        park.pop();

        int motorista = std::get<0>(evento);
        bool entrada = std::get<2>(evento);

        if (entrada) {
            // Verifica capacidade antes de adicionar
            if (carros_no_estacionamento >= capacidade) {
                return false; // Estacionamento cheio
            }
            pilha.push(motorista);
            carros_no_estacionamento++;
        } else {
            // Verifica se a ordem de saída é válida
            if (pilha.empty() || pilha.top() != motorista) {
                return false; // Ordem de saída inválida
            }
            pilha.pop();
            carros_no_estacionamento--;
        }
    }

    return pilha.empty(); // Pilha deve estar vazia no final
}

int main() {
    while (true) {
        long int N, K;
        std::cin >> N >> K;

        if (N == 0 && K == 0) break;

        estacionamento park;

        for (long int i = 0; i < N; i++) {
            int chegada, saida;
            std::cin >> chegada >> saida;

            park.push(std::make_tuple(i, chegada, true));  // Evento de entrada
            park.push(std::make_tuple(i, saida, false));   // Evento de saída
        }

        bool isValid = verificar_validade(park, K);
        std::cout << (isValid ? "Sim" : "Nao") << std::endl;
    }

    return 0;
}
