#include "zad3.h"

std::string eliminateWhitespaces(std::string&& str) {
    if (str.empty())
        return str;
    int start, fin;
    int i = 0;
    while (isblank(str[i])) {   // szukamy indeksu pierwszego "nie-bia³ego" znaku od lewej
        i++;
    }
    start = i;
    i = str.length() - 1;
    while (isblank(str[i])) { // szukamy indeksu pierwszego "nie-bia³ego" znaku od lewej
        i--;
    }
    fin = i;
    return str.substr(start, fin - start + 1);
}