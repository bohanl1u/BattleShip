//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

BattleShip::StandardView::StandardView(): in(std::cin), out(std::cout){
}


BattleShip::StandardView::StandardView(std::istream& in, std::ostream& out): in(in), out(out){
}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration(){
    int numPlayas;
    out<<"What type of game do you want to play?\n"
         "1. Human vs Human\n"
         "2. Human vs AI\n"
         "3. AI vs AI\n"
         "Your choice: "<<std::endl;


    in>>numPlayas;

    if(numPlayas== 1){
        return BattleShip::PlayerConfiguration(2,0);
    }else
    if(numPlayas== 2){
        return BattleShip::PlayerConfiguration(1,1);
    }else
    if(numPlayas== 3){
        return BattleShip::PlayerConfiguration(0,2);
    }else{
        return BattleShip::PlayerConfiguration(0,0);
    }
}

int BattleShip::StandardView::getAiChoice(){
    int numAI;

    out<<"What AI do you want?\n"
         "1. Cheating AI\n"
         "2. Random AI\n"
         "3. Hunt Destroy AI\n"
         "Your choice:"<<std::endl;

    in>>numAI;


    return numAI;
}


std::string BattleShip::StandardView::getPlayerName(int i) {
    std::cout<<"Player 1 please enter your name:"<<std::endl;
    std::string name;
    verifiedRead(in, name);
    return name;
}


void BattleShip::StandardView::printBoardAsObscured(const Board &board) {
    std::vector<std::string> hidBoard = board.getHiddenVersion();
    printBoard(hidBoard);

}

void BattleShip::StandardView::printBoardAsVisible(const Board &board) {
    std::vector<std::string>  visBoard = board.getVisibleVersion();
    printBoard(visBoard);

}

void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {
    for (int i = 0; i < board.size(); i++){
        out<<board[i];
        out<<"\n";
    }
}


void BattleShip::StandardView::showPlayersBoard(const Player& player){

}

void BattleShip::StandardView::showPlacementBoard(const Player &player) {
    printBoardAsVisible(player.getBoard());
}

void BattleShip::StandardView::updateShipPlacementView(const Player &player) {
    showPlacementBoard(player);
}


ShipPlacement BattleShip::StandardView::getShipPlacement(const Player &player, char shipChar, int shipLen) {
    char input;
    int row;
    int col;

    int endRow;
    int endCol;



    out<<player.getName()<< ",  do you want to place "<<shipChar<<" horizontally or vertically?\n"
                                                                  "Enter h for horizontal or v for vertical\n"
                                                                  "Your choice: "<<std::endl;

    verifiedRead(in, input);

    if(input == 'v'){


        out<<player.getName() << ",  enter the row and column you want to place" << shipChar << ", which is " <<shipLen<< " long, at with a space in between row and col:"<<std::endl;
        verifiedRead(in, row);
        verifiedRead(in, col);

        endRow = row+shipLen;
        endCol = col;


    }else
    if( input == 'h'){

        out<<player.getName() << ",  enter the row and column you want to place" << shipChar << ", which is " <<shipLen<< " long, at with a space in between row and col:"<<std::endl;
        verifiedRead(in, row);
        verifiedRead(in, col);


        endCol = row+shipLen;
        endRow = row;

    }

    ShipPlacement place(row, col, endRow, endCol);

    return  place;

}



