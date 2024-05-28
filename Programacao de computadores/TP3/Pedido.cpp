#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Pedido.h"
#include "Text.h"
#include "Arquivo.h"
#include  "Produto.h"
using namespace std;

void menu(Produto p[], int tam) { // Exibe o menu de opções 
	for (int i = 0, j = 65; i < tam; i++, j++) { // De acordo 
		cout << "(" << char(j)  <<")" << " " << p[i].nome << endl;
	}
	cout << "(S) Sair" << endl;
}


char ler_opcao(char opcao) {
	
	cin >> opcao;
	opcao = toupper(opcao); // Lendo a opção escolhida e já transformando para maiuscula 

	return opcao;
}

int add_pedido( char opcao, Produto estoque[], pedido pedido_cliente[], int qtd_pedidos, leitura_arq* arq) { 
	if (opcao == 'S') {
		return qtd_pedidos; // Caso a opção escolhida seja S (sair) a função só irá retornar a quantidade de pedidos
	}
	else { // Se ele escolher uma opção do cardapio
		pedido novo_pedido;
	
		int index = int(opcao) - 65; // Fazendo o mapeamento de qual opção foi escolhida
	
		strcpy(novo_pedido.opcao, estoque[index].nome); // Copiando o nome da opção mapeada para o pedido do cliente 
		novo_pedido.preco_unitario = estoque[index].preco; // Adicionando o preço ao pedido
		system("cls");
		novo_pedido.qtd_pedido = ler_qtd_opcao(novo_pedido, arq, index); // Fazer a leitura da quantidade
	
		novo_pedido.preco_final = novo_pedido.qtd_pedido * estoque[index].preco; // Fazendo calculo do pedido final
	

		pedido_cliente[qtd_pedidos] = novo_pedido; // Atualiza o vetor de pedidos, colocando o novo pedido escolhido na ultima posicao
		qtd_pedidos++; // Atualiza a quantidade de pedidos
		
		return qtd_pedidos; 
	}

	
}

int ler_qtd_opcao(pedido pedido_cliente, leitura_arq* arq, int index) {
	cout << "Pedido\n"; 
	lines('=', 5);
	cout << pedido_cliente.opcao << endl;
	cout << "R$" << pedido_cliente.preco_unitario << endl;
	lines('=', 5);
	
	cout << "Quantidade: [ ]\b\b"; // Lendo a quantidade do produto escolhido

	int qtd;
	cin >> qtd;

	if (qtd > arq->produtos[index].qtd) { // Verificando se a quantidade escolhida esta disponivel 
		cout << "Apenas " << arq->produtos[index].qtd<< " disponíveis.\n";
		cout << "Quantidade: [ ]\b\b";
		cin >> qtd;
	}

	arq->produtos[index].qtd -= qtd;
	return qtd;

}

void mostrar_carrinho(int qtd_pedidos, pedido pedido_cliente[]) { // Função para mostrar quais pedidos já foram escolhidos
	if (qtd_pedidos == 0) {
		return; // Caso o cliente não tenha pedido nada ainda, a função irá parar e não fará nada
	}
	else { // Caso tenha pelo menos um pedido será exibido as informações do pedido
		for (int i = 0; i < qtd_pedidos; i++) {
			cout << fixed; cout.precision(2);
			cout << pedido_cliente[i].qtd_pedido << " x " << pedido_cliente[i].opcao << " de R$" <<
				pedido_cliente[i].preco_unitario << " = R$" << pedido_cliente[i].preco_final << endl;
		
;
		}
		lines('=', 10);
	}
}

void pagamento(int qtd_pedido, pedido pedido_cliente[], leitura_arq* arq, int qtd_pedido_total) {

	if (qtd_pedido == 0) {
		cout << "Volte sempre!\n"; // Caso ele não tenha feito nenhum pedido
	}
	else {
		float total = 0; float taxa_entrega = 6.0; char opcao_pag = ' '; 
		cout << "RapZinho\n";
		lines('=', 10);

		// EXIBINDO O CARRINHO // 

		for (int i = 0; i < qtd_pedido; i++) {
			cout << fixed; cout.precision(2);
			cout << pedido_cliente[i].qtd_pedido << " x " << pedido_cliente[i].opcao << " de R$" <<
				pedido_cliente[i].preco_unitario << " = R$" << pedido_cliente[i].preco_final << endl;
			total += pedido_cliente[i].preco_final; // Somando o preço das opções
		}
		cout << fixed; cout.precision(2);
		cout << "Taxa de entrega = R$" << taxa_entrega << endl; // Exibindo taxa de entrega
		lines('=', 10);
		// Somando a taxa de entrega e mostrando o valor total do pedido
		total += taxa_entrega; 
		cout << "Total = R$" << total << endl << endl;
		// Verificando a forma de pagamento
		cout << "[P] Pix\n[C] Cartão\n\nPagamento: [ ]\b\b";
		opcao_pag = ler_opcao(opcao_pag);

		system("cls");

		if (opcao_pag == 'P') {
			cout << "RapZinho\n";
			lines('=', 10);
			// EXIBINDO O CARRINHO // 


			mostrar_carrinho(qtd_pedido, pedido_cliente);
			cout << fixed; cout.precision(2);
			float desconto = total * 0.1; ;// Calculando o desconto
			// Exibindo
			cout << "Desconto de 10% = R$" << desconto << endl;
			cout << "Taxa de entrega = R$" << taxa_entrega << endl;
			lines('=', 10);
			// Descontando
			total -= desconto;
			cout << "Total = R$" << total << endl << endl;
			// Confirmando pedido
			confirmar_pedido(pedido_cliente, taxa_entrega, 10, desconto, total, qtd_pedido, arq, qtd_pedido_total); // Criando o recibo para a opcao de pix
		}
		else {
			// ------------ Para opção de Cartão ---------------//
			cout << "RapZinho\n";
			lines('=', 10);
			mostrar_carrinho(qtd_pedido, pedido_cliente);
			cout << fixed; cout.precision(2);


			float desconto = total * 0.05;
			cout << "Desconto de 5% = R$" << desconto << endl;
			cout << "Taxa de entrega = R$" << taxa_entrega << endl;
			lines('=', 10);
			total -= desconto;
			cout << "Total = R$" << total << endl << endl;
			confirmar_pedido(pedido_cliente, taxa_entrega, 5, desconto, total, qtd_pedido, arq, qtd_pedido_total); // Criando o recibo para a opcao de cartao
			
		}
	}


	
}

void confirmar_pedido(pedido pedido_cliente[], int taxa_entrega, int opcao_desconto, float desconto, float total, int qtd_pedido, leitura_arq* arq, int qtd_pedido_total) {
	char opcao = ' ';
	cout << "Confirmar pedido(S/N): [ ]\b\b";
	opcao = ler_opcao(opcao);
	if (opcao == 'S') { // Caso confirme
		arq->qtd_pedidos++; // Atualizando a quantidade de pedidos feitos no aplicativo 
		criando_recibo(pedido_cliente, taxa_entrega, opcao_desconto, desconto, total, qtd_pedido, qtd_pedido_total); // Criando o arquivo txt
		escrever_arquivo(arq); // Escrevendo no arquivo binário

	} else if(opcao == 'N') {
		return; // Volta para a tela inicial sem gravar nenhum arquivo
	}
}



