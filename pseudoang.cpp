#include <iostream>
#include <ctime>
#include "sort.h"
#include "pseudoangulo.h"
using namespace std;

std::clock_t start;

// Driver para testar os algoritmos ------------------------------------------------------
int main(){

   // Ponto do vetor a
   int x1 = 0;
   int y1 = -1;

   // pseudoangulo(a) - vetor a
   start = std::clock();
   int resultado1 = pseudoang(x1, y1);
   std::cout << "Tempo do pseudoangulo a: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
   std::cout << "pseudoangulo(a): " << resultado1 << "\n";

   // Ponto do vetor b
   int x2 = 1;
   int y2 = 0;

    // pseudoangulo(b) - vetor b
   start2 = std::clock();
   int resultado2 = pseudoang(x2, y2);
   std::cout << "Tempo do pseudoangulo b: " << (std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
   std::cout << "pseudoangulo(b): " << resultado2 << "\n";

   // pseudoangulo(a, b)
   int resultado = resultado1 - resultado2;

    std::cout << "pseduoangulo(a,b): " << resultado << "\n";

    // a a direita ou a esquerda de b 
    if (resultado1 > resultado2){
         std::cout << "a esta a esquerda de b";
    } else {
         std::cout << "a esta a direita de b";
    }

    cin.get();
    return 0;
}
// Driver para testar os algoritmos ------------------------------------------------------