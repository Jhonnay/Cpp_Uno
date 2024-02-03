#pragma once

#ifndef CCARD_H
#define CCARD_H

#include <iostream>
#include <string>

enum eColor {
    Red = 1,
    Green,
    Blue,
    Yellow,
    Special,
    LastElement
};

class CCard {
public:
    CCard(eColor color, int number);

    // Getter functions
    eColor GetColor() const;
    int GetNumber() const;

    // Setter functions
    void SetColor(eColor color);
    void SetNumber(int number);

    // Function to display card information
    virtual std::string DisplayCard() const;

private:
    eColor m_eColor;
    int m_nNumber;
};

#endif // CCARD_H