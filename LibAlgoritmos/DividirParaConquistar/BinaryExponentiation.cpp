#include <iostream>
#include <concepts>
#include <cmath>

template <typename T>
requires std::integral<T> || std::floating_point<T>
T BinaryExpo(T & a, int b){
  if(b==1) return a; 
  if(b==0) return 1;
  if(b%2 == 0) return pow(BinaryExpo(a,b/2),2);
  return a * pow(BinaryExpo(a,b/2),2);
}

int main (){
  float a;
  int b;
  while(1){
  std::cin >> a;
  std::cin >> b; 
  auto c = BinaryExpo(a, b);
  std::cout << c << std::endl;}
  return 0;
}
