#pragma once

struct Data
{
	int dia, mes, ano;
};


struct transacao
{
	Data data;
	int qtd;
	float preco;
};

struct empresa
{
	char nome[20];
	char ticker[6];
	int qtd_trans;
	transacao* ptr_trans;
};

void ler_empresas(int, empresa*);
void ler_transacao(int, empresa* );
float resumo_carteira(empresa[], int);
void rentabilidade_carteira(float, float , float);
int linearizacao(float, float);