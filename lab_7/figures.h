#pragma once
#include<iostream>
#include<fstream>
#include<math.h>

const int ID_Square = 1;
const int ID_Triangle = 2;
const int ID_Rectangle = 3;

class Figure {
public:
	virtual void Print() = 0;
	virtual void Save(std::ostream& file) = 0;
	virtual ~Figure() {}
};

template<typename T>
class Square: public Figure {
private:
	using coords = std::pair<T, T>;
	coords a, b, c, d;
	size_t side;
public:
	Square(T s):side(s) {
		b.first = c.second = c.first = d.second = s;
		a.first = a.second = b.second = d.first = 0;
	}
	Square() {}
	~Square() {
		side = 0;
	}

	void Print() override {
		std::cout << "Square: ";
		std::cout << "(" << a.first << ", " << a.second << "), ";
		std::cout << "(" << b.first << ", " << b.second << "), ";
		std::cout << "(" << c.first << ", " << c.second << "), ";
		std::cout << "(" << d.first << ", " << d.second << ")" << std::endl;
	}

	void Save(std::ostream& file) override {
		file.write((char*)&ID_Square, sizeof(int));
		file.write((char*)&side, sizeof(size_t));
	}
};

template<typename T>
class Triangle: public Figure {
private:
	using coords = std::pair<T, T>;
	coords a, b, c;
	size_t side;

public:
	Triangle(size_t s): side(s) {
		a.first = a.second = b.second = 0;
		b.first = s;
		c.second = s * sqrt(3)/2;
		c.first = (double)s / 2;
	}
	Triangle() {}
	~Triangle() {
		side = 0;
	}

	void Print() override {
		std::cout << "Triangle: ";
		std::cout << "(" << a.first << ", " << a.second << "), ";
		std::cout << "(" << b.first << ", " << b.second << "), ";
		std::cout << "(" << c.first << ", " << c.second << ")" << std::endl;
	}

	void Save(std::ostream& file) override {
		file.write((char*)&ID_Triangle, sizeof(int));
		file.write((char*)&side, sizeof(size_t));
	}
};

template<typename T>
class Rectangle : public Figure {
private:
	using coords = std::pair<T, T>;
	coords a, b, c, d;
	size_t side, height;
public:
	Rectangle(T s, T h) :side(s), height(h) {
		a.first = a.second = b.second = d.first = 0;
		b.first = c.first = s;
		c.second = d.second = h;
	}

	Rectangle() {}

	~Rectangle() {
		side = 0;
	}

	void Print() override {
		std::cout << "Rectangle: ";
		std::cout << "(" << a.first << ", " << a.second << "), ";
		std::cout << "(" << b.first << ", " << b.second << "), ";
		std::cout << "(" << c.first << ", " << c.second << "), ";
		std::cout << "(" << d.first << ", " << d.second << ")" << std::endl;
	}

	void Save(std::ostream& file) override {
		file.write((char*)&ID_Rectangle, sizeof(int));
		file.write((char*)&side, sizeof(size_t));
		file.write((char*)&height, sizeof(size_t));
	}
};
