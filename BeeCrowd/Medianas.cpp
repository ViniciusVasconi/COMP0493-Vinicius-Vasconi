#include <cmath>
#include <iomanip>
#include <iostream>

double area_medianas(double ma, double mb, double mc) {
  double sm = (ma + mb + mc) / 2.0;
  double termo = sm * (sm - ma) * (sm - mb) * (sm - mc);
  if (termo < 0)
    return -1.00;
  return (4.0 / 3.0) * std::sqrt(termo);
}

int main() {
  double m1, m2, m3;

  while (std::cin >> m1 >> m2 >> m3) {
    std::cout << std::fixed << std::setprecision(3);

    if (m1 + m2 > m3 && m1 + m3 > m2 && m2 + m3 > m1) {
      double area = area_medianas(m1, m2, m3);
      std::cout << area << std::endl;
    } else {
      std::cout << -1.00 << std::endl;
    }
  }

  return 0;
}
