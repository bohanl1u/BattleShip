//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"

BattleShip::Board::Board(int numRows, int numCols, char blankChar):  blankChar(blankChar){

    for(int i=0; i<numRows; i++){
        std::vector<Cell> curRow;
        for(int j=0; j < numCols; j++){
            curRow.push_back(this->blankChar);
        }
        boardState.push_back(curRow);
    }

}

BattleShip::Board::Board(int numRows, int numCols): boardState(std::vector<std::vector<Cell>>()), blankChar('*'){

    for(int i=0; i<numRows; i++){
        std::vector<Cell> curRow;
        for(int j=0; j < numCols; j++){
            curRow.push_back(blankChar);
        }
        boardState.push_back(curRow);
    }
}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
    if (inBounds(shipPlacement)&&spacesAreEmpty(shipPlacement)){
        return true;
    }
    else{
        return false;
    }
}

int BattleShip::Board::getNumRows() const {
    return boardState.size();
}

int BattleShip::Board::getNumCols() const {
    return boardState[0].size();
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
    std::vector<std::string> vec;
    std::string str;
    for(int i=0; i<getNumRows(); i++){

        for(int j=0; j < getNumCols(); j++){
            str += boardState[i][j].getContentsIfHidden();
        }
        vec.push_back(str);
        str = "";
    }
    return vec;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
    std::vector<std::string> vec;
    std::string str;
    for(int i=0; i<getNumRows(); i++){
        for(int j=0; j < getNumCols(); j++){
            str += boardState[i][j].getContentsIfVisible();
        }
        vec.push_back(str);
        str = "";
    }
    return vec;
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
    if (canPlaceShipAt(shipPlacement)){
        for (int i=shipPlacement.rowStart; i<=shipPlacement.rowEnd; i++){
            for (int j=shipPlacement.colStart; j<=shipPlacement.colEnd; j++){
                at(i, j).setContents(shipChar);
            }
        }
    }
}

bool BattleShip::Board::inBounds(int row, int col) const {
    return ((between(row, 0, getNumRows()))&&(between(col, 0, getNumCols())));
}

BattleShip::Cell& BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}

const BattleShip::Cell& BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}
bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
    return between(shipPlacement.rowStart, 0, getNumRows())&&between(shipPlacement.rowEnd, 0,
                                                                     getNumRows())&&between(shipPlacement.colStart, 0, getNumRows())&&between(shipPlacement.colEnd, 0, getNumRows());
}

bool BattleShip::Board::between(int value, int low, int high) const {
    if ((value >= low)&&(value <= high)){
        return true;
    }
    else{
        return false;
    }
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const {
    bool b = false;
    for (int i=shipPlacement.rowStart; i<=shipPlacement.rowEnd; i++){
        for (int j=shipPlacement.colStart; j<=shipPlacement.colEnd; j++){
            if (at(i, j).getContents()=='*'){
                b = true;
            }
            else{
                b = false;
            }
        }
    }
    return b;
}