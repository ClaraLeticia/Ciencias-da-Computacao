#include <iostream>
using namespace std;

void Ajustar_cor(int cor_texto, int cor_fundo) {
	cout << "\033[48;5;" << cor_fundo << "m"; // C�digo para alterar a cor do fundo do texto
	cout<< "\033[38;5;" << cor_texto << "m"; // C�digo para alterar a cor do texto
}


void Resetar_Cor() {
	cout << "\033[m"; // C�digo para a cor do terminal voltar ao normal
}
