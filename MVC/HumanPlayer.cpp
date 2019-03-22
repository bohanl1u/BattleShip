//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"
#include "stdio.h"

BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : Player(
        gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
    std::pair<int, int> pair = view.getFiringCoordinate(*this);
    return std::make_unique<BattleShip::Attack>(*this, pair.first, pair.second);
}

void BattleShip::HumanPlayer::placeShips() {
    for (auto const&x : shipHealths){
        char shipChar = x.first;
        int shipLen = x.second;
        board.AddShip(shipChar, view.getShipPlacement(*this, shipChar, shipLen));
        view.updateShipPlacementView(*this);
    }
}

void BattleShip::HumanPlayer::initializeName() {
    setName(view.getPlayerName(getId()+1));
}
