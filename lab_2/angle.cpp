#include "angle.h"
#define Pi 3.14159265
#include<cmath>
#include <iostream>

Angle::Angle(long double z) :degrees(z) {}

Angle::~Angle() {
    degrees = 0;
}

void Angle::Print() {
    std::cout << degrees << std::endl;
}

void Angle::Rad(long double val) {
    std::cout << degrees * val << " radians;" << std::endl;
}

void Angle::Range() {
    long double z = degrees;
    while (z > 360) {
        z -= 360;
    }
    std::cout << "In a 360 degree range it is " << z << " degrees;" << std::endl;
}

void Angle::sinx() {
    std::cout << sin(degrees) << std::endl;
}

void Angle::ctanx() {
    std::cout << 1 / tan(degrees) << std::endl;
}

void Angle::tanx() {
    std::cout << tan(degrees) << std::endl;
}

void Angle::cosx() {
    std::cout << cos(degrees) << std::endl;
}

double operator""_min(long double val) {
    return val / 60;
}

double operator""_rad(long double val) {
    return Pi / 180;
}

double operator""_dgr(long double val) {
    return val;
}
void Angle::Degrees(long double a) {
    degrees = a;
}
void Angle::operator+(Angle& other) {
    std::cout << "" << degrees + other.degrees << std::endl;
}

void Angle::operator-(Angle& other) {
    std::cout << degrees - other.degrees << std::endl;
}

void Angle::operator/(Angle& other) {
    std::cout << degrees / other.degrees << std::endl;
}

void Angle::operator==(Angle& other) {
    if (degrees > other.degrees) {
        std::cout << "The first angle is greater than the second;" << std::endl;
    }
    else if (degrees < other.degrees) {
        std::cout << "The second angle is greater than the first;" << std::endl;
    }
    else {
        std::cout << "This angles are equal;" << std::endl;
    }
}
