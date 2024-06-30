#include "cell.h"
#include <vector>

Cell::Cell(){
    _position = std::vector<int> {0, 0};
    _isGoal = false;
    _isObstacle = false;
    _isExplored = false;
    _isFrontier = false;
}

Cell::Cell (std::vector<int> position){
    _position = position;
    _isObstacle = false;
    _isExplored = false;
}

std::vector<int> Cell::getPosition(){
    return this->_position;
}

void Cell::setObstacle(bool isObstacle){
    this->_isObstacle = isObstacle;
}

bool Cell::isObstacle(){
    return this->_isObstacle;
}

void Cell::setExplored(bool isExplored){
    this->_isExplored = isExplored;
}

bool Cell::isExplored(){
    return this->_isExplored;
}

void Cell::setFrontier(bool isFrontier){
    this->_isFrontier = isFrontier;
}

bool Cell::isFrontier(){
    return this->_isFrontier;
}

void Cell::addNeighbor(Cell* neighbor){
    _neighbors.push_back(neighbor);
}