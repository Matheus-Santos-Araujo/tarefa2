#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
std::clock_t start1;
std::clock_t start2;
std::clock_t start3;

// Utilitário para copiar 1 array em outro -------------------------------------------
void copy_array(int s[], int d[], int n) {
    for (int i = 0; i < n; i++)
        d[i] = s[i];   
}  

// Utilitário para troca de posição no array -------------------------------------------
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/* Utilitário para printar o array ordenado ----------------------------------------------- */
void printdata(int data[], int size){
	int i;
	for (i=0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

// Ordenação por seleção ---------------------------------------------------------------
void selectionSort(int data[], int n){
	int i, j, min_idx;

	// Seleciona um por um para o começo do array
	for (i = 0; i < n-1; i++){
		// Encontrar o elemento mínimo
		min_idx = i; // Mínimo inicia em i
		for (j = i+1; j < n; j++) // Verifica subsequentes de i
		  if (data[j] < data[min_idx]) // Caso algum seja menor, seleciona-o
			 min_idx = j; // E é o novo mínimo

		// Troca o elemento mínimo encontrado com o primeiro elemento
		swap(&data[min_idx], &data[i]); 
	}
}
// Ordenação por seleção ---------------------------------------------------------------

// Ordenação por Quicksort ---------------------------------------------------------------
/* Utilitário que coloca o último elemento como pivô, 
  na sua devida posição e coloca todos os menos que ele à esquerda 
  todos os elementos maiores à direita */
int partition (int data[], int low, int high){
    int pivot = data[high]; // pivô
    int i = (low - 1); // Índice do menor elemento
 
    for (int j = low; j <= high - 1; j++){
        // Se o elemento atual for menor do que o pivô
        if (data[j] < pivot){
            i++; // índice de incremento do menor elemento
			// Troca o elemento mínimo encontrado com o primeiro elemento
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return (i + 1);
}
 
void quickSort(int data[], int low, int high){
    if (low < high){ 
        /* pi é o índice de partição */
        int part = partition(data, low, high);
 
        // Separar elementos em antes da partição e após a partição
        quickSort(data, low, part - 1);
        quickSort(data, part + 1, high);
    }
}
// Ordenação por Quicksort ---------------------------------------------------------------

// Ordenação por Mergesort ---------------------------------------------------------------
void merge(int array[], int const left, int const mid, int const right){
	// Índices dos arrays
    int const array1 = mid - left + 1;
    int const array2 = right - mid;
  
    // Arrays temporários esquerda e direita
    int *leftArray = new int[array1];
	int *rightArray = new int[array2];
    for (int i = 0; i < array1; i++) leftArray[i] = array[left + i];
    for (int j = 0; j < array2; j++) rightArray[j] = array[mid + 1 + j];
  
    int L = 0, // Índice inicial do primeiro subarray iniciado em 0
    R = 0; // Índice inicial do segundo subarray iniciado em 0
    int M = left; // Índice inicial do merged subarray iniciado em left
  
    // Merge os arrays temporários de volta em array[left..right]
	// Enquanto percorremos ambos os arrays
    while (L < array1 && R < array2) {
		// Se right for maior left é registrado no array merge e incrementado
        if (leftArray[L] <= rightArray[R]) {
            array[M] = leftArray[L];
            L++;
        }
        else {
		    // Caso contrário right é registrado no array merge e incrementado
            array[M] = rightArray[R];
            R++;
        }
        M++;
    }
    // Copia os restantes elementos de left[], se houverem
    while (L < array1) {
        array[M] = leftArray[L];
        L++;
        M++;
    }
    // Copia os restantes elementos de right[], se houverem
    while (R < array2) {
        array[M] = rightArray[R];
        R++;
        M++;
    }
}

// Função recursiva 
void mergeSort(int array[], int const begin, int const end){
    if (begin >= end) return;
  
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
// Ordenação por Mergesort ---------------------------------------------------------------

// Ordenação por Mergesort double ---------------------------------------------------------------
void merged(double array[], int const left, int const mid, int const right){
	// Índices dos arrays
    int const array1 = mid - left + 1;
    int const array2 = right - mid;
  
    // Arrays temporários esquerda e direita
    double *leftArray = new double[array1];
	double *rightArray = new double[array2];
    for (int i = 0; i < array1; i++) leftArray[i] = array[left + i];
    for (int j = 0; j < array2; j++) rightArray[j] = array[mid + 1 + j];
  
    int L = 0, // Índice inicial do primeiro subarray iniciado em 0
    R = 0; // Índice inicial do segundo subarray iniciado em 0
    int M = left; // Índice inicial do merged subarray iniciado em left
  
    // Merge os arrays temporários de volta em array[left..right]
	// Enquanto percorremos ambos os arrays
    while (L < array1 && R < array2) {
		// Se right for maior left é registrado no array merge e incrementado
        if (leftArray[L] <= rightArray[R]) {
            array[M] = leftArray[L];
            L++;
        }
        else {
		    // Caso contrário right é registrado no array merge e incrementado
            array[M] = rightArray[R];
            R++;
        }
        M++;
    }
    // Copia os restantes elementos de left[], se houverem
    while (L < array1) {
        array[M] = leftArray[L];
        L++;
        M++;
    }
    // Copia os restantes elementos de right[], se houverem
    while (R < array2) {
        array[M] = rightArray[R];
        R++;
        M++;
    }
}

// Função recursiva 
void mergeSortd(double array[], double const begin, double const end){
    if (begin >= end) return;
  
    int mid = begin + (end - begin) / 2;
    mergeSortd(array, begin, mid);
    mergeSortd(array, mid + 1, end);
    merged(array, begin, mid, end);
}

/* Utilitário para printar o array ordenado ----------------------------------------------- */
void printdatad(double data[], int size){
	int i;
	for (i=0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

// Ordenação por Mergesort double ---------------------------------------------------------------
