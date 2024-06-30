#ifndef DEPTHFIRST_HEADER
#define DEPTHFIRST_HEADER

#include <stack>

# include "search.h"

// Depth First Search

class DepthFirstSearch : public Search{
    public:
        DepthFirstSearch(Cell *, Cell *, const std::vector<std::vector<Cell*>>&);

        void update();

        void initialize();

    private:
        std::vector<std::vector<Cell*>> _stateSpace;
        std::stack<Cell*> _frontier;

        Cell* _start;
        Cell* _goal;

        int _width;
        int _height;
};

#endif /* !DEPTHFIRST_HEADER */