#pragma once
int levenshtein(
	int lx,            // длина слова x 
	std::string x,     // слово длиной lx
	int ly,            // длина слова y
	std::string y      // слово y
);
// -- дистанции   Левенштeйна (рекурсия)
int levenshtein_r(
	int lx,            // длина строки x 
	std::string x,     // строка длиной lx
	int ly,            // длина строки y
	std::string y      // строка y
);
