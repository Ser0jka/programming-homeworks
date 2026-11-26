#pragma once

class Tree {
private:
    static int objectCount;

public:
    Tree();
    virtual ~Tree();

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    virtual void Show() const = 0;
    virtual void ShowWinter() const = 0;

    static int GetObjectCount();
};

class Birch : public Tree {
public:
    void Show() const override;
    void ShowWinter() const override;
};

class Spruce : public Tree {
public:
    void Show() const override;
    void ShowWinter() const override;
};
