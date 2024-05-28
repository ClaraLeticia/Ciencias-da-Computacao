#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Pedido.h"
#include "Text.h"
#include "Arquivo.h"
using namespace std;

void adicionando_produto(leitura_arq* arq) {

	// Lendo o novo produto
	Produto p;
	cout << "Adicionar\n";
	lines('=', 15);
	cout << "Produto: ";
	cin >> p.nome;
	cout << "Pre�o: ";
	cin >> p.preco;
	cout << "Quantidade: ";
	cin >> p.qtd;

	// Verificando se o produto existe

	for (int i = 0; i < arq->qtd_produtos; i++) {

		if (strcmp(p.nome, arq->produtos[i].nome) == 0) {
			// Apenas atualizando o pre�o e acrescentando a quantidade
			arq->produtos[i].preco = p.preco;
			arq->produtos[i].qtd += p.qtd;
			return; // Encerra a fun��o
		}
	}

	// Caso n�o seja a atualiza��o de um produto ele estar� adicionando

	if (arq->capacidade == arq->qtd_produtos) { // Caso a capacidade seja igual a quantidade de produtos
		expandir_vetor(arq, p); // Ser� necess�rio expandir o vetor

	}
	else {
		arq->produtos[arq->qtd_produtos] = p; // Como a inicializa��o � do 0, o novo produto sera alocado no index da qtd_produto
		arq->qtd_produtos++; // Adicionando um valor a mais em quantidade produto, que diz respeito ao novo produto criado

	}

}

void excluir_vetor(leitura_arq* arquivo) {
	cout << "Excluir\n";
	lines('-', 7);
	for (int i = 0; i < arquivo->qtd_produtos; i++) {
		cout << i + 1 << ") " << arquivo->produtos[i].nome << endl;
	}
	// Verificando qual produto deseja excluir
	cout << "\nProduto: [ ]\b\b";
	int p;
	cin >> p;

	// Confirmando exclus�o
	cout << "Deseja excluir " << arquivo->produtos[p - 1].nome << " (S/N)? ";
	char resposta;
	cin >> resposta;
	resposta = toupper(resposta);
	if (resposta == 'N') {
		cout << "Exclus�o de pedido cancelada\n";
	}
	else { // Caso confirme
		arquivo->produtos[p - 1] = arquivo->produtos[arquivo->qtd_produtos - 1]; // O produto escolhido para ser exclu�do � substituido pelo ultimo produto
		arquivo->produtos[arquivo->qtd_produtos - 1] = {}; // A ultima posi��o do vetor agora � vazia
		arquivo->qtd_produtos = arquivo->qtd_produtos - 1; // Diminuindo a quantidade de produtos
	}
}

void listar_produto(leitura_arq* arq) { // Listando os produtos
	cout << "Listagem\n";
	lines('-', 7);

	for (int i = 0; i < arq->qtd_produtos; i++) {

		cout << arq->produtos[i].nome;
		cout << fixed; cout.precision(2);
		cout << "\t- R$" << arq->produtos[i].preco;
		cout << " - " << arq->produtos[i].qtd << " und.\n";
	}
}

void expandir_vetor(leitura_arq* arquivo, Produto novo_produto) {
	arquivo->capacidade = arquivo->capacidade + 1; // Aumentando a capacidade di vetor de armazenando dos produtos
	Produto* aux = new Produto[arquivo->capacidade]; // Criando um novo vetor com a capacidade nova

	for (int i = 0; i < arquivo->qtd_produtos; i++) {
		aux[i] = arquivo->produtos[i]; // Copiando os itens antigos
	}

	aux[arquivo->capacidade - 1] = novo_produto; // Armazenando o novo produto
	delete[] arquivo->produtos; // Liberando a memoria que existia em arquivo->produto
	arquivo->produtos = aux; // Alocando os itens existentes 
	arquivo->qtd_produtos = arquivo->qtd_produtos + 1; // Atualizando a quantidade de produtos

}
