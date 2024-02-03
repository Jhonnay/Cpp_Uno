#include "CCardSpecial.h"


CCardSpecial::CCardSpecial(eColor color, int number, eSpecialType eType)
    : CCard(color, number), eSpecialCardType(eType)
{


}

eSpecialType CCardSpecial::GetSpecialType() const {
    return eSpecialCardType;
}

void CCardSpecial::SetSpecialType(eSpecialType eType) {
    eSpecialCardType = eType;
}

bool CCardSpecial::IsSpecialCard() const {
    return eSpecialCardType != eSpecialType::Normal ;
}

std::string CCardSpecial::DisplayCard() const {
    std::string strDisplay = CCard::DisplayCard();
    std::string strSpecialType;

    switch (eSpecialCardType) {
    case Plus2:
        strSpecialType = "Plus2";
        break;
    case Plus4:
        strSpecialType = "Plus4";
        break;
    case Block:
        strSpecialType = "Block";
        break;
    case Reverse:
        strSpecialType = "Reverse";
        break;
    case Normal:
        strSpecialType = "Normal";
        break;
    case ColorChooser:
        strSpecialType = "ColorChooser";
        break;
    default:
        strSpecialType = "Unknown";
        break;
    }

    return strDisplay + ", Type - " + strSpecialType + "\n";
}