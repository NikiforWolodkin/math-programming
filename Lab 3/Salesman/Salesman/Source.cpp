// --- main 
#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5
int main()
{
    int d[N][N] = { //0   1    2    3     4        
                  { 0,   8,   25,  INF,  4},    //  0
                  { 4,   0,   19,  64,   80},    //  1
                  { 6,   12,  0,   86,   53},    //  2 
                  { 21,  54,  16,  0,    12},    //  3
                  { 89,  70,  52,  17,   0} };  //  4  
    int r[N];                     // результат 
    int s = salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Commis voyageur -- ";
    std::cout << std::endl << "-- Cities           : " << N;
    std::cout << std::endl << "-- Distance matrix  : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- Optimal route    : ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- Route length     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}
