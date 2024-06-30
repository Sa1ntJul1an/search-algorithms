#include "searchFactory.h"
#include "searchAlgorithms.h"
#include "search.h"
#include "breadthFirst.h"
#include "depthFirst.h"
#include "cell.h"

Search* SearchFactory::createSearch(Cell* start, Cell * goal, const std::vector<std::vector<Cell*>>& stateSpace, SearchAlgorithm searchAlgorithm){
     switch(searchAlgorithm){
        case SearchAlgorithm::BreadthFirst:
            return new BreadthFirstSearch(start, goal, stateSpace);
            break;
        //case SearchAlgorithm::DepthFirst:
        //    return new DepthFirstSearch(start, goal, stateSpace);
        default:
            return new BreadthFirstSearch(start, goal, stateSpace);
    }
}