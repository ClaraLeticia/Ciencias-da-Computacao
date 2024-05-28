#include <iostream>
#include "Text.h"
#include "Pedido.h"
#include "Arquivo.h"
#include  "Produto.h"
using namespace std;

void Rapizinho_cliente() {
	leitura_arq arq_estoque; 
	abrir_estoque(&arq_estoque); // Fazendo a leitura do arquivo bin�rio com os produtos de estoque
	char pedido_novamente = ' '; // Impedindo o erro de n�o inicializa��o da variavel
	while (pedido_novamente != 'N') {
		int pedido_rapizinho = arq_estoque.qtd_pedidos; // Pedidos totais que foram feitos no rapizinho
		int qtd_produto = arq_estoque.qtd_produtos; 

		// Criando um vetor de pedidos, que corresponde aos pedidos dos clientes 
		int qtd_pedido = 0; // Quantidade de pedidos do cliente
		char opcao = ' '; // For�ando a entrada no la�o de repeti��o
		
		pedido* pedido_cliente = new pedido[arq_estoque.qtd_produtos]; // Criando um vetor de para armazenar o pedido dos clientes
		while (opcao != 'S')
		{
			// ----------------Menu-----------------//
			cout << "RapZinho\n"; 
			lines('=', 10);
			mostrar_carrinho(qtd_pedido, pedido_cliente); 
			menu(arq_estoque.produtos, arq_estoque.qtd_produtos); // Mostra menu de op��es
			lines('=', 10);
			cout << "Op��o: [ ]\b\b";
			opcao = ler_opcao(opcao); // Lendo a op��o do menu escolhida
			qtd_pedido = add_pedido(opcao, arq_estoque.produtos, pedido_cliente, qtd_pedido, &arq_estoque);// Adiciona pedido do cliente
			cout << endl;
			system("cls");
		}
		// Quando cliente n�o quiser fazer mais nenhum pedido
		pagamento(qtd_pedido, pedido_cliente, &arq_estoque, pedido_rapizinho);
		system("cls");
		delete[] pedido_cliente; // Limpando a "cesta" de pedidos do cliente
		qtd_pedido = 0; // Zerando a quantidade de pedidos
		opcao = ' ';
		cout << "Deseja fazer outro pedido: [ ]\b\b"; // Verificando se o cliente deseja fazer outro pedido
		pedido_novamente = ler_opcao(pedido_novamente);
	}
		
	delete[] arq_estoque.produtos;
}