#include "bfs_solver.h"
#include "board_generator.h"

#include <gtest/gtest.h>

BoardState MakeMoves(const BoardState &board, const std::vector<Move> &moves) {

  BoardState final_board = board;
  for (Move move : moves) {
    final_board = final_board.MakeMove(move);
  }
  return final_board;
}

TEST(BfsSolverTest, SolveTwoMoves) {
  BfsSolver solver;

  BoardState board;
  board = board.MakeMove(UP);
  board = board.MakeMove(LEFT);

  std::vector<Move> solution = solver.Solve(board);

  EXPECT_EQ(solution.size(), 2);
  BoardState final_board = MakeMoves(board, solution);

  EXPECT_TRUE(final_board.IsSolved());
}

TEST(BfsSolverTest, SolveRandomBoard) {
  BfsSolver solver;
  BoardGenerator generator;

  for (int i = 0; i < 10; ++i) {
    BoardState random_board = generator.Generate();

    std::vector<Move> solution = solver.Solve(random_board);

    BoardState final_board = MakeMoves(random_board, solution);

    EXPECT_TRUE(final_board.IsSolved());
  }
}
