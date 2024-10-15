#include "board_generator.h"
#include <algorithm>
#include <array>
#include <gtest/gtest.h>

TEST(BoardGeneratorTest, GenerateBoard) {
  BoardGenerator generator;

  for (int i = 0; i < 10; ++i) {
    BoardState board = generator.Generate();
    const std::array<int, 9> &board_array = board.GetBoard();

    std::array<int, 9> expected_elements = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::array<int, 9> actual_elements = board_array;

    std::sort(actual_elements.begin(), actual_elements.end());

    EXPECT_EQ(expected_elements, actual_elements);
  }
}
