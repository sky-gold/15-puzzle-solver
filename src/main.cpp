#include "bfs_solver.h"
#include "board_generator.h"
#include "presentation_service.h"

#include <chrono>
#include <iostream>

int main() {
  PresentationService::ClearScreen();
  BoardGenerator generator;
  const BoardState state = generator.Generate();
  std::cout << "Generated Board:" << std::endl;
  PresentationService::PrintBoard(state.GetBoard());
  std::cout << std::endl;
  BfsSolver bfs_solver;

  auto start = std::chrono::high_resolution_clock::now();
  const auto moves = bfs_solver.Solve(state);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

  PresentationService::PrintSolution(state, moves);
  PresentationService::PrintSolutionInfo(moves, duration);
  return 0;
}