//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {
    BattleShip::Board& curLoc = getOpponent().getBoard();
    for (int i=0; i<curLoc.getNumRows(); i++){
        for (int j=0; j<curLoc.getNumCols(); j++){
            if (curLoc.at(i, j).containsShip()&&!curLoc.at(i, j).HasBeenFiredAt()){
                return std::make_unique<BattleShip::Attack>(*this, i, j);
            }
        }
    }
    return std::make_unique<BattleShip::Attack>(*this, 0, 0);
}


