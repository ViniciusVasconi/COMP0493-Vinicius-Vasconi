#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using substancia = std::string;
using potes = int;

std::vector<substancia> loadReaction(const std::string& reacao) {
    std::istringstream ss(reacao);
    std::vector<substancia> substancias;
    std::string subs;
    while (ss >> subs) {
        if (subs != "->" && subs != "+") {
            substancias.push_back(subs);
        }
    }
    return substancias;
}

void adicionarReacao(const std::string& reacao, std::map<substancia, potes>& ref_table, substancia& subs_final) {
    std::vector<substancia> substancias = loadReaction(reacao);

    // Garantir que temos valores iniciais no mapa para as substâncias
    for (int i = 0; i < 2; i++) {
        if (ref_table.find(substancias[i]) == ref_table.end()) {
            ref_table[substancias[i]] = 0;  // Inicializa com 0 se não estiver no mapa
        }
    }

    // Potes para as substâncias da reação
    int potes_para[2];
    for (int i = 0; i < 2; i++) {
        potes_para[i] = ref_table[substancias[i]];  // Usa o valor do mapa
    }

    // Calcula a quantidade de potes para a substância final

    if(potes_para[0] == potes_para[1])
     ref_table[substancias[2]] = potes_para[0]+1;
    else ref_table[substancias[2]] = std::max(potes_para[0], potes_para[1]);

    // Define a substância final da reação
    subs_final = substancias[2];
}

int main() {
    while (true) {
        int R;
        std::cin >> R;
        if (R == 0) break;  // Se R for 0, encerra a execução

        std::map<substancia, potes> ref_table;
        substancia subs_final;

        // Lê as reações e as processa
        std::cin.ignore();  // Para limpar o buffer após a leitura de R
        for (int i = 0; i < R; i++) {
            std::string reacao;
            std::getline(std::cin, reacao);  // Lê a linha inteira da reação
            adicionarReacao(reacao, ref_table, subs_final);
        }

        std::cout << subs_final << " requires " << ref_table[subs_final] << " containers" << std::endl;
    }

    return 0;
}
