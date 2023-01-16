#include <iostream>
#include "Field.h"

int main() {
    Field field;
    field.createShape();
    field.printField();
    field.rotate();
    cout << endl;
    field.printField();
    for(int i = 1; i < 40; i++){
        cout << i << endl;
        field.fall();
        field.printField();
    }

}
