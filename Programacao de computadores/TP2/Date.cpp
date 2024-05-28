#include <iostream>
#include "Stock.h"
#include "Text.h"
#include "Date.h"
using namespace std;

istream& operator>>(istream& is, Data& d) { // Fun��o que faz o tipo data ser lido como tipo b�sico
 
    is >> d.dia;
    is.ignore();
    is >> d.mes;
    is.ignore();
    is >> d.ano;

    return is;
};

ostream& operator<<(ostream& os, Data& d) { // Fun��o que faz o tipo data ser exibido como tipo b�sico

    os << d.dia << '/' << d.mes << '/' << d.ano;

    return os;
};
