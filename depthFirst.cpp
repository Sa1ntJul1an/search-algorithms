#include "depthFirst.h"
#include "cell.h"

DepthFirstSearch::DepthFirstSearch(const Cell& start, const Cell& goal, std::vector<std::vector<Cell*>> stateSpace) : Search(start, goal, stateSpace){}

void DepthFirstSearch::update(){
    return;
}

void DepthFirstSearch::initialize(){
    return;
}