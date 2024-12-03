#include <iostream>
#include <map>

void calcularGramasTotais(int& qDiferente, int& gTotais){

  std::map<int,int> tipo_grama;
  int tipo_aux, grama_aux;

  for (int i = 0; i<qDiferente; i++){
    std::cin >> tipo_aux >> grama_aux;

    if (grama_aux >= 10 && grama_aux <= 100){
      if(tipo_grama.find(tipo_aux) == tipo_grama.end() || tipo_grama[tipo_aux] < grama_aux){
        tipo_grama[tipo_aux] = grama_aux;
      }
    }
  }
  for (auto&tipo : tipo_grama){
    gTotais+=tipo.second;
  }
}


int main () {
  
  int quantidade_testes = 0;
  std::cin >> quantidade_testes;

  for(int i = 0; i<quantidade_testes; i++){

    int total_gramas = 0;
    int quantidade_diferente;
    std::cin >> quantidade_diferente;
    calcularGramasTotais(quantidade_diferente, total_gramas);
    std::cout << total_gramas << std::endl;

  }
  return 0;
} 
