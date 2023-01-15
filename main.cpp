#include <iostream>
#include "Generator.h"

int main() {
    Generator generator;
    Shape* shape = generator.generateShape();
    shape->printShape();
}
