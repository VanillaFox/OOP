#include "figures.h"
#include "functions.h"
#include <iostream>
#include <tuple>


void menu() {
    std::cout << "Enter 0-5 to:" << std::endl;
    std::cout << "1 - add a trapeze" << std::endl;
    std::cout << "2 - add a rhombus" << std::endl;
    std::cout << "3 - add a rectangle" << std::endl;
    std::cout << "4 - print all coordinates of figures" << std::endl;
    std::cout << "5 - find the total square" << std::endl;
    std::cout << "0 - exit" << std::endl;
}

void error() {
    std::cout << "Incorrect value!" << std::endl;
}

int main()
{
    int choice, type;
    double a, b, c;
    menu();
    std::tuple<Trapeze<double>, Trapeze<int>, Rhombus<double>, Rhombus<int>, Rectangle<double>, Rectangle<int>> all;
    std::cout << "Your choice: ";

    do {
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "What datatype of shape coordinates do you want? int(1) or double(2)? ";
            std::cin >> type;
            if (type > 2) {
                error();
            }
            else {
                std::cout << "Enter the two bases and the height of the trapezoid: ";
                std::cin >> a >> b >> c;
                if (type == 2) {
                    get_coord_trapeze(std::get<0>(all), a, b, c);
                }
                else if (type == 1) {
                    double correct = abs(a-b)/2;
                    if (correct == (long long)correct && a==(long long)a && b == (long long)b && c == (long long)c) {
                        get_coord_trapeze(std::get<1>(all), a, b, c);
                    }
                    else {
                        error();
                    }
                }
            }
            break;
        case 2:
            std::cout << "What datatype of shape coordinates do you want? int(1) or double(2)? ";
            std::cin >> type;
            if (type > 2) {
                error();
            }
            else {
                std::cout << "Enter the two diagonals of the rhombus: ";
                std::cin >> a >> b;
                if (type == 2) {
                    get_coords_rhomb(std::get<2>(all), a, b);
                }
                else if (type == 1) {
                    double correct1 = a/2, correct2=b/2;
                    if (correct1 == (long long)correct1 && correct2 == (long long)correct2) {
                        get_coords_rhomb(std::get<3>(all), a, b);
                    }
                    else {
                        error();
                    }
                }
            }
            break;
        case 3:
            std::cout << "What datatype of shape coordinates do you want? int(1) or double(2)? ";
            std::cin >> type;
            if (type > 2) {
                error();
            }
            else {
                std::cout << "Enter the two sides of the rectangle: ";
                std::cin >> a >> b;
                if (a != b) {
                    if (type == 2) {
                        get_coords_rectanle(std::get<4>(all), a, b);
                    }
                    else if (type == 1) {
                        if (a == (long long)a && b == (long long)b) {
                            get_coords_rectanle(std::get<5>(all), a, b);
                        }
                        else {
                            error();
                        }
                    }
                }
                else {
                    error();
                }
            }
            break;
        
        case 4:
            print_tuple<decltype(all), 0>(all);
            break;
        case 5:
            std::cout <<"Total square of figures is "<< square(all)<<std::endl;
            break;
        case 0:
            std::cout << "The program is closed, goodbye!\n";
            return false;
            break;
        default:
            std::cout << "Incorrect values! Try again.\n";
            break;
        }
        std::cout << "What's next?\n";
        std::cout << ">>";
    } while (choice);

}
