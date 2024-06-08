#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "cell.h"

// mingw32-make.exe

using namespace sf;
using namespace std;

// width in height, in grid cells
const int WIDTH = 50;
const int HEIGHT = 50;

// size of cell, pixels
const int CELL_SIZE = 20;

const vector<int> start = {0, HEIGHT - 1};
const vector<int> goal = {WIDTH - 1, 0};

int main(){

    vector<float> mousePosition;

    vector<vector<Cell>> cells;

    for (int row = 0; row < WIDTH; row ++){
        vector<Cell> column;
        for (int col = 0; col < HEIGHT; col ++){
            Cell cell({row, col});
            column.push_back(cell);
        }
        cells.push_back(column);
    }

    bool searching = false;

    int iteration = 0;

    // RENDER WINDOW
    // =======================================================================
    RenderWindow renderWindow(VideoMode(WIDTH * CELL_SIZE + 1, HEIGHT * CELL_SIZE + 2), "Search Algorithm");
    renderWindow.setFramerateLimit(10);
    // =======================================================================

    Font font;
    FileInputStream fontIn;
    fontIn.open("slkscr.ttf");
    font.loadFromStream(fontIn);

    Text iterationText;
    iterationText.setFillColor(Color::Red);
    iterationText.setPosition(10, 10);
    iterationText.setFont(font);
    iterationText.setCharacterSize(30);

    RectangleShape cellRect(Vector2f(CELL_SIZE, CELL_SIZE));

    while(renderWindow.isOpen()){

        mousePosition = {float(Mouse::getPosition(renderWindow).x), float(Mouse::getPosition(renderWindow).y)};

        if (Mouse::isButtonPressed(Mouse::Left)){       // set as obstacle
            int row = mousePosition[0] / CELL_SIZE;
            int col = mousePosition[1] / CELL_SIZE;

            if (row < WIDTH && row >= 0 && col < HEIGHT && col >= 0) {
                cells[row][col].setObstacle(true);
            }

        } else if (Mouse::isButtonPressed(Mouse::Right))       // remove obstacle
        {
            int row = mousePosition[0] / CELL_SIZE;
            int col = mousePosition[1] / CELL_SIZE;

            if (row < WIDTH && row > 0 && col < HEIGHT && col > 0) {
                cells[row][col].setObstacle(false);
            }
        }

        if (searching){
            iteration ++;
        }


        // KEYBOARD EVENTS =========================================
        if (Keyboard::isKeyPressed(Keyboard::Space)){   // space to pause / unpause
            searching = !searching;
        }
        if (Keyboard::isKeyPressed(Keyboard::R)){       // R to reset
            for (int row = 0; row < WIDTH; row++){
                for (int col = 0; col < HEIGHT; col++){
                    cells[row][col].setObstacle(false);
                }
            }
            iteration = 0;
            searching = false;
        }
        // =========================================================


        // CLOSE WINDOWS IF X PRESSED
        // ==========================================================
        Event renderWindowEvent;

        while(renderWindow.pollEvent(renderWindowEvent)){
            
            if(renderWindowEvent.type == Event::Closed){
                renderWindow.close();
            }
        }
        // ==========================================================


        // DRAW CELLS
        // ==========================================================
        renderWindow.clear();

        for (int row = 0; row < WIDTH; row ++){
            for (int col = 0; col < WIDTH; col ++){
                if (cells[row][col].isObstacle()){
                    vector<int> cellPosition = cells[row][col].getPosition();
                    cellRect.setPosition(Vector2f(double(cellPosition[0] * CELL_SIZE), double(cellPosition[1] * CELL_SIZE)));

                    Color color(255, 255, 255);
                    cellRect.setFillColor(color);

                    renderWindow.draw(cellRect);
                }
            }
        }

        // DRAW VERTICAL GRID CELLS
        int greyValue = 100;
        Color gridColor(greyValue, greyValue, greyValue);
        for (int i = 0; i <= WIDTH; i++){
            RectangleShape verticalLine(Vector2f(2, CELL_SIZE * HEIGHT));
            Color color(greyValue, greyValue, greyValue);
            verticalLine.setFillColor(gridColor);
            verticalLine.setPosition(Vector2f(i * CELL_SIZE, 0));
            renderWindow.draw(verticalLine);
        }

        // DRAW HORIZONTAL GRID CELLS
        for (int i = 0; i <= HEIGHT; i++){
            RectangleShape horizontalLine(Vector2f(CELL_SIZE * HEIGHT, 2));
            horizontalLine.setFillColor(gridColor);
            horizontalLine.setPosition(Vector2f(0, i * CELL_SIZE));
            renderWindow.draw(horizontalLine);
        }
        // ==========================================================

        // DRAW START
        Color startColor(0, 255, 0);
        cellRect.setFillColor(startColor);
        cellRect.setPosition(Vector2f(double(start.at(0) * CELL_SIZE), double(start.at(1) * CELL_SIZE)));
        renderWindow.draw(cellRect);

        // DRAW GOAL
        Color goalColor(255, 0, 0);
        cellRect.setFillColor(goalColor);
        cellRect.setPosition(Vector2f(double(goal.at(0) * CELL_SIZE), double(goal.at(1) * CELL_SIZE)));
        renderWindow.draw(cellRect);

        iterationText.setString("Iteration: " + to_string(iteration));

        renderWindow.draw(iterationText);

        renderWindow.display();

    }

    return 0;
}
