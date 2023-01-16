#ifndef TETRIS_FIELD_H
#define TETRIS_FIELD_H
#include "Generator.h"

class Field {
    Shape* archive;
    Shape* fallingShape;
    Generator generator;
    char field[20][10]; // 4 types of block: 'E' - empty, 'S' - shape, 'F' - floor
    bool loose = false;

public:
    Field(){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 10; j++){
                field[i][j] = 'E';
            }
        }
    }

    int updateField(bool create = false){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 10; j++){
                if(field[i][j] == 'S'){
                    field[i][j] = 'E';
                }
            }
        }
        int length = fallingShape->getCoords().size();
        int y = fallingShape->getAnchorY();
        int x = fallingShape->getAnchorX();
        for(int i = length - 1; i >= 0; i--){
            for(int j = 0; j <= length; j++){
                if(fallingShape->getCoords()[i][j]){
                    if(y + i >= 20 or x + j >= 10 or x + j < 0){
                        fallingShape->copy(archive);
                        return updateField();
                    }
                    else if(y + i < 0){
                        fallingShape->copy(archive);
                        updateField();
                        return freezeShape()*100;
                    }
                    else if(field[y + i][x + j] == 'F'){
                        if(create){
                            cout << "!!!!Game lost!!!!" << endl;
                            for(int i = 0; i < 20; i++){
                                for(int j = 0; j < 10; j++){
                                    field[i][j] = 'E';
                                }
                            }
                            loose = true;
                            createShape();
                            return 0;
                        }
                        fallingShape->copy(archive);
                        updateField();
                        return freezeShape()*100;
                    }
                    else if(field[y + i][x + j] != 'E'){
                        fallingShape->copy(archive);
                        return updateField();
                    }
                    field[y + i][x + j] = 'S';
                }
            }
        }
        archive->copy(fallingShape);
    }

    int freezeShape(){
        int length = fallingShape->getCoords().size();
        int y = fallingShape->getAnchorY();
        int x = fallingShape->getAnchorX();
        for(int i = length - 1; i >= 0; i--){
            for(int j = 0; j <= length; j++) {
                if (fallingShape->getCoords()[i][j]) {
                    field[y + i][x + j] = 'F';
                }
            }
        }
        int num = checkField();
        createShape();
        return num;
    }

    int fillOneBlock(int y, int x){
        if(field[y][x] == 'E'){
            field[y][x] = 'F';
            checkField();
            return 1000;
        }
        return 0;
    }

    int checkField(){
        int cleared = 0;
        vector<int> lines;
        for(int i = 19; i >= 0; i--){
            bool lineToClear = true;
            for(int j = 0; j < 10; j++){
                if(field[i][j] != 'F'){
                    lineToClear = false;
                    break;
                }
            }
            if(lineToClear){
                lines.push_back(i);
                cleared++;
            }
        }
        for(int i = 0; i < lines.size(); i++){
            clearLine(lines[i]);
        }
        return cleared;
    }

    void clearLine(int index){
        for(int i = 0; i < 10; i++){
            field[index][i] = 'E';
        }
        for(int i = index + 1; i < 20; i++){
            for(int j = 0; j < 10; j++){
                field[i - 1][j] = field[i][j];
            }
        }
    }

    void createShape(){
        fallingShape = generator.generateShape();
        archive = new Shape(fallingShape->getAnchorX(), fallingShape->getAnchorY(), fallingShape->getCoords());
        updateField(true);
    }

    int fall(){
        fallingShape->fall();
        return updateField();
    }

    int moveRight(){
        fallingShape->moveRight();
        return updateField();
    }

    int moveLeft(){
        fallingShape->moveLeft();
        return updateField();
    }

    int rotate(){
        fallingShape->rotate();
        return updateField();
    }

    bool getLoose(){
        return loose;
    }

    void printField(){
        for(int i = 19; i >= 0; i--){
            for(int j = 0; j < 10; j++){
                if(field[i][j] == 'S' or field[i][j] == 'F'){
                    cout << "❏" << " ";
                }
                else{
                    cout << "." << " ";
                }
            }
            cout << endl;
        }
    }


};


#endif
