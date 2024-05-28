#include <iostream>
#include <cmath>
#include "Stock.h"
#include "Text.h"
#include "Date.h"
#include "Cores.h"
using namespace std;


// Fun��o para ler as informa��es da empresa
void ler_empresas(int qtd, empresa* a) {
	for (int i = 0; i < qtd; i++) {
		Ajustar_cor("Empresa: ", ciano_texto, preto);
		cin.ignore();
		cin.getline((a + i)->nome, 80);
		Ajustar_cor("Ticker: ", ciano_texto, preto);
		cin >> (a + i)->ticker;
		maiusculo(a[i]);
		Ajustar_cor("Transa��es: ", ciano_texto, preto);
		cin >> (a + i)->qtd_trans;
		
		lines('-', 27, azul, preto);
		
	}
}

//Fun��o para ler as informa��es das transa��es de cada empresa
void ler_transacao(int qtd, empresa* a) {
	for (int i = 0; i < qtd; i++) { // Depende do numero de transa��es da empresa
		Ajustar_cor("Data: ", ciano_texto, preto);
		cin >> a->ptr_trans[i].data; 
		Ajustar_cor("Quantidade: ", ciano_texto, preto);
		cin >> a->ptr_trans[i].qtd;
		Ajustar_cor("Pre�o: ", ciano_texto, preto);
		cin >> a->ptr_trans[i].preco;
		cout << "\n";
	}
	
	
}

// Fun��o para mostrar o resumo da carteira
float resumo_carteira(empresa empresas[], int n) {
	float investido = 0;
	for (int i = 0; i < n; i++) { // La�o que corresponde a quantidade de empresas, para cada empresa existente ira calcular
		// o valor unit�rio de cada transacao e o pre�o total das transa��es
		int qtd_acoes = 0;
		float valor = 0;
		float preco_total = 0;

		for (int j = 0; j < (empresas + i)->qtd_trans; j++) {
			qtd_acoes += (empresas + i)->ptr_trans[j].qtd; // Calculando o total de a��es que foram compradas
			valor += (empresas + i)->ptr_trans[j].preco;
			preco_total += ((empresas + i)->ptr_trans[j].qtd * (empresas + i)->ptr_trans[j].preco); // Valor total das a���es * a quantidade que foi comprada

		}

		cout << left; cout.width(10); // Alinhando o texto a esquerda
		cout << (empresas + i)->nome;

		cout << fixed;
		cout.precision(2); // Fixando o cout para mostrar dois valores depois da virgula

		alinhamento_texto((empresas + i)->ticker, branco, preto, 15);
		alinhamento_texto_int(qtd_acoes, 20, branco, preto);
		alinhamento_texto_float(preco_total/qtd_acoes, 25, branco, preto);
		alinhamento_texto_float(preco_total, 27, branco, preto);

		investido += preco_total; // Retorno da fun��o
		cout << endl;
	}

	return investido;
}

// Fun��o para exibir os valores nos pr�ximos anos
void rentabilidade_carteira(float valor_investido, float aporte, float rendimento) {
	float investido[21] = { valor_investido }; // Inicializando o vetor com o valor inicial no ano 0
	float rendimento_anual[21] = { 0 }; // Como � o ano 0, n�o houve rendimento
	float acumulado[21] = { valor_investido }; // Inicializando o vetor com o valor inicial no ano 0

	for (int i = 1; i < 21; i++) { // Correspondente aos anos, come�a do 1, pois o ano zero � o anterior
		investido[i] = investido[i - 1] + aporte; // Calculando o investido: investido do ano anterior + aporte
		rendimento_anual[i] = (acumulado[i - 1] + aporte) * (rendimento / 100); // Calculando o rendimento de cada ano : 
		//(acumulado do ano anterior + aporte) * rendimento em porcentagem
		acumulado[i] = acumulado[i - 1] + aporte + rendimento_anual[i];// Calculando o acumulado: acumulado do ano anterior + rendimento daquele ano
	}
	int acumulado_linear[21]; // criando um vetor para armazenar os numeros normalizados

	for (int i = 0; i < 21; i++) {
		acumulado_linear[i] = linearizacao(acumulado[i], acumulado[20]); // Chamando a fun��o que faz a normaliza��o e adicionando o valor retornado ao vetor

	}
	
	
	// La�o para realizar a constru��o do gr�fico
	for (int i = 21; i > 0; i--) { // Corresponde as linhas do gr�fico, come�ando da linha 21 em ordem decrescente
		alinhamento_texto_int(21 - i, 3, branco, ciano); // Utilizandoa a mesma vari�vel, para exibir o valor em ordem crescente apenas subtrai de 21
		Ajustar_cor(" ", ciano_texto, ciano);
		alinhamento_texto_float(investido[21 - i], 11, branco, preto);
		cout << " ";
		alinhamento_texto_float(rendimento_anual[21 - i], 11, branco, preto);
		cout << " ";
		alinhamento_texto_float(acumulado[21 - i], 10, branco, preto);
		cout << "      "; // Para dar espa�o para escrita do gr�fico
		
		for (int j = 0; j < 21; j++) { // Corresponde as colunas do gr�fico
			// Como no exemplo dado a coluna mais a direita correspontida ao valor 21. Caso o valor na posi��o j ( j = 0, acumulado[j] = 1)
			//  seja maior que a linha(i = 21), vai ser escrito um quadrado na cor escolhida, caso contr�rio vai escrever um quadrado preto, como se 
			//  fosse um quadrado transparente. Ou seja de j = 0 ate j = 19, vai ser escrito quadrados transparentes, quando j = 20, acumulado[j] = 21
			//  que � igual a linha sendo assim ir� escrever um quadrado colorido
			if (acumulado_linear[j] >= i) { 
				cout << "\033[" << ciano_texto << ";" << preto << "m" << "\xDC" << " "; 
				cout << "\033[m";
			}
			else {
				cout << "\033[" << preto_texto << ";" << preto << "m" << "\xDC" << " ";
				cout << "\033[m";
			}
		}
		cout << endl;
	}


}

int linearizacao(float acumulado, float max_acumulado) {
	int result = ceil((acumulado / max_acumulado) * 21); // Arredonda para cima o resultado da divis�o do acumulado no ano especifico pelo acumulado 
	// m�ximo e em seguida multiplicando por 21, para facilitar 

	return result;
}