#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Stock.h"
#include "Cores.h"
using namespace std;

void lines(char ch, int tam, int cor_texto, int cor_fundo) { // Função para gerar linhas
	cout << "\033[0;" << cor_texto << ";" << cor_fundo << "m";
	for (int i = 0; i < tam; i++) {
		cout << ch;
	}
	cout << "\033[m";
	cout << '\n';
}

void alinhamento_texto(const char ch[], int cor_t, int cor_f, int espaco) { // Função para alinhamnento do texto à direita
	cout << right; cout.width(espaco);
	Ajustar_cor(ch , cor_t, cor_f);
}

void alinhamento_texto_int(int i, int espaco, int cor_texto, int cor_fundo) { // Função para alinhamnento de inteiro
	cout << "\033[" << cor_texto << ";" << cor_fundo << "m";
	cout << right;
	cout.width(espaco);
	cout << i;
	cout << "\033[m";
}

void alinhamento_texto_float(float f, int espaco, int cor_texto, int cor_fundo) { // Função para alinhamnento de float 
	cout << "\033[" << cor_texto << ";" << cor_fundo << "m";
	cout << right; 
	cout.width(espaco); 
	cout << f;
	cout << "\033[m";
}

void espacos_laterais(const char ch[], int cor_t, int cor_f, int espaco) { // Função para gerar espaços em brancos com o intuito de centralizar o texto
	int espacos = (espaco - strlen(ch)) / 2;

	for (int i = 0; i < espacos; ++i) {
		Ajustar_cor(" ", cor_t, cor_f);
	}
}

void alinhamento_central(const char ch[], int cor_t, int cor_f, int espaco) { // Função para alinhar o texto, usando o alinhamento central
	espacos_laterais(ch, cor_f, cor_f, espaco);

	Ajustar_cor(ch, cor_t, cor_f);

	espacos_laterais(ch, cor_f, cor_f, espaco);


}

void maiusculo(empresa& e ){ // Função para deixar as letras maiusculas

	char upper[6];

	for (int i = 0; i < 5; i++) {
		upper[i] = toupper(e.ticker[i]);
	}

	upper[5] = '\0';
	
	// A função recebe o endereço da empresa para conseguir copiar a palavra já em maiusculo
	strcpy(e.ticker, upper);

	cout << upper;
}
