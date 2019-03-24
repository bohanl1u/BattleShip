//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::Controller::Controller(): hasBeenSetUp(false), model(BattleShip::Model()) {
    BattleShip::StandardView stdview;
    this->view = std::make_unique<StandardView>(stdview);
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {
// in setupGame, you should make sure to setup the game so that it is ready to begin.
// So you need at least to:
//Load game configuration from the file.
//get the player configuration (type of game ).
//create and add the players to your game
// ( you can see in the add player function, it calls placeShips for each player..
// so this is part of the setup, and set the opponents for all the players
    AiPlayer::seed_random_number_generator(seed);
    setupGame(GameConfigurationFile);
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {
    model.loadGameConfigurationFromFile(GameConfigurationFile);
    PlayerConfiguration playerConfig = (*view).getPlayerConfiguration();
    for (int i=0; i<playerConfig.numHumanPlayers; i++){
        model.addPlayer<HumanPlayer>(*view);
    }
    for (int j=0; j<playerConfig.numAiPlayers; j++){
        int numAI = (*view).getAiChoice();
        if (numAI == 1){
            model.addPlayer<RandomAI>(*view);
        }
        else if (numAI == 2){
            model.addPlayer<RandomAI>(*view);
        }
        else if (numAI == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }
    }
    model.SetOpponents();
    hasBeenSetUp = true;

}

void BattleShip::Controller::setupGame() {
}

void BattleShip::Controller::playGame() {
//in PlayGame: you can get the move from the current player,
// enact the move then change the turn until the game is over!

    while (!model.isGameOver()){
        model.getNextMove()->enact(model, *view);
        model.changeTurn();
    }
    view->showWinner(model.getWinner());
}
