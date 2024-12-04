#include <iostream>
#include <map>


// ATENÇÃO: A solução a seguir não está escrita da maneira mais legível, espero que
//          ao menos os comentários sirvam de guia para melhor execução.

std::map<int,int> tipo_grama;

void calcularGramasTotais(int & total_gramas);
void preencherMap(int& qDiferente);

int main () {
  
  int quantidade_testes;
  std::cin >> quantidade_testes;

  for(int i = 0; i<quantidade_testes; i++){
    tipo_grama.clear();
    int total_gramas = 0;
    int quantidade_diferente;
    std::cin >> quantidade_diferente;
    preencherMap(quantidade_diferente);
    calcularGramasTotais(total_gramas);
    std::cout << total_gramas << std::endl;

  }
  return 0;
} 

bool dentroIntervalo(const int& a, const int& b, int& pos){
  bool isIN = (pos <= b && pos >= a)?true:false;
  return isIN;
}

void preencherMap(int& qDiferente){
  for (int i = 0; i<qDiferente; i++){
    int tipo_aux, grama_aux;
    std::cin >> tipo_aux >> grama_aux;
    
    //insere se não houver nenhum.
    if(tipo_grama.find(tipo_aux) == tipo_grama.end()){
      tipo_grama[tipo_aux] = grama_aux;
      continue;
    }

    int gramasLa = tipo_grama[tipo_aux];
    //quero inserir no intervalo
    if(dentroIntervalo(10, 100, grama_aux)){
      // o que está lá está no intervalo
      if(dentroIntervalo(10,100, gramasLa)){
        //mas o que tneho é maior, substitua.
        if(grama_aux > gramasLa)
           tipo_grama[tipo_aux] = grama_aux;
        // se não deixe como está.
        else continue;
      }
      //se quero inserir no intervalo, e o que tenho está fora, substitua
      else  tipo_grama[tipo_aux] = grama_aux;
    }
    //se quero inserir fora
    else {
       //e o que tenho está fora
       if(!dentroIntervalo(10, 100, gramasLa)) {
         //mas o que quero inserir é maior, substitua.
         if(grama_aux > gramasLa) tipo_grama[tipo_aux] = grama_aux;
         // se o que tenho, é maior, deixe como está.
         else continue;
       }
       //quero inserir fora, mas o que tneho está dentro, não faça nada.
       else continue;
    }
  }
}

void calcularGramasTotais(int& total_gramas){
  for (auto&tipo : tipo_grama){
    total_gramas+=tipo.second;
  }
}


