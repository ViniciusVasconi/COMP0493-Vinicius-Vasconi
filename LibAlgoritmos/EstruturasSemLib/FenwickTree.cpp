#include <vector>
using namespace std;

inline int getLSB(int x) {
    return x & -x;
}

int prefixSum(int indice, const vector<int>& arr) {
    int sum = 0;
    while (indice > 0) {
        sum += arr[indice];
        indice -= getLSB(indice);
    }
    return sum;
}

int query(int indice_inicial, int indice_final, const vector<int>& arr) {
    return prefixSum(indice_final, arr) - prefixSum(indice_inicial - 1, arr);
}

void update(int indice, int newValue, vector<int>& arr) {
    while (indice < arr.size()) {  
        arr[indice] += newValue;
        indice += getLSB(indice);
    }
}

vector<int> build(const vector<int>& arr) {
    vector<int> fenwick(arr.size() + 1, 0);
    
    // Copia os valores 
    for (size_t i = 0; i < arr.size(); i++) 
        fenwick[i + 1] = arr[i];  

    // Gera propagação nas células dependentes
    for (size_t i = 1; i < fenwick.size(); i++) {
        size_t j = i + getLSB(i);
        if (j < fenwick.size()) {
            fenwick[j] += fenwick[i];
        }
    }

    return fenwick;
}

