#ifndef TETRIS_SHAPE_H
#define TETRIS_SHAPE_H
using namespace std;
#include "string"
#include "vector"
vector<string> split(const string line, char delim = ' ');


class Shape {
protected:
    int anchorCoord[2];
    vector<vector<bool>> shape;

public:
    Shape(int x, int y, vector<vector<bool>> shape){
        anchorCoord[0] = y;
        anchorCoord[1] = x;
        this->shape = shape;
    }
    void fall(){
        anchorCoord[0] -= 1;
    }
    void moveRight(){
        anchorCoord[1] += 1;
    }
    void moveLeft(){
        anchorCoord[1] -= 1;
    }
    void rotate(){
        if(shape.size() == 3){
            vector<vector<bool>> newVect = shape;
            newVect[2][0] = shape[0][0];
            newVect[2][1] = shape[1][0];
            newVect[2][2] = shape[2][0];
            newVect[1][0] = shape[0][1];
            newVect[1][2] = shape[2][1];
            newVect[0][0] = shape[0][2];
            newVect[0][1] = shape[1][2];
            newVect[0][2] = shape[2][2];
            shape = newVect;
        }
        else if(shape.size() == 4){
            vector<vector<bool>> newVect = shape;
            newVect[3][1] = shape[1][0];
            newVect[3][2] = shape[2][0];
            newVect[2][0] = shape[0][1];
            newVect[2][1] = shape[1][1];
            newVect[2][2] = shape[2][1];
            newVect[2][3] = shape[3][1];
            newVect[1][0] = shape[0][2];
            newVect[1][1] = shape[1][2];
            newVect[1][2] = shape[2][2];
            newVect[1][3] = shape[3][2];
            newVect[0][1] = shape[1][3];
            newVect[0][2] = shape[2][3];
            shape = newVect;
        }
    }

};

#endif
