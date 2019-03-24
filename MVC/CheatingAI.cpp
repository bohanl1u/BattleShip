//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes, view) {
}

//std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {
//    int numRows = getOpponent().getBoard().getNumRows();
//    int numCols = getOpponent().getBoard().getNumCols();
//    for (int i=0; i<numRows; i++){
//
//    }
//}


