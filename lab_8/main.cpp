#include "factory.h"
#include "handler.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

void menu() {
    std::cout << "Enter 0-1 to:" << std::endl;
    std::cout << "1 - add figure" << std::endl;
    std::cout << "0 - exit" << std::endl;
}


int main(int argc, char** argv) {
    size_t buf_size = 2;

    if (argc == 2) {
        std::stringstream argc;
        argc << argv[1];
        argc >> buf_size;
    }
    
    int choice;
    unsigned long side;
    char r[10];
    Handler handler(buf_size);

    handler.Functions([](const std::list<std::shared_ptr<Figure>>& figs) {
        for (auto& fig : figs) {
            fig->Print();
        }
    });
    
    static int filename;

    handler.Functions([](const std::list<std::shared_ptr<Figure>>& figs) {
        filename = rand();
        std::string str = std::to_string(filename) + ".txt";
        std::ofstream file(str);
        for (auto items : figs) {
            items->Write(file);
        }
        file.close();
    });

    menu();
    do {
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter name of figure: ";
            std::cin >> r;
            handler.Push(Factory<double>::CreateFigure(r));
            std::cout << "Done!\n";
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
    } while (choice);

    std::cout << std::endl;
    return 0;
}
