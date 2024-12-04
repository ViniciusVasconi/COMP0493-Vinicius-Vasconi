#include <iostream>
#include <vector>
#include <string>

template <typename T>
void printNTimes (T elemento,const int& vezes){
  for(int i = 0; i < vezes; i++) std::cout << elemento <<std::endl;
}

template <typename T>
void addNTimes (std::vector<T>& imagem, T elemento,const int& vezes){
  for(int i = 0; i < vezes; i++)  imagem.push_back(elemento);
}

template <typename T>
void exibirImagem(std::vector<T>& imagem){
  for (auto& linha : imagem){
    std::cout << linha << std::endl;
  }
}


int main(){
  
  std::vector<std::vector<std::string>> imagens_criadas;

  while (true){

    int linhas, colunas;
    std::cin >> linhas >> colunas;
    //se a matriz for vazia não processamos.
    if(linhas == 0 || colunas == 0) break;

    std::vector<std::string> imagem(linhas);
    
    //preenchemos a imagem.
    for (int i = 0; i < linhas; i++){
      std::cin >> imagem[i];
    }

    int A, B;
    std::cin >> A >> B;

    int multiplicador_linhas = (int) A/linhas;
    int multiplicador_colunas = (int) B/colunas;


    //para cada linha do vetor
    std::vector<std::string> nova_imagem;
    for(auto& linha : imagem){
      std::string novaLinha = "";
      // Atualizamos a linha
      for(auto& caracter : linha)
        novaLinha.append(std::string(multiplicador_colunas, caracter));
      // Printamos essa nova linha quantas vezes o multiplicador exigir.
      addNTimes(nova_imagem, novaLinha, multiplicador_linhas);
    }
    imagens_criadas.push_back(nova_imagem);
  }

  for(auto& imagem : imagens_criadas){
    exibirImagem(imagem);
    std::cout << std::endl;
  }

  return 0;
}
