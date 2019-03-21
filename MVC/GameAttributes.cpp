//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes() {

}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols) {
    setNumRows(numRows);
    setNumCols(numCols);
}

BattleShip::GameAttributes::GameAttributes(std::istream &in) {
    if(in){
        verifiedRead(in, numRows);
        verifiedRead(in, numCols);

        int numShips;
        verifiedRead(in, numShips);

        char shipChar;
        int shipSize;
        for (int i=0; i<numShips; i++){
            verifiedRead(in, shipChar);
            verifiedRead(in, shipSize);
            shipAttributes.insert(std::make_pair(shipChar, shipSize));
        }
    }
}

int BattleShip::GameAttributes::getNumRows() const {
    return this->numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
    this->numRows = numRows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return this->numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
    this->numCols = numCols;
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
    return shipAttributes.at(ShipChar);
}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return this->shipAttributes;
}

std::istream& BattleShip::operator>>(std::istream& in, BattleShip::GameAttributes& gameAttributes){
    gameAttributes = GameAttributes(in);
    return in;
}