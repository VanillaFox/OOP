#include <iostream>
#include <cmath>
#define PI 3.14159265

class vector3D {
	public:
		void get_cor(int ai[]) {
			a = ai[0];
			b = ai[1];
			c = ai[2];
		}

		vector3D operator+(vector3D& v2);
		vector3D operator-(vector3D& v2);
		int operator*(vector3D& v2);
		vector3D operator*(int a);
		vector3D operator^(vector3D& v2);
		double operator==(vector3D& v2);
		void operator>=(vector3D& v2);
		void operator<=(vector3D& v2);

		//длина вектора
		double size() {
			return sqrt(std::pow(a, 2) + std::pow(b, 2) + std::pow(c, 2));
		}
		//вывод
		void show() {
			std::cout << a << " " << b << " " << c<<std::endl;
		}

	private:
		int a, b, c;
};

//сравнение длин векторов
void vector3D::operator>=(vector3D& v2) {
	if ((*this).size()>v2.size()) {
		std::cout << "V1 more then V2" << std::endl;
	}else if((*this).size() < v2.size()) {
		std::cout << "V2 more then V1" << std::endl;
	}
	else {
		std::cout << "V1 and V2 are the same" << std::endl;
	}
}

//совпадение векторов
void vector3D::operator<=(vector3D& v2) {
	if (a == v2.a && b == v2.b && c == v2.c) {
		std::cout << "Yes, they match!" << std::endl;
	}
	else {
		std::cout << "No, they don't match!" << std::endl;
	}
}

//сложение векторов
vector3D vector3D::operator+(vector3D& v2) {
	vector3D vec;
	vec.a = a + v2.a;
	vec.b = b + v2.b;
	vec.c = c + v2.c;
	return vec;
}

//умножение на скаляр
vector3D vector3D::operator*(int neww) {
	vector3D vec;
	vec.a = a * neww;
	vec.b = b * neww;
	vec.c = c * neww;
	return vec;
}

//скалярное произведение
int vector3D::operator*(vector3D& v2) {
	return (a * v2.a + b * v2.b + c * v2.c);
}

//угол между векторами
double vector3D::operator==(vector3D& v2) {
	double cos = (*this) * v2/((*this).size()*v2.size());
	double angle = acos(cos) * 180 / PI;
	return angle;
}

//векторное произведение
vector3D vector3D::operator^(vector3D& v2) {
	vector3D vec;
	vec.a = b * v2.c - v2.b * c;
	vec.b = (-1) * (a * v2.c - v2.a * c);
	vec.c = a * v2.b - v2.a * b;
	return vec;
}

//разность векторов
vector3D vector3D::operator-(vector3D& v2) {
	vector3D vec;
	vec.a = a - v2.a;
	vec.b = b - v2.b;
	vec.c = c - v2.c;
	return vec;
}

void menu() {
	std::cout << "Enter 0-11 to:" << std::endl;
	std::cout << "1 - compare lengths of vectors;" << std::endl;
	std::cout << "2 - perform subtraction of vectors;" << std::endl;
	std::cout << "3 - perform addition of vectors;" << std::endl;
	std::cout << "4 - multiply vector by scalar;" << std::endl;
	std::cout << "5 - compare vectors for match" << std::endl;
	std::cout << "6 - calculate vector length" << std::endl;
	std::cout << "7 - calculate the angle between vectors" << std::endl;
	std::cout << "8 - get vector product;" << std::endl;
	std::cout << "9 - get scalar product;" << std::endl;
	std::cout << "10 - change vector coordinates;" << std::endl;
	std::cout << "11 - print vector coordinates;" << std::endl;
	std::cout << "0 - exit" << std::endl;
}

int main() {
	vector3D vector1;
	vector3D vector2;
	int vec1[3], vec2[3];

	std::cout << "This program works with vectors in space. To get started enter coordinates of two vectors." << std::endl;

	std::cout << "Vvedi v1:" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cin >> vec1[i];
	}

	std::cout << "Vvedi v2:" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cin >> vec2[i];
	}

	vector1.get_cor(vec1);
	vector2.get_cor(vec2);

	int a;
	menu();
	std::cout << "Your choice: ";
	std::cin >> a;
	while (a != 0) {
		std::cout << ">> ";
		if (a == 1)
			vector1 >= vector2;
		if (a == 2)
			(vector1 - vector2).show();
		if (a == 3)
			(vector1 + vector2).show();
		if (a == 4) {
			double b;
			int c;
			std::cout << "Enter scalar: ";
			std::cin >> b;
			std::cout << ">> What vector do we take for multiplication? (Write the number) ";
			std::cin >> c;
			if (c == 1)
				(vector1 * b).show();
			else
				(vector2 * b).show();
		}
		if (a == 5)
			vector1 <= vector2;
		if (a == 6) {
			std::cout << "Which vector length do you want to get? (Write the number) ";
			int b;
			std::cin >> b;
			if (b == 1)
				std::cout << vector1.size() << std::endl;
			else
				std::cout << vector2.size() << std::endl;
		}
		if (a == 7)
			std::cout << (vector1 == vector2) << std::endl;
		if (a == 8)
			(vector1 ^ vector2).show();
		if (a == 9)
			std::cout << vector1 * vector2 << std::endl;
		if (a == 10){
			std::cout << "Which vector coordinates do you want to change? (Write the number) ";
			int b, change[3];
			std::cin >> b;
			std::cout << "Enter coordinates of new vector: ";
			for (int i = 0; i < 3; i++) {
				std::cin >> change[i];
			}
			if(b==1)
				vector1.get_cor(change);
			else
				vector2.get_cor(change);
			std::cout << "Done!"<<std::endl;
		}
		if (a == 11) {
			std::cout << "Which vector coordinates do you want to print? (Write the number) ";
			int b;
			std::cin >> b;
			if (b == 1)
				vector1.show();
			else
				vector2.show();
		}
		std::cout << " " << std::endl;
		std::cout << "What's next? ";
		std::cin >> a;
	}
	std::cout << "The program is closed, goodbye!" << std::endl;
	return 0;
}
