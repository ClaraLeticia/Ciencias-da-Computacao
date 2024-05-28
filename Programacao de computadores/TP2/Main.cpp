#include <iostream>
#include "Stock.h"
#include "Text.h"
#include "Cores.h"
#include "Date.h"
using namespace std;


int main() {

	Ajustar_cor(" Carteira de A��es ", branco, ciano); // Fazendo com que a frase " Carteira de A��es " saia colorida
	cout << "\n\n";
	Ajustar_cor("Quantidade de empresas [ ]\b\b", ciano_texto, preto); // Fazendo com que a frase " Carteira de A��es " saia colorida
	
	// Lendo a quantidade a��es (empresas) foram compradas
	int n;
	cin >> n;
	lines('-', 27, azul, preto); // Escrevendo linhas

	// Criando um vetor dinamico de empresas
	empresa* empresas = new empresa[n];

	ler_empresas(n, empresas); // Fun��o para ler empresas

	system("cls");

	//------------------------------------ Trans���es realizadas ---------------------------//

	Ajustar_cor(" Transa��es realizadas ", branco, ciano);
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		(empresas + i)->ptr_trans = new transacao[(empresas + i)->qtd_trans]; // Criando um vetor de transa��es para cada empresa
	}


	// Imprimindo a tela de leitura das transa��es e realizando a leitura
	for (int i = 0; i < n; i++) {
		Ajustar_cor((empresas + i)->nome, azul, preto);
		Ajustar_cor(" - ", azul, preto);
		Ajustar_cor((empresas + i)->ticker, azul, preto);
		cout << "\n\n";
		ler_transacao((empresas + i)->qtd_trans, (empresas + i)); // Passando a quantidade de transa��es da empresa[i], juntamente com o endere�o da empresa
	}

	system("cls");


	alinhamento_central("Resumo da carteira", branco, ciano, 103); // Usando a fun��o de alinhamento central para criar o titulo da tela

	cout << endl;

	lines('-', 102, ciano_texto, preto);

	// Criando os titulos para a tabela do resumo da carteira
	alinhamento_texto(" Empresa ", branco, ciano, 0);
	alinhamento_texto(" Ticker ", branco, ciano, 15);
	alinhamento_texto(" Qtd. ", branco, ciano, 16);
	alinhamento_texto(" Pre�o m�dio ", branco, ciano, 16);
	alinhamento_texto(" Investido ", branco, ciano, 16);

	cout << endl;
	// Chamando a fun��o resumo_carteira para exibir o resumo, e atribuindo o valor investido a uma variavel
	float valor_investido = resumo_carteira(empresas, n); 

	lines('-', 102, ciano_texto, preto);
	
	// Exibindo o rodap� da tabela com o valor investido total
	Ajustar_cor("Investido", branco, ciano);
	//espacos_laterais("Investido", ciano_texto, ciano, 181); // Criando o espa�o entre a palavra "Investido" e o valor, para que o valor seja alinhado a esquerda
	alinhamento_texto_float(valor_investido, 93, branco, ciano);

	cout << "\n";
	system("pause");
	system("cls");

	//------------------------------------- Rentabilidade da Carteira ---------------------------------------//

	float aporte, rendimento;

	Ajustar_cor("Aporte anual R$[    ]\b\b\b\b\b", ciano_texto, preto);
	cin >> aporte;
	Ajustar_cor("Rendimento anual estimado [  ]%\b\b\b\b", ciano_texto, preto);
	cin >> rendimento;
	
	cout << endl;



	alinhamento_central(" Rentabilidade da carteira", branco, ciano, 87);
	cout << endl;

	lines('-', 86, ciano_texto, preto);
	// Criando os titulos para a tabela do resumo da carteira
	alinhamento_texto(" Ano ", branco, ciano, 0);
	alinhamento_texto(" Investido ", branco, ciano, 0);
	alinhamento_texto(" Rendimento ", branco, ciano, 0);
	alinhamento_texto(" Acumulado ", branco, ciano, 0);
	alinhamento_central(" Gr�fico ", branco, ciano, 47);
	
	
	cout << endl;

	rentabilidade_carteira(valor_investido, aporte, rendimento);

	lines('-', 86, ciano_texto, preto);
	


	// Deletando um vetor dinamico de empresas 
	for (int i = 0; i < n; i++) {
		delete[](empresas + i)->ptr_trans;
	}

	delete[] empresas;



}

