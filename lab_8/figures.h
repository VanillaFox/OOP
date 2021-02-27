#pragma once
#include<iostream>
#include <fstream>

class Figure {
public:
	virtual void Print() = 0;
	virtual void Write(std::ostream& file) = 0;
	virtual ~Figure() = default;
};

template<typename T>
class Square : public Figure {
private:
	using coords = std::pair<T, T>;
	coords a, b, c, d;
	size_t side;
public:
	Square(T s) :side(s) {
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

	void Write(std::ostream& file) override {
		file << "Square ";
		file << "{";
		file << "(" << a.first << ", " << a.second << "), ";
		file << " (" << b.first << ", " << b.second << "), ";
		file << " (" << c.first << ", " << c.second << "), ";
		file << " (" << d.first << ", " << d.second << ")";
		file << "}\n";
	}
};

template<typename T>
class Triangle : public Figure {
private:
	using coords = std::pair<T, T>;
	coords a, b, c;
	size_t side;

public:
	Triangle(size_t s) : side(s) {
		a.first = a.second = b.second = 0;
		b.first = s;
		c.second = s * sqrt(3) / 2;
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

	void Write(std::ostream& file) override {
		file << "Triangle ";
		file << "{";
		file << "(" << a.first << ", " << a.second << "), ";
		file << " (" << b.first << ", " << b.second << "), ";
		file << " (" << c.first << ", " << c.second << ")";
		file << "}\n";
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
		height = 0;
	}

	void Print() override {
		std::cout << "Rectangle: ";
		std::cout << "(" << a.first << ", " << a.second << "), ";
		std::cout << "(" << b.first << ", " << b.second << "), ";
		std::cout << "(" << c.first << ", " << c.second << "), ";
		std::cout << "(" << d.first << ", " << d.second << ")" << std::endl;
	}

	void Write(std::ostream& file) override {
		file << "Rectangle ";
		file << "{";
		file << "(" << a.first << ", " << a.second << "), ";
		file << " (" << b.first << ", " << b.second << "), ";
		file << " (" << c.first << ", " << c.second << "), ";
		file << " (" << d.first << ", " << d.second << ")";
		file << "}\n";
	}
};
