#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>


void exibirordenado(std::map<int, int>& media_pessoa, std::string& saida){
    bool first = true;
    for (const auto& entry : media_pessoa) {
        if (!first) {
          saida.append(" ");
        }
        saida.append(std::to_string(entry.second) + "-" + std::to_string(entry.first));
        first = false;
    }
    saida.append("\n");
}

int main(){

  int cidade = 1;
  std::vector<std::string> saidas; 

  while (1){

    int N;
    std::cin>>N;
    if(N == 0) break;
    std::map<int, int> media_pessoa; //map com a média e com o número de pessoas.
    
    long int total_pessoas = 0, total_consumo = 0;

    for(int i=0; i<N; i++){
      int X, Y;
      std::cin>>X>>Y;
      int media = (int) Y/X;
      if(media_pessoa.find(media) == media_pessoa.end()){
        media_pessoa[media] = X;
      }
      else {
        media_pessoa[media]+=X;
      }
      total_pessoas+=X;
      total_consumo+=Y;
    }

    std::string saida = "Cidade# " + std::to_string(cidade++) + ":\n";
    exibirordenado(media_pessoa, saida);

    double consumo_medio = static_cast<double>(total_consumo) / total_pessoas;
    consumo_medio = floor(consumo_medio * 100) / 100.0; // Truncar para duas casas decimais
    char buffer[100];
    sprintf(buffer, "Consumo medio: %.2lf m3.\n\n", consumo_medio);

    saida.append(buffer);

    saidas.push_back(saida);
  }
  for (const std::string& s : saidas) {
    std::cout << s;
  }

  return 0;
}
