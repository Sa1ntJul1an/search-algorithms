#ifndef SEARCH_HEADER
#define SEARCH_HEADER

#include "cell.h"
#include "searchAlgorithms.h"

class Search{
    public:
        Search(const Cell&, const Cell&, std::vector<std::vector<Cell*>>&);

        virtual void update() = 0;      // pure virtual function where each derived class can implement the update procedure

        virtual void initialize() = 0;

    private:
        Cell _start;
        Cell _goal;

        std::vector<std::vector<Cell*>> _stateSpace;
};


#endif /* !SEARCH_HEADER */