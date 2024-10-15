#include "board_state.h"
#include <gtest/gtest.h>

TEST(BoardStateTest, DefaultConstructor) {
  BoardState board;
  std::array<int, 9> expected_board = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  EXPECT_EQ(board.GetBoard(), expected_board);
}

TEST(BoardStateTest, ParameterizedConstructor) {
  std::array<int, 9> initial_board = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  BoardState board(initial_board);
  EXPECT_EQ(board.GetBoard(), initial_board);
}

TEST(BoardStateTest, MakeMove) {
  std::array<int, 9> initial_board = {1, 2, 3, 4, 0, 5, 6, 7, 8};
  BoardState board(initial_board);

  BoardState new_board = board.MakeMove(DOWN);
  std::array<int, 9> expected_board_down = {1, 2, 3, 4, 7, 5, 6, 0, 8};
  EXPECT_EQ(new_board.GetBoard(), expected_board_down);

  new_board = board.MakeMove(RIGHT);
  std::array<int, 9> expected_board_right = {1, 2, 3, 4, 5, 0, 6, 7, 8};
  EXPECT_EQ(new_board.GetBoard(), expected_board_right);

  new_board = board.MakeMove(UP);
  std::array<int, 9> expected_board_up = {1, 0, 3, 4, 2, 5, 6, 7, 8};
  EXPECT_EQ(new_board.GetBoard(), expected_board_up);

  new_board = board.MakeMove(LEFT);
  std::array<int, 9> expected_board_left = {1, 2, 3, 0, 4, 5, 6, 7, 8};
  EXPECT_EQ(new_board.GetBoard(), expected_board_left);
}

TEST(BoardStateTest, IsValidMove) {
  std::array<int, 9> initial_board = {1, 2, 3, 4, 0, 5, 6, 7, 8};
  BoardState board1(initial_board);
  BoardState board2;

  EXPECT_TRUE(board1.IsValidMove(UP));
  EXPECT_TRUE(board1.IsValidMove(LEFT));
  EXPECT_TRUE(board1.IsValidMove(DOWN));
  EXPECT_TRUE(board1.IsValidMove(RIGHT));

  EXPECT_TRUE(board2.IsValidMove(UP));
  EXPECT_TRUE(board2.IsValidMove(LEFT));
  EXPECT_FALSE(board2.IsValidMove(DOWN));
  EXPECT_FALSE(board2.IsValidMove(RIGHT));
}

TEST(BoardStateTest, IsSolved) {
  std::array<int, 9> solved_board = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  BoardState solved(solved_board);
  EXPECT_TRUE(solved.IsSolved());

  std::array<int, 9> unsolved_board = {1, 2, 3, 4, 0, 5, 6, 7, 8};
  BoardState unsolved(unsolved_board);
  EXPECT_FALSE(unsolved.IsSolved());
}

TEST(BoardStateTest, ComparisonOperators) {
  std::array<int, 9> board1 = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  std::array<int, 9> board2 = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  std::array<int, 9> board3 = {1, 2, 3, 4, 0, 5, 6, 7, 8};

  BoardState state1(board1);
  BoardState state2(board2);
  BoardState state3(board3);

  EXPECT_TRUE(state1 == state2);
  EXPECT_FALSE(state1 != state2);

  EXPECT_FALSE(state1 == state3);
  EXPECT_TRUE(state1 != state3);
}

TEST(BoardStateTest, HashFunction) {
  std::array<int, 9> board1 = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  std::array<int, 9> board2 = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  std::array<int, 9> board3 = {1, 2, 3, 4, 0, 5, 6, 7, 8};

  BoardState state1(board1);
  BoardState state2(board2);
  BoardState state3(board3);

  std::hash<BoardState> hasher;

  EXPECT_EQ(hasher(state1), hasher(state2));
  EXPECT_NE(hasher(state1), hasher(state3));
}
