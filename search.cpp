#include "search.h"
#include "cell.h"
#include "searchAlgorithms.h"

Search::Search(const Cell& start, const Cell& goal, std::vector<std::vector<Cell*>>& stateSpace){
    _start = start;
    _goal = goal;

    _stateSpace = stateSpace;
}