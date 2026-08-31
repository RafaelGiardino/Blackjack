#pragma once

#include "Cards.h"
#include "randomgenerator.h"

class Deck {
public:
	Deck();

	Card dealCard();

	void shuffle();

private:
	std::array<Card, 52> m_cards{};
	std::size_t m_index{ 0 };
};
