#ifndef DEPTHFIRST_HEADER
#define DEPTHFIRST_HEADER

#include <stack>

# include "search.h"

// Depth First Search

class DepthFirstSearch : public Search{
    public:
        DepthFirstSearch(const Cell&, const Cell&);

        void update();

    private:
        std::stack<Cell*> _frontier;
};

#endif /* !DEPTHFIRST_HEADER */