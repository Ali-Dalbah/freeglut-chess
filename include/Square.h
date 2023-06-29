#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
class Square: public Shape{
public:
    inline Square(const int size);
    Square(const int size, const int x, const int y);
    Square(const int size, const int x, const int y, const Vector4f color4fv);
    ~Square() = default;
    void render(void) const override;
private:
    int size;
};

inline Square::Square(const int size): Square(size, 0.f, 0.f) {}
#endif