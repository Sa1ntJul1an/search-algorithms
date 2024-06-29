#include "searchFactory.h"
#include "searchAlgorithms.h"
#include "search.h"
#include "breadthFirst.h"
#include "depthFirst.h"
#include "cell.h"

Search* SearchFactory::createSearch(const Cell& start, const Cell& goal, std::vector<std::vector<Cell*>> stateSpace, SearchAlgorithm searchAlgorithm){
     switch(searchAlgorithm){
        case SearchAlgorithm::BreadthFirst:
            return new BreadthFirstSearch(start, goal, stateSpace);
            break;
        case SearchAlgorithm::DepthFirst:
            return new DepthFirstSearch(start, goal, stateSpace);
        default:
            return new BreadthFirstSearch(start, goal, stateSpace);
    }
}