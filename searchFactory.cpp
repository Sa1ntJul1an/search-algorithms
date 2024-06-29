#include "searchFactory.h"
#include "searchAlgorithms.h"
#include "search.h"
#include "breadthFirst.h"
#include "depthFirst.h"
#include "cell.h"

Search* SearchFactory::createSearch(const Cell& start, const Cell& goal, SearchAlgorithm searchAlgorithm){
     switch(searchAlgorithm){
        case SearchAlgorithm::BreadthFirst:
            return new BreadthFirstSearch(start, goal);
            break;
        case SearchAlgorithm::DepthFirst:
            return new DepthFirstSearch(start, goal);
        default:
            return new BreadthFirstSearch(start, goal);
    }
}