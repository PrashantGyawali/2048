#pragma once

#include<raylib.h>

class Window{
public:

Window(int w,int h, const char* title){
    InitWindow(w,h,title);
    SetTargetFPS(15);
}

};