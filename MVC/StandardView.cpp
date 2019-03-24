//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"
#include "stdio.h"

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
    std::cout<<"Player "<<i<<" please enter your name:"<<std::endl;
    std::string name;
    in >> name;
    return name;
}

void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {
    out<<"  ";
    for(int i = 0; (unsigned)i < board.size(); i++){
        out<<(i)<<" ";
    }
    out<<"\n";
    for (int i = 0; (unsigned)i < board.size(); i++){
        out<<(i);
        for(int j = 0; (unsigned)j< board[i].size(); j++){
            out<<" "<< board[i][j];
        }
        out<<"\n";
    }
}


void BattleShip::StandardView::printBoardAsObscured(const Board &board) {
    std::vector<std::string> hidBoard = board.getHiddenVersion();

    printBoard(hidBoard);

}

void BattleShip::StandardView::printBoardAsVisible(const Board &board) {
    std::vector<std::string>  visBoard = board.getVisibleVersion();

    printBoard(visBoard);

}



void BattleShip::StandardView::showPlayersBoard(const Player& player){
    out<<player.getName()<<"'s Firing Board"<<std::endl;
    printBoardAsObscured(player.getOpponent().getBoard());
}

void BattleShip::StandardView::showPlacementBoard(const Player &player) {
    out<<player.getName()<<"'s Placement Board"<<std::endl;
    printBoardAsVisible(player.getBoard());
}

void BattleShip::StandardView::updateShipPlacementView(const Player &player) {
    printBoardAsVisible(player.getBoard());
}


ShipPlacement BattleShip::StandardView::getShipPlacement(const Player &player, char shipChar, int shipLen) {
    char input;
    int row = 0;
    int col = 0;

    int endRow = 0;
    int endCol = 0;



    out<<player.getName()<< ", do you want to place "<<shipChar<<" horizontally or vertically?\n"
                                                                 "Enter h for horizontal or v for vertical\n"
                                                                 "Your choice: "<<std::endl;

    verifiedRead(in, input);

    if(input == 'v'){


        out<<player.getName() << ", enter the row and column you want to place " << shipChar << ", which is " <<shipLen<< " long, at with a space in between row and col:"<<std::endl;
        verifiedRead(in, row);
        verifiedRead(in, col);

        endRow = row-1+shipLen;
        endCol = col;


    }else
    if( input == 'h'){

        out<<player.getName() << ", enter the row and column you want to place " << shipChar << ", which is " <<shipLen<< " long, at with a space in between row and col:"<<std::endl;
        verifiedRead(in, row);
        verifiedRead(in, col);


        endCol = col-1+shipLen;
        endRow = row;

    }

    ShipPlacement place(row, col, endRow, endCol);

    return  place;

}


std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player &attacker) {
    int row;
    int col;

    out<<attacker.getName()<<", where would you like to fire?\nEnter your attack coordinate in the form row col:";

    verifiedRead(in, row);
    verifiedRead(in, col);

    std::pair<int, int> coord;

    coord = std::make_pair(row, col);

    return coord;
}


void BattleShip::StandardView::showWinner(const Player &winner) {
    out<<winner.getName()<<" won the game!"<<std::endl;
}

void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &attacker,
                                                  const BattleShip::AttackResult &attackResult) {
    if(attackResult.hit&&!attackResult.destroyed){
        out<<attacker.getName()<<" hit "<<attacker.getOpponent().getName()<<"'s "<<attackResult.shipChar<<"!"<<std::endl;
    }else if(attackResult.hit&&attackResult.destroyed){
        out<<attacker.getName()<<" hit "<<attacker.getOpponent().getName()<<"'s "<<attackResult.shipChar<<"!"<<std::endl;
        out<<attacker.getName()<<" destroyed "<<attacker.getOpponent().getName()<<"'s "<<attackResult.shipChar<<"!"<<std::endl;
    }
    else{
        out<<"Missed."<<std::endl;
    }


}





