#ifndef SEARCHFACTORY_HEADER
#define SEARCHFACTORY_HEADER

#include "search.h"
#include "searchAlgorithms.h"
#include "breadthFirst.h"
#include "cell.h"

class SearchFactory{
    public:
        Search* createSearch(const Cell&, const Cell&, SearchAlgorithm);

    private:
        
};

#endif /* !SEARCHFACTORY_HEADER */