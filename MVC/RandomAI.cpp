//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes, view) {
    for (int i=0; i<this->board.getNumRows(); i++){
        for (int j=0; j<this->board.getNumCols(); j++){
            firingLocations.push_back(std::make_pair(i, j));
        }
    }
}

std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
    auto itr = chooseRandom(firingLocations, randomNumberGenerator);
    auto itrCopy = itr;
    firingLocations.erase(itr);
    return std::make_unique<Attack>(*this, (*itrCopy).first, (*itrCopy).second);
}
