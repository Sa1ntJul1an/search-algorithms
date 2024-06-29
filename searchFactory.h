#ifndef SEARCHFACTORY_HEADER
#define SEARCHFACTORY_HEADER

#include "search.h"
#include "searchAlgorithms.h"
# include "breadthFirst.h"

class SearchFactory{
    public:
        Search* createSearch(SearchAlgorithm searchAlgorithm){
            switch(searchAlgorithm){
                case BreadthFirst:
                    return new BreadthFirstSearch();
                    break;
                case DepthFirst:
                    return new BreadthFirstSearch();

            }
        }
};


#endif /* !SEARCHFACTORY_HEADER */