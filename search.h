#ifndef SEARCH_HEADER
#define SEARCH_HEADER

#include "cell.h"
#include "searchAlgorithms.h"

class Search{
    public:
        Search(Cell *, Cell *, const std::vector<std::vector<Cell*>>&);

        virtual void update() = 0;      // pure virtual function where each derived class can implement the update procedure

        virtual void initialize() = 0;

    private:
        int _width;
        int _height;

        Cell * _start;
        Cell * _goal;

        std::vector<std::vector<Cell*>> _stateSpace;

    protected:
        void _populateNeighbors();
};


#endif /* !SEARCH_HEADER */