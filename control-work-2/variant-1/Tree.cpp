#include "Tree.hpp"
#include <iostream>

int Tree::objectCount = 0;

Tree::Tree() {
    ++objectCount;
}

Tree::~Tree() {
    --objectCount;
}

int Tree::GetObjectCount() {
    return objectCount;
}

void Birch::Show() const {
    std::cout << "Берёза — лиственное дерево." << std::endl;
}

void Birch::ShowWinter() const {
    std::cout << "Зимой берёза стоит без листьев." << std::endl;
}

void Spruce::Show() const {
    std::cout << "Ель — хвойное дерево." << std::endl;
}

void Spruce::ShowWinter() const {
    std::cout << "Зимой ель остаётся зелёной." << std::endl;
}
