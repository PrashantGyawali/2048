#pragma once

#include <vector>
#include "raylib.h"
#include "unordered_map"

using namespace std;

class Grid{
    int dimension;
    public:
    vector<vector<int>> grid,newGrid;
        Grid(int size):dimension{size},grid(size,vector<int>(size,0)),newGrid(size,vector<int>(size,0))
        {};

        ~Grid();
        void Move(Vector2 direction,int &score);
        void Draw();
        void Transpose(vector<vector<int>> &grid);
        void Reverse(vector<vector<int>> &grid);
        bool IsFull();
        Vector2 GenerateNewNumber();

    private:

        vector<int> GetEmptyCells();
};