#include <iostream>
#include "crossprod.h"
using namespace std;

#define INF 10000

// Algoritmo do tiro ------------------
bool tiro(Point polygon[], int n, Point p) {
	
	// Ao menos 3 vertices
	if (n < 3) return false;

    //ponto da linha para o infinito no lado
	Point extreme = {INF, p.y};

    // Contador de interseções e loop
	int count = 0, i = 0;
	do {
		//proximo a cada 3
		int next = (i+1)%n;
		// verifica se a linha do ponto ao extremo faz interseção com a linha de polygon[i] a polygon[next]
		if (intersect(polygon[i], polygon[next], p, extreme)){
			// Se o ponto p for colinear com o segmento de linha next, então verifica se está na linha next
           // Se está, inLine retorna true, caso contrário false
			if (orientation(polygon[i], p, polygon[next]) == 0)
			return inLine(polygon[i], p, polygon[next]);

			count++;
		}
		i = next;
	} while (i != 0);

    // Retorna true se count for ímpar, false caso contrário
	return count&1; 
}
// Algoritmo do tiro ------------------

// Algoritmo do índice de rotação ------------------
int isLeft(const Point &a, const Point &b, const Point &point) {
    return ((b.x - a.x) * (point.y - a.y) -
            (point.x - a.x) * (b.y - a.y));
}

bool rot(const Point points_list [], int n, const Point &point) {
    // contador do indice
    int winding_number = 0;
	int i;

    for (i = 0; i < n; ++i) {
        Point point1(points_list[i]);
        Point point2;

        if (i == (n - 1)) {
            point2 = points_list[0];
        } else {
            point2 = points_list[i + 1];
        }

        if (point1.y <= point.y) {
            if (point2.y > point.y) {
                if (isLeft(point1, point2, point) > 0) {
                    ++winding_number;                               
                }
            }
        } else {
            if (point2.y <= point.y) {
                if (isLeft(point1, point2, point) < 0) {
                    --winding_number;                               
                }
            }
        }
    }

    return winding_number;
}
// Algoritmo do índice de rotação ------------------

int main() {
	// Caso  patológico - ponto de vértice
	Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	int n = sizeof(polygon1)/sizeof(polygon1[0]);
	Point p = {0, 0};
	tiro(polygon1, n, p)? cout << "Tiro: " << "Sim \n":  cout << "Tiro: " << "Nao \n";
	rot(polygon1, n, p) != 0? cout << "indice: " << "Sim\n \n": cout << "indice: " << "Nao \n\n";
 
    // Caso  patológico - Ponto na fronteira
	p = {0, 5};
	tiro(polygon1, n, p)? cout << "Tiro: " << "Sim \n": cout << "Tiro: " << "Nao \n";
	rot(polygon1, n, p) != 0? cout << "indice: " << "Sim \n\n": cout << "indice: " << "Nao \n\n";

    // Caso  patológico - linha passando na quina  
	Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
	p = {0, 5};
	n = sizeof(polygon2)/sizeof(polygon2[0]);
	tiro(polygon2, n, p)? cout << "Tiro: " << "Sim \n": cout << "Tiro: " << "Nao \n";
	rot(polygon2, n, p) != 0? cout << "indice: " << "Sim \n\n": cout << "indice: " << "Nao \n\n";
    
	// Pontos fora
	p = {7, 1};
	tiro(polygon2, n, p)? cout << "Tiro: " << "Sim \n": cout << "Tiro: " << "Nao \n";
	rot(polygon2, n, p) != 0? cout << "indice: " << "Sim \n\n": cout << "indice: " << "Nao \n\n";

    // Ponto fora
	p = {8, 1};
	tiro(polygon2, n, p)? cout << "Tiro: " << "Sim \n": cout << "Tiro: " << "Nao \n";
	rot(polygon2, n, p) != 0? cout << "indice: " << "Sim \n\n": cout << "indice: " << "Nao \n\n";

    // Caso  patológico - Polígono concavo
	Point polygon3[] = {{0, 0}, {10, 0}, {5,5}, {10, 10}, {0, 10}};
	
	// Ponto na quina
	p = {0,5};
	n = sizeof(polygon3)/sizeof(polygon3[0]);
	tiro(polygon3, n, p)? cout << "Tiro:" << "Sim \n": cout << "Tiro: " << "Nao \n";
	rot(polygon3, n, p) != 0? cout << "Indice:" << "Sim \n\n": cout << "indice: " << "Nao \n\n";

    // Ponto dentro
	p = {4, 3};
	n = sizeof(polygon3)/sizeof(polygon3[0]);
	tiro(polygon3, n, p)? cout << "Tiro:" << "Sim \n": cout << "Tiro: " << "Nao \n";
	rot(polygon3, n, p) != 0? cout << "Indice:" << "Sim \n\n": cout << "indice: " << "Nao \n\n";

    cin.get();
	return 0;
}
