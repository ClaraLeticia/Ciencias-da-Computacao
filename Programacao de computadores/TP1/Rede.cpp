#include <iostream>
// Incluindo as bibliotecas necessárias, que foram criadas no projeto
#include "Cores.h"
#include "Pacote.h"
using namespace std;

unsigned int rede; // Variavel global
	

void Transmitir(unsigned int passos, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oil) {
	// Função que tem como objetivo empacotar as caracteristcas do caminhão, atraves da função empacotar da biblioteca "Pacote"
	rede = Empacotar(passos, cor, pos, vel, oil);
	cout << rede << endl;

}

unsigned int Receber() {
	// Função para decompor e exibir os dados usando as funções da biblioteca "Pacote"
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

	//Posição
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
	// Decompor a função oil, resulta em 0 ou 1, realizando um if para transformar em texto
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
	// A função para calcular e retornar a próxima posição do caminhão

	unsigned int pos_atual = pos(rede);
	unsigned int vel_atual = vel(rede);
	unsigned int oil_atual = oil(rede);
	unsigned int nova_pos = pos_atual + vel_atual - oil_atual;

	return nova_pos;
}

