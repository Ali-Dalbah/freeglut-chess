#ifndef SHAPE_H
#define SHAPE_H
#include <GL/glut.h>
#include "Vector.h"
class Shape{
public:
    inline Shape(void);
    Shape(const float x, const float y);
    Shape(const float x, const float y, const Vector4f& color4fv);
    virtual void render(void) const;
    virtual void setColor(const float r, const float g, const float b, const float a);
    virtual void setColor(const Vector4f& color4fv);
    ~Shape(void) = default;
private:
    Vector4f color4fv;
protected:
    inline void applyColor(void) const;
    float x;
    float y;
};

inline Shape::Shape(void): Shape(0.f, 0.f) {}
inline void Shape::applyColor(void) const {
    glColor4f(color4fv.x(), color4fv.y(), color4fv.z(), color4fv.w());
}
#endif
