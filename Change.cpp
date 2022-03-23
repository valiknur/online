#include "Change.h"


int Change(std::vector<Foo> arr, int Keys, std::string message)
{
	if ((Keys & FIRSTPAUSE) == FIRSTPAUSE)
	{
		std::cout << '\n';
		system("pause");
	}
	if (message[0] != '\n') std::cout << '\n';
	if ((Keys & NONEEXIT) != NONEEXIT) arr.push_back({ []() {return 0; } ,"Назад" });
	int selected = 0;
	do
	{
		CLEARCONSOLE;
		std::cout << message;
		if (!message.empty() && message[message.size() - 1] != '\n') std::cout << '\n';
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i].string << (i == selected ? " <-" : "") << '\n';
		}
		switch (_getch())
		{
		case 80:
		{
			selected = (arr.size() - 1 < selected + 1 ? arr.size() - 1 : selected + 1);
			break;
		}
		case 72:
		{
			selected = (arr.size() > selected - 1 ? selected - 1 : 0);
			break;
		}
		case 13:
		{
			std::cout << "\033[2J\033[1;1H";
			if ((Keys & ONETIME) == ONETIME) return arr[selected].func();

			arr[selected].func();
			break;
		}
		default:
			break;
		}
	} while (true);
	return 0;
}

Foo::Foo(int(*func)(), const char* string)
{
	this->func = func;
	this->string = string;
}