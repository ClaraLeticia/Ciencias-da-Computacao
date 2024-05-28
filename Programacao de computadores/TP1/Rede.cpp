#include <iostream>
// Incluindo as bibliotecas necess�rias, que foram criadas no projeto
#include "Cores.h"
#include "Pacote.h"
using namespace std;

unsigned int rede; // Variavel global
	

void Transmitir(unsigned int passos, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oil) {
	// Fun��o que tem como objetivo empacotar as caracteristcas do caminh�o, atraves da fun��o empacotar da biblioteca "Pacote"
	rede = Empacotar(passos, cor, pos, vel, oil);
	cout << rede << endl;

}

unsigned int Receber() {
	// Fun��o para decompor e exibir os dados usando as fun��es da biblioteca "Pacote"
	cout << "Recebendo dados..." << endl;

	// Passos
	Ajustar_cor(cor(rede), zero);
	cout << "Passos " ;
	Resetar_Cor();
	// Decompondo
	Ajustar_cor(zero, cor(rede));
	cout << " " << passos(rede) << " ";
	Resetar_Cor();

	//-----------------------

	//Posi��o
	Ajustar_cor(cor(rede), zero);
	cout << " Pos " ;
	Resetar_Cor();
	// Decompondo
	Ajustar_cor(zero, cor(rede));
	cout << " " << pos(rede) << " ";
	Resetar_Cor();

	//----------------------

	//Velocidade
	Ajustar_cor(cor(rede), zero);
	cout << " Vel ";
	Resetar_Cor();
	// Decompondo
	Ajustar_cor(zero, cor(rede));
	cout << " " << vel(rede) << " ";
	Resetar_Cor();

	//----------------------

	// Estado da pista
	Ajustar_cor(cor(rede), zero);
	cout << " Oil ";
	Resetar_Cor();
	// Decompondo
	Ajustar_cor(zero, cor(rede));
	// Decompor a fun��o oil, resulta em 0 ou 1, realizando um if para transformar em texto
	if (oil(rede) == 1) {
		cout << " True";
	}
	else {
		cout << " False";
	}
	cout << " " << endl;
	Resetar_Cor();
	
	return rede;
}

unsigned int processar(unsigned int rede) {
	// A fun��o para calcular e retornar a pr�xima posi��o do caminh�o

	unsigned int pos_atual = pos(rede);
	unsigned int vel_atual = vel(rede);
	unsigned int oil_atual = oil(rede);
	unsigned int nova_pos = pos_atual + vel_atual - oil_atual;

	return nova_pos;
}

