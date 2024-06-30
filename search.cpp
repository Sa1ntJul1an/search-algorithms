#include "search.h"
#include "cell.h"
#include "searchAlgorithms.h"

Search::Search(Cell * start, Cell * goal, const std::vector<std::vector<Cell*>>& stateSpace){
    _start = start;
    _goal = goal;
    _stateSpace = stateSpace;
}