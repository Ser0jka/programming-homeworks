#include "Tree.hpp"
#include <iostream>

int main() {
    std::cout << "Выберите дерево: 1 — берёза, 2 — ель." << std::endl;
    int choice = 0;
    if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Введите 1 или 2" << std::endl;
        return 1;
    }

    Tree* tree;
    if (choice == 1) {
        tree = new Birch;
    } else {
        tree = new Spruce;
    }

    std::cout << "Позднее связывание:" << std::endl;
    tree->Show();
    tree->ShowWinter();

    Birch birch;
    Spruce spruce;
    std::cout << "Раннее связывание:" << std::endl;
    birch.Birch::Show();
    birch.Birch::ShowWinter();
    spruce.Spruce::Show();
    spruce.Spruce::ShowWinter();

    std::cout << "Создано объектов: " << Tree::GetObjectCount() << std::endl;

    delete tree;
    std::cout << "После удаления выбранного дерева: "
              << Tree::GetObjectCount() << std::endl;
}
