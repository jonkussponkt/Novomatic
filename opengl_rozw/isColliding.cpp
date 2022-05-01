//#include "isColliding.h"
//#include <iostream>
//#include <utility>
//#include <algorithm>
//
//double getLength(int x1, int y1, int x2, int y2) {
//    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//}
//
//template<typename NUMBER>
//triangle generateTriangle(NUMBER x1, NUMBER x2, NUMBER y1, NUMBER y2) {
//    double lengths[3];
//    triangle triangle1;
//    srand(time(NULL));
//    for (int i = 0; i < 3; i++) {
//        triangle1.points[i].x = rand() % (x2 - x1 + 1) + x1;
//        triangle1.points[i].y = rand() % (y2 - y1 + 1) + y1;
//    }
//    lengths[0] = getLength(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[1].x, triangle1.points[1].y);
//    lengths[1] = getLength(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
//    lengths[2] = getLength(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);
//    while (lengths[0] > lengths[1] + lengths[2] || lengths[1] > lengths[0] + lengths[2] || lengths[2] > lengths[0] + lengths[1]) {
//        triangle1.points[2].x = rand() % x1 + x2;
//        triangle1.points[2].y = rand() % y1 + y2;
//        lengths[1] = getLength(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
//        lengths[2] = getLength(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);
//    }
//    return triangle1;
//}
//
//std::pair<double, double> generateEquation(double x1, double y1, double x2, double y2) {
//    std::pair<double, double> equation;
//    equation.first = (y2-y1)/(x2-x1);
//    equation.second = x1 * equation.first - y1;
//    std::cout << "y=" << equation.first << "x+" << equation.second << std::endl;
//    return equation;
//}
//
//std::pair<double, double> generateDomain(double x1, double x2) {
//    return x1 < x2 ? std::make_pair(x1, x2) : std::make_pair(x2, x1);
//}
//
//bool checkCollision(const std::pair<double, double> & equation1, const std::pair<double, double>& equation2) {
//    
//    return true;
//}
//
//bool isColliding(/*const triangle& triangle1, const triangle& triangle2*/) {
//    int x1 = -7, x2 = -1; 
//    int y1 = 1, y2 = 6;
//    triangle triangle1 = generateTriangle(-7, -1, 1, 6);
//    triangle triangle2 = generateTriangle(-6, 0, 0, 4);
//
//    std::cout << "TRIANGLE NR 1:\n(";
//    for (int i = 0; i < 3; i++) {
//        std::cout << triangle1.points[i].x << ", " << triangle1.points[i].y << ")\n(";
//    }
//    std::cout << "TRIANGLE NR 2:\n(";
//    for (int i = 0; i < 3; i++) {
//        std::cout << triangle2.points[i].x << ", " << triangle2.points[i].y << ")\n(";
//    }
//
//    std::pair<double, double> equations[6];
//    equations[0] = generateEquation(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[1].x, triangle1.points[1].y);
//    equations[1] = generateEquation(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);
//    equations[2] = generateEquation(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
//    equations[3] = generateEquation(triangle2.points[0].x, triangle2.points[0].y, triangle2.points[1].x, triangle2.points[1].y);
//    equations[4] = generateEquation(triangle2.points[0].x, triangle2.points[0].y, triangle2.points[2].x, triangle2.points[2].y);
//    equations[5] = generateEquation(triangle2.points[1].x, triangle2.points[1].y, triangle2.points[2].x, triangle2.points[2].y);
//
//
//    std::pair<double, double> domains[6];
//    domains[0] = generateDomain(triangle1.points[0].x, triangle1.points[1].x);
//    domains[1] = generateDomain(triangle1.points[0].x, triangle1.points[2].x);
//    domains[2] = generateDomain(triangle1.points[1].x, triangle1.points[2].x);
//    domains[3] = generateDomain(triangle2.points[0].x, triangle2.points[1].x);
//    domains[4] = generateDomain(triangle2.points[0].x, triangle2.points[2].x);
//    domains[5] = generateDomain(triangle2.points[1].x, triangle2.points[2].x);
//
//    std::cout << "Are they colliding??\n";
//    double x, y;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 3; j < 6; j++) {
//            x = (equations[j].second - equations[i].second) / (equations[i].first - equations[j].first);
//            y = equations[i].first * x + equations[i].second;
//            if (x >= domains[j].first || x <= domains[j].second) {
//                std::cout << "YES";
//                return true;
//            }
//        }
//    }
//    std::cout << "NO";
//    return false;
//}
