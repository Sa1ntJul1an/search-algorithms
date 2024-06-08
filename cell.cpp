#include "cell.h"
#include <vector>

Cell::Cell (std::vector<int> position){
    _position = position;
    _isObstacle = false;
    _isExplored = false;
}

std::vector<int> Cell::getPosition(){
    return _position;
}

void Cell::setObstacle(bool isObstacle){
    _isObstacle = isObstacle;
}

bool Cell::isObstacle(){
    return _isObstacle;
}

void Cell::update(){

}
