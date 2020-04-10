#ifndef CARD_H
#define CARD_H

class Card
{
public:
    enum Suit {
        Club,
        Diamond,
        Heart,
        Spade
    };

    enum Rank {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    Card(Suit suit, Rank rank) : _suit(suit), _rank(rank) {}

private:
    Suit _suit;
    Rank _rank;
};

#endif // CARD_H