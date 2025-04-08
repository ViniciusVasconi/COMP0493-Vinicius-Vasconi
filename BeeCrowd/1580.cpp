#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

#define MOD 1000000007

unordered_map<int, long long> fatLUT = {
    {0, 1},
    {1, 1}
};

// Função para calcular fatorial com memoização
long long fatorial(int n) {
    if (fatLUT.count(n)) return fatLUT[n];

    int start = n - 1;
    while (start > 1 && !fatLUT.count(start))
        --start;

    long long resultado = fatLUT[start];
    for (int i = start + 1; i <= n; ++i)
        resultado = fatLUT[i] = (resultado * i) % MOD;

    return resultado;
}

// Função para calcular a^b % MOD (exponenciação rápida)
long long modpow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Inverso modular de x modulo MOD
long long modinv(long long x) {
    return modpow(x, MOD - 2);
}

int main() {
    string palavra;
    while (cin >> palavra) {
        unordered_map<char, int> quantidade_letra;

        for (char letra : palavra)
            quantidade_letra[letra]++;

        int n = palavra.size();
        long long numerador = fatorial(n);

        long long denominador = 1;
        for (auto [letra, qtd] : quantidade_letra)
            denominador = (denominador * fatorial(qtd)) % MOD;

        long long resultado = (numerador * modinv(denominador)) % MOD;
        cout << resultado << endl;
    }

    return 0;
}

