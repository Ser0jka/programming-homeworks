#include "Tree.hpp"
#include <iostream>

int main() {
    std::cout << "Выберите дерево: 1 — берёза, 2 — ель.\n";
    int choice = 0;
    if (choice != 1 && choice != 2) {
        std::cout << "Введите 1 или 2\n";
    }

    Tree* tree;
    if (choice == 1) {
        tree = new Birch;
    } else {
        tree = new Spruce;
    }

    tree->Show();
    tree->ShowWinter();

    Birch birch;
    Spruce spruce;
    std::cout << "\nРаннее связывание:\n";
    birch.Birch::Show();
    birch.Birch::ShowWinter();
    spruce.Spruce::Show();
    spruce.Spruce::ShowWinter();

    std::cout << "\nСоздано объектов: " << Tree::GetObjectCount() << '\n';

    delete tree;
    std::cout << "После удаления выбранного дерева: "
              << Tree::GetObjectCount() << '\n';
}
