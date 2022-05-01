#include <iostream>
#include <utility>
#include <cmath>
#include <array>
#include <ctime>

struct vec2 {
    float x, y;
};
struct triangle {
    std::array<vec2, 3> points;
};

template<typename NUMBER>
double getLength(NUMBER x1, NUMBER y1, NUMBER x2, NUMBER y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

//generator trójk¹tów do testowania

template<typename NUMBER>
triangle generateTriangle(NUMBER x1, NUMBER x2, NUMBER y1, NUMBER y2) {
    double lengths[3];
    triangle triangle1;
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        triangle1.points[i].x = rand() % (x2 - x1 + 1) + x1;
        triangle1.points[i].y = rand() % (y2 - y1 + 1) + y1;
    }
    lengths[0] = getLength(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[1].x, triangle1.points[1].y);
    lengths[1] = getLength(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
    lengths[2] = getLength(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);

    //sprawdzenie nierównoœci trójk¹ta przy losowaniu 3 wierzcho³ka

    while (lengths[0] > lengths[1] + lengths[2] || lengths[1] > lengths[0] + lengths[2] || lengths[2] > lengths[0] + lengths[1]) {
        triangle1.points[2].x = rand() % (x2 - x1 + 1) + x1;
        triangle1.points[2].y = rand() % (y2 - y1 + 1) + y1;
        lengths[1] = getLength(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
        lengths[2] = getLength(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);
    }
    return triangle1;
}

std::pair<double, double> generateEquation(double x1, double y1, double x2, double y2);
std::pair<double, double> generateDomain(double x1, double x2);
bool isColliding(const triangle& triangle1, const triangle& triangle2);
