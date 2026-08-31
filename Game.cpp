#include "Deck.h"
#include "Settings.h"
#include "Cards.h"
#include "Game.h"
#include <iostream>

using namespace Settings;

bool dealerTurn(Deck& game, Player& dealer)
{
	while (dealer.score < StopDealer) {
		Card newCard{ game.dealCard() };
		std::cout << "The dealer flips a " << newCard << ".";
		std::cout << "\tThey now have: " << (dealer.score += newCard.value()) << '\n';
	}

	if (dealer.score > BustPlayer) {
		std::cout << "The dealer went bust!\n";
		return true;
	}
	return false;
}

bool playerTurn(Deck& game, Player& player)
{
	char input{};

	while (player.score <= BustPlayer) {
		Card newCard{ game.dealCard() };

		std::cout << "(h) to hit, or (s) to stand: ";
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
		if (input == 'h') {
			std::cout << "You were dealt " << newCard << ".";
			std::cout << "\tYou now have: " << (player.score += newCard.value()) << '\n';
			if (player.score <= BustPlayer)
				continue;
			else {
				std::cout << "You went bust!\n";
				return false;
			}
		}
		if (input == 's')
			return true;
	}
	return false;
}

bool drawCards()
{
	Deck game{};
	game.shuffle();

	Player dealer{ game.dealCard().value() };
	Player player{ game.dealCard().value() + game.dealCard().value() };

	std::cout << "The dealer is showing: " << dealer.score << '\n';
	std::cout << "You have score: " << player.score << '\n';

	if (playerTurn(game, player)) {
		if (dealerTurn(game, dealer))
			return true;
	}
	if (player.score > BustPlayer)
		return false;
	return (player.score > dealer.score);
}