#include"raylib.h"
#include"raygui.h"
#include<iostream>
#include "game.h"
#include "utils.h"

int main()
{
    InitWindow(700, 700, "Game");
    SetTargetFPS(60);

    Game g{5};
    bool newAdded=false;
    float count=0;
    while(!WindowShouldClose())
    {
        if(newAdded)
        {
            Vector2 pos= g.NewTile();
            while(count>0)
            {
                        count-=0.3;
                        BeginDrawing();
                        ClearBackground(RAYWHITE);
                        g.Draw();
                        int t=g.grid.grid[pos.x][pos.y];
                        DrawRectangle((pos.y*100+100-2)-6,(pos.x*100+100-2)-6,96+count*4,98+count*4,{250,250,250,100});

                        DrawRectangle((pos.y*100+100-2)-count,(pos.x*100+100-2)-count,94+count*2,94+count*2,GetColorForTile(t));
                        DrawText(TextFormat("%d",t),100+pos.y*100+30,100+pos.x*100+30,30,BLACK);
                        EndDrawing();

            }
            newAdded=false;
        }
        else{
        BeginDrawing();
        ClearBackground(RAYWHITE);
        newAdded=g.Update();
        
        if(newAdded)
        {
            count=5;
        }

        g.Draw();
        EndDrawing();
        }
    }

    return 0;
}