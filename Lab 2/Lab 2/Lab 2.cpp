#include <iostream>
#include <iomanip> 
#include "Combi.h"
#include "Boat.h"
#include "Auxil.h"
#define N (sizeof(AA4)/2)
#define M 3
#define NN (sizeof(v)/sizeof(int))


int main()
{
    // генерация подмножеств
    setlocale(LC_ALL, "rus");
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << " - Генератор множества всех подмножеств -" << std::endl;
    std::cout << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";
    combi::subset s1(sizeof(AA) / 2);         // создание генератора   
    int  n = s1.getfirst();                  // первое (пустое) подмножество    
    while (n >= 0)                          // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";

        for (int i = 0; i < n; i++)

            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = s1.getnext();                   // cледующее подмножество 
    };
    std::cout << std::endl << "всего: " << s1.count() << std::endl;

    // генерация сочетаний
    char  AA2[][2] = { "A", "B", "C", "D", "E" };
    std::cout << std::endl << " --- Генератор сочетаний ---" << std::endl;
    std::cout << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA2) / 2; i++)
        std::cout << AA2[i] << ((i < sizeof(AA2) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    combi::xcombination xc(sizeof(AA2) / 2, 3);
    std::cout << "из " << xc.n << " по " << xc.m;
    int  n2 = xc.getfirst();
    while (n2 >= 0)
    {
        std::cout << std::endl << xc.nc << ": { ";

        for (int i = 0; i < n2; i++)

            std::cout << AA2[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");

        std::cout << "}";

        n2 = xc.getnext();
    };
    std::cout << std::endl << "всего: " << xc.count() << std::endl;

    // генерация перестановок
    char  AA3[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор перестановок ---" << std::endl;
    std::cout << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA3) / 2; i++)
        std::cout << AA3[i] << ((i < sizeof(AA3) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    combi::permutation p(sizeof(AA3) / 2);
    __int64  n3 = p.getfirst();
    while (n3 >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";

        for (int i = 0; i < p.n; i++)

            std::cout << AA3[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

        std::cout << "}";

        n3 = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;

    // генерация размещений
    char  AA4[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < N; i++)
        std::cout << AA4[i] << ((i < N - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
    combi::accomodation s(N, M);
    int  n4 = s.getfirst();
    while (n4 >= 0)
    {
        std::cout << std::endl << std::setw(2) << s.na << ": { ";

        for (int i = 0; i < 3; i++)

            std::cout << AA4[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");

        std::cout << "}";

        n4 = s.getnext();
    };
    std::cout << std::endl << "всего: " << s.count() << std::endl;

    // задача об оптимальной загрузке судна
    clock_t  t1 = 0, t2 = 0;
    auxil::start();

    const int MM = 5;
    const int CA = 8;
    int v[CA]; // вес
    for (int i = 0; i < CA; i++)
    {
        v[i] = auxil::iget(100, 200);
    }
    int c[CA]; // доход 
    for (int i = 0; i < CA; i++)
    {
        c[i] = auxil::iget(10, 100);
    }
    int minv[MM];    // минимальный  вес 
    for (int i = 0; i < MM; i++)
    {
        minv[i] = auxil::iget(50, 120);
    }
    int maxv[MM];    // максимальный вес
    for (int i = 0; i < MM; i++)
    {
        maxv[i] = auxil::iget(150, 850);
    }
    short r[MM];

    t1 = clock();
    int cc = boat_с(
        MM,    // [in]  количество мест для контейнеров
        minv,  // [in]  максимальный вес контейнера на каждом  месте 
        maxv,  // [in]  минимальный вес контейнера на каждом  месте  
        NN,    // [in]  всего контейнеров  
        v,     // [in]  вес каждого контейнера  
        c,     // [in]  доход от перевозки каждого контейнера   
        r      // [out] номера  выбранных контейнеров  
    );
    t2 = clock();

    std::cout << std::endl << "- Задача о размещении контейнеров на судне -";
    std::cout << std::endl << "- общее количество контейнеров   : " << NN;
    std::cout << std::endl << "- количество мест для контейнеров  : " << MM;
    std::cout << std::endl << "- минимальный  вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << minv[i] << " ";
    std::cout << std::endl << "- максимальный вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << maxv[i] << " ";
    std::cout << std::endl << "- вес контейнеров      : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1) : ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : " << cc;
    std::cout << std::endl << std::endl;

    std::cout << std::endl << "количество мест:           " << MM;
    std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
    std::cout << std::endl << "                  (сек):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;

    system("pause");
    return 0;
}
