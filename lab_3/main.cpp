/*Создать программу, которая позволяет:
•       Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
•       Сохранять созданные фигуры в динамический массив std::vector<Figure*>
•   	Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
•       Необходимо уметь вычислять общую площадь фигур в массиве.
•       Удалять из массива фигуру по индексу;
Фигуры: прямоугольник, трапеция, ромб.
*/
#include "figure.h"
#include <iostream>
#include <vector>

void menu() {
	std::cout << "Enter 0-7 to:" << std::endl;
	std::cout << "1 - add a trapeze" << std::endl;
	std::cout << "2 - add a rhombus" << std::endl;
	std::cout << "3 - add a rectangle" << std::endl;
	std::cout << "4 - find the total area" << std::endl;
	std::cout << "5 - call all common functions" << std::endl;
	std::cout << "6 - delete the n-th object" << std::endl;
	std::cout << "7 - find out the area, coordinates and geometric center of the n-th figure" << std::endl;
	std::cout << "0 - exit" << std::endl;
}

int main()
{

    std::vector<Figure*> vec;
    double a, b, c, total=0;
    int index, num = 1;

    Figure* R;
    menu();

    int choice;
    std::cout << "Your choice: ";
    
    do {
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the two bases and the side of the trapezoid: ";
            std::cin >> a >> b >> c;
            R = new Trapeze(a, b, c);
            vec.push_back(R);
            break;
        case 2:
            std::cout << "Enter the two diagonals of the rhombus: ";
            std::cin >> a >> b;
            R = new Rhombus(a, b);
            vec.push_back(R);
            break;
        case 3:
            std::cout << "Enter the two sides of the rectangle: ";
            std::cin >> a >> b;
            R = new Rectangle(a, b);
            vec.push_back(R);
            break;
        case 4:
            for (const auto&obj: vec) {
                total += obj->GetArea();
            }
            std::cout <<"The total area of the figures is " << total <<std::endl;
            total = 0;
            break;
        case 5:
            for (const auto& obj : vec) {
                std::cout << "Figure " << num <<":\n";
                obj->Area();
                obj->Coordinates();
                obj->GeometricCenter();
                std::cout << "\n";
                num++;
            }
            num = 1;
            break;
        case 6:
            std::cout << "Which figure number do you want to delete? ";
            std::cin >> index;
            vec.erase(vec.begin() + (index - 1));
            std::cout << "Done!\n";
            break;
        case 7:
            std::cout << "What figure do you want to print? (enter her number) ";
            std::cin >> index;
            vec[index - 1]->Area();
            vec[index - 1]->Coordinates();
            vec[index - 1]->GeometricCenter();
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

    return 0;
}
