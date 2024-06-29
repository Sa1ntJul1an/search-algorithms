#ifndef DEPTHFIRST_HEADER
#define DEPTHFIRST_HEADER

#include <stack>

# include "search.h"

// Depth First Search

class DepthFirstSearch : public Search{
    public:
        DepthFirstSearch(const Cell&, const Cell&, std::vector<std::vector<Cell*>>);

        void update();

        void initialize();

    private:
        std::vector<std::vector<Cell*>> _stateSpace;
        std::stack<Cell*> _frontier;
};

#endif /* !DEPTHFIRST_HEADER */