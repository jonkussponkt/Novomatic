#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <utility>
#include "zad1.h"
#include "zad3.h"

struct Point2 {
    float x;
    float y;
    Point2() { x = 0; y = 0; }
    Point2(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

Point2 rectanglePos[4] = {
    Point2(-0.4, 0.8),
    Point2(-0.4, 0.6),
    Point2(0.8, 0.6),
    Point2(0.8, 0.8)
};

float colors_red[]{
    1.0, 0.0, 0.0,
    1.0, 0.75, 0.8,
};

float colors_green[]{
    0.0, 1.0, 0.0,
    0.75, 1.0, 0.8
};

// generujemy równanie prostej przechodz¹cej przez dwa punkty i zwracamy jako parê wsp. a i b
std::pair<float, float> generateEquation(float x1, float y1, float x2, float y2) {
    std::pair<float, float> equation;
    equation.first = (y1 - y2) / (x1 - x2);
    equation.second = y1 - x1 * equation.first;
    return equation;
}

bool collide() {
    float a, b, tempX, tempY;
    std::pair<float, float>functions[4];
    //wyznaczamy równania prostych przechodz¹cych przez wierzcho³ki prostok¹ta i zawieraj¹cych jego boki
    for (int i = 0; i < 3; i++) {
        functions[i] = generateEquation(rectanglePos[i].x, rectanglePos[i].y, rectanglePos[i+1].x, rectanglePos[i+1].y);
    }
    functions[3] = generateEquation(rectanglePos[3].x, rectanglePos[3].y, rectanglePos[0].x, rectanglePos[0].y);
    const double step = 0.05;
    // sprawdzamy czy miejsce przeciêcia wg odleg³oœci euklidesowej znajduje siê w œrodku ko³a, jeœli tak to zwróæ true
    // sprawdzamy wszystkie wspó³rzêdne x na ka¿dym boku prostok¹ta z krokiem w zmiennej "step"
    for (int i = 0; i < 3; i++) {
        tempX = rectanglePos[i].x;
        while (tempX < rectanglePos[i + 1].x) {
            tempY = tempX*functions[i].first + functions[i].second;
            if(sqrt(pow(tempX, 2) + pow(tempY, 2)) <= 0.5)
                return true;
            tempX+=step;
        }
    }
    tempX = rectanglePos[3].x;
    while (tempX < rectanglePos[0].x) {
        tempY = tempX * functions[3].first + functions[3].second;
        if (sqrt(pow(tempX, 2) + pow(tempY, 2)) <= 0.5)
            return true;
        tempX += step;
    }
    return false;
}

void display() { //funkcja rysuj¹ca

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);  // zaczynamy tworzyæ wype³niony poligon
    if (collide()) { //jeœli figury nachodz¹ na siebie to ustawiamy kolor zielony
        glColor3f(colors_green[0], colors_green[1], colors_green[2]);
    }   
    else {  // jeœli nie nachodz¹ to czerwony
        glColor3f(colors_red[0], colors_red[1], colors_red[2]); 
    }
    
    float radians;
    for (int i = 0; i < 360; i += 10) {   // rysujemy ko³o o promieniu 0.5
        radians = i * 3.14 / 180;
        glVertex2f(0.5*cos(radians), 0.5*sin(radians));
    }
    glEnd();
    glBegin(GL_QUADS);   //rysowanie czworok¹ta
    if (collide()) { //jeœli figury nachodz¹ na siebie to ustawiamy kolor zielony
        glColor3f(colors_green[3], colors_green[4], colors_green[5]);
    }
    else {    //jeœli nie nachodz¹ to czerwony
        glColor3f(colors_red[3], colors_red[4], colors_red[5]); 
    }
    
    for (int i = 0; i < 4; i++) {
        glVertex2f(rectanglePos[i].x, rectanglePos[i].y);
    }
    glEnd();
    glFlush();
}


void keys(int key, int x, int y) {
    float angle = 30*3.14/180; //30 stopni zamieniamy na radiany
    float tempX;
    // wyznaczamy wspó³rzêdne œrodka prostok¹ta, punkt wokó³ którego obracamy figurê
    float midX = (rectanglePos[0].x + rectanglePos[2].x) / 2;
    float midY = (rectanglePos[0].y + rectanglePos[2].y) / 2;
    switch (key) {
        case GLUT_KEY_LEFT:
            //translacja o wektor -x, -y tak aby œrodek prostok¹ta znalaz³ siê w punkcie 0,0
            for (int i = 0; i < 4; i++) {
                rectanglePos[i].x = rectanglePos[i].x - midX;
                rectanglePos[i].y = rectanglePos[i].y - midY;
                // obrót i powrót do dawnej pozycji
                tempX = rectanglePos[i].x;
                rectanglePos[i].x = midX + rectanglePos[i].x * cos(angle) - rectanglePos[i].y * sin(angle);
                rectanglePos[i].y = midY + tempX * sin(angle) + rectanglePos[i].y * cos(angle);
           
            }
            break;
        case GLUT_KEY_RIGHT:
            //translacja o wektor -x, -y tak aby œrodek prostok¹ta znalaz³ siê w punkcie 0,0
            for (int i = 0; i < 4; i++) {
                rectanglePos[i].x = rectanglePos[i].x - midX;
                rectanglePos[i].y = rectanglePos[i].y - midY;
                // obrót i powrót do dawnej pozycji
                tempX = rectanglePos[i].x;
                rectanglePos[i].x = midX + rectanglePos[i].x * cos(angle) - rectanglePos[i].y * sin(-angle);
                rectanglePos[i].y = midY + tempX * sin(-angle) + rectanglePos[i].y * cos(angle);
            }
            break;
    }
}

int main(int argc, char** argv) {

    // wywo³ania
    // ZADANIE 1
    
    /*
    int x1 = -7, x2 = -1;  //przedzia³y x-ów i y-ów do generacji trójk¹tów
    int y1 = 1, y2 = 6;
    std::pair<double, double> equations[6] = {
        std::make_pair(0, 0), std::make_pair(0, 0), std::make_pair(0, 0),
        std::make_pair(0, 0), std::make_pair(0, 0), std::make_pair(0, 0)
    };
    triangle triangle1, triangle2;
    while (equations[0] == equations[1] && equations[0] == equations[2]) {
        triangle1 = generateTriangle(-7, -1, 1, 6);
        equations[0] = generateEquation(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[1].x, triangle1.points[1].y);
        equations[1] = generateEquation(triangle1.points[0].x, triangle1.points[0].y, triangle1.points[2].x, triangle1.points[2].y);
        equations[2] = generateEquation(triangle1.points[1].x, triangle1.points[1].y, triangle1.points[2].x, triangle1.points[2].y);
    }
    while (equations[3] == equations[4] && equations[3] == equations[5]) {
        triangle2 = generateTriangle(-6, 0, 0, 4);
        equations[3] = generateEquation(triangle2.points[0].x, triangle2.points[0].y, triangle2.points[1].x, triangle2.points[1].y);
        equations[4] = generateEquation(triangle2.points[0].x, triangle2.points[0].y, triangle2.points[2].x, triangle2.points[2].y);
        equations[5] = generateEquation(triangle2.points[1].x, triangle2.points[1].y, triangle2.points[2].x, triangle2.points[2].y);
    }
    isColliding(triangle1, triangle2);
    */

    // ZADANIE 2

    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(250, 250); //pozycja okna
    glutInitWindowSize(500, 500);     //rozmair okna
    glutCreateWindow("Zadanie 2");    //nazwa okna

    glutSpecialFunc(keys);    //funkcja do obs³ugi klawiszy
    glutDisplayFunc(display); //funkcja do rysowania

    glutMainLoop();  

    

    //// ZADANIE 3

    /*
    std::cout << "\"" + eliminateWhitespaces("			przykladowy  string		") + "\"" << std::endl;
    std::cout << "\"" + eliminateWhitespaces("      str") + "\"" << std::endl;
    std::cout << "\"" + eliminateWhitespaces("") + "\"" << std::endl;
    std::cout << "\"" + eliminateWhitespaces("st    ") + "\"" << std::endl;
    */

    return 0;
}