#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <memory.h>
#include <string>
#include "Levenshtein.h"
#include "MultiMatrix.h"
#define N 6
// #define N 12
// #define N 18

using namespace std;

int main()
{
	//srand(time(NULL));

	//std::string S1 = "";
	//for (int i = 0; i < 300; i++)
	//{
	//	S1 += ('a' + rand() % 26);
	//}

	//std::string S2 = "";
	//for (int i = 0; i < 200; i++)
	//{
	//	S2 += ('a' + rand() % 26);
	//}

	//std::cout << "S1: " << S1 << std::endl;
	//std::cout << std::endl;
	//std::cout << "S2: " << S2 << std::endl;
	//std::cout << std::endl;

	//clock_t t1 = 0, t2 = 0, t3, t4;
	////const int count = 10;
	////double k[count] = { 1.0 / 10, 2.0 / 10, 3.0 / 10, 4.0 / 10, 5.0 / 10, 6.0 / 10, 7.0 / 10, 8.0 / 10, 9.0 / 10, 1 };
	//const int count = 7;
	//double k[count] = { 1.0 / 25, 1.0 / 20, 1.0 / 15, 1.0 / 10, 1.0 / 5, 1.0 / 2, 1 };
	//int lx = S1.length(), ly = S2.length();

	//for (int i = 0; i < count; i++)
	//{
	//	std::cout << "String length: " << std::setw(8) << (int)(lx * k[i]) << "/" << (int)(ly * k[i]);
	//	//std::cout << "\tRecursion distance: ";
	//	//std::cout << levenshtein_r(lx * k[i], S1, ly * k[i], S2);
	//	std::cout << "\tDyn. prog. distance: ";
	//	std::cout << std::setw(6) << levenshtein(lx * k[i], S1, ly * k[i], S2);
	//	
	//	//t1 = clock();
	//	//levenshtein_r(lx * k[i], S1, ly * k[i], S2);
	//	//t2 = clock();
	//	//std::cout << "\tRecursion time: " << (t2 - t1) << " ms" << std::endl;

	//	t3 = clock();
	//	levenshtein(lx * k[i], S1, ly * k[i], S2);
	//	t4 = clock();
	//	std::cout << "\tDyn. prog. time: " << (t4 - t3) << " ms" << std::endl;
	//}



	int Mc[N + 1] = { 20,15,30,53,10,20,11 }, Ms[N][N], r = 0, rd = 0;
	// int Mc[N + 1] = { 20, 15, 30, 53, 10, 20, 11, 25, 35, 45, 55, 65, 75 }, Ms[N][N], r = 0, rd = 0;
	// int Mc[N + 1] = { 20, 15, 30, 53, 10, 20, 11, 25, 35, 45, 55, 65, 75, 85, 95, 105, 115, 125, 135 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);
	clock_t t1, t2;
	t1 = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	t2 = clock();
	cout << endl;
	cout << endl << "-- brackets (recursion) " << endl;
	cout << endl << "matrix size: ";
	for (int i = 1; i <= N; i++) cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	cout << endl << "minimal amount of operations: " << r;
	cout << endl << endl << "matrix S" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)  cout << Ms[i][j] << "  ";
	}
	cout << endl;
	cout << "time: " << (t2 - t1) << " ms" << endl;

	memset(Ms, 0, sizeof(int) * N * N);
	clock_t t3, t4;
	t3 = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	t4 = clock();
	cout << endl
		<< "-- brackets (dyn. prog.) " << endl;
	cout << endl << "matrix size: ";
	for (int i = 1; i <= N; i++)
		cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	cout << endl << "minimal amount of operations: "
		<< rd;
	cout << endl << endl << "matrix S" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << endl;
		for (int j = 0; j < N; j++)  cout << Ms[i][j] << "  ";
	}
	cout << endl;
	cout << "time: " << (t4 - t3) << " ms" << endl;

	return 0;
}