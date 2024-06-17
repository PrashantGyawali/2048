#pragma once
#include "grid.h"
#include "unordered_map"
#include "raylib.h"
using namespace std;

class Game{

    private:
    int dimension;

    public:
    int score=0;
    Grid grid;
    Game(int dimension);
    void Draw();
    void Move();
    int GetDimension();
    bool Update();  
    Vector2 NewTile();

    // void MoveUp();
    // void MoveDown();
    // void MoveLeft();
    // void MoveRight();
};