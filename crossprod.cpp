#include <iostream>
#include <algorithm>
#include "crossprod.h"
using namespace std;

 int main(){
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int c = cross(p1, p2, p3);
    cout << "Prod Vetorial: " << c << "\n";
    int o = orientation(p1, p2, p3);
    if (o==0)         cout << "Linear" << "\n";
    else if (o == 1)  cout << "Horario" << "\n";
    else              cout << "Anti horario" << "\n";

    struct Point s1 = {1, 1}, q1 = {10, 1};
    struct Point s2 = {1, 2}, q2 = {10, 2};
    intersect(s1, q1, s2, q2)? cout << "Sim\n": cout << "Nao\n";
 
    s1 = {10, 0}, q1 = {0, 10};
    s2 = {0, 0}, q2 = {10, 10};
    intersect(s1, q1, s2, q2)? cout << "Sim\n": cout << "Nao\n";
 
    s1 = {-5, -5}, q1 = {0, 0};
    s2 = {1, 1}, q2 = {10, 10};
    intersect(s1, q1, s2, q2)? cout << "Sim\n": cout << "Nao\n";

    cin.get();
    return 0;
 }   
