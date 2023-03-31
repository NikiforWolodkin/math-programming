#include <iostream>
#include <string>

int main()
{
	srand(time(NULL));
	std::string s1 = "";
	for (int i = 0; i < 300; i++)
	{
		s1 += ('a' + rand() % 26);
	}

	std::string s2 = "";
	for (int i = 0; i < 200; i++)
	{
		s2 += ('a' + rand() % 26);
	}

	std::cout << "s1: " << s1 << std::endl << std::endl;
	std::cout << "s2: " << s2 << std::endl;
}

    