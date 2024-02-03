#pragma once

#include <iostream>
#include <vector>
#include "CCardSpecial.h"
#include <algorithm>
#include <random>

#ifndef CCARDDECK_H
#define CCARDDECK_H

class CCardDeck {
public:
    // Constructor
    CCardDeck();

    CCardDeck(CCardDeck* pExternalDrawDeck, CCardDeck* pExternalPlayDeck);

    // Destructor
    ~CCardDeck();

    // Getter for deck size
    int GetDeckSize();

    // Display all cards in the deck
    std::string ShowDeck();

    // Add a card to the deck
    void AddCardToDeck(CCardSpecial* pCard);

    // Remove a card from the deck
    void RemoveCardFromDeck(int nIndex);

    // Draw cards from external Draw Deck (m_pExternalDrawCardDeck)
    bool DrawCard(int nNumberCards);

    // Place a card into the deck
    bool PlaceCard(int nCardIndex);

    bool IsValidCardIndex(int nCardIndex);

    // Check if a card can be placed at a specific index
    bool CanPlaceCard(int nCardIndex);

    void Shuffle();

    CCardSpecial* GetLastCard();

private:
    std::vector<CCardSpecial> m_arrCardDeck;
    CCardDeck* m_pExternalDrawCardDeck;
    CCardDeck* m_pExternalPlayCardDeck;
};

#endif CCARDDECK_H