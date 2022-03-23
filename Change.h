#pragma once
#include "Resourse.h"
#ifndef CHANGE

#define CHANGE
#define NONEEXIT 2
#define ONETIME 4
#define FIRSTPAUSE 8
#define CLEARCONSOLE system("cls")//std::cout << "\033[2J\033[1;1H"
struct Foo
{
	int (*func)();
	const char* string;
	Foo(int (*func)(), const char* string);
};

int Change(std::vector<Foo> arr, int Keys = 0, std::string message = "");

template<class T>
T Vvod(const char* string = "", bool(*func)(T) = [](T) {return true; })
{
	T per;
	bool repeat = false;
	std::cout << string << '\n';
	do
	{
		repeat = false;
		if (!(std::cin >> per))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неверный ввод\n";
			repeat = true;
			continue;
		}
		if (!func(per)) std::cout << "Неверный ввод\n";
	} while (!func(per) || repeat);
	return per;
}

template<class T>
inline void Swap(T& a, T& b)
{
	T delta;
	delta = a;
	a = b;
	b = delta;
}

#endif // !CHANGE