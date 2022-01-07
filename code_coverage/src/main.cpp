#include <iostream>

#include "calculator.h"

// entry point of the main project
int main(int argc, char** argv)
{
	std::cout << "Calculator app\n";
	std::cout << "================\n";

	bool keep_running = true;

	int choice{ 1 };

	while (choice > 0 && choice <= 4)
	{
		std::cout << "1. Addition\n";
		std::cout << "2. Substraction\n";
		std::cout << "3. Multiplication\n";
		std::cout << "4. Division\n\n";
		std::cout << "0. Exit\n\n";


		std::cout << "Choice ? :";
		std::cin >> choice;

		if (choice == 0) break;

		int x{ 0 }, y{ 0 }, res{ 0 };
		ask_x_y(&x, &y);

		switch (choice)
		{
		case 1:
			res = add(x, y);
			std::cout << x << " + " << y << " = " << res << std::endl;
			break;

		case 2:
			res = sub(x, y);
			std::cout << x << " - " << y << " = " << res << std::endl;
			break;

		case 3:
			res = mult(x, y);
			std::cout << x << " * " << y << " = " << res << std::endl;
			break;

		case 4:
			res = division(x, y);
			std::cout << x << " / " << y << " = " << res << std::endl;
			break;

		default:
			break;
		}
	}

	std::cout << "Bye !" << std::endl;

}
