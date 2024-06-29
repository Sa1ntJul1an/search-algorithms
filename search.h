#ifndef SEARCH_HEADER
#define SEARCH_HEADER

#include "cell.h"
#include "searchAlgorithms.h"

class Search{
    public:
        Search(const Cell&, const Cell&);

        virtual void update() = 0;      // pure virtual function where each derived class can implement the update procedure

    private:
        Cell _start;
        Cell _goal;
};


#endif /* !SEARCH_HEADER */