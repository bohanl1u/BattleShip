//
// Created by mfbut on 3/10/2019.
//

#include <algorithm>
#include "ShipPlacement.h"
ShipPlacement::ShipPlacement() {
}

ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd) {
    ShipPlacement::rowStart = rowStart;
    ShipPlacement::colStart = colStart;
    ShipPlacement::rowEnd = rowEnd;
    ShipPlacement::colEnd = colEnd;
}

void ShipPlacement::normalize() {
    if (rowStart>rowEnd){
        int temp = rowEnd;
        rowEnd = rowStart;
        rowStart = temp;
    }
    if (colStart>colEnd){
        int temp = colEnd;
        colEnd = colStart;
        colStart = temp;
    }
}