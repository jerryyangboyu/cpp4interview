#include <iostream>
#include <cassert>

class Shape {
public:
    virtual void draw() {};

    int another() { return 1; }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle" << std::endl;
    }

    int another() { return 2;}
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Square" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw(); // 输出: Drawing a Circle
    shape2->draw(); // 输出: Drawing a Square

    assert(shape1->another() == 1);

    delete shape1;
    delete shape2;
    return 0;
}
