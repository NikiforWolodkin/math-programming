#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include "Levenshtein.h"

int main()
{
	srand(time(NULL));

	std::string S1 = "";
	for (int i = 0; i < 2500; i++)
	{
		S1 += ('a' + rand() % 26);
	}

	std::string S2 = "";
	for (int i = 0; i < 2500; i++)
	{
		S2 += ('a' + rand() % 26);
	}

	std::cout << "S1: " << S1 << std::endl;
	std::cout << "S2: " << S2 << std::endl;
	std::cout << std::endl;

	clock_t t1 = 0, t2 = 0, t3, t4;
	/*const int count = 12;
	double k[count] = { 1. / 10, 1. / 5, 1. / 4, 1. / 3, 4. / 10, 5. / 10, 6. / 10, 7. / 10, 8. / 10, 9. / 10, 1. };*/
	const int count = 7;
	double k[count] = { 1.0 / 25, 1.0 / 20, 1.0 / 15, 1.0 / 10, 1.0 / 5, 1.0 / 2, 1 };
	int lx = S1.length(), ly = S2.length();

	for (int i = 0; i < count; i++)
	{
		std::cout << "String length: " << std::setw(6) << (int)(lx * k[i]) << "/" << (int)(ly * k[i]);
		/*std::cout << "\tRecursion distance: ";
		std::cout << levenshtein_r(lx * k[i], S1, ly * k[i], S2);*/
		std::cout << "\tDyn. prog. distance: ";
		std::cout << std::setw(6) << levenshtein(lx * k[i], S1, ly * k[i], S2);
		
		/*t1 = clock();
		levenshtein_r(lx * k[i], S1, ly * k[i], S2);
		t2 = clock();

		std::cout << "\tRecursion time: " << (t2 - t1) << " ms";*/

		t3 = clock();
		levenshtein(lx * k[i], S1, ly * k[i], S2);
		t4 = clock();
		std::cout << "\tDyn. prog. time: " << (t4 - t3) << " ms" << std::endl;
	}

	return 0;
}