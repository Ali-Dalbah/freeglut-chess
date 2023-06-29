#ifndef BUTTON_H
#define BUTTON_H
#include "Shape.h"
#include <time.h>
// --- the function parameter must be a pointer!!
template<typename rtrn, typename arg>
class Button: public Shape {
public:
    Button(const float posX, const float posY, const float width, const float height, rtrn (*callback)(arg*), const Vector4f& color4fv, const std::string& text);
    ~Button();
    bool isMouseOn(const float x, const float y);
    rtrn onClick(arg* argument);
    void changeText(const std::string& text);
    void render(void) const override;
    void setColor(const float r, const float g, const float b, const float a) override;
    void setColor(const Vector4f& color4fv) override;
    void setFunction(rtrn (*callback)(arg*));
private:
    rtrn (*callback)(arg*);
    Vector4f onClickColor;
    long lastClicked;
    std::string text;
protected:
    void applyColor(const bool invert) const;
    bool mouseOn;
    float width;
    float height;
};

template<typename rtrn, typename arg>
Button<rtrn, arg>::Button(const float posX, const float posY, const float width, const float height, rtrn (*callback)(arg*), const Vector4f& color4fv, const std::string& text): Shape(posX, posY, color4fv), text(text), callback(callback), width(width), height(height) {
    this->onClickColor = Vector4f({1, 1, 1, 1}) - color4fv;
    this->mouseOn = false;
}
template<typename rtrn, typename arg>
void Button<rtrn, arg>::render(void) const {
    applyColor(mouseOn);
    glBegin(GL_QUADS);
        glVertex2f(x        , y         );
        glVertex2f(x + width, y         );
        glVertex2f(x + width, y + height);
        glVertex2f(x        , y + height);
    glEnd();
}

template<typename rtrn, typename arg>
void Button<rtrn, arg>::setColor(const float r, const float g, const float b, const float a) {
    const Vector4f color4fv({r, g, b, a});
    Shape::setColor(color4fv);
    this->onClickColor = Vector4f({1, 1, 1, 1}) - color4fv;
}

template<typename rtrn, typename arg>
void Button<rtrn, arg>::setColor(const Vector4f& color4fv) {
    Shape::setColor(color4fv);
    this->onClickColor = Vector4f({1, 1, 1, 1}) - color4fv;
}

template<typename rtrn, typename arg>
void Button<rtrn, arg>::changeText(const std::string& text) {
    this->text = text;
}

template<typename rtrn, typename arg>
bool Button<rtrn, arg>::isMouseOn(const float x, const float y) {
    if ((x <= Shape::x + width) && (x >= Shape::x) && (y >= Shape::y) && (y <= Shape::y + height))
        mouseOn = true;
    else
        mouseOn = false;
    return mouseOn;
}

template<typename rtrn, typename arg>
void Button<rtrn, arg>::applyColor(const bool invert) const {
    if (!invert)
        Shape::applyColor();
    else
        glColor4f(onClickColor.x(), onClickColor.y(), onClickColor.z(), onClickColor.w());
}

template<typename rtrn, typename arg>
Button<rtrn, arg>::~Button() {

}

template<typename rtrn, typename arg>
rtrn Button<rtrn, arg>::onClick(arg* argument) {
    if (mouseOn && (time(NULL) - lastClicked) >= 1){
        lastClicked = time(NULL);
        return (rtrn)callback(argument);
    }
    return (rtrn)NULL;
}

template<typename rtrn, typename arg>
void Button<rtrn, arg>::setFunction(rtrn (*callback)(arg*)) {
    this->callback = callback;
}

#endif