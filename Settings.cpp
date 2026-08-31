#include <limits>
#include <iostream>
#include "Settings.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}
