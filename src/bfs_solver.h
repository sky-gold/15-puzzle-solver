#pragma once

#include "board_state.h"

#include <unordered_map>
#include <vector>

class BfsSolver {
private:
  std::unordered_map<BoardState, std::pair<BoardState, Move>> parent_;

public:
  std::vector<Move> Solve(const BoardState &initial_board);
};
