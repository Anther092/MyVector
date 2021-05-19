#include <iostream>
#include <vector>
#include "MyVector.hpp"

using namespace std;
int main() {

    MyVector v1(2, ResizeStrategy::Multiplicative, 2);
    v1.printSize();

//    cout << "size: " << v.getSize() << endl;
//    v.printSize();
//    cout << "capacity: " << v.getCapacity() << endl;
//    v.printCapacity();
//    cout << endl;
//
//    v.insert(v.getSize(), 1);
//    cout << "size: " << v.getSize() << endl;
//    v.printSize();
//    cout << "capacity: " << v.getCapacity() << endl;
//    v.printCapacity();
//    cout << endl;
//
//
//    v.insert(0, 2);
//    cout << "size: " << v.getSize() << endl;
//    v.printSize();
//    cout << "capacity: " << v.getCapacity() << endl;
//    v.printCapacity();
//    cout << endl;



    return 0;
}
