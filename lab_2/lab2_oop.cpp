/* Вариант-10
Создать класс Angle для работы с углами на плоскости, задаваемыми величиной в градусах и минутах. 
Обязательно должны быть реализованы: перевод в радианы, приведение к диапазону 0–360, сложение и вычитание углов, деление углов,
получение значений тригонометрических функций, сравнение углов. Операции сложения, вычитания, деления, сравнения (на равенство, больше и меньше)
должны быть выполнены в виде перегрузки операторов.
Необходимо реализовать пользовательский литерал для работы с константами типа Angle.
*/

#include "angle.h"
#include <iostream>

void start(){
    std::cout << "This program works with angles. Set the first angle in degrees and/or minutes\n";
    std::cout << "Memo for minutes and degrees. In 1 degree 60 minutes.\nSo, 10 degrees = " << 10.0_dgr << " and 10 minutes = " << 10.0_min << std::endl;
}

void menu() {
    std::cout << "Enter 0-12 to:" << std::endl;
    std::cout << "1 - get the angle in radians;" << std::endl;
    std::cout << "2 - get the angle value in the range 0-360;" << std::endl;
    std::cout << "3 - find the sum of the angles;" << std::endl;
    std::cout << "4 - find the angle difference;" << std::endl;
    std::cout << "5 - get the result of dividing the angles" << std::endl;
    std::cout << "6 - find the sin(x) of an angle;" << std::endl;
    std::cout << "7 - find the cos(x) of an angle;" << std::endl;
    std::cout << "8 - find the tan(x) of an angle;" << std::endl;
    std::cout << "9 - find the ctan(x) of an angle;" << std::endl;
    std::cout << "10 - compare angles;" << std::endl;
    std::cout << "11 - change the degree of the angle;" << std::endl;
    std::cout << "12 - print the degree of the angle;" << std::endl;
    std::cout << "0 - exit" << std::endl;
}

void error() {
    std::cout << "incorrectly entered data" << std::endl;
}
void which() {
    std::cout << "Which angle? (enter the number) ";
}
int main()
{
    Angle ang1, ang2;
    start();
    int a, b;
    std::cout << "Degrees of first angle: ";
    std::cin >> a;
    std::cout << "Minutes of first angle: ";
    std::cin >> b;
    ang1.Degrees(a * 1.0_dgr + b * 1.0_min);

    std::cout << "Degrees of second angle: ";
    std::cin >> a;
    std::cout << "Minutes of second angle: ";
    std::cin >> b;
    ang2.Degrees(a * 1.0_dgr + b * 1.0_min);
    int al;
    menu();
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;
    while (choice!=0) {
        std::cout << ">> ";
        if (choice == 1) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.Rad(1.0_rad);
            }
            else if (al == 2) {
                ang2.Rad(1.0_rad);
            }
            else {
                error();
            }
        }
        else if (choice == 2) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.Range();
            }
            else if (al == 2) {
                ang2.Range();
            }
            else {
                error();
            }
        }
        else if (choice == 3) {
            ang1 + ang2;
        }
        else if (choice == 4) {
            ang1 - ang2;
        }
        else if (choice == 5) {
            ang1/ang2;
        }
        else if (choice == 6) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.sinx();
            }
            else if (al == 2) {
                ang2.sinx();
            }
            else {
                error();
            }
        }
        else if (choice == 7) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.cosx();
            }
            else if (al == 2) {
                ang2.cosx();
            }
            else {
                error();
            }
        }
        else if (choice == 8) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.tanx();
            }
            else if (al == 2) {
                ang2.tanx();
            }
            else {
                error();
            }
        }
        else if (choice == 9) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.ctanx();
            }else if (al == 2) {
                ang2.ctanx();
            }
            else {
                error();
            }
        }
        else if (choice == 10) {
            ang1 == ang2;
        }
        else if (choice == 11) {
            which();
            std::cin >> al;
            if (al == 1) {
                std::cout << "Degrees of first angle: ";
                std::cin >> al;
                std::cout << "Minutes of first angle: ";
                std::cin >> b;
                ang1.Degrees(al * 1.0_dgr + b * 1.0_min);
            }
            else if (al == 2) {
                std::cout << "Degrees of second angle: ";
                std::cin >> al;
                std::cout << "Minutes of second angle: ";
                std::cin >> b;
                ang2.Degrees(al * 1.0_dgr + b * 1.0_min);
            }
            else {
                error();
            }
        }
        if (choice == 12) {
            which();
            std::cin >> al;
            if (al == 1) {
                ang1.Print();
            }
            else if (al == 2) {
                ang2.Print();
            }
            else {
                error();
            }
        }
            std::cout << " " << std::endl;
            std::cout << "What's next? ";
            std::cin >> choice;
    }
    std::cout << "The program is closed, goodbye!" << std::endl;
    return 0;
}
