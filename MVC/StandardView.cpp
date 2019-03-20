//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

BattleShip::StandardView::StandardView() {

}

BattleShip::StandardView::StandardView(std::istream &in, std::ostream &out) {

}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
    return BattleShip::PlayerConfiguration(0, 0);
}

std::string BattleShip::StandardView::getPlayerName(int i) {
    return std::string();
}

ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    return ShipPlacement();
}

void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player &player) {

}

std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player &attacker) {
    return std::pair<int, int>();
}

void BattleShip::StandardView::showWinner(const BattleShip::Player &winner) {

}

void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &attacker,
                                                  const BattleShip::AttackResult &attackResult) {

}

void BattleShip::StandardView::showPlayersBoard(const BattleShip::Player &player) {

}

void BattleShip::StandardView::showPlacementBoard(const BattleShip::Player &player) {

}

void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {

}

void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {

}

void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {

}

int BattleShip::StandardView::getAiChoice() {
    return 0;
}

void BattleShip::StandardView::clearInput() {

}
