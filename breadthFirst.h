#ifndef BREADTHFIRST_HEADER
#define BREADTHFIRST_HEADER

#include <queue>

# include "search.h"

// Breadth First Search

class BreadthFirstSearch : public Search{
    public:
        BreadthFirstSearch(const Cell&, const Cell&);

        void update();

    private:
        Cell _start;
        Cell _goal;
        
        std::queue<Cell*> _frontier;
};

#endif /* !BREADTHFIRST_HEADER */