#include <iostream>
#include <vector>
#include <cmath>
#include <string>

std::string LCPrefix(std::vector<std::string>& array) {
    // Caso base: se o vetor contém apenas um elemento, retorna ele como prefixo
    if (array.size() == 1) return array[0];

    // Divide o vetor em duas partes
    int n = array.size();
    std::vector<std::string> ladoA(array.begin(), array.begin() + n / 2);
    std::vector<std::string> ladoB(array.begin() + n / 2, array.end());

    // Chamada recursiva
    std::string comum1 = LCPrefix(ladoA);
    std::string comum2 = LCPrefix(ladoB);

    // Calcula o prefixo comum entre os dois lados
    std::string comum = "";
    for (int i = 0; i < std::min(comum1.size(), comum2.size()); i++) {
        if (comum1[i] != comum2[i]) break;
        comum += comum1[i];
    }
    return comum;
}

int main() {
    std::vector<std::string> palavras = {"flor", "floresta", "florido", "florescer"};

    std::cout << "Palavras: ";
    for (const auto& palavra : palavras) {
        std::cout << palavra << " ";
    }
    std::cout << "\n";

    std::string prefixoComum = LCPrefix(palavras);
    std::cout << "Maior prefixo comum: " << prefixoComum << "\n";

    return 0;
}
