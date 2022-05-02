#include <iostream>
#include <ctime>
#include <time.h>
#include "sort.h"
#include "pseudoangulo.h"
using namespace std;

std::clock_t start;
std::clock_t start4;

// Driver para testar os algoritmos ------------------------------------------------------
int main(){
   	int ptsx [] = {50, 42, 3, 9, 60, 80, 23, 12, 34, 5};
    int ptsy [] = {18, 6, 3, 44, 10, 27, 12, 89, 1, 45};
    
    int const n = 10;
    int data[n];
   
   int i;
   for (i = 0; i < 10; i++){
   // pseudoangulo
   start = std::clock();
   int resultado1 = pseudoang(ptsx[i], ptsy[i]);
   data[i] = resultado1;
   std::cout << "ponto: " << ptsx[i] << "," << ptsy[i] << "\n";
   std::cout << "Tempo do pseudoangulo: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
   std::cout << "pseudoangulo: " << resultado1 << "\n";
   }

   start = std::clock();
    mergeSort(data, 0, n - 1);
    std::cout << "Array ordenado dos angulos pseudo: \n";
    printdata(data, n);
    std::cout << "Tempo de ordenar do pseudoangulo: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

   for (i = 0; i < 10; i++){
    // atan2
    start2 = std::clock();
    int atan21 = atan2(ptsx[i], ptsy[i]);
    data[i] = atan21;
    std::cout << "ponto: " << ptsx[i] << "," << ptsy[i] << "\n";
    std::cout << "atan2: " << atan21 << "\n";
    std::cout << "Tempo do atan2: " << (std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
   }

    start2 = std::clock();
    mergeSort(data, 0, n - 1);
    cout << "Array ordenado do angulos atan2: \n";
    printdata(data, n);
    std::cout << "Tempo de ordenar do atan2: " << (std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

   for (i = 0; i < 10; i++){
     // acosseno
    start3 = std::clock();
    int acos = acosine(ptsx[i], ptsy[i]);
    data[i] = acos;
    std::cout << "ponto: " << ptsx[i] << "," << ptsy[i] << "\n";
    std::cout << "acosseno: " << acos << "\n";
    std::cout << "Tempo do acosseno: " << (std::clock() - start3) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
   }

    start3 = std::clock();
    mergeSort(data, 0, n - 1);
    cout << "Array ordenado dos angulos acosine: \n";
    printdata(data, n);
    std::cout << "Tempo de ordenar do acosseno: " << (std::clock() - start3) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

   for (i = 0; i < 10; i++){
     // basic
    start4 = std::clock();
    int bas = basic(ptsx[i], ptsy[i]);
    data[i] = bas;
    std::cout << "ponto: " << ptsx[i] << "," << ptsy[i] << "\n";
    std::cout << "basic: " << bas << "\n";
    std::cout << "Tempo do basic: " << (std::clock() - start4) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
   }

    start4 = std::clock();
    mergeSort(data, 0, n - 1);
    cout << "Array ordenado dos angulos basic: \n";
    printdata(data, n);
    std::cout << "Tempo de ordenar do basic: " << (std::clock() - start4) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    
    cin.get();
    return 0;
}
// Driver para testar os algoritmos ------------------------------------------------------