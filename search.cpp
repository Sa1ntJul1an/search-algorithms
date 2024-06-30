#include "search.h"
#include "cell.h"
#include "searchAlgorithms.h"

Search::Search(Cell * start, Cell * goal, const std::vector<std::vector<Cell*>>& stateSpace){
    _start = start;
    _goal = goal;
    _stateSpace = stateSpace;
}

void Search::_populateNeighbors(){
    _width = _stateSpace.size();
    _height = _stateSpace[0].size();

    for (int row = 0; row < _width; row++){
        for (int col = 0; col < _height; col++){
            Cell* currentCell = _stateSpace.at(row).at(col);

            if (currentCell->isObstacle()){
                continue;
            }

            for (int row_offset = -1; row_offset <= 1; row_offset++){
                for (int col_offset = -1; col_offset <= 1; col_offset++){
                    if (row + row_offset >= 0 && row + row_offset <= _width - 1){
                        if (col + col_offset >= 0 && col + col_offset <= _height - 1){
                            
                            Cell* neighbor = _stateSpace[row + row_offset][col + col_offset];

                            if (!(neighbor->isObstacle())){
                                currentCell->addNeighbor(neighbor);
                            }

                        }
                    }
                }
            }

        }
    }
}