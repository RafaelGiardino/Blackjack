#include <cassert>
#include "randomgenerator.h"
#include <algorithm>
#include "Deck.h"
#include "Cards.h"

Deck::Deck() : m_cards{} {
	std::size_t count{ 0 };
	for (auto suit : Card::allsuits)
		for (auto rank : Card::allranks)
			m_cards[count++] = { rank, suit };
}

Card Deck::dealCard()
{
	assert(m_index != 52 && "Deck ran out of cards.");

	return m_cards[m_index++];
}

void Deck::shuffle()
{
	std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
	m_index = 0;
}