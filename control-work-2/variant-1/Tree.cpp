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
    std::cout << "Берёза — лиственное дерево.\n";
}

void Birch::ShowWinter() const {
    std::cout << "Зимой берёза стоит без листьев.\n";
}

void Spruce::Show() const {
    std::cout << "Ель — хвойное дерево.\n";
}

void Spruce::ShowWinter() const {
    std::cout << "Зимой ель остаётся зелёной.\n";
}
