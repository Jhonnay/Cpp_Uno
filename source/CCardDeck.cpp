#include "CCardDeck.h"


// Constructor
CCardDeck::CCardDeck() {
    m_pExternalDrawCardDeck = NULL;
    m_pExternalPlayCardDeck = NULL;
}

CCardDeck::CCardDeck(CCardDeck* pExternalDrawDeck, CCardDeck* pExternalPlayDeck) {
    m_pExternalDrawCardDeck = pExternalDrawDeck;
    m_pExternalPlayCardDeck = pExternalPlayDeck;
}

// Destructor
CCardDeck::~CCardDeck() {
    // Optionally, perform cleanup if needed
}


// Getter for deck size
int CCardDeck::GetDeckSize() {
    return (int)m_arrCardDeck.size();
}

// Display all cards in the deck
std::string CCardDeck::ShowDeck() {
    std::string result;
    int i = 1;
    for (const auto& card : m_arrCardDeck) {
        result += std::to_string(i) + ") " + card.DisplayCard();  // Assuming displayCard() returns a string
        i++;
    }

    if (result.empty()) {
        result = "Empty Deck";
    }

    return result;
}

// Add a card to the deck
void CCardDeck::AddCardToDeck(CCardSpecial* pCard) {
    if (pCard != nullptr) {
        if (pCard->IsSpecialCard()) {
            pCard->SetNumber(-1);
        }
        m_arrCardDeck.push_back(*pCard);
    }
}

// Remove a card from the deck
void CCardDeck::RemoveCardFromDeck(int nIndex) {
    if (nIndex >= 0 && nIndex < GetDeckSize()) {
        m_arrCardDeck.erase(m_arrCardDeck.begin() + nIndex);
    }
}

// Draw cards from another deck
bool CCardDeck::DrawCard(int nNumberCards) {
    if (!m_pExternalDrawCardDeck) {
        throw std::runtime_error("External Deck invalid!");
        return false;
    }

    if (m_pExternalDrawCardDeck->m_arrCardDeck.empty()) {
        throw std::runtime_error("External Deck Empty!");
        return false;
    }

    for (int i = 0; i < nNumberCards; ++i) {
        m_arrCardDeck.push_back(m_pExternalDrawCardDeck->m_arrCardDeck.back());
        m_pExternalDrawCardDeck->m_arrCardDeck.pop_back();
    }

    return true;
}

// Place own card unto external deck
bool CCardDeck::PlaceCard(int nCardIndex) {
    nCardIndex--;
    if (!m_pExternalPlayCardDeck) {
        throw std::runtime_error("External Deck invalid!");
        return false;
    }

    if (!IsValidCardIndex(nCardIndex)) {
        throw std::runtime_error("Place Card index outside of range!");
        return false;
    }

    if (CanPlaceCard(nCardIndex)) {
        m_pExternalPlayCardDeck->m_arrCardDeck.push_back(m_arrCardDeck.back());
        m_arrCardDeck.pop_back();
        return true;
    }

    return false;
}

bool CCardDeck::IsValidCardIndex(int nCardIndex)
{
    return nCardIndex >= 0 && nCardIndex < GetDeckSize();
}

// Check if a card can be placed at a specific index
bool CCardDeck::CanPlaceCard(int nCardIndex) {
    if (!m_pExternalPlayCardDeck) {
        return false;
    }

    if (!IsValidCardIndex(nCardIndex)) {
        throw std::runtime_error("Place Card index outside of range!");
        return false;
    }

    CCardSpecial* pMyCard = GetLastCard();
    CCardSpecial* pExternalCard = m_pExternalPlayCardDeck->GetLastCard();
    if (!pMyCard || !pExternalCard) {
        throw std::runtime_error("Place Card nullptr Exception");
    }


    if (pMyCard->GetColor() == pExternalCard->GetColor() ||
        (pMyCard->GetNumber() == pExternalCard->GetColor() && pMyCard->GetColor() != eColor::Special && pExternalCard->GetColor() != eColor::Special) ||
        pMyCard->GetSpecialType() == pExternalCard->GetSpecialType()) {
        return true;
    }


    return false;
}

void CCardDeck::Shuffle()
{
    std::shuffle(m_arrCardDeck.begin(), m_arrCardDeck.end(), std::default_random_engine(std::random_device()()));
}

CCardSpecial* CCardDeck::GetLastCard()
{
    CCardSpecial* card = m_arrCardDeck.data() + m_arrCardDeck.size() - 1;
    
    return card;
}
