#include <iostream>
#include "Stock.h"
#include "Text.h"
#include "Date.h"
using namespace std;

istream& operator>>(istream& is, Data& d) { // Função que faz o tipo data ser lido como tipo básico
 
    is >> d.dia;
    is.ignore();
    is >> d.mes;
    is.ignore();
    is >> d.ano;

    return is;
};

ostream& operator<<(ostream& os, Data& d) { // Função que faz o tipo data ser exibido como tipo básico

    os << d.dia << '/' << d.mes << '/' << d.ano;

    return os;
};
