#include "presentation_service.h"

#include <iostream>

void PresentationService::ClearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void PresentationService::PrintBoard(const BoardState &board_state) {
  auto board = board_state.GetBoard();
  for (int i = 0; i < 9; ++i) {
    if (board[i] == 0) {
      std::cout << "# ";
    } else {
      std::cout << board[i] << " ";
    }
    if ((i + 1) % 3 == 0)
      std::cout << std::endl;
  }
}

std::string BoardPieceToString(int board_piece) {
  if (board_piece == 0) {
    return "#";
  }
  return std::to_string(board_piece);
}

void PresentationService::PrintSolution(const BoardState &initial_board,
                                        const std::vector<Move> &moves) {
  static const std::array<std::string, 4> move_string = {"UP", "DOWN", "LEFT",
                                                         "RIGHT"};
  static const size_t ROW_CNT = 6;
  std::vector<BoardState> boards = {initial_board};
  auto board = initial_board;
  for (auto move : moves) {
    board = board.MakeMove(move);
    boards.push_back(board);
  }
  for (size_t start_i = 0; start_i < boards.size(); start_i += ROW_CNT) {
    for (size_t k = 0; k < 3; ++k) {
      for (size_t i = start_i; (i < start_i + ROW_CNT) && (i < boards.size());
           ++i) {
        std::cout << BoardPieceToString(boards[i].GetBoard()[3 * k]) << " "
                  << BoardPieceToString(boards[i].GetBoard()[3 * k + 1]) << " "
                  << BoardPieceToString(boards[i].GetBoard()[3 * k + 2]);
        if ((k == 1) && (i + 1 != boards.size())) {
          std::cout << " -> ";
        } else {
          std::cout << "    ";
        }
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

void PresentationService::PrintSolutionInfo(
    const std::vector<Move> &moves, std::chrono::milliseconds duration) {
  std::cout << "Solution length = " << moves.size() << std::endl;
  std::cout << "Calculation time = " << duration.count() << " milliseconds"
            << std::endl;
  std::cout << std::endl;
}