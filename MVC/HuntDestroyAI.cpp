//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const GameAttributes &gameAttributes, View &view): RandomAI(gameAttributes, view), priorityFiringQueue(std::vector<std::pair<int,int>>()) {

}

std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove() {
    std::unique_ptr<Attack> attack;
    if(!priorityFiringQueue.empty()){
        std::pair<int, int> locationToFire = priorityFiringQueue.front();
        priorityFiringQueue.erase(priorityFiringQueue.cbegin());
        attack = std::make_unique<Attack>(*this, locationToFire.first, locationToFire.second);
    }
    else{
        Attack* temp = dynamic_cast<Attack*>(RandomAI::getMove().release());
        attack.reset(temp);
    }

    std::pair<int, int> attackLocation(attack->getRow(), attack->getCol());
    if (getOpponent().getBoard().at(attackLocation.first, attackLocation.second).containsShip()){
        auto surroundingLocations = getSurroundingLocations(attackLocation);

        for(const auto& x : surroundingLocations){
            auto itr = std::find(firingLocations.begin(), firingLocations.end(), x);
            if (itr != firingLocations.end()){
                priorityFiringQueue.push_back(x);
                firingLocations.erase(itr);
            }
        }
    }
    return attack;
}

std::vector<std::pair<int, int>> BattleShip::HuntDestroyAI::getSurroundingLocations(
        const std::pair<int, int> &center) const {
    int  centerRow = center.first;
    int centerCol = center.second;

    std::vector<std::pair<int, int>> surr;

    std::pair<int, int> up, down, left, right;

    up = std::make_pair(centerRow-1, centerCol);
    down = std::make_pair(centerRow+1, centerCol);
    left = std::make_pair(centerRow, centerCol-1);
    right = std::make_pair(centerRow, centerCol+1);

    surr.push_back(up);
    surr.push_back(down);
    surr.push_back(left);
    surr.push_back(right);

    return surr;
}