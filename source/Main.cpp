
#include <iostream>
#include "CCardDeck.h"

int main()
{
    CCardDeck GameDrawDeck = CCardDeck();
    CCardDeck GamePlayDeck = CCardDeck();
    CCardDeck Player1 = CCardDeck(&GameDrawDeck, &GamePlayDeck);

    CCardSpecial card = CCardSpecial(eColor::Red, 2, eSpecialType::Normal);
    //Initialize Decks;

    
    GamePlayDeck.AddCardToDeck(&card);

    for (int i = 0; i < eColor::LastElement; i++) {
        for (int j = 1; j <= 9; j++) {
            card = CCardSpecial(eColor(eColor::Red + i), j, eSpecialType::Normal);
            GameDrawDeck.AddCardToDeck(&card);
            Player1.AddCardToDeck(&card);
        }

        for (int j = eSpecialType::Plus2; j < eSpecialType::LastElementSpecial; j++) {
            card = CCardSpecial(eColor(eColor::Red + i), j, eSpecialType(eSpecialType::Normal + j));
            GameDrawDeck.AddCardToDeck(&card);
            Player1.AddCardToDeck(&card);
        }
        card = CCardSpecial(eColor(eColor::Red + i), -1, eSpecialType::Plus4);
        GameDrawDeck.AddCardToDeck(&card);
        Player1.AddCardToDeck(&card);
        card = CCardSpecial(eColor(eColor::Red + i), -1, eSpecialType::ColorChooser);
        GameDrawDeck.AddCardToDeck(&card);
        Player1.AddCardToDeck(&card);

    }




    std::cout << "Deck Player1: " << std::endl << Player1.ShowDeck() << std::endl;
    
    std::cout << "Deck Draw: " << std::endl << GameDrawDeck.ShowDeck() << std::endl;

    std::cout << "Deck Game: " << std::endl << GamePlayDeck.ShowDeck() << std::endl;


}



