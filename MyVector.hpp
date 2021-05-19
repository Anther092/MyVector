//
// Created by Bogdan on 26/04/2021.
//

#ifndef MYVECTOR_MYVECTOR_HPP
#define MYVECTOR_MYVECTOR_HPP

#include <cstdlib>

using ValueType = double;

enum class ResizeStrategy {
    Additive,
    Multiplicative
};

class MyVector {
private:
    size_t _size;
    size_t _capacity;
    ValueType *_data;

    ResizeStrategy _strategy;
    double _multCoef;

    void increaseCapacity();
    bool checkMem() const;
    void createNewVector();
    void initVector(size_t s);
    void shift(size_t hole);
public:

    MyVector(size_t size = 0,
             ResizeStrategy r = ResizeStrategy::Multiplicative,
             float coef = 1.5f);
    MyVector(size_t size,
             ValueType value,
             ResizeStrategy r = ResizeStrategy::Multiplicative,
             float coef = 1.5f);
    MyVector(size_t s);
    MyVector();

    MyVector(const MyVector& copy);
    MyVector& operator=(const MyVector& copy);

    ~MyVector();

    const ValueType& at(size_t idx) const;
    void assign(size_t idx, const ValueType& x);

    void setAll(ValueType x);

    const size_t& getSize() const;
    const size_t& getCapacity() const;

    void insert(size_t idx, const ValueType& x);
    void pushBack(const ValueType& x);
    void pushFront(const ValueType& x);

    void printSize() const;
    void printCapacity() const;
};


#endif //MYVECTOR_MYVECTOR_HPP
