#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include <string_view>

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,
 
    max_suits
};
 
enum class CardRank
{
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
    rank_ace,
 
    max_ranks
};

struct Card{
    CardRank rank{};
    CardSuit suit{};
};

char getSuit(const Card& c){
    switch (c.suit) {
        case CardSuit::club:
            return 'C';
        case CardSuit::diamond:
            return 'D';
        case CardSuit::heart:
            return 'H';
        case CardSuit::spade:
            return 'S';
        case CardSuit::max_suits:
        default:
            return ' ';
    }
}

char getRank(const Card& c){
    switch(c.rank){
        case CardRank::rank_2:
        case CardRank::rank_3:
        case CardRank::rank_4:
        case CardRank::rank_5:
        case CardRank::rank_6:
        case CardRank::rank_7:
        case CardRank::rank_8:
        case CardRank::rank_9:
            return static_cast<char>(c.rank) + '2';
        case CardRank::rank_10:
            return 'T';
        case CardRank::rank_jack:
            return 'J';
        case CardRank::rank_queen:
            return 'Q';
        case CardRank::rank_king:
            return 'K';
        case CardRank::rank_ace:
            return 'A';
        case CardRank::max_ranks:
        default:
            return ' ';
    }
}

void printCard(const Card& c){
    std::cout << getRank(c) << getSuit(c);
}

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

std::array<Card, 52> createDeck(){
    deck_type deck;
    index_type index{0};
    for (auto suit = 0; suit < static_cast<int>(CardSuit::max_suits); ++suit){
        for (auto rank = 0; rank < static_cast<int>(CardRank::max_ranks); ++rank){
            deck[index].suit = static_cast<CardSuit>(suit);
            deck[index].rank = static_cast<CardRank>(rank);
            index++;
        }
    }
    return deck;
}

void printDeck(const deck_type& deck){
    for (const Card& card : deck){
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(deck_type& deck){
    static std::mt19937 mt { static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& c){
    switch(c.rank){
        case CardRank::rank_2:
        case CardRank::rank_3:
        case CardRank::rank_4:
        case CardRank::rank_5:
        case CardRank::rank_6:
        case CardRank::rank_7:
        case CardRank::rank_8:
        case CardRank::rank_9:
        case CardRank::rank_10:
            return static_cast<int>(c.rank) + 2;
        case CardRank::rank_jack:
        case CardRank::rank_queen:
        case CardRank::rank_king:
            return 10;
        case CardRank::rank_ace:
            return 11;
        case CardRank::max_ranks:
        default:
            return 0;
    }
}

// Maximum score before losing.
constexpr int maximumScore{ 21 };
 
// Minimum score that the dealer has to have.
constexpr int minimumDealerScore{ 17 };

// now returns the money multiplier for player
// should make hit into a function
int playBlackjack(const deck_type& deck){
    int drawIndex{0};
    int dealerValue{0};
    dealerValue += getCardValue(deck[drawIndex++]);
    std::cout << "Dealer has: " << dealerValue << '\n';
    int playerValue{0};
    playerValue += getCardValue(deck[drawIndex++]);
    int drawVal {getCardValue(deck[drawIndex++])};
    if (drawVal == 11 && (maximumScore - playerValue) < 11) drawVal = 1;
    playerValue += drawVal;
    std::cout << "You have: " << playerValue << '\n';
    while (true){
        std::cout << "hit or stand? ";
        std::string option{};
        std::cin >> option;
        if (option == "hit"){
            drawVal = getCardValue(deck[drawIndex++]);
            if (drawVal == 11 && (maximumScore - playerValue) < 11) drawVal = 1;
            playerValue += drawVal;
            std::cout << "You hit: " << playerValue << '\n';
            if (playerValue > maximumScore){
                std::cout << "You busted!\n";
                return 0;
            }
        }
        if (option == "stand"){
            break;
        }
    }
    while (dealerValue <= minimumDealerScore){
        drawVal = getCardValue(deck[drawIndex++]);
        if (drawVal == 11 && (maximumScore - dealerValue) < 11) drawVal = 1;
        dealerValue += drawVal;
        std::cout << "Dealer hits: " << dealerValue << '\n';
        if (dealerValue > maximumScore) {
            std::cout << "Dealer busts!\n";
            return 2;
        }
    }
    if (playerValue == dealerValue) return 1;
    return playerValue > dealerValue;
}

int main(){
    auto deck { createDeck() };
    // printDeck(deck);
    shuffleDeck(deck);
    // printDeck(deck);
    // std::cout << getCardValue(deck[0]);
    std::cout << (playBlackjack(deck) ? "You win!" : "You Lose!");
    return 0;
}