#pragma once
#include<iostream>
#include<tuple>

template<typename T, typename S>
void get_coord_trapeze(T& tuple, S base1, S base2, S height) {
    double tmp;
    if (base1 < base2) {
        tmp = base2;
        base2 = base1;
        base1 = tmp;
    }
    tuple.a.first = tuple.a.second = tuple.b.second = 0;
    tuple.b.first = base1;
    tuple.c.first = base2 + (base1 - base2) / 2;
    tuple.c.second = tuple.d.second = height;
    tuple.d.first = (base1 - base2) / 2;
}

template<typename T, typename S>
void get_coords_rectanle(T& tuple_elem, S horiz, S vert) {
    tuple_elem.a.first = tuple_elem.a.second = tuple_elem.d.first = tuple_elem.b.second = 0;
    tuple_elem.b.first = tuple_elem.c.first = horiz;
    tuple_elem.c.second = tuple_elem.d.second = vert;
}

template<typename T, typename S>
void get_coords_rhomb(T& tuple_elem, S horiz, S vert) {
    tuple_elem.a.first = tuple_elem.a.second = tuple_elem.c.second = 0;
    tuple_elem.b.first = tuple_elem.d.first = horiz / 2;
    tuple_elem.b.second = vert / 2;
    tuple_elem.c.first = horiz;
    tuple_elem.d.second = -vert / 2;
}

template <class T, size_t index> typename std::enable_if<index >= std::tuple_size<T>::value, void>::type print_tuple(T&) {
    std::cout << std::endl;
}
template <class T, size_t index> typename std::enable_if < index<std::tuple_size<T>::value, void>::type print_tuple(T& tuple) {
    auto vertex = std::get<index>(tuple);
    print(vertex);
    print_tuple<T, index + 1>(tuple);
}

template<typename T>
void print(T& obj) {
    std::cout <<"Name of shape is "<< obj.name <<std::endl;
    std::cout << "(" << obj.a.first << ", " << obj.a.second << "), (" << obj.b.first << ", " << obj.b.second << "), (" << obj.c.first << ", " << obj.c.second << "), (" << obj.d.first << ", " << obj.d.second << ")" << std::endl;
}

template<typename T>
double square_of_rectangle(T& elem) {
    return elem.c.first* elem.c.second;
}

template<typename T>
double square_of_rhombus(T& elem) {
    return (elem.b.first * elem.b.second * 2);
}

template<typename T>
double square_of_trapeze(T& elem) {
    return ((elem.b.first + elem.c.first - elem.d.first) / 2) * elem.c.second;
}

template<typename T>
double square(T& tuple) {
    double t = 0;
    t = t + square_of_trapeze(std::get<0>(tuple)) + square_of_trapeze(std::get<1>(tuple));
    t = t + square_of_rhombus(std::get<2>(tuple)) + square_of_rhombus(std::get<3>(tuple));
    t = t + square_of_rectangle(std::get<4>(tuple)) + square_of_rectangle(std::get<5>(tuple));
    return t;
}
