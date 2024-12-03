#include <iostream>

void lerEntrada(std::string& entrada, int &valor, int &k){
  for (auto& caracter : entrada){
    if (std::isdigit(caracter)){
      valor = valor*10 + (caracter -'0');
    }
    else k++;
  }
}

void calcularFacK(int& valor, int& k,long int& fac_k){
  while (valor>=1){
    fac_k *= valor;
    valor-=k;
  }
}

int main () {

  int numero_entradas;

  std::cin >> numero_entradas;

  for (int i = 0; i<numero_entradas;i++){

    long int fac_k = 1;
    int valor = 0;
    int k = 0;

    std::string entrada;
    std::cin >> entrada;

    lerEntrada(entrada, valor, k);
    calcularFacK(valor, k, fac_k);
    std::cout << fac_k << std::endl;
  }

  return 0;
} 
