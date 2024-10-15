#include "board_state.h"

BoardState::BoardState() : board_{1, 2, 3, 4, 5, 6, 7, 8, 0} {}

BoardState::BoardState(const std::array<int, 9> &board) : board_(board) {}

BoardState BoardState::MakeMove(Move direction) const {
  int empty_index = FindEmptyIndex();
  int new_index = empty_index;
  switch (direction) {
  case UP:
    new_index -= 3;
    break;
  case DOWN:
    new_index += 3;
    break;
  case LEFT:
    new_index -= 1;
    break;
  case RIGHT:
    new_index += 1;
    break;
  }

  BoardState new_state{*this};
  new_state.Swap(new_index, empty_index);
  return new_state;
}

bool BoardState::IsValidMove(Move direction) const {
  int empty_index = FindEmptyIndex();
  switch (direction) {
  case UP:
    return empty_index >= 3;
  case DOWN:
    return empty_index < 6;
  case LEFT:
    return empty_index % 3 != 0;
  case RIGHT:
    return empty_index % 3 != 2;
  }
}

bool BoardState::IsSolved() const {
  const static std::array<int, 9> solved_board = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  return board_ == solved_board;
}

const std::array<int, 9> &BoardState::GetBoard() const { return board_; }

bool BoardState::operator==(const BoardState &other) const {
  return board_ == other.board_;
}

bool BoardState::operator!=(const BoardState &other) const {
  return board_ != other.board_;
}

int BoardState::FindEmptyIndex() const {
  for (int i = 0; i < 9; ++i) {
    if (board_[i] == 0) {
      return i;
    }
  }
}

void BoardState::Swap(size_t i, size_t j) { std::swap(board_[i], board_[j]); }