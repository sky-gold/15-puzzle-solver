#include "bfs_solver.h"

#include <algorithm>
#include <cassert>

std::vector<Move> BfsSolver::Solve(const BoardState &initial_board) {
  if (initial_board.IsSolved()) {
    return {};
  }
  static const std::array<Move, 4> all_moves = {UP, DOWN, LEFT, RIGHT};
  parent_.clear();
  parent_[initial_board] = {initial_board, UP};
  std::vector<BoardState> q = {initial_board};
  for (size_t i = 0; i < q.size(); ++i) {
    const auto current_board = q[i];
    if (current_board.IsSolved()) {
      break;
    }
    for (auto move : all_moves) {
      if (!current_board.IsValidMove(move)) {
        continue;
      }
      const auto next_board = current_board.MakeMove(move);
      if (parent_.count(next_board)) {
        continue;
      }
      q.push_back(next_board);
      parent_[next_board] = {current_board, move};
    }
  }
  auto board = BoardState();
  std::vector<Move> answer;
  do {
    assert(parent_.count(board));
    auto [new_board, move] = parent_[board];
    answer.push_back(move);
    board = std::move(new_board);
  } while (board != initial_board);
  std::reverse(answer.begin(), answer.end());
  return answer;
}