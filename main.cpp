#include <iostream>
#include "Field.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    Field field;
    field.createShape();
    bool play = true;

    while(play){

        string command;
        cout << "Command: ";
        cin >> command;
        if(command == "exit"){
            play = false;
        }
        else if(command == "fall"){
            field.fall();
            field.fall();
            field.fall();
        }
        else if(command == "fullFall"){
            field.fall();
            field.fall();
            field.fall();
            field.fall();
            field.fall();
            field.fall();
            field.fall();
            field.fall();
            field.fall();
        }
        else if(command == "moveRight"){
            field.moveRight();
        }
        else if(command == "moveLeft"){
            field.moveLeft();
        }
        else if(command == "rotate"){
            field.rotate();
        }
        field.printField();
    }
}
