#include <iostream>
#include <algorithm>
using namespace std;

// Interseção entre segmentos ------------------------------
struct Point {
   int x, y;
};

  //Produto Vetorial  ------------------------------
  int cross(Point a, Point b, Point c){
 
    int p = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);

    return p;
}
   //Produto Vetorial  ------------------------------

// Área orientada ------------------------------

int orientation(Point a, Point b, Point c) {
   // Produto Vetorial
   int val = cross(a, b, c);
   if (val == 0)
      return 0;     //colinear
   else if(val < 0)
      return 2;    // anti-horario
      return 1;    // horario
}

// Área orientada ------------------------------
bool inLine(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool intersect(Point p1, Point q1, Point p2, Point q2){
   // Quatro orientações necessárias
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // Caso geral
    if (o1 != o2 && o3 != o4)
        return true;
 
    // p1, q1 e p2 são colineares e p2 está no segmento p1q1
    if (o1 == 0 && inLine(p1, p2, q1)) return true;
 
    // p1, q1 e p2 são colineares e q2 está no segmento p1q1
    if (o2 == 0 && inLine(p1, q2, q1)) return true;
 
    // p2, q2 e p1 são colineares e p1 está no segmento p2q2
    if (o3 == 0 && inLine(p2, p1, q2)) return true;
 
    // p2, q2 e q1 são colineares e q1 está no segmento p2q2
    if (o4 == 0 && inLine(p2, q1, q2)) return true;
 
    return false; // Nenhum dos casos
}
    // Interseção entre segmentos ------------------------------