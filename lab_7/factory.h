#pragma once
#include<memory>
#include"figures.h"

template<typename T>
class Factory {
public:
	static std::shared_ptr<Figure> CreateFigure(char* type){
		std::shared_ptr<Figure> fig;
		std::cout << "Enter side: ";
		T side;
		if (type[0] == 's') {
			std::cin >> side;
			fig = std::make_shared<Square<T>>(side);
		}
		if (type[0] == 't') {
			std::cin >> side;
			fig = std::make_shared<Triangle<T>>(side);
		}
		if (type[0] == 'r') {
			T height;
			std::cin >> side >> height;
			fig = std::make_shared<Rectangle<T>>(side, height);
		}
		return fig;
	}	
};
