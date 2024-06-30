#include "cell.h"
#include <vector>

Cell::Cell(){
    _position = std::vector<int> {0, 0};
    _neighbors.clear();
    _isGoal = false;
    _isObstacle = false;
    _isExplored = false;
    _isFrontier = false;
    _parent = nullptr;
    _isPath = false;
}

Cell::Cell (std::vector<int> position){
    _neighbors.clear();
    _position = position;
    _isGoal = false;
    _isObstacle = false;
    _isExplored = false;
    _isFrontier = false;
    _parent = nullptr;
    _isPath = false;
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

void Cell::setPath(bool isPath){
    this->_isPath = isPath;
}

bool Cell::isPath(){
    return this->_isPath;
}

void Cell::setParent(Cell* parent){
    this->_parent = parent;
}

Cell* Cell::getParent(){
    return this->_parent;
}

void Cell::addNeighbor(Cell* neighbor){
    _neighbors.push_back(neighbor);
}

std::vector<Cell*> Cell::getNeighbors(){
    return this->_neighbors;
}

void Cell::resetState(){
    _neighbors.clear();
    _isObstacle = false;
    _isExplored = false;
    _isFrontier = false;
    _parent = nullptr;
    _isPath = false;
}