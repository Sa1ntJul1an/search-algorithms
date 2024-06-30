#include "breadthFirst.h"
#include "cell.h"

#include <iostream>

BreadthFirstSearch::BreadthFirstSearch(Cell * start, Cell * goal, const std::vector<std::vector<Cell*>>& stateSpace) : Search(start, goal, stateSpace){
    _stateSpace = stateSpace;
    _start = start;
    _goal = goal;
}

void BreadthFirstSearch::update(){
    if (_frontier.empty()){
        std::cout << "Frontier empty..." << std::endl;
        return;
    }

    Cell* currentCell = _frontier.front();
    _frontier.pop();
    currentCell->setFrontier(false);

    if (currentCell == _goal){
        return;
    }

    std::vector<Cell*> neighbors = currentCell->getNeighbors();
    int numNeighbors = neighbors.size();

    for (int i = 0; i < numNeighbors; i ++){
        Cell * neighbor = neighbors[i];
        if (!neighbor->isExplored()){
            neighbor->setExplored(true);
            neighbor->setParent(currentCell);
            neighbor->setFrontier(true);
            _frontier.push(neighbor);
        }
    }
}

void BreadthFirstSearch::initialize(){

    std::cout << "Initializing breadth first search..." << std::endl;

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

    _frontier.push(_start);
    _start->setExplored(true);

    std::cout << "Node tree created, beginning search." << std::endl;
}