#include "zad1.h"

//funkcja generuj�ca wz�r prostej - elementy pary to wsp�czynniki a i b
std::pair<double, double> generateEquation(double x1, double y1, double x2, double y2) {
    std::pair<double, double> equation;
    equation.first = (y1 - y2) / (x1 - x2);
    equation.second = y1 - x1 * equation.first;
    return equation;
}

//generuje dziedzin� 
std::pair<double, double> generateDomain(double x1, double x2) {
    return x1 < x2 ? std::make_pair(x1, x2) : std::make_pair(x2, x1);
}

bool isColliding(const triangle& triangle1, const triangle& triangle2) {

    std::cout << "TRIANGLE NR 1:\n(";
    for (int i = 0; i < 3; i++) {
        std::cout << triangle1.points[i].x << ", " << triangle1.points[i].y << ")\n(";
    }
    std::cout << "TRIANGLE NR 2:\n(";
    for (int i = 0; i < 3; i++) {
        std::cout << triangle2.points[i].x << ", " << triangle2.points[i].y << ")\n(";
    }

    //generowanie r�wna� kierunkowych prostych zawieraj�cych boki obu tr�jk�t�w
    std::pair<double, double> equations[6];
    equations[0] = generateEquation(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[1].x, triangle1.points[1].y);
    equations[1] = generateEquation(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);
    equations[2] = generateEquation(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
    equations[3] = generateEquation(triangle2.points[0].x, triangle2.points[0].y, triangle2.points[1].x, triangle2.points[1].y);
    equations[4] = generateEquation(triangle2.points[0].x, triangle2.points[0].y, triangle2.points[2].x, triangle2.points[2].y);
    equations[5] = generateEquation(triangle2.points[1].x, triangle2.points[1].y, triangle2.points[2].x, triangle2.points[2].y);

    //generowanie dziedzin tych prostych
    std::pair<double, double> domains[6];
    domains[0] = generateDomain(triangle1.points[0].x, triangle1.points[1].x);
    domains[1] = generateDomain(triangle1.points[0].x, triangle1.points[2].x);
    domains[2] = generateDomain(triangle1.points[1].x, triangle1.points[2].x);
    domains[3] = generateDomain(triangle2.points[0].x, triangle2.points[1].x);
    domains[4] = generateDomain(triangle2.points[0].x, triangle2.points[2].x);
    domains[5] = generateDomain(triangle2.points[1].x, triangle2.points[2].x);

    std::cout << "Are they colliding??\n";
    double x;
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 6; j++) {
            //znajdujemy punkt przeci�cia si� prostych z obu tr�jk�t�w, czyli rozwi�zujemy r�wnanie przyr�wnuj�ce obie te proste do siebie
            x = (equations[j].second - equations[i].second) / (equations[i].first - equations[j].first);
            // je�li rozwi�zanie si� mie�ci w dziedzinie, czyli proste si� w niej przecinaj� to tr�jk�ty si� przecinaj� r�wnie�
            if (x >= domains[j].first && x <= domains[j].second) {
                std::cout << "YES";
                return true;
            }
        }
    }
    std::cout << "NO";
    return false;
}