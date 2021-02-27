#pragma once

class Angle {
public:
    Angle(long double z = 0);
    ~Angle();

    void Degrees(long double a);

    void operator+(Angle& other);
    void operator-(Angle& other);
    void operator/(Angle& other);
    void operator==(Angle& other);

    void cosx();
    void tanx();
    void ctanx();
    void sinx();

    void Rad(long double val);
    void Range();

    //âûâîä óãëà â ãðàäóñàõ
    void Print();

private:
    long double degrees;
};

double operator"" _min(long double a);
double operator"" _dgr(long double a);
double operator"" _rad(long double a);
