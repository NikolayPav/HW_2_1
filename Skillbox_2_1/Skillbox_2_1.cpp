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
        Info = new std::string("Hello");
    }

    Vector(float num) = delete;

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
       Info = new std::string("Hello");
    }

   Vector(const Vector& other)
    {
        std::cout << "\n Copy constructor \n";
        x = other.x;
        y = other.y;
        z = other.z;   
        Info = new std::string("Hello");
    }

    ~Vector()
    {
        //std::cout << "Destructor calling\n";
        if (Info)
        {
            delete Info;
        }
    }

    Vector& operator=(Vector& other)
    {
        std::cout << "Operator = \n";
        x = other.x;
        y = other.y;
        z = other.z;

        if (other.Info)
        {
            if (Info) delete Info;
            Info = new std::string(*(other.Info));
        }
       
        return (*this);
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

    std::string* Info;
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


class A
{
public:
    A(int a)
    {
        std::cout << "int constructor\n";
        test = a;
    }

    A(char a) = delete;
private:
    int test;
};


class MyArray
{
public:
    MyArray(int row, int col)
    {
        n = row;
        m = col;
        matr = new int* [n]; 
        
        for (int i = 0; i < n; i++)
        {
            matr[i] = new int[m];
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matr[i][j] = 0;
            }
        }
        
        Name = new std::string("Array");
    }

    ~MyArray()
        {
        for (int i = 0; i < n; i++)
        {
            if (matr[i]) delete matr[i];
        }

        if (matr) delete[] matr;

        if (Name) delete Name;
        std::cout << "Array delete\n";
        }
    
    MyArray& operator=(MyArray& other)
    {
        if (other.matr)
        {
            for (int i = 0; i < n; i++)
            {
                if (matr[i]) delete matr[i];
            }
            if (matr) delete[] matr;
        }

        n = other.n;
        m = other.m;
        
        matr = new int* [n];

        for (int i = 0; i < n; i++)
        {
            matr[i] = new int[m];
        }
                
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matr[i][j] = other.matr[i][j];
            }
        }

        if (other.Name)
        {
            if (Name) delete Name;
            Name = new std::string(*(other.Name));
        }
      
        std::cout << "Operator = \n"; 
        return (*this);
    }

    friend std::ostream& operator<<(std::ostream& out, const MyArray& a);
    friend std::istream& operator>>(std::istream& in, MyArray& a);

private:
 
    int** matr;
    int n;
    int m;
    std::string* Name;
};

std::ostream& operator<<(std::ostream& out, const MyArray& a)
{
    std::cout << "Array "<<*a.Name <<"[" << a.n << ", " << a.m << "]:\n";
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            out << a.matr[i][j]<<' ';
        }
        std::cout <<'\n';
    }
    
    return out;
}


std::istream& operator>>(std::istream& in, MyArray& a)
{
    delete a.Name;
    std::string Name;
    std::cout << "Enter Name for Array:";
    std::cin >> Name;
    a.Name = new std::string(Name);
   
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            std::cout << "Enter value [" << i<<", "<< j<<"]:";
            in >> a.matr[i][j];
        }
    }
    
    return in;
}


int main()
{
    /*Vector v1(1,1,1);
    Vector v2(2,2,2); 
    Vector v3;
    std::cout << v2 << '\n'; 
    v3 = v2 = v1;
    std::cout << v2<<'\n';
    std::cout << v3 << '\n';*/
        
    MyArray Array1(2, 2);
    std::cout << Array1;
    std::cin >> Array1;
    std::cout << Array1;
    MyArray Array2(2, 3);
    std::cout << Array2;
    Array2 = Array1;
    std::cout << Array2;
}
