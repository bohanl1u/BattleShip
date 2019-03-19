#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {
  // Create Controller object
  BattleShip::Controller controller;
  controller.setupGame();
  controller.playGame();

  return 0;
}
