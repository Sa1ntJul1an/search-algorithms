#include "breadthFirst.h"
#include "cell.h"

BreadthFirstSearch::BreadthFirstSearch(const Cell& start, const Cell& goal, std::vector<std::vector<Cell*>>& stateSpace) : Search(start, goal, stateSpace){}

void BreadthFirstSearch::update(){
    return;
}

void BreadthFirstSearch::initialize(){
    _width = _stateSpace.size();
    _height = _stateSpace.at(0).size();

    for (int row = 0; row < _width; row++){
        for (int col = 0; col < _height; col++){
            Cell* currentCell = _stateSpace.at(row).at(col);

            if (currentCell->isObstacle()){
                continue;
            }

            for (int row_offset = -1; row_offset <= 1; row_offset++){
                for (int col_offset = -1; col_offset <= 1; col_offset++){
                    if (row + row_offset > 0 && row + row_offset < _width - 1){
                        if (col + col_offset > 0 && col + col_offset < _height - 1){
                            
                            Cell* neighbor = _stateSpace.at(row + row_offset).at(col + col_offset);

                            if (!neighbor->isObstacle()){
                                currentCell->addNeighbor(neighbor);
                            }
                        }
                    }
                }
            }

        }
    }
}