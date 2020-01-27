#include <iostream>
#include <string>
#include <vector>

#include "Math.h"

enum UserOption
{
	Add = 1,
	Subtract = 2,
	Multiply = 3,
	Divide = 4
};

void showMenu()
{
	std::cout << "Please select an option below.\n";
	std::cout << "---------------------------------------\n";
	std::cout << "1. Add\n";
	std::cout << "2. Subtract\n";
	std::cout << "3. Multiply\n";
	std::cout << "4. Divide\n";
}

std::vector<int> getNumbers()
{
	int numberOne;
	int numberTwo;

	std::cout << "Enter number 1:\n";
	std::cin >> numberOne;

	std::cout << "Enter number 2:\n";
	std::cin >> numberTwo;

	return std::vector<int>({ numberOne, numberTwo });
}

int main()
{
	showMenu();

	bool exit{ false };

	while (!exit)
	{
		int userOption;

		std::cin >> userOption;

		int result;

		switch (userOption)
		{
			case UserOption::Add:
			{
				std::vector<int> numbers = getNumbers();
				result = Math::Add(numbers[0], numbers[1]);
				break;
			}

			case UserOption::Subtract:
			{
				std::vector<int> numbers = getNumbers();
				result = Math::Subtract(numbers[0], numbers[1]);
				break;
			}

			case UserOption::Multiply:
			{
				std::vector<int> numbers = getNumbers();
				result = Math::Multiply(numbers[0], numbers[1]);
				break;
			}

			case UserOption::Divide:
			{
				std::vector<int> numbers = getNumbers();
				result = Math::Divide(numbers[0], numbers[1]);
				break;
			}

			default:
				exit = true;
				break;
		}

		if (!exit)
		{ 
			std::cout << "Result: " << result << "\n\n";

			result = 0;

			showMenu();
		}
	}

	return 0;
}