#include<iostream>
#include"factory.h"
#include"document.h"
#include<memory>
#include<algorithm>

void menu() {
    std::cout << "Enter 0-7 to:" << std::endl;
    std::cout << "1 - add figure" << std::endl;
    std::cout << "2 - delete figure" << std::endl;
    std::cout << "3 - print file" << std::endl;
    std::cout << "4 - undo" << std::endl;
    std::cout << "5 - create new file" << std::endl;
    std::cout << "6 - save file" << std::endl;
    std::cout << "7 - load file" << std::endl;
    std::cout << "0 - exit" << std::endl;
}

int main()
{
    std::ofstream fout;
    std::ifstream fin;
    Document doc;
    int choice;
    unsigned long side;
    char r[30];

    menu();
    do {
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter the position you want to place the new figure: ";
            std::cin >> side;
            try {
                if (side > doc.figures.size() + 1) {
                    throw side;
                }
            }
            catch (const unsigned long a) {
                std::cout << "There is no such position in the list!\n";
                break;
            }
            doc.AddElem(side);
            std::cout << "Done!\n";
            break;
        case 2:
            std::cout << "Enter the position of the figure you want to delete: ";
            try {
                std::cin >> side;
                if (side > doc.figures.size()) {
                    throw side;
                }
            }
            catch (const unsigned long s) {
                std::cout<< "There is no such position in the list!\n";
                break;
            }
            doc.DeleteElem(side);
            std::cout << "Done!\n";
            break;
        case 3: {
            auto print = [](std::shared_ptr<Figure> elem) {
                elem->Print();
            };
            std::for_each(doc.figures.begin(), doc.figures.end(), print);
            break; 
        }
        case 4:
            doc.Undo();
            break;
        case 5:
            doc.CreateNew();
            break;
        case 6:
            std::cout << "Enter the name of file to save: ";
            std::cin >> r;
            fout.open(r, std::ios::out);
            doc.Save(fout);
            std::cout << "Saved!\n";
            fout.close();
            break;
        case 7:
            std::cout << "Enter the name of file to load: ";
            std::cin >> r;
            fin.open(r, std::ios::in);
            if (fin) {
                doc.Load(fin);
                std::cout << "Loaded!\n";
                fin.close();
            }
            else {
                std::cout << "ERROR: can't open file\n";
            }
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
