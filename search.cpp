#include "search.h"
#include "cell.h"
#include "searchAlgorithms.h"

Search::Search(const Cell& start, const Cell& goal){
    _start = start;
    _goal = goal;
}