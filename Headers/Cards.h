#pragma once

#include <array>
#include <iostream>

struct Card {
	enum Rank {
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_cards
	};

	enum Suits {
		clubs,
		diamonds,
		hearts,
		spades,

		max_suits
	};
	Rank rank{};
	Suits suit{};

	friend std::ostream& operator<<(std::ostream& out, const Card& card);

	static constexpr std::array<Rank, max_cards> allranks{ rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
	static constexpr std::array<Suits, max_suits> allsuits{ clubs, diamonds, hearts, spades };

	static_assert(std::size(allranks) == max_cards);
	static_assert(std::size(allsuits) == max_suits);

	int value() const;
};
