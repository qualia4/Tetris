#ifndef TETRIS_GAMEENGINE_H
#define TETRIS_GAMEENGINE_H
#include "Field.h"


class GameEngine {
    Field field;
    int score;
    int bestScore;
public:
    GameEngine(int score = 0, int bestScore = 0){
        field.createShape();
    }

    void executeCommand(){
        string command;
        cout << "Enter command: ";
        cin >> command;
        if(command == "fall"){
            fall();
            fall();
            fall();
        }
        else if(command == "moveRight"){
            moveRight();
        }
        else if(command == "moveLeft"){
            moveLeft();
        }
        else if(command == "rotate"){
            rotate();
        }
        else if(command == "fill"){
            int y,x;
            cout << "Enter Y: ";
            cin >> y;
            cout << "Enter X: ";
            cin >> x;
            fillOneBlock(y, x);
        }
    }

    void fillOneBlock(int y, int x){
        if (score >= 1000){
            score -= field.fillOneBlock(y, x);
        }
        else{
            cout << "Not enough points" << endl;
        }
    }

    void fall(){
        score += field.fall();
        checkScore();
    }

    void moveRight(){
        score += field.moveRight();
        checkScore();
    }

    void moveLeft(){
        score += field.moveLeft();
        checkScore();
    }

    void rotate(){
        score += field.rotate();
        checkScore();
    }

    bool checkIfLost(){
        return field.getLoose();
    }

    void checkScore(){
        if(score > bestScore){
            bestScore = score;
        }
    }

    int getScore(){
        return score;
    }

    int getBestScore(){
        return bestScore;
    }

    void printField(){
        field.printField();
    }
};


#endif
