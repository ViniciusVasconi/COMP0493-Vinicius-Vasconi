#include <iostream>
#include <vector>

using namespace std;

int binomialCoefficient_recursive(int n, int k){
  if(n == k || k == 0) return 1;
  // Usa a relação de recorrência
  return (binomialCoefficient_recursive(n-1,k-1) + binomialCoefficient_recursive(n-1,k));
}

int binomialCoefficient_dynamic(int n, int k) {
    // Usa um vetor de tamanho (k+1) para armazenar a linha atual
    vector<int> dp(k + 1, 0);
    dp[0] = 1; // C(n, 0) = 1

    for (int i = 1; i <= n; i++) {
        // Preenche de trás para frente para evitar sobrescrever valores necessários
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1]; // Relação de recorrência
        }
    }

    return dp[k];
}

int main() {
    int n , k;
    cin >> n >> k; 
    cout << "C(" << n << ", " << k << ") = " << binomialCoefficient_dynamic(n, k) << endl;
    cout << "C(" << n << ", " << k << ") = " << binomialCoefficient_recursive(n, k) << endl;
    return 0;
}
