#include <iostream>
#include <iter.hpp>
#include <cstdlib>
#include <ctime>

struct Point2D {
    int x, y;
    Point2D() {
        x = 0;
        y = 0;
    }
};

std::ostream &operator<<(std::ostream &out, Point2D const &point) {
    out << "<Point2D x=" << point.x << " y=" << point.y << ">" << std::endl;
    return out;
}

void    randomizePoint2D(Point2D& point) {
    point.x = rand() % 10 + 1;
    point.y = rand() % 10 + 1;
}

template<typename T>
void    print(T& data) {
    std::cout << data;
}

int main()
{
    srand(time(NULL));

    Point2D pointsArr[5];
    Point2D *pointsArr2 = new Point2D[10];

    iter(pointsArr, 5, randomizePoint2D);
    iter(pointsArr, 5, print);
    std::cout << "------" << std::endl;
    iter(pointsArr2, 5, randomizePoint2D);
    iter(pointsArr2, 10, print);

    delete[] pointsArr2;

	return 0;
}
