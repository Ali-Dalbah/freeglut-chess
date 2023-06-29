
#include "../include/Shape.h"
#include "../include/Vector.h"

Shape::Shape(const float x, const float y): x(x), y(y) {
    this->color4fv = Vector4f();
}

Shape::Shape(const float x, const float y, const Vector4f& color4fv): x(x), y(y), color4fv(color4fv) {

}

void Shape::render(void) const {

}

void Shape::setColor(const float r, const float g, const float b, const float a) {
    this->color4fv = Vector4f({r, g, b, a});
}

void Shape::setColor(const Vector4f& color4fv) {
    this->color4fv = color4fv;
}