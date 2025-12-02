#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>

std::vector<std::string> ft_split(std::string input, char delimiter){;
	std::stringstream ss(input);
	std::string split;
	std::vector<std::string> strings;

	while (std::getline(ss, split, delimiter)) {
		strings.push_back(split);
	}

	return strings;
}

int main() {
	std::string input = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";
	std::vector<std::string> ids = ft_split(input, ',');
	std::vector<std::pair<int, int>> ranges;
	for (std::vector<std::string>::iterator it = ids.begin(); it != ids.end(); it++)
	{
		std::pair<int, int> range;
		range.first = std::atoi(ft_split(*it, '-')[0].c_str());
		range.second = std::atoi(ft_split(*it, '-')[1].c_str());
		ranges.push_back(range);
	}

	for (std::vector<std::pair<int, int>>::iterator it = ranges.begin(); it != ranges.end(); it++)
		std::cout << it->first << "-" << it->second <<std::endl;
	return 0;
}