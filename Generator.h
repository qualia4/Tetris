#ifndef TETRIS_GENERATOR_H
#define TETRIS_GENERATOR_H
#include "Shape.h"
#include "ctime"
#include <cstdlib>


class Generator {
public:
    Shape* generateShape(){
        sranddev();
        int num = rand() % 7;
        switch (num)
        {
            case 0:
                return generateI();
                break;
            case 1:
                return generateJ();
                break;
            case 2:
                return generateL();
                break;
            case 3:
                return generateO();
                break;
            case 4:
                return generateZ();
                break;
            case 5:
                return generateT();
                break;
            case 6:
                return generateS();
                break;
            default:
                return generateI();
        }
    }

    Shape* generateI(){
        int y = 16;
        int x = 3;
        vector<vector<bool>> shape = genField(4);
        shape[2][0] = true;
        shape[2][1] = true;
        shape[2][2] = true;
        shape[2][3] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    Shape* generateJ(){
        int y = 17;
        int x = 3;
        vector<vector<bool>> shape = genField(3);
        shape[2][0] = true;
        shape[1][0] = true;
        shape[1][1] = true;
        shape[1][2] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    Shape* generateL(){
        int y = 17;
        int x = 3;
        vector<vector<bool>> shape = genField(3);
        shape[1][0] = true;
        shape[1][1] = true;
        shape[1][2] = true;
        shape[2][2] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    Shape* generateO(){
        int y = 17;
        int x = 3;
        vector<vector<bool>> shape = genField(4);
        shape[2][1] = true;
        shape[2][2] = true;
        shape[1][1] = true;
        shape[1][2] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    Shape* generateZ(){
        int y = 17;
        int x = 3;
        vector<vector<bool>> shape = genField(3);
        shape[2][0] = true;
        shape[2][1] = true;
        shape[1][1] = true;
        shape[1][2] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    Shape* generateT(){
        int y = 17;
        int x = 3;
        vector<vector<bool>> shape = genField(3);
        shape[2][1] = true;
        shape[1][0] = true;
        shape[1][1] = true;
        shape[1][2] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    Shape* generateS(){
        int y = 17;
        int x = 3;
        vector<vector<bool>> shape = genField(3);
        shape[2][1] = true;
        shape[2][2] = true;
        shape[1][0] = true;
        shape[1][1] = true;
        Shape* result = new Shape(x, y, shape);
        return result;
    }

    vector<vector<bool>> genField(int size){
        vector<vector<bool>> field;
        for(int i = 0; i < size; i++){
            vector<bool> line;
            for(int i = 0; i < size; i++){
                line.push_back(false);
            }
            field.push_back(line);
        }
        return field;
    }
};


#endif
