// Skillbox_2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <istream>

class Vector
{
public:
    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, const float& b);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);
    friend bool operator>(const Vector& a, const Vector& b);

    float operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            std::cout << "Index error ";
            return 0;
            break;
        }
    }
private:
    float x;
    float y;
    float z;
};

Vector operator+(const Vector& a, const Vector& b)
{
  return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const Vector& a, const float& b)
{
    return Vector(a.x * b, a.y * b, a.z * b);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    std::cout << "X=";
    in >> v.x;
    std::cout << "Y=";
    in >> v.y;
    std::cout << "Z=";
    in >> v.z;
    return in;
}

bool operator>(const Vector& a, const Vector& b)
{
    return false;
}

int main()
{
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3;
    v3 = v1 + v2;
    std::cout << v3<<'\n';
    std::cout << "v3 lenght: " << static_cast<float>(v3) << '\n';
    Vector v4=v1*2.0f;
    std::cout << "v1*2=" << v4 << '\n';
    std::cout << "v2-v1=" << v2-v1 << '\n';
    Vector v5; 
    std::cin >> v5;
    std::cout << "v5=" << v5 << '\n';
}
