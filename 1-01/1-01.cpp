#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream input("1-01-input.txt");

	std::string line;
	int current = 0;
	int highest = 0;
	while(std::getline(input, line))
	{
		if(line.length() == 0)
		{
			if(current > highest)
			{
				highest = current;
			}
			current = 0;
		}
		current += std::atoi(line.c_str());
	}
	input.close();
	if(current > highest)
	{
		highest = current;
	}

	std::cout << highest ;

	return EXIT_SUCCESS;
}