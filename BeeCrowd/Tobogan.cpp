#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int L, H;

// Função para calcular a distância de um ponto P até um segmento AB.
// Se a projeção de P na reta definida por A e B cai fora do segmento,
// retorna a distância até o endpoint mais próximo.
double pontoParaSegmento(const pair<double, double> &P, const pair<double, double> &A, const pair<double, double> &B) {
    double ABx = B.first - A.first;
    double ABy = B.second - A.second;
    double APx = P.first - A.first;
    double APy = P.second - A.second;
    double AB2 = ABx * ABx + ABy * ABy;
    double t = (APx * ABx + APy * ABy) / AB2;
    
    if(t < 0.0) { // P projeta fora, antes de A
        return sqrt((P.first - A.first) * (P.first - A.first) + (P.second - A.second) * (P.second - A.second));
    }
    if(t > 1.0) { // P projeta fora, depois de B
        return sqrt((P.first - B.first) * (P.first - B.first) + (P.second - B.second) * (P.second - B.second));
    }
    // P projeta dentro do segmento: calcula a distância da projeção até P.
    double proj_x = A.first + t * ABx;
    double proj_y = A.second + t * ABy;
    return sqrt((P.first - proj_x) * (P.first - proj_x) + (P.second - proj_y) * (P.second - proj_y));
}

int main() {
    
    int numero_aletas;
    while (cin >> numero_aletas) {
        cin >> L >> H;
        double diametro_minimo = (double)L;
        
        // Vetores para armazenar parâmetros de cada aleta:
        // endpoints: fim da aleta (x_f, y_f) em ponto de dupla precisão;
        // starts: valor y do início da aleta.
        vector<pair<double, double>> endpoints;
        vector<int> starts;
        
        // A lógica para inclinação e intercepto não é necessária para a distância até o segmento,
        // pois vamos trabalhar diretamente com os endpoints e os pontos de início.
        for (int i = 0; i < numero_aletas; i++) {
            int y_i, x_f, y_f;
            cin >> y_i >> x_f >> y_f;
            endpoints.push_back({(double)x_f, (double)y_f});
            starts.push_back(y_i);
        }
        
        // Para cada transição (de aleta i para aleta i+1)
        for (int i = 0; i < numero_aletas - 1; i++) {
            // Clearance horizontal: se a aleta atual é da esquerda, gap = L - x_end; se direita, gap = x_end.
            bool currentIsLeft = (i % 2 == 0);
            double horizontal_gap = currentIsLeft ? (L - endpoints[i].first) : endpoints[i].first;
            
            // Para a aleta seguinte (i+1), definimos os pontos que definem o segmento.
            // Se a aleta i+1 for da esquerda, seu início é (0, starts[i+1]) e o fim é o endpoint.
            // Se for da direita, seu início é (L, starts[i+1]) e o fim é o endpoint.
            pair<double, double> A, B;
            if ((i+1) % 2 == 0) { 
                A = {0.0, (double)starts[i+1]};
                B = endpoints[i+1];
            } else {
                A = {(double)L, (double)starts[i+1]};
                B = endpoints[i+1];
            }
            
            // P é o endpoint da aleta atual (o ponto de transição).
            pair<double, double> P = endpoints[i];
            
            // Calcula a distância mínima de P até o segmento da aleta i+1.
            double dist_segment = pontoParaSegmento(P, A, B);
            
            // O clearance para essa transição é o menor entre o gap horizontal e a distância calculada.
            double clearance = min(horizontal_gap, dist_segment);
            diametro_minimo = min(diametro_minimo, clearance);
        }
        
        // Para a última aleta, não há transição; usa-se o gap horizontal até a haste oposta.
        int lastIndex = numero_aletas - 1;
        bool lastIsLeft = (lastIndex % 2 == 0);
        double last_gap = lastIsLeft ? (L - endpoints[lastIndex].first) : endpoints[lastIndex].first;
        diametro_minimo = min(diametro_minimo, last_gap);
        
        // Arredonda corretamente para duas casas decimais.
        diametro_minimo = round(diametro_minimo * 100) / 100.0;
        printf("%.2lf\n", diametro_minimo);
    }
    
    return 0;
}
