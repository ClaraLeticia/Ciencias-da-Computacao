// Incluindo todas as bibliotecas que ser�o utilizadas
#include <iostream>
#include "Cores.h"
#include "Pacote.h"
#include "Rede.h"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

void Desenhar(unsigned int, unsigned int);
void WhiteSpace(int);


int main()
{
	// Criando uma semente para gerar um numero pseudoaleatorio
	srand(unsigned(time(NULL)));

	// --------------------
	// Inicializa dados:
	// - Posi��o
	// - Velocidade
	// - Cores
	// - Estado da pista
	unsigned int posA = 0, posB = 0, velA = 0, velB = 0, pistaA = 0, pistaB = 0, nova_posA = 0, nova_posB = 0, rede_A = 0, rede_B = 0, corA = verde , corB = azul;
	// --------------------

	
	int passo = 0;
	do
	{
		// Declarando que a posi��o atual vai ser igual a nova posi��o, como na primeira vez que o loop rodar ambos v�o ser zeros
		posA = nova_posA;
		posB = nova_posB;


		// ------------------
		// Limpa tela
		system("cls");
		// Desenha caminh�es
		// Caminh�o 1
		Desenhar(posA, corA);
		// Caminh�o 2
		Desenhar(posB, corB);
		// ------------------ 
		

		// ------------------------
		// Atualiza velocidade
		// Caminh�o 1
		velA = rand() % 10 + 1;
		// Caminh�o 2
		velB = rand() % 10 + 1;
		// Atualiza estado da pista
		pistaA = rand() % 2;
		// Caminh�o 2
		pistaB = rand() % 2;
		// ------------------------
			
		// ----------------------------------
		// Transmite, recebe e processa dados
		// Caminh�o 1
		cout << "Transmitindo dados..." << endl;
		Ajustar_cor(zero, corA);
		Transmitir(passo, corA, posA, velA, pistaA); // Empacotando os dados e exibindo na tela o valor inteiro de 32 bits correspondente a rede
		Resetar_Cor();

		rede_A =  Receber();  // Decompondo os dados referentes a passo, posicao, velocidade e estado da pisra e exibindo na tela


		// Calcula Pr�xima posi��o
		cout << "Processando dados..." << endl;
		Ajustar_cor(corA, zero);
		nova_posA = processar(rede_A); // Calculando nova posi��o
		cout << "Pr�xima posi��o: " << nova_posA << endl << endl; // Exibindo
		Resetar_Cor();

		
		// ----------------------------------
		
		// Caminh�o 2
		cout << "Transmitindo dados..." << endl;
		Ajustar_cor(zero, corB);
		Transmitir(passo, corB, posB, velB, pistaB); // Empacotando os dados e exibindo na tela o valor inteiro de 32 bits correspondente a rede
		Resetar_Cor();

		rede_B = Receber(); // Decompondo os dados referentes a passo, posicao, velocidade e estado da pisra e exibindo na tela


		// Calcula Pr�xima posi��o
		cout << "Processando dados..." << endl;
		Ajustar_cor(corB, zero);
		nova_posB = processar(rede_B); // Calculando nova posi��o
		cout << "Pr�xima posi��o: " << nova_posB << endl; // Exibindo
		Resetar_Cor();

		

		// -------------------------------
		// Aguarda pressionamento de tecla
		system("pause");
		// -------------------------------


		passo = passo + 1;
	}
	while (posA <=100 && posB <= 100);
	
	// Ap�s a vit�ria de um dos caminh�es

	// --------------------
	// Limpa tela
	system("cls");
	// Desenha caminh�es 
	Desenhar(posA, corA);
	Desenhar(posB, corB);


	// Exibe resultados
	// --------------------
	// Passos
	Ajustar_cor(zero, cinza);
	cout << " Passos ";
	Resetar_Cor();
	cout << " " << passo << " " << endl << endl;
	 
	// Exibindo a Posi��o e Velocidade do Caminh�o 1
	// Posi��o
	Ajustar_cor(zero, corA);
	cout << " Posi��o ";
	Resetar_Cor();

	Ajustar_cor(corA, zero);
	cout << " " << posA << " ";
	Resetar_Cor();

	// Velocidade m�dia
	Ajustar_cor(zero, corA);
	cout << " Velocidade m�dia ";
	Resetar_Cor();
	Ajustar_cor(corA, zero);
	float vmA = float(posA) / passo; // F�rmula usando o type cast para realizar a convers�o
	// Ajustando o cout para exibir apenas duas casas decimais ap�s a virgula
	cout << fixed;
	cout.precision(2);
	cout << " " << vmA << " " << endl;
	Resetar_Cor();

	cout << "\n";

	// Exibindo a Posi��o e Velocidade do Caminh�o 1
	// Posi��o
	Ajustar_cor(zero, corB);
	cout << " Posi��o ";
	Resetar_Cor();

	Ajustar_cor(corB, zero);
	cout << " " << posB << " ";
	Resetar_Cor();

	// Velocidade m�dia
	Ajustar_cor(zero, corB);
	cout << " Velocidade m�dia ";
	Resetar_Cor();

	Ajustar_cor(corB, zero);
	float vmB = float(posB) / passo; // F�rmula usando o type cast para realizar a convers�o
	// Ajustando o cout para exibir apenas duas casas decimais ap�s a virgula
	cout << fixed;
	cout.precision(2);
	cout << " " << vmB << " " << endl;
	Resetar_Cor();
	
}

void Desenhar(unsigned int pos, unsigned int cor) {
	// Usando os caracteres especiais para desenhar o caminh�o
	cout << "\n\n";
	Ajustar_cor(cor, zero);
	WhiteSpace(pos);
	cout << "\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDC";
	cout << "\n";
	WhiteSpace(pos);
	cout << "\xDF\xDFOO\xDF\xDF\xDFO\xDF\n";
	cout << "----------------------------------------------------------------------------------------------------|------------\n";
	cout << "                                                                                                   100" << endl;
	Resetar_Cor();

}

void WhiteSpace(int qtd) { 
	// Digita os espa�os em branco que faz o caminh�o avan�ar
	while (qtd-- > 0) {
		cout << " ";
	}
}
