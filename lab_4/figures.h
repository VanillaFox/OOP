#pragma once
#include <iostream>

template<typename T>
struct Rectangle {
	using coords = std::pair<T, T>;
	coords a, b, c, d;
	char name[10] = "rectangle";
};


template<typename T>
struct Rhombus {
	using coords = std::pair<T, T>;
	coords a, b, c, d;
	char name[8] = "rhombus";
}; 


template<typename T>
struct Trapeze {
	using coords = std::pair<T, T>;
	coords a, b, c, d;
	char name[8] = "trapeze";
};
