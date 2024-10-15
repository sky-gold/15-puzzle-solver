#pragma once

#include "board_state.h"
#include <random>

class BoardGenerator {
public:
  static const int NUM_MOVES = 200;

  BoardGenerator();
  BoardState Generate() const;

private:
  mutable std::mt19937 rng_;
};