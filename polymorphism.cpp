#include <iostream>

class Shape {
public:
    static void draw() {
        std::cout << "Drawing a Shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    // 在Circle类中对draw()函数进行重载
    static void draw(int radius) {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }

    static void draw() {
        // do nothing
    }
};

int main() {
    Circle::draw();
    Circle::draw(5);
    return 0;
}
