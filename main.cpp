#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  // Create Controller object
  BattleShip::Controller controller;

  if (argc == 3) {
    controller.setupGame(argv[1], atoi(argv[2]));
  }else if(argc == 2){
    controller.setupGame(argv[1]);
  }
  controller.playGame();

  return 0;
}

/* Test */

