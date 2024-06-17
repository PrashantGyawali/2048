#include "game.h"
#include "raylib.h"

Game::Game(int dimension):dimension{dimension},grid{dimension}
{
    Vector2 pos1=grid.GenerateNewNumber();
    Vector2 pos2=grid.GenerateNewNumber();
    grid.grid[pos1.x][pos1.y]=2;
    grid.grid[pos2.x][pos2.y]=2;
    score=2;
}

int Game::GetDimension()
{
    return dimension;
}


void Game::Move()
{
grid.Move({1,0},score);
}

void Game::Draw(){
    grid.Draw();
    DrawText("2048", 300, 10, 50, DARKGRAY);
    DrawText(TextFormat("Score:%d",score), 500, 50, 30, BLACK);
}

bool Game::Update()
{
    if(grid.IsFull())
    {
        return false;
    }
    if(IsKeyReleased(KEY_RIGHT))
    {
        grid.Move({1,0},score);
        return true;
    }
    else if(IsKeyReleased(KEY_LEFT))
    {
        grid.Move({-1,0},score);
        return true;
    }
    else if(IsKeyReleased(KEY_UP))
    {
        grid.Move({0,-1},score);
        return true;
    }
    else if(IsKeyReleased(KEY_DOWN))
    {
        grid.Move({0,1},score);
        return true;
    }
    return false;
}

Vector2 Game::NewTile()
{
    return grid.GenerateNewNumber();
    
}
