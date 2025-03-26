#include <iostream>

void GeneratePyramid(unsigned short int num)
{
	// make sure the input is odd, if even, reduce it by 1 to make it odd
	if (num % 2 == 0)
	{
		num--;
	}

	if (num != 0)
	{
		// first, print the top part of the pyramid (increasing stars)
		for (int i = 1; i <= num; i += 2)
		{
			// print leading spaces for alignment
			for (int j = 0; j < (num - i) / 2; j++)
			{
				std::cout << " ";
			}
			// print the stars
			for (int j = 0; j < i; j++)
			{
				std::cout << "*";
			}
			// print new line after each row
			std::cout << std::endl;
		}

		// then, print the bottom part of the pyramid (decreasing stars)
		for (int i = num - 2; i >= 1; i -= 2)
		{
			// print leading spaces for alignment
			for (int j = 0; j < (num - i) / 2; j++)
			{
				std::cout << " ";
			}
			// print the stars
			for (int j = 0; j < i; j++)
			{
				std::cout << "*";
			}
			// print new line after each row
			std::cout << std::endl;

		}
	}

}

int main()
{

	unsigned short int num;
	std::cout << "Enter a number for the size of the pyramid" << std::endl;
	std::cin >> num;

	GeneratePyramid(num);

	return 0;
}