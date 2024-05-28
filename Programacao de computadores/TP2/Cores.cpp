#include <iostream>
using namespace std;

void Ajustar_cor(const char texto[], int cor_texto, int cor_fundo) {
	cout << "\033["<<cor_texto<<";"<<cor_fundo<<"m"; // Ajustando a cor
	
	cout << texto;

	cout << "\033[m";
}



