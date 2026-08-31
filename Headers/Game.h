#pragma once

#include "Deck.h"

struct Player {
	int score{};
};

bool dealerTurn(Deck& game, Player& dealer);
bool playerTurn(Deck& game, Player& player);
bool drawCards();
