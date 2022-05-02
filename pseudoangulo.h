#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// Algoritmo do cálculo do pseudoangulo
int pseudoang(int x,int y){
if (y >= 0){
         if (x >= 0){
             if (x >= y){
                 return y/x;
             }     
         return 2 - x/y;
         }

     if (-x <= y){
         return 2 + (-x)/y;
     }     
     return 4 - y/(-x);
}

if (x < 0){
     if (-x >= -y){
         return 4 + (-y)/(-x);
     }
     return 6 - (-x)/(-y);
}

if (x <= -y){
     return 6 + x/(-y);
}     
return 8 - (-y)/x;
}

// Algoritmo do arco cosseno do pseudoangulo
double acosine(int a, int b){
    double ang = acos(a/sqrt(a^2 + b^2));
    
    if (b < 0){
       ang = ang * -1;
    }
    
    return ang;
}

// Algoritmo básico do pseudoangulo
int basic(int y, int x){
   int r = y / (abs(x) + abs(y));
    if (x < 0){
        return 2. - r;
     } else {
        return 4. + r;
     }
}


//  Algoritmo do cálculo do pseudoangulo atan2
double atan2(int dx, int dy){
    double p = dx/(abs(dx)+abs(dy));
    if (dy < 0) { 
        return p - 1; 
    } else { 
        return 1 - p;
    } 
}
