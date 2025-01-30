#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int R, K;

    while (cin >> R >> K) {
        vector<int> grau(R, 0);  // Vetor de grau das regiões

        // Lendo as pontes e atualizando os graus das regiões
        for (int i = 0; i < K; i++) {
            int A, B;
            cin >> A >> B;
            grau[A-1]++;
            grau[B-1]++;
        }

        int target = K;

        bitset<10001> dp;  
        dp[0] = 1;  

        // Processando cada grau
        for (int i = 0; i < R; i++) {
            dp |= (dp << grau[i]);  
        }
        

        cout << (dp[target] ? "S" : "N") << endl;
    }

    return 0;
}
