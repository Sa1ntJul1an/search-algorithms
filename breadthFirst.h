#ifndef BREADTHFIRST_HEADER
#define BREADTHFIRST_HEADER

#include <queue>

# include "search.h"

// Breadth First Search

class BreadthFirstSearch : public Search{
    public:
        BreadthFirstSearch(Cell *, Cell *, const std::vector<std::vector<Cell*>>&);

        void update();

        void initialize();

    private:
        Cell* _start;
        Cell* _goal;

        int _width;
        int _height;

        std::vector<std::vector<Cell*>> _stateSpace;
        std::queue<Cell*> _frontier;
};

#endif /* !BREADTHFIRST_HEADER */