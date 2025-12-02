#include "day_1.hpp"
#include <tuple>

std::vector<std::string> getInput()
{
	std::vector<std::string>	input;
	std::string	text;

	std::ifstream	file("./input.txt");
	while (std::getline(file, text))
		input.push_back(text);
	file.close();
	return (input);
}

char	getOperation(std::string change)
{
	size_t	found = change.find('L') || change.find('R');
	if (found == std::string::npos)
		return 0;
	return (change[found -1]);
}

int	getNumber(std::string change)
{
	size_t	found = change.find('L') || change.find('R');
	int	number = 0;
	if (found == std::string::npos)
		return 0;
	number = std::stoi(change.substr(found, change.length() -1));
	return number;
}

int	solve(int number, int dial, char operation)
{
	if (operation == 'L')
	{
		if ((dial - number < 0) && (dial - number) > -100)
			dial = 100 + (dial - number);
		else if ((dial - number < 0) && (dial - number) <= -100)
			dial = 100 + (dial - number % 100);
		else
			dial -= number;
		if (dial >= 100)
			dial %= 100;
		return (dial);
	}
	else if (operation == 'R')
	{
		if (dial + number >= 100)
			dial += number % 100;
		else
			dial += number;
		if (dial >= 100)
			dial %= 100;
		return(dial);
	}
	return (-1);
}

int	main() {
	int	result = 50;
	int count = 0;
	std::vector<std::string> input = getInput();
	std::vector<std::string>::iterator it;

	for(it = input.begin(); it != input.end(); it++) {
		result = solve(getNumber(*it), result, getOperation(*it));
		std::cout << "Operation: "<< *it << "\tResult: "<< result << std::endl;
		if (result == 0)
			count++;
	}
	std::cout << "Result: "<< count << std::endl;
	return (0);
}