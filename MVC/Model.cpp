//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"

BattleShip::Model::Model() {

}

BattleShip::Player &BattleShip::Model::getAttackingPlayer() {
    return <#initializer#>;
}

const BattleShip::Player &BattleShip::Model::getAttackingPlayer() const {
    return <#initializer#>;
}

BattleShip::Player &BattleShip::Model::getDefendingPlayer() {
    return <#initializer#>;
}

const BattleShip::Player &BattleShip::Model::getDefendingPlayer() const {
    return <#initializer#>;
}

bool BattleShip::Model::isGameOver() const {
    return false;
}

void BattleShip::Model::changeTurn() {

}

void BattleShip::Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {

}

void BattleShip::Model::endGame() {

}

std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove() {
    return std::unique_ptr<BattleShip::Move>();
}

BattleShip::Player &BattleShip::Model::getWinner() {
    return <#initializer#>;
}

void BattleShip::Model::SetOpponents() {

}

