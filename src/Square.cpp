#include "../include/Square.h"

Square::Square(const int size, const int x, const int y): Shape(x, y), size(size) {}
Square::Square(const int size, const int x, const int y, const Vector4f color4fv): Shape(x, y, color4fv), size(size) {}

void Square::render(void) const {
    Shape::applyColor();
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

