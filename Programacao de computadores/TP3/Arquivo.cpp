#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include <iostream>
#include "Pedido.h"
#include "Arquivo.h"
using namespace std;



void criando_recibo(pedido pedido_cliente[], int taxa_entrega, int opcao_desconto, float desconto, float total, int qtd_pedido, int qtd_pedido_total) {
		
		char name[13] = "pedido_";
		name[7] = '0' + qtd_pedido_total; // Transforma o inteiro em um caractere e adiciona na posicao após o underline 
		// Solução só é válida para 10 pedidos
		strcat(name, ".txt"); // Concantena o nome do arquivo com a extenção .txt


		ofstream fout; // cria objeto para saída
		fout.open(name); // associa com arquivo

		// Escrevendo no arquivo
		fout.precision(2);
		fout << "Pedido #"<<qtd_pedido_total << endl; // #1 é variavel
		fout << "--------------------------------------------------"<<endl;
		// Escrevendo as opções escolhidas
		for (int i = 0; i < qtd_pedido; i++) {
			fout.setf(ios_base::fixed, ios_base::floatfield);
			fout << pedido_cliente[i].qtd_pedido << " x " << pedido_cliente[i].opcao << " de R$" <<
				pedido_cliente[i].preco_unitario << " = R$" << pedido_cliente[i].preco_final << endl;
		}

		// Escrevendo as informações sobre o pedido
		fout << "Desconto de "<< opcao_desconto <<"% = R$" << desconto << endl;
		fout << "Taxa de entrega = R$" << taxa_entrega << endl;
		fout << "--------------------------------------------------" << endl;
		fout << "Total = R$" << total << endl ;
		fout.close(); // Fechando a função fout
	
}

void abrir_estoque(leitura_arq* arq) {
	ifstream fin;
	

	fin.open("Estoque.bin", ios_base::in | ios_base::binary);
	// Lendo as informações
	if (fin.is_open()) {
		fin.read((char*)&arq->qtd_pedidos, sizeof(unsigned int)); 
		fin.read((char*)&arq->qtd_produtos, sizeof(unsigned int));
		arq->capacidade = arq->qtd_produtos; // Ao abrir o arquivo, a capacidade será igual a quantidade de produtos
		arq->produtos = new Produto[arq->capacidade];
		fin.read((char*) arq->produtos, arq->qtd_produtos * sizeof(Produto));
		fin.close();
	}
	else {// Caso nenhum arquivo exista ainda tudo será inicializado com zero
		cout << "Nenhum produto cadastrado!\nCadastre seu primeiro produto\n";
		arq->qtd_pedidos = 0;
		arq->qtd_produtos = 0;
		arq->capacidade = arq->qtd_produtos; // Ao abrir o arquivo, a capacidade será igual a quantidade de produtos
		arq->produtos = nullptr;
		system("pause");
	}


}

void escrever_arquivo(leitura_arq* arq) {
	ofstream fout;
	fout.open("Estoque.bin", ios_base::out | ios_base::binary);

	// Escrevendo a qtd de pedidos
	fout.write((char*) &arq->qtd_pedidos, sizeof(unsigned int));

	// Escrevendo a qtd de produtos
	fout.write((char*)&arq->qtd_produtos, sizeof(unsigned int));
	
	// Escrevendo os produtos
	fout.write((char*) arq->produtos, arq->qtd_produtos * sizeof(Produto));

	fout.close();
}
