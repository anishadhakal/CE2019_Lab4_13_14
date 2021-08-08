#pragma once
#include <iostream>

//To: Anisha, vertex class, changes can be made if necessary
class Vertex{
public:
    int value;
    Vertex* next;
    Vertex* left;
    Vertex* right;
    Vertex(int value){
        value = value;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
    ~Vertex(){  
    }
};

