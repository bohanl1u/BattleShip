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

}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return <#initializer#>;
}

std::istream& BattleShip::GameAttributes::operator>>(std::istream& in, BattleShip::GameAttributes& gameAttributes){

}