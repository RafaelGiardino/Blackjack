#include <iostream>
#include "Cards.h"

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	static constexpr std::array ranks{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	static constexpr std::array suits{ 'C', 'D', 'H', 'S' };

	out << ranks[card.rank] << suits[card.suit];
	return out;
}

int Card::value() const
{
	constexpr std::array cardValue{ 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
	return cardValue[rank];
}
