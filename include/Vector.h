#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <iostream>
#include <cassert>

template<typename T, int len>
class Vector{
public:
    Vector(T* data);
    Vector(void);
    Vector(std::initializer_list<T> data);
    Vector(const Vector<T, len>& other);
    T              operator* (const Vector<T, len>& other) const;
    T              x         (void)                        const;
    T              y         (void)                        const;
    T              z         (void)                        const;
    T              w         (void)                        const;
    T              get       (int index)                        ;
    T*             asArray   (void)                        const;
    T*             getArray  (void)                             ;
    void           print     (void)                        const;
    void           operator+=(const Vector<T, len>& other)      ;
    void           operator-=(const Vector<T, len>& other)      ;
    void           operator*=(const T& other);
    void           operator= (const Vector<T, len>& other)      ;
    Vector<T, len> operator+ (const Vector<T, len>& other) const;
    Vector<T, len> operator- (const Vector<T, len>& other) const;
    Vector<T, len> operator* (const T& mul) const;
    ~Vector() { free(data); }
private:
    T* data;
};

using Vector2i = Vector<int,    2>;
using Vector2f = Vector<float,  2>;
using Vector2d = Vector<double, 2>;
using Vector3i = Vector<int,    3>;
using Vector3f = Vector<float,  3>;
using Vector3d = Vector<double, 3>;
using Vector4i = Vector<int,    4>;
using Vector4f = Vector<float,  4>;
using Vector4d = Vector<double, 4>;


template<typename T, int len> 
Vector<T, len>::Vector(std::initializer_list<T> data) {
    assert(data.size() <= len);
    auto it = data.begin();
    this->data = (T*)malloc(sizeof(T) * data.size());
    int i = 0;
    while (it != data.end()) this->data[i++] = *it++;
    while (i <= len) this->data[i++] = (T) NULL;
}

template<typename T, int len> 
Vector<T, len>::Vector() {
    this->data = (T*)malloc(sizeof(T) * (len + 1));
    for (int i = 0; i <= len; i++)
        this->data[i] = (T) NULL;
}

template<typename T, int len> 
Vector<T, len>::Vector(T* data) {
    this->data = (T*)malloc(sizeof(T) * len);
    for (int i = 0; i < len; i++)
        this->data[i] = data[i];
}

template<typename T, int len> 
Vector<T, len>::Vector(const Vector<T, len>& other) {
    this->data = (T*)malloc(sizeof(T) * len);
    for (int i = 0; i < len; i++)
        this->data[i] = other.data[i];
}

template<typename T, int len> 
Vector<T, len> Vector<T, len>::operator+(const Vector<T, len>& other) const{
    T data[len];
    for (int i = 0; i < len; i++)
        data[i] = this->data[i] + other.data[i];
    return Vector<T, len>(data);
}

template<typename T, int len>
Vector<T, len> Vector<T, len>::operator-(const Vector<T, len>& other) const {
    T data[len];
    for (int i = 0; i < len; i++)
        data[i] = this->data[i] - other.data[i];
    return Vector<T, len>(data);
}

template<typename T, int len>
T Vector<T, len>::operator*(const Vector<T, len>& other) const {
    T rtrn = 0;
    for (int i = 0; i < len; i++)
        rtrn += this->data[i] * other.data[i];
    return rtrn;
}

template<typename T, int len>
Vector<T, len> Vector<T, len>::operator*(const T& other) const {
    T data[len];
    for (int i = 0; i < len; i++)
        data[i] = this->data[i] * other;
    return Vector<T, len>(data);
}

template<typename T, int len>
Vector<T, len> operator*(const T product, const Vector<T, len>& vector) {
    return vector * product;
}

template<typename T, int len> 
void Vector<T, len>::operator+=(const Vector<T, len>& other) {
    for (int i = 0; i < len; i++)
       this->data[i] += other.data[i];
}

template<typename T, int len>
void Vector<T, len>::operator-=(const Vector<T, len>& other) {
    for (int i = 0; i < len; i++)
        this->data[i] -= other.data[i];
}

template<typename T, int len>
void Vector<T, len>::operator=(const Vector<T, len>& other) {
    for (int i = 0; i < len; i++)
        this->data[i] = other.data[i];
}

template<typename T, int len>
void Vector<T, len>::operator*=(const T& other) {
    for (int i = 0; i < len; i++)
        this->data[i] *= other;
}

template<typename T, int len>
T* Vector<T, len>::asArray(void) const {
    T* data = (T*)malloc(sizeof(T) * (len + 1));
    for (int i = 0; i < len; i++)
        data[i] = this->data[i];
    data[len] = NULL;
    return data;
}

template<typename T, int len>
T* Vector<T, len>::getArray(void) {
    return this->data;
}

template<typename T, int len>
void Vector<T, len>::print(void) const {
    std::cout<<"{"<<this->data[0];
    for (int i = 1; i < len; i++)
        std::cout<< ", "<< this->data[i];
    std::cout<<"}"<<std::endl;
}

template<typename T, int len>
T Vector<T, len>::x(void) const {
    if constexpr (0 < len)
        return this->data[0];
    throw std::range_error("out of range");
}

template<typename T, int len>
T Vector<T, len>::y(void) const {
    if constexpr (1 < len)
        return this->data[1];
    throw std::range_error("out of range");
}

template<typename T, int len>
T Vector<T, len>::z(void) const {
    if constexpr (2 < len)
        return this->data[2];
    throw std::range_error("out of range");
}

template<typename T, int len>
T Vector<T, len>::w(void) const {
    if constexpr (3 < len)
        return this->data[3];
    throw std::range_error("out of range");
}

template<typename T, int len>
T Vector<T, len>::get(int index) {
    if (index < len)
        return this->data[3];
    throw std::range_error("out of range");
}

#endif