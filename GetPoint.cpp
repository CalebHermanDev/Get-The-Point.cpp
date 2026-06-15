#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord)
    {
        x = xCoord;
        y = yCoord;
    }

    double operator-(const Point &other) const
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const
    {
        return !(*this == other);
    }

    Point operator/(const Point &other) const
    {
        double midX = (x + other.x) / 2.0;
        double midY = (y + other.y) / 2.0;

        return Point(midX, midY);
    }

    friend ostream &operator<<(ostream &out, const Point &p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
    Point &operator++()
    {
        x++;
        return *this;
    }

    Point operator++(int)
    {
        Point temp = *this;
        y++;
        return temp;
    }

    Point &operator--()
    {
        x--;
        return *this;
    }

    Point operator--(int)
    {
        Point temp = *this;
        y--;
        return temp;
    }

    double &operator[](int index)
    {
        if (index == 0)
            return x;
        else
            return y;
    }

    friend istream &operator>>(istream &in, Point &p)
    {
        char c1, c2, c3;

        in >> c1 >> p.x >> c2 >> p.y >> c3;

        return in;
    }
};

int main()
{
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    cout << "Distance: " << p1 - p2 << endl;
    cout << "Equal: " << (p1 == p2) << endl;
    cout << "Not equal: " << (p1 != p2) << endl;
    cout << "Midpoint: " << (p1 / p2) << endl;

    ++p1;
    cout << "After ++p1: " << p1 << endl;

    p1++;
    cout << "After p1++: " << p1 << endl;

    --p1;
    cout << "After --p1: " << p1 << endl;

    p1--;
    cout << "After p1--: " << p1 << endl;

    cout << "x = " << p1[0] << endl;
    cout << "y = " << p1[1] << endl;

    Point p3(0, 0);

    cout << "Enter a point in the form (x, y): ";
    cin >> p3;

    cout << "You entered " << p3 << endl;

    return 0;
}

/**
 * 1. both == and != operators return boolean values.
 *
 * 2. Distance returns a double type
 *
 * 3. Midpoint returns a Point type that we declared in the class.
 *
 * 4. I feel that operators like == for equality and != for inequality are intuitive and commonly used, and even things
 * like << and >> for output and input are pretty easily understandable, but using p1 - p2 or p1 / p2 for distance
 * and midpoint is less intuitive and might be confusing for some developers. something like a function call like p1.distance(p2)
 * or p1.midpoint(p2) might be more clear, and normally substraction and division imply mathematical arithmetic.
 *
 * 5. There isn't a natural way to compare whether one point is greater or less than another in a cartesian system.
 * Although we can define our own ordering scheme, such as comparing x-values first or comparing distance from the origin,
 * these methods are arbitrary and may not match what another programmer expects.
 */