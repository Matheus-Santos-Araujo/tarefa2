#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int *sum(int a[], int b[], int n){

   int i;
   static int c[2];

    for (i = 0; i < n; i++)
      c[i] = a[i] + b[i];

    return c;  
}

int *subt(int a[], int b[], int n){

   int i;
   static int c[2];

    for (i = 0; i < n; i++)
      c[i] = a[i] - b[i];

    return c;  
}

double norm(int a[], int n){
  double accum = 0.;
    for (int i = 0; i < n; ++i) {
        accum += a[i] * a[i];
    }
    double norm = sqrt(accum);

    return norm;
}

int dist(int a[], int b[], int n){
    int *dis = subt(a, b, n);
    return norm(dis, n);
}

int dotscalar(int a[], int b, int n){
    int p = 0;
 
    for (int i = 0; i < n; i++)
        p = p + a[i] * b;
    return p;
}

int dotprod(int a[], int b[], int n){
    int p = 0;
 
    for (int i = 0; i < n; i++)
 
        p = p + a[i] * b[i];
    return p;
}

double cosinesimi(int a[], int b[], unsigned int n)
{
    double dot = 0.0;
     for(unsigned int i = 0u; i < n; ++i) {
        dot += a[i] * b[i] ;
    }
    return dot / (norm(a, n) * norm(b, n)) ;
}

int main()
{
    int n = 2;
    int vectorr1 [] =  {rand(), rand()};
    int vectorr2 [] =  {rand(), rand()};  
	int vector1 [] =  {0, 2};
    int vector2 [] =  {2, 2};
	int vector3 [] =  {2, 2};
	int vector4 [] =  {0, 0};

 // Vetores aleatorios
    cout <<  "Vetor a: " << vectorr1[0] << " " << vectorr1[1] << "\n";
    cout <<  "Vetor b: " << vectorr2[0] << " " << vectorr2[1] << "\n";
     int *soma = sum(vectorr1, vectorr2, n);
     cout << "Soma: " << soma[0] << " " << soma[1] << "\n";
     int *sub = subt(vectorr1, vectorr2, n);
     cout << "Subtracao: " << sub[0] << " " << sub[1] << "\n";         
     double norm1 = norm(vectorr1, n);
     cout << "Norma de a: " << norm1 << "\n";
     double norm2 = norm(vectorr2, n);
     cout << "Norma de b: " << norm2 << "\n";  
     int ds1 = dotscalar(vectorr1, 10, n);
     cout << "produto por escalar(a,10): " << ds1 << "\n";           
     int ds2 = dotscalar(vectorr2, 10, n);
     cout << "Produto  por escalar(b,10): " << ds2 << "\n";  
     int dot = dotprod(vectorr1, vectorr2, n);
     cout << "Produto escalar: " << dot << "\n";
     double dist1 = dist(vector1, vector2, n);
     cout << "Distancia entre a e b: " << dist1 << "\n";    
     double cos = cosinesimi(vectorr1, vectorr2, n);
     cout << "Similaridade do cos: " << cos << "\n\n";        

     // Casos Patológicos - Vetores Colineares
    cout <<  "Vetor a: " << vector1[0] << " " << vector1[1] << "\n";
    cout <<  "Vetor b: " << vector2[0] << " " << vector2[1] << "\n";
     soma = sum(vector1, vector2, n);
     cout << "Soma: " << soma[0] << " " << soma[1] << "\n";
     sub = subt(vector1, vector2, n);
     cout << "Subtracao: " << sub[0] << " " << sub[1] << "\n";         
     norm1 = norm(vector1, n);
     cout << "Norma de a: " << norm1 << "\n";
     norm2 = norm(vector2, n);
     cout << "Norma de b: " << norm2 << "\n";  
     ds1 = dotscalar(vector1, 10, n);
     cout << "produto por escalar(a,10): " << ds1 << "\n";           
     ds2 = dotscalar(vector2, 10, n);
     cout << "Produto  por escalar(b,10): " << ds2 << "\n";  
     dot = dotprod(vector1, vector2, n);
     cout << "Produto escalar: " << dot << "\n";  
     dist1 = dist(vector1, vector2, n);
     cout << "Distancia entre a e b: " << dist1 << "\n";    
     cos = cosinesimi(vector1, vector2, n);
     cout << "Similaridade do cos: " << cos << "\n\n";        

     // Casos Patológicos - Vetores Idênticos
    cout <<  "Vetor a: " << vector2[0] << " " << vector2[1] << "\n";
    cout <<  "Vetor b: " << vector3[0] << " " << vector3[1] << "\n";
     soma = sum(vector2, vector3, n);
     cout << "Soma: " << soma[0] << " " << soma[1] << "\n";
     sub = subt(vector2, vector3, n);
     cout << "Subtracao: " << sub[0] << " " << sub[1] << "\n";         
     norm1 = norm(vector2, n);
     cout << "Norma de a: " << norm1 << "\n";
     norm2 = norm(vector3, n);
     cout << "Norma de b: " << norm2 << "\n";  
     ds1 = dotscalar(vector2, 10, n);
     cout << "produto por escalar(a,10): " << ds1 << "\n";           
     ds2 = dotscalar(vector3, 10, n);
     cout << "Produto  por escalar(b,10): " << ds2 << "\n";  
     dot = dotprod(vector2, vector3, n);
     cout << "Produto escalar: " << dot << "\n";  
     dist1 = dist(vector1, vector2, n);
     cout << "Distancia entre a e b: " << dist1 << "\n";  
     cos = cosinesimi(vector2, vector3, n);
     cout << "Similaridade do cos: " << cos << "\n\n"; 

 // Casos Patológicos - Vetor nulo
     cout <<  "Vetor a: " << vector2[0] << " " << vector2[1] << "\n";
     cout <<  "Vetor b: " << vector4[0] << " " << vector4[1] << "\n";
     soma = sum(vector2, vector4, n);
     cout << "Soma: " << soma[0] << " " << soma[1] << "\n";
     sub = subt(vector2, vector4, n);
     cout << "Subtracao: " << sub[0] <<  " " << sub[1] << "\n";         
     norm1 = norm(vector2, n);
     cout << "Norma de a: " << norm1 << "\n";
     norm2 = norm(vector4, n);
     cout << "Norma de b: " << norm2 << "\n";  
     ds1 = dotscalar(vector2, 10, n);
     cout << "produto por escalar(a,10): " << ds1 << "\n";           
     ds2 = dotscalar(vector4, 10, n);
     cout << "Produto  por escalar(b,10): " << ds2 << "\n";  
     dot = dotprod(vector2, vector4, n);
     cout << "Produto escalar: " << dot << "\n";  
     dist1 = dist(vector1, vector2, n);
     cout << "Distancia entre a e b: " << dist1 << "\n";  
     cos = cosinesimi(vector2, vector4, n);
     cout << "Similaridade do cos: " << cos << "\n\n"; 

    cin.get();
	return 0;
}
