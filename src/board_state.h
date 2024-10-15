#pragma once

#include <array>
#include <functional>
#include <stddef.h>

enum Move { UP, DOWN, LEFT, RIGHT };

class BoardState {
public:
  BoardState();
  BoardState(const std::array<int, 9> &board);
  BoardState MakeMove(Move direction) const;
  bool IsValidMove(Move direction) const;
  bool IsSolved() const;
  const std::array<int, 9> &GetBoard() const;
  bool operator==(const BoardState &other) const;
  bool operator!=(const BoardState &other) const;

private:
  std::array<int, 9> board_;
  void Swap(size_t i, size_t j);
  int FindEmptyIndex() const;
};

template <> struct std::hash<BoardState> {
  std::size_t operator()(const BoardState &state) const {
    const std::array<int, 9> &board = state.GetBoard();
    size_t seed = 0;
    for (int i = 0; i < 9; ++i) {
      seed ^=
          std::hash<int>{}(board[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};