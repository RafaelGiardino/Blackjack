#include <iostream>
#include "Deck.h"
#include "Cards.h"
#include "Settings.h"
#include "Game.h"

int main()
{
	char input{};
	while (true) {
		if (drawCards()) {
			std::cout << "You win!\n";
		}
		else
			std::cout << "You lose!\n";

		std::cout << "\nWanna play again? Press (y) for 'Yes' or (n) for 'No': ";
		std::cin >> input;
		if (!std::cin)
		{
			std::cin.clear();
			ignoreLine();
			continue;
		}
		if (hasUnextractedInput()) {
			ignoreLine();
			continue;
		}
		if (input == 'y')
			continue;
		if (input == 'n') {
			std::cout << "Thank you for playing!\n";
			break;
		}
	}
	return 0;
}