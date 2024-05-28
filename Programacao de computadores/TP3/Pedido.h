#pragma once
struct pedido
{
	char opcao[24];
	int qtd_pedido;
	float preco_final;
	float preco_unitario;
	
	
};

struct Produto {
	char nome[24];
	float preco;
	unsigned int qtd;
};

struct leitura_arq {
	unsigned int qtd_pedidos;
	unsigned int qtd_produtos;
	unsigned int capacidade;
	Produto* produtos;
};



void menu(Produto p[], int tam);
char ler_opcao(char);
int add_pedido(char, Produto[], pedido[], int, leitura_arq*);
void mostrar_carrinho(int, pedido[]);
int ler_qtd_opcao(pedido, leitura_arq*, int);
void pagamento(int, pedido[], leitura_arq*, int);
void adicionando_produto(leitura_arq*);
void expandir_vetor(leitura_arq*, Produto );
void excluir_vetor(leitura_arq*);
void listar_produto(leitura_arq*);
void confirmar_pedido(pedido[], int, int, float, float, int, leitura_arq* arq, int);