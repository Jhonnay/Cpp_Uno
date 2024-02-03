
#include <iostream>
#include "CCardDeck.h"
#include <string>

int main()
{
    CCardDeck GameDrawDeck = CCardDeck();
    CCardDeck GamePlayDeck = CCardDeck();
    CCardDeck Player1 = CCardDeck(&GameDrawDeck, &GamePlayDeck);

    CCardSpecial card = CCardSpecial(eColor::Red, 2, eSpecialType::Normal);
    
    int playerInput; 

    
    GamePlayDeck.AddCardToDeck(&card);

    for (int i = 0; i < eColor::LastElement-2; i++) {
        for (int j = 1; j <= 9; j++) {
            card = CCardSpecial(eColor(eColor::Red + i), j, eSpecialType::Normal);
            GameDrawDeck.AddCardToDeck(&card);
            //Player1.AddCardToDeck(&card);
        }

        for (int j = 0; j <= (eSpecialType::Reverse - eSpecialType::Plus2); j++) {
            card = CCardSpecial(eColor(eColor::Red + i), -1, eSpecialType(eSpecialType::Plus2 + j));
            GameDrawDeck.AddCardToDeck(&card);
            //Player1.AddCardToDeck(&card);
        }
        card = CCardSpecial(eColor::Special, -1, eSpecialType::Plus4);
        GameDrawDeck.AddCardToDeck(&card);
        //Player1.AddCardToDeck(&card);
        card = CCardSpecial(eColor::Special, -1, eSpecialType::ColorChooser);
        GameDrawDeck.AddCardToDeck(&card);
        //Player1.AddCardToDeck(&card);

    }

    GameDrawDeck.Shuffle();

    Player1.DrawCard(6);
    
    while (1) {
        std::cout << "Deck Game: " << std::endl << GamePlayDeck.ShowDeck() << std::endl;
        std::cout << "Deck Player1: " << std::endl << Player1.ShowDeck() << std::endl;

        std::cout << "Place Card: ";
        std::cin >> playerInput;

        if (playerInput == -1) {
            Player1.DrawCard(1);
        }
        else {
            Player1.PlaceCard(playerInput);
        }
    }
    




}



