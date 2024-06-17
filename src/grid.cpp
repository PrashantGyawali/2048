#include "grid.h"
#include "raylib.h"
#include <vector>
#include <iostream>
#include "utils.h"
#include "game.h"
using namespace std;

Grid::~Grid()
{

}

Vector2 Grid::GenerateNewNumber()
{
    vector<int> emptyCells = GetEmptyCells();
    vector<int> borderEmptyCells;
    for(int i=0;i<emptyCells.size();i++)
    {
        int x = emptyCells[i]/dimension;
        int y = emptyCells[i]%dimension;
        if(x==0 || x==dimension-1 || y==0 || y==dimension-1)
        {
            borderEmptyCells.push_back(emptyCells[i]);
        }
    }
    if(borderEmptyCells.size()!=0)
    {
        int index =  GetRandomValue(0,borderEmptyCells.size()-1);
        int cell = borderEmptyCells[index];
        int x = cell/dimension;
        int y = cell%dimension;
        int random = GetRandomValue(0,10);
        grid[x][y] = random>6?4:2;
        return{x*1.0f,y*1.0f};
    }

    if(emptyCells.size()==0)
    {
        return{-1,-1};
    }
    cout<<"Empty Cells:"<<emptyCells.size()<<endl;
    int index =  GetRandomValue(0,emptyCells.size()-1);
    int cell = emptyCells[index];
    int x = cell/dimension;
    int y = cell%dimension;
    grid[x][y] = GetRandomValue(0,10)>8?4:2;
    return {x*1.0f,y*1.0f};
}



vector<int> Grid::GetEmptyCells()
{
    vector<int> emptyCells;
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            if(grid[i][j]==0)
            {
                emptyCells.push_back(i*dimension+j);
            }
        }
    }
    return emptyCells;
}


bool Grid::IsFull()
{
    vector<int> emptyCells = GetEmptyCells();
    if(emptyCells.size()==0)
    {
        return true;
    }
    return false;
}

void Grid::Move(Vector2 direction,int &score)
{
    if(IsFull())
    {
        return;
    }

    newGrid = grid;
    if(direction.y==0)
    {
        if(direction.x==-1)
        {
            Reverse(newGrid);
        }
    }
    if(direction.y!=0)
    {
        Transpose(newGrid);

        if(direction.y==-1)
        {
            Reverse(newGrid);
        }
    }
{
    if(IsFull())
    {
        return;
    }

    newGrid = grid;
    if(direction.y==0)
    {
        if(direction.x==-1)
        {
            Reverse(newGrid);
        }
    }
    if(direction.y!=0)
    {
        Transpose(newGrid);

        if(direction.y==-1)
        {
            Reverse(newGrid);
        }
    }


//  merge the cells
    for(int i=0;i<dimension;i++)
    {
        int lpointer=0,rpointer=1;
        while(rpointer<dimension)
        {
            if(newGrid[i][lpointer]==0)
            {
                lpointer++;
                rpointer++;
                continue;
            }
            if(newGrid[i][rpointer]==0)
            {
                if(rpointer==dimension-1)
                {
                    int t=newGrid[i][lpointer];
                    newGrid[i][lpointer]=0;
                    newGrid[i][rpointer]=t;
                }
                rpointer++;
                continue;
            }
            else if(newGrid[i][rpointer]!=0)
            {
                if(newGrid[i][rpointer]==newGrid[i][lpointer])
                {
                    newGrid[i][rpointer]*=2;

                    newGrid[i][lpointer]=0;
                    lpointer=rpointer+1;
                    rpointer=lpointer+1;
                }
                else
                {
                    int t=newGrid[i][lpointer];
                    newGrid[i][lpointer]=0;
                    newGrid[i][rpointer-1]=t;
                    lpointer=rpointer;
                    rpointer++;
                }
            }     
        }
    }

int max=0;
for(int i=0;i<dimension;i++)
{
    vector<int> temp;
    vector<int> temp2;
    int count0=0;

    for(int j=dimension-1;j>=0;j--)
    {
        if(newGrid[i][j]!=0)
        {
            temp.push_back(newGrid[i][j]);
            if(newGrid[i][j]>max)
            {
                max=newGrid[i][j];
            }
        }
        else{
            count0++;
        }

    }   
    for(int j=0;j<count0;j++)
    {
        temp2.push_back(0);
    }
    for(int j=temp.size()-1;j>=0;j--)
    {
        temp2.push_back(temp[j]);
    }
    newGrid[i]=temp2;
}






    if(direction.y==0)
    {
        if(direction.x==-1)
        {
            Reverse(newGrid);
        }
    }
    if(direction.y!=0)
    {
        if(direction.y==-1)
        {
            Reverse(newGrid);
        }
        Transpose(newGrid);
    }

    grid=newGrid;
    score=max;
}
}



void Grid::Draw()
{
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
                int fontSize = 30;

                int modifier=0;
                int t=grid[i][j];
                while(t>0)
                {
                    if(t<100&&t>10)
                    {
                        if(t<10)
                        {
                            modifier--;
                        }
                        break;
                    }
                    {
                        break;
                    }
                    t/=10;
                    modifier++;
                }
                fontSize = 30-modifier*2;

            DrawRectangle(100+j*100-10,100+i*100-10, 110, 110, GRAY);
            DrawRectangle(100+j*100-2,100+i*100-2,94,94,WHITE);
            if(grid[i][j]!=0)
            {
                Color clr=GetColorForTile(grid[i][j]);
                DrawRectangle(100+j*100-2,100+i*100-2,94,94,clr);
                DrawText(TextFormat("%d",grid[i][j]),100+j*100+30-modifier*2,100+i*100+30,30,WHITE);
            }
        }
    }
}

void Grid::Transpose(vector<vector<int>> &grid)
{
    for(int i=0;i<dimension;i++)
    {
        for(int j=i;j<dimension;j++)
        {
            int temp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = temp;
        }
    }
}

void Grid::Reverse(vector<vector<int>> &grid)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension / 2; j++)
        {
            int temp = grid[i][j];
            grid[i][j] = grid[i][dimension - 1 - j];
            grid[i][dimension - 1 - j] = temp;
        }
    }
}

