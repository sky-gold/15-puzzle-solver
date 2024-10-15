#include "board_generator.h"

BoardGenerator::BoardGenerator() : rng_(std::random_device()()) {}

BoardState BoardGenerator::Generate() const {
  BoardState state;
  static const std::array<Move, 4> all_moves = {UP, DOWN, LEFT, RIGHT};
  for (int i = 0; i < NUM_MOVES; ++i) {
    Move move;
    do {
      move = all_moves[rng_() % 4];
    } while (!state.IsValidMove(move));
    state = state.MakeMove(move);
  }

  return state;
}