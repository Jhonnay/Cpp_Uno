#pragma once
#include "CCard.h"

#ifndef CCARDSPECIAL_H
#define CCARDSPECIAL_H


enum eSpecialType {
    Normal = 1,
	Plus2,
	Plus4,
	Block,
	Reverse,
    ColorChooser,
	LastElementSpecial
};

class CCardSpecial : public CCard {
public:
    CCardSpecial(eColor color, int number, eSpecialType specialType);

    // Getter and setter for Special Type
    eSpecialType GetSpecialType() const;
    void SetSpecialType(eSpecialType specialType);

    // Function to check if the card is special
    bool IsSpecialCard() const;

    // Override show card function
    virtual std::string DisplayCard() const override;

private:
    eSpecialType eSpecialCardType;
};

#endif // CCARDSPECIAL_H

