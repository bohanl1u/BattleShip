//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"

int BattleShip::Player::num_instances = 0;

BattleShip::Player::Player(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view): id(BattleShip::Player::num_instances),
        view(view), board(BattleShip::Board(gameAttributes.getNumRows(), gameAttributes.getNumCols())) {
    BattleShip::Player::num_instances++;
    shipHealths = gameAttributes.getShipAttributes();
}

const std::string &BattleShip::Player::getName() const {
    return this->name;
}

void BattleShip::Player::setName(const std::string &name) {
    this->name = name;
}

const BattleShip::Board &BattleShip::Player::getBoard() const {
    return this->board;
}

BattleShip::Board &BattleShip::Player::getBoard() {
    return this->board;
}

const int BattleShip::Player::getId() const {
    return this->id;
}

bool BattleShip::Player::operator==(const BattleShip::Player &rhs) const {
    return false;
}

bool BattleShip::Player::operator!=(const BattleShip::Player &rhs) const {
    return false;
}

bool BattleShip::Player::allShipsSunk() const {
    return shipHealths.empty();
}

BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {
    char charAt = getOpponent().getBoard().at(row, col).getContents();
    bool destroyed;
    bool h = this->hit(charAt);
    if (h){
        shipHealths.at(charAt)--;
        if(shipHealths.at(charAt)==0){
            destroyed = true;
            shipHealths.erase(charAt);
        }
        else{
            destroyed = false;
        }
    }
    else{
        destroyed = false;
    }
    return AttackResult(h, destroyed, charAt);
}

BattleShip::Player &BattleShip::Player::getOpponent() {
    return *opponent;
}

const BattleShip::Player &BattleShip::Player::getOpponent() const {
    return *opponent;
}

void BattleShip::Player::setOpponent(BattleShip::Player &opponent) {
    this->opponent = &opponent;
}

bool BattleShip::Player::hit(char shipChar) {
    if (shipChar == '*'){
        return false;
    }
    else{
        return true;
    }
}
