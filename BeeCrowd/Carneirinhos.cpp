#include <iostream>
#include <set>

int main () {

  int casos_teste = 0;
  std::cin >> casos_teste;

  for(int i=0; i<casos_teste; i++){

    size_t tamanho_entrada=0;
    std::cin>>tamanho_entrada;

    std::set<long int> carneirinhos;
    
    for(size_t j = tamanho_entrada; j>0;j--){
      long int carneiro_n;
      std::cin >> carneiro_n;
      carneirinhos.insert(carneiro_n);
    }
    std::cout << carneirinhos.size() << std::endl;
  }
  
  return 0;
}
