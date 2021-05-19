//
// Created by Bogdan on 26/04/2021.
//

#include <cassert>
#include <iostream>
#include "MyVector.hpp"

void MyVector::initVector(size_t s) {
    _size = s;
    increaseCapacity();

    _data = new ValueType[getCapacity()];
    setAll(42); // debug
}

MyVector::MyVector(size_t size, ResizeStrategy r, float coef) {
    _strategy = r;
    _multCoef = coef;
    initVector(size);
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy r, float coef) {
    _strategy = r;
    _multCoef = coef;
    initVector(size);
}

MyVector::MyVector(const MyVector &copy) {
    _strategy = copy._strategy;
    _multCoef = copy._multCoef;
    initVector(copy.getSize());
    for (int i = 0; i < getSize(); ++i) {
        _data[i] = copy.at(i);
    }
}

MyVector::MyVector() {
    initVector(0);
}

MyVector::MyVector(size_t size) {
    initVector(size);
}

void MyVector::increaseCapacity() {
    if (_strategy == ResizeStrategy::Multiplicative)
        _capacity = _multCoef*getSize();

    if (_strategy == ResizeStrategy::Additive)
        _capacity = _multCoef + getSize();
}

const ValueType &MyVector::at(const size_t idx) const {
    assert(idx < getSize());
    return _data[idx];
}

void MyVector::createNewVector()
{
    increaseCapacity();
    auto *buf = new ValueType[getCapacity()];

    for (int i = 0; i < getSize(); ++i) {
        buf[i] = _data[i];
    }

    delete _data;
    _data = buf;
}

const size_t& MyVector::getSize() const {
    return _size;
}

const size_t &MyVector::getCapacity() const {
    return _capacity;
}

void MyVector::insert(const size_t idx, const ValueType& x)
{
    ++_size;

    if (checkMem()) {
        shift(idx);
    }
    else {
        createNewVector();
        shift(idx);
    }

    assign(idx, x);
}

void MyVector::assign(size_t idx, const ValueType& x) {
    assert(idx < getSize());
    _data[idx] = x;
}

void MyVector::pushBack(const ValueType& x) {
    insert(getSize(), x);
    assign(getSize()-1, x);
}

void MyVector::pushFront(const ValueType& x) {
    insert(0, x);
    assign(0, x);
}

void MyVector::printSize() const {
    for (int i = 0; i < getSize(); ++i) {
        std::cout << at(i) << " ";
    }
    std::cout << std::endl;
}

void MyVector::printCapacity() const {
    for (int i = 0; i < getCapacity(); ++i) {
        std::cout << _data[i] << " ";
    }
    std::cout << std::endl;
}

bool MyVector::checkMem() const {
    return getSize() <= getCapacity();
}

void MyVector::shift(size_t hole)
{
    for (int i = 0; i < getSize()-hole; ++i) {
        _data[getSize() - i] = _data[getSize()-1 - i];
    }
}

void MyVector::setAll(ValueType x) {
    for (int i = 0; i < getSize(); ++i) {
        _data[i] = x;
    }
}

//MyVector &MyVector::operator=(const MyVector &copy) {
//    delete _data;
//    return ;
//}

MyVector::~MyVector() {
    delete _data;
}








