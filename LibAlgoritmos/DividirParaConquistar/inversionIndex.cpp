#include <iostream>
#include <vector>
#include <concepts>
#include <iterator> // Para std::next

template <typename T>
requires std::totally_ordered<T>
int inversionIndex(const std::vector<T>& array) {
    // Caso base: se o vetor contém um único elemento, não há inversões
    if (array.size() <= 1) return 0;

    // Sub-vetor que exclui o primeiro elemento
    std::vector<T> sub_array(array.begin() + 1, array.end());

    // Chamada recursiva para o sub-vetor
    int inversionAux = inversionIndex(sub_array);

    // Contabiliza as inversões para o elemento atual
    for (const auto& valor : sub_array) {
        if (array[0] > valor) inversionAux++;
    }

    return inversionAux;
}

int main() {
    // Caso de teste
    std::vector<int> arr = {5, 3, 2, 1, 4};

    std::cout << "Array original: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    int inversions = inversionIndex(arr);

    std::cout << "Número de inversões: " << inversions << "\n";

    return 0;
}
