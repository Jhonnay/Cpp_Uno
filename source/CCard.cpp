#include "CCard.h"

CCard::CCard(eColor color, int number) : m_eColor(color), m_nNumber(number) {
    

}

eColor CCard::GetColor() const {
    return m_eColor;
}

int CCard::GetNumber() const {
    return m_nNumber;
}

void CCard::SetColor(eColor color) {
    m_eColor = color;
}

void CCard::SetNumber(int number) {
    m_nNumber = number;
}

std::string CCard::DisplayCard() const {
    std::string colorString;

    switch (m_eColor) {
    case Red:
        colorString = "Red";
        break;
    case Green:
        colorString = "Green";
        break;
    case Blue:
        colorString = "Blue";
        break;
    case Yellow:
        colorString = "Yellow";
        break;
    case Special:
        colorString = "Special";
        break;
    default:
        colorString = "Invalid";
        break;
    }

    return "Card: Color - " + colorString + ", Number - " + std::to_string(m_nNumber);
}
