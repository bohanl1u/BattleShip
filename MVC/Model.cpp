//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"
#include "stdio.h"

BattleShip::Model::Model(): gameAttributes(BattleShip::GameAttributes()),
    players(std::vector<std::unique_ptr<Player>>()), playerTurn(0), forcedGameOver(false) {
}

BattleShip::Player &BattleShip::Model::getAttackingPlayer() {
    return *players[playerTurn];
}

const BattleShip::Player &BattleShip::Model::getAttackingPlayer() const {
    return *players[playerTurn];
}

BattleShip::Player &BattleShip::Model::getDefendingPlayer() {
    return *players[(playerTurn+1)%2];
}

const BattleShip::Player &BattleShip::Model::getDefendingPlayer() const {
    return *players[(playerTurn+1)%2];
}

bool BattleShip::Model::isGameOver() const {
    bool isGameOver = players[playerTurn]->allShipsSunk()||players[(playerTurn+1)%2]->allShipsSunk();
    return isGameOver;
}

void BattleShip::Model::changeTurn() {
    playerTurn = (1 + playerTurn) % 2;
}

void BattleShip::Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {
    std::ifstream f;
    f.open(gameConfigurationFile);
    f>>gameAttributes;
}

void BattleShip::Model::endGame() {

}

std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove() {
    return getAttackingPlayer().getMove();
}

BattleShip::Player &BattleShip::Model::getWinner() {
    return getAttackingPlayer();
}

void BattleShip::Model::SetOpponents() {
    players.front()->setOpponent(*players.back());
    players.back()->setOpponent(*players.front());
}


