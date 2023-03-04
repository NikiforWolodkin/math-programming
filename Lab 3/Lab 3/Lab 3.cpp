// Программа на C++, решающая задачу коммивояжера
// с помощью метода ветвей и границ.
#include <Bits.h>
#include <iostream>
using namespace std;
const int N = 5;
// final_path[] хранит финальное решение - путь коммивояжера.
int final_path[N + 1];

// visited[] отслеживает уже посещенные узлы
// в конкретном пути
bool visited[N];

// Хранит финальный минимальный вес кратчайшего маршрута.
int final_res = INT_MAX;

// Функция копирует временное решение в
// финальное решение
void copyToFinal(int curr_path[])
{
    for (int i = 0; i < N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

// Функция находит минимальную стоимость ребра,
// заканчивающегося на вершине i
int firstMin(int adj[N][N], int i)
{
    int min = INT_MAX;
    for (int k = 0; k < N; k++)
        if (adj[i][k] < min && i != k)
            min = adj[i][k];
    return min;
}

// Функция находит второе минимальное ребро
// заканчивающееся на вершине i
int secondMin(int adj[N][N], int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (i == j)
            continue;

        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second &&
            adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

// Функция, которая принимает в качестве аргументов:
// curr_bound -> нижняя граница корневого узла
// curr_weight -> хранит вес пути до сих пор
// level -> текущий уровень при перемещении в поиске
// пространства дерева
// curr_path[] -> где хранится решение, которое
// впоследствии будет скопировано в final_path[]
void TSPRec(int adj[N][N], int curr_bound, int curr_weight,
    int level, int curr_path[])
{
    // Базовый случай - достижение уровня N, что
// означает, что мы прошли по всем узлам один раз
    if (level == N)
    {
        // проверяем, есть ли ребро от последней вершины
        // в пути обратно к первой вершине
        if (adj[curr_path[level - 1]][curr_path[0]] != 0)
        {
            // curr_res содержит общий вес решения
            int curr_res = curr_weight +
                adj[curr_path[level - 1]][curr_path[0]];

            // Обновляем конечный результат и конечный путь,
        // если текущий результат лучше.
            if (curr_res < final_res)
            {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    // для любого другого уровня перебираем все вершины
// рекурсивно создавая дерево пространства поиска
    for (int i = 0; i < N; i++)
    {
        // Рассматриваем следующую вершину, если она не совпадает (диагональный
        // элемент в матрице смежности и еще не посещена)
        if (adj[curr_path[level - 1]][i] != 0 &&
            visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];

            // Разное вычисление curr_bound для
        // уровня 2 от других уровней
            if (level == 1)
                curr_bound -= ((firstMin(adj, curr_path[level - 1]) +
                    firstMin(adj, i)) / 2);
            else
                curr_bound -= ((secondMin(adj, curr_path[level - 1]) +
                    firstMin(adj, i)) / 2);

            // curr_bound + curr_weight - это реальная нижняя граница
            // для узла, на котором мы находимся
            // Если текущая нижняя граница < final_res, то мы должны дальше исследовать
            // этот узел
            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;

                // вызываем TSPRec для следующего уровня
                TSPRec(adj, curr_bound, curr_weight, level + 1,
                    curr_path);
            }

            // Иначе нам нужно обрезать узел, сбросив
        // все изменения в curr_weight и curr_bound
            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;

            // Также сбрасываем массив visited
            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

// Эта функция устанавливает конечный путь final_path[]
void TSP(int adj[N][N])
{
    int curr_path[N + 1];

    // Вычисляем начальную нижнюю границу для корневого узла
// с помощью формулы 1/2 * (сумма первой минимальной +
// второй минимальной) для всех ребер.
// Также инициализируем массив curr_path и visited
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));

    // Вычисляем начальную границу
    for (int i = 0; i < N; i++)
        curr_bound += (firstMin(adj, i) +
            secondMin(adj, i));

    // Округляем нижнюю границу до целого числа
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 :
        curr_bound / 2;

    // Мы начинаем с вершины 1, поэтому первая вершина
    // в curr_path[] равна 0
    visited[0] = true;
    curr_path[0] = 0;

    // Вызываем TSPRec для curr_weight равного 0 и уровня 1
    TSPRec(adj, curr_bound, 0, 1, curr_path);
}

// Код вызова функций
int main()
{
    // Матрица смежности для данного графа
    int adj[N][N] = { 
        {INFINITY, 8, 25, INFINITY, 4},
        {4, INFINITY, 19, 64, 80},
        {6, 12, INFINITY, 86, 53},
        {21, 54, 16, INFINITY, 12},
        {89, 70, 52, 17, INFINITY}
    };

    TSP(adj);

    printf("Minimum cost : %d\n", final_res);
    printf("Path Taken : ");
    for (int i = 0; i <= N; i++)
        printf("%d ", final_path[i]);

    return 0;
}