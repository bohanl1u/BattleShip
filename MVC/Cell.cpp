//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker): hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker){
    BattleShip::Cell::contents = contents;
}

BattleShip::Cell::Cell(char contents): hiddenMarker('*'), hitMarker('X'), missMarker('O'){
    BattleShip::Cell::contents = contents;
}

char BattleShip::Cell::getContents() const {
    return contents;
}

void BattleShip::Cell::setContents(char contents) {
    BattleShip::Cell::contents = contents;
}

char BattleShip::Cell::getContentsIfHidden() const {
    if (containsShip()){
        if (HasBeenFiredAt()){
            return hitMarker;
        }
        else{
            return hiddenMarker;
        }
    }
    else{
        if (HasBeenFiredAt()){
            return missMarker;
        }
        else{
            return hiddenMarker;
        }
    }
}

char BattleShip::Cell::getContentsIfVisible() const {
    if (containsShip()){
        if (HasBeenFiredAt()){
            return hitMarker;
        }
        else{
            return contents;
        }
    }
    else{
        if (HasBeenFiredAt()){
            return missMarker;
        }
        else{
            return hiddenMarker;
        }
    }
}

bool BattleShip::Cell::HasBeenFiredAt() const {
    return BattleShip::Cell::firedAt;
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt){
    BattleShip::Cell::firedAt = hasBeenFiredAt;
}

bool BattleShip::Cell::containsShip() const {
    if ((BattleShip::Cell::contents != BattleShip::Cell::hiddenMarker) && (BattleShip::Cell::contents != missMarker)) {
        return true;
    }
    else {
        return false;
    }
}