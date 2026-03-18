#include "Polynomial.h"
#include <cmath>
#include <iostream>
#include <string>

int main() {
  Polynomial p1, p2;
  int choice;

  while (true) {
    std::cout << "\n          MENU          \n";
    std::cout << "1. Input first polynomial (P1)\n";
    std::cout << "2. Input second polynomial (P2)\n";
    std::cout << "3. Addition (P1 + P2)\n";
    std::cout << "4. Polynomial Multiplication (P1 * P2)\n";
    std::cout << "5. Scalar Multiplication (P1 * k)\n";
    std::cout << "6. Show current polynomials\n";
    std::cout << "0. Exit\n";

    if (!(std::cin >> choice)) {
      std::cout << "Please enter a number between 0 and 6.\n";
      std::cin.clear();
      continue;
    }

    switch (choice) {
    case 1:
      p1 = Polynomial();
      std::cout << "\nInput P1\n";
      inputPolynomial(p1);
      break;

    case 2:
      p2 = Polynomial();
      std::cout << "\nInput P2\n";
      inputPolynomial(p2);
      break;

    case 3: {
      std::cout << "\nResult (P1 + P2): ";
      (p1 + p2).print();
      break;
    }

    case 4: {
      std::cout << "\nResult (P1 * P2): ";
      (p1 * p2).print();
      break;
    }

    case 5: {
      double k;
      std::cout << "Enter scalar (k): ";
      if (!(std::cin >> k)) {
        std::cout << "Invalid scalar!\n";
        std::cin.clear();
      } else {
        std::cout << "Result (P1 * " << k << "): ";
        (p1 * k).print();
        std::cout << "Result (P2 * " << k << "): ";
        (p2 * k).print();
      }
      break;
    }

    case 6:
      std::cout << "\nCurrent Polinoms\n";
      std::cout << "P1: ";
      p1.print();
      std::cout << "P2: ";
      p2.print();
      break;

    case 0:
      std::cout << "Goodbye!\n";
      return 0;
    }
  }
  return 0;
}