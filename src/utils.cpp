#include "utils.h"


Color GetColorForTile(int value){

    Color clr;
                    switch(value) {
                case 2:
                    clr = {204, 192, 179, 255}; // Slightly darker beige
                    break;
                case 4:
                    clr = {204, 192, 150, 255}; // Slightly darker yellowish-grey
                    break;
                case 8:
                    clr = {221, 140, 84, 255}; // Slightly darker orange
                    break;
                case 16:
                    clr = {221, 107, 67, 255}; // Darker orange/red
                    break;
                case 32:
                    clr = {221, 82, 63, 255}; // Darker orange/red
                    break;
                case 64:
                    clr = {221, 63, 39, 255}; // Darker orange/red
                    break;
                case 128:
                    
                    clr = {204, 177, 84, 255}; // Slightly darker orange-yellow
                    break;
                case 256:
                    clr = {204, 170, 63, 255}; // Slightly darker orange-yellow
                    break;
                case 512:
                    clr = {204, 160, 46, 255}; // Slightly darker orange-yellow
                    break;
                case 1024:
                    clr = {204, 154, 28, 255}; // Slightly darker orange-yellow
                    break;
                case 2048:
                    clr = {204, 147, 10, 255}; // Slightly darker orange-yellow
                    break;
                default:
                        clr = {0,0,0,255};
                        break;
}
    
        return clr;
}