#pragma once
#include<iostream>

class Figure {
	public:
		virtual void Area() = 0;
		virtual void Coordinates() = 0;
		virtual void GeometricCenter() = 0;
		virtual double GetArea() = 0;
};



class Trapeze: public Figure {
public:
	Trapeze() : base1(0), base2(0), height(0) {}
	Trapeze(double a, double b, double c) : base1(a), base2(b), height(c) {}
	~Trapeze() {}

	double GetArea() {
		return (base1 * base2) * height / 2;
	}

	void Area() override{
		std::cout << "Area of trapeze is " << (base1*base2)*height / 2 << std::endl;
	}
	void Coordinates() override {
		double llong, change;
		llong = abs(base1-base2)/2;
		if (base2 > base1) {
			change = base1;
			base1 = base2;
			base2 = change;
		}
		std::cout << "Coordinates of trapeze: (0, 0), (" << base1 << ", 0), (" << llong << ", " << height << "), (" << (base2 + llong) << ", " << height << ")" << std::endl;
	}
	void GeometricCenter() override {
		double change;
		if (base2 > base1) {
			change = base1;
			base1 = base2;
			base2 = change;
		}
		std::cout << "Geometric center of the trapeze is (" << base1 / 2 << ", " << height / 2 << ")" << std::endl;
	}
private:
	double base1, base2, height;
};



class Rhombus: public Figure {
public:
	Rhombus() : horizontal(0), vertical(0) {}
	Rhombus(double d1, double d2) :horizontal(d1), vertical(d2) {}
	~Rhombus() {}

	double GetArea() {
		return (horizontal * vertical) / 2;
	}

	void Area() override {
		std::cout << "Area of rhombus is "<< (horizontal * vertical) / 2<<std::endl;
	}
	void Coordinates() override {
		std::cout << "Coordinates of rhombus: (0, 0), (" << horizontal <<", 0), ("<< horizontal/2 <<", "<< vertical /2 <<"), (-" << horizontal/ 2 << ", -" << vertical/ 2 << ")"<< std::endl;
	}
	void GeometricCenter() override {
		std::cout << "Geometric center of the rhombus is (0, " << horizontal / 2 << ")" << std::endl;
	}
private:
	double horizontal, vertical;
};



class Rectangle: public Figure {
public:
	Rectangle() : width(0), height(0) {}
	Rectangle(double d1, double d2) :width(d1), height(d2) {}
	~Rectangle() {}
	void Area() override {
		std::cout << "Area of rectangle is " << (width * height) << std::endl;
	}

	double GetArea() {
		return (width * height);
	}

	void Coordinates() override {
		std::cout << "Coordinates of rectangle: (0, 0), (" << width << ", 0), (0, " << height << "), (" << width  << ", " << height << ")" << std::endl;
	}
	void GeometricCenter() override {
		std::cout << "Geometric center of the rectangle is (" << width/2 <<", " << height/2 << ")" << std::endl;
	}
private:
	double width, height;
};
