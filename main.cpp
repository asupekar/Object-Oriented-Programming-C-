#//
// Created by Aishwarya Supekar on 11/18/19.
//


#include <iostream>
using namespace std;

class Shape {

public:

    Shape (double height = 0.0, double width = 0.0 ):height(height),width(width) {}

    virtual void getArea() {
        cout<<"Area of Shape class";
    }

    virtual void getPerimeter(){
        cout<<"Perimeter of Shape class";
    }

protected:
    double height, width;
};

class Rectangle : public Shape {
public:

    Rectangle (double height = 0.0, double width = 0.0 ):height(height),width(width) {}

    void getArea() override {
        cout<<"\nArea of Rectangle class";
    }

    void getPerimeter() override {
        cout<<"\nPerimeter of Rectangle class";
    }

protected:
    double height, width;

};

class Triangle : public Shape {
public:

    Triangle (double height = 0.0, double width = 0.0 ):height(height),width(width) {}

    void getArea() override {
        cout<<"\nArea of Triangle class";
    }

    void getPerimeter() override {
        cout<<"\nPerimeter of Triangle class";
    }

protected:
    double height, width;

};

class Circle : public Shape {
public:

    Circle (double height = 0.0, double width = 0.0 ):height(height),width(width) {}

    void getArea() override {
        cout<<"\nArea of Circle class";
    }

    void getPerimeter() override {
        cout<<"\nPerimeter of Circle class";
    }

protected:
    double height, width;

};

int main(){
    Shape s(2);
    Rectangle r;
    Circle c;
    Triangle t;

    // Shape *one = &r;
    // one -> getArea();
    // one -> getPerimeter();

    // Shape *two = &c;
    Shape* collection[3];
    collection[0] = &r;
    collection[1] = &c;
    collection[2] = &t;

    for(int i = 0; i < 3; i++){
        cout << endl;
        collection[i]->getArea();
        collection[i]->getPerimeter();
        cout <<endl << endl;
    }



}

