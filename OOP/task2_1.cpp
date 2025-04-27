#include <iostream>

void task_2_1()
{
	int a, b, c, d;

	std::cout << "Enter a, b, c, d: ";
	std::cin >> a >> b >> c >> d;


	int resBinary = ((a << 5) + (a << 1)) + (((a << 3) + (a << 2) + a) + ((c << 3) + (c << 2)) >> 6) - ((b << 11) + (b << 9)) + ((d << 7) - d) - ((c << 4) + (c << 1));
	int resDecimal = a * 34 + (13 * a + 12 * c) / 64 - b * 2560 + d * 127 - c * 18;

	std::cout << "Result (binary): " << resBinary << std::endl;
	std::cout << "Result (decimal): " << resDecimal << std::endl;

	std::cin.ignore();
	std::cin.get();
	system("cls");
}