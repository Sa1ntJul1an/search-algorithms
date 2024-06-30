#ifndef CELL_HEADER
#define CELL_HEADER

#include <vector>

// GRID CELL CLASS

class Cell{
    public:
        Cell();

        Cell(std::vector<int>);

        std::vector<int> getPosition();

        void setObstacle(bool);

        bool isObstacle();
    
        void setExplored(bool);

        bool isExplored();

        void setFrontier(bool);

        bool isFrontier();

        void addNeighbor(Cell*);

    private:
        std::vector<Cell*> _neighbors;
        bool _isGoal;
        bool _isObstacle;
        bool _isExplored;
        bool _isFrontier;
        std::vector<int> _position;
};

#endif /* !CELL_HEADER */