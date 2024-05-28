#include <iostream>
#include <fstream>
#include "Text.h"
#include "Pedido.h"
#include "Arquivo.h"
#include  "Produto.h"
using namespace std;

void controle_estoque() {

	leitura_arq arq_estoque;
	abrir_estoque(&arq_estoque);
	char opcao = ' '; // Inicializa��o necess�ria para nao ocorrer o erro C4700
	system("cls");

	do {
		cout << "Painel de Controle\n";
		lines('=', 20);
		cout << "(A)dicionar\n(E)xcluir\n(L)istar\n(S)air\n";
		lines('=', 20);
		cout << "Opc�o: [ ]\b\b";
		opcao = ler_opcao(opcao);
		system("cls");

		switch (opcao) {
		case 'A': adicionando_produto(&arq_estoque);
			system("cls");
			cout << "Produto adicionado!!\n";
			system("pause");
			break;

		case 'E': excluir_vetor(&arq_estoque);
			system("cls");
			cout << "Produto exclu�do!!\n";
			system("pause");
			break;

		case 'L': listar_produto(&arq_estoque);
			system("pause");
		}

		system("cls");
				
		
	} while (opcao != 'S');

	escrever_arquivo(&arq_estoque); // Escrevendo no arquivo bin�rio

	delete[] arq_estoque.produtos; 
}