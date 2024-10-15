#pragma once

#include "board_state.h"

#include <chrono>

class PresentationService {
public:
  static void ClearScreen();
  static void PrintBoard(const BoardState &board);
  static void PrintSolution(const BoardState &initial_board,
                            const std::vector<Move> &moves);
  static void PrintSolutionInfo(const std::vector<Move> &moves,
                                std::chrono::milliseconds duration);
};
