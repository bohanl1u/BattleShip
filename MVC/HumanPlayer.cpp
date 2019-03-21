//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"

BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : Player(
        gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
    std::pair<int, int> pair = view.getFiringCoordinate(*this);
    return std::make_unique<BattleShip::Attack>(*this, pair.first, pair.second);
}

void BattleShip::HumanPlayer::placeShips() {
    for (int i=0; i<shipHealths.size(); i++){
        char shipChar = shipHealths.;
        getBoard().AddShip(view.getShipPlacement(this, shipHealths));
    }
}

void BattleShip::HumanPlayer::initializeName() {
    setName(view.getPlayerName(getId()+1));
}
