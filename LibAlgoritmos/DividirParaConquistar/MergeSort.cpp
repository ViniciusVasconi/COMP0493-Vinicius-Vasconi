#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

/*
 *   i1                        i2                   i3
 * [(a,     b,     c,     d), (e,     f,     g,     h) ...]
 */


template <typename S>
requires std::totally_ordered<S>
void merge(std::vector<S> &array, int i1, int i2, int i3){
  std::vector<S> temp(i3 - i1 + 1);      //tamanho do intervalo := final - inicial + 1
  int inf1 = i1, inf2 = i2, sup = i3, contador = 0;
  while(inf1 < i2 && inf2 <= i3){
    if(array[inf1] <= array[inf2]) temp[contador++] = array[inf1++];
    else                           temp[contador++] = array[inf2++];
  }
  while(inf1 < i2) temp[contador++] = array[inf1++];  // Copio os valores do primeiro intervalo
  while(inf2 <= i3) temp[contador++] = array[inf2++]; // Copio os valores do segundo
  
  for (int i = 0; i < temp.size(); i++) array[i1 + i] = temp[i];// Transcrevo os valores de temp para o array original 
}

template <typename T>
requires std::totally_ordered<T>
void MergeSort(T & array){
  int n = array.size();
  for(int passo = 1; passo < n; passo *= 2){
    for(int i1 = 0; i1 < n - passo; i1 += 2*passo){
      int i2 = i1 + passo;                        // indice inicial do segundo grupo
      int i3 = std::min(n-1, i1 + 2*passo - 1);   // para garantir que o indice final esteja dentro do intervalo
      merge(array, i1, i2, i3);
    }
  }
}



int main(){
  std::vector<int> arr = {18, 12, 17, 20, 27, 4, 9, 50, 3, 1, 304, 5, 3, 5, 6, 2, 5, 1, 0};

  std::cout << "Array original:\n";
  for (int num : arr) std::cout << num << " ";
  std::cout << std::endl;

  MergeSort(arr);

  std::cout << "Array ordenado:\n";
  for (int num : arr) std::cout << num << " ";
  std::cout << std::endl;
  return 0;
}
