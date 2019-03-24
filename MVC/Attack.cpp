//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"
#include <iostream>


BattleShip::Attack::Attack(BattleShip::Player &attacker, int row, int col): BattleShip::Move(attacker), row(row), col(col) {
}

void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::View &view) {
    view.showPlayersBoard(moveMaker);
    std::cout<<moveMaker.getName()<<"'s Placement Board"<<std::endl;
    view.showPlacementBoard(moveMaker);
    BattleShip::AttackResult result = moveMaker.fireAt(getRow(), getCol());
    view.showResultOfAttack(moveMaker, result);

}

bool BattleShip::Attack::isValid() const {
    return moveMaker.getBoard().inBounds(getRow(), getCol());
}

const int BattleShip::Attack::getRow() const {
    return row;
}

const int BattleShip::Attack::getCol() const {
    return col;
}
