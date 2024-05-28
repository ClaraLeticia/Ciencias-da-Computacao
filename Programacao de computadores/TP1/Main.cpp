// Incluindo todas as bibliotecas que serão utilizadas
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
	// - Posição
	// - Velocidade
	// - Cores
	// - Estado da pista
	unsigned int posA = 0, posB = 0, velA = 0, velB = 0, pistaA = 0, pistaB = 0, nova_posA = 0, nova_posB = 0, rede_A = 0, rede_B = 0, corA = verde , corB = azul;
	// --------------------

	
	int passo = 0;
	do
	{
		// Declarando que a posição atual vai ser igual a nova posição, como na primeira vez que o loop rodar ambos vão ser zeros
		posA = nova_posA;
		posB = nova_posB;


		// ------------------
		// Limpa tela
		system("cls");
		// Desenha caminhões
		// Caminhão 1
		Desenhar(posA, corA);
		// Caminhão 2
		Desenhar(posB, corB);
		// ------------------ 
		

		// ------------------------
		// Atualiza velocidade
		// Caminhão 1
		velA = rand() % 10 + 1;
		// Caminhão 2
		velB = rand() % 10 + 1;
		// Atualiza estado da pista
		pistaA = rand() % 2;
		// Caminhão 2
		pistaB = rand() % 2;
		// ------------------------
			
		// ----------------------------------
		// Transmite, recebe e processa dados
		// Caminhão 1
		cout << "Transmitindo dados..." << endl;
		Ajustar_cor(zero, corA);
		Transmitir(passo, corA, posA, velA, pistaA); // Empacotando os dados e exibindo na tela o valor inteiro de 32 bits correspondente a rede
		Resetar_Cor();

		rede_A =  Receber();  // Decompondo os dados referentes a passo, posicao, velocidade e estado da pisra e exibindo na tela


		// Calcula Próxima posição
		cout << "Processando dados..." << endl;
		Ajustar_cor(corA, zero);
		nova_posA = processar(rede_A); // Calculando nova posição
		cout << "Próxima posição: " << nova_posA << endl << endl; // Exibindo
		Resetar_Cor();

		
		// ----------------------------------
		
		// Caminhão 2
		cout << "Transmitindo dados..." << endl;
		Ajustar_cor(zero, corB);
		Transmitir(passo, corB, posB, velB, pistaB); // Empacotando os dados e exibindo na tela o valor inteiro de 32 bits correspondente a rede
		Resetar_Cor();

		rede_B = Receber(); // Decompondo os dados referentes a passo, posicao, velocidade e estado da pisra e exibindo na tela


		// Calcula Próxima posição
		cout << "Processando dados..." << endl;
		Ajustar_cor(corB, zero);
		nova_posB = processar(rede_B); // Calculando nova posição
		cout << "Próxima posição: " << nova_posB << endl; // Exibindo
		Resetar_Cor();

		

		// -------------------------------
		// Aguarda pressionamento de tecla
		system("pause");
		// -------------------------------


		passo = passo + 1;
	}
	while (posA <=100 && posB <= 100);
	
	// Após a vitória de um dos caminhões

	// --------------------
	// Limpa tela
	system("cls");
	// Desenha caminhões 
	Desenhar(posA, corA);
	Desenhar(posB, corB);


	// Exibe resultados
	// --------------------
	// Passos
	Ajustar_cor(zero, cinza);
	cout << " Passos ";
	Resetar_Cor();
	cout << " " << passo << " " << endl << endl;
	 
	// Exibindo a Posição e Velocidade do Caminhão 1
	// Posição
	Ajustar_cor(zero, corA);
	cout << " Posição ";
	Resetar_Cor();

	Ajustar_cor(corA, zero);
	cout << " " << posA << " ";
	Resetar_Cor();

	// Velocidade média
	Ajustar_cor(zero, corA);
	cout << " Velocidade média ";
	Resetar_Cor();
	Ajustar_cor(corA, zero);
	float vmA = float(posA) / passo; // Fórmula usando o type cast para realizar a conversão
	// Ajustando o cout para exibir apenas duas casas decimais após a virgula
	cout << fixed;
	cout.precision(2);
	cout << " " << vmA << " " << endl;
	Resetar_Cor();

	cout << "\n";

	// Exibindo a Posição e Velocidade do Caminhão 1
	// Posição
	Ajustar_cor(zero, corB);
	cout << " Posição ";
	Resetar_Cor();

	Ajustar_cor(corB, zero);
	cout << " " << posB << " ";
	Resetar_Cor();

	// Velocidade média
	Ajustar_cor(zero, corB);
	cout << " Velocidade média ";
	Resetar_Cor();

	Ajustar_cor(corB, zero);
	float vmB = float(posB) / passo; // Fórmula usando o type cast para realizar a conversão
	// Ajustando o cout para exibir apenas duas casas decimais após a virgula
	cout << fixed;
	cout.precision(2);
	cout << " " << vmB << " " << endl;
	Resetar_Cor();
	
}

void Desenhar(unsigned int pos, unsigned int cor) {
	// Usando os caracteres especiais para desenhar o caminhão
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
	// Digita os espaços em branco que faz o caminhão avançar
	while (qtd-- > 0) {
		cout << " ";
	}
}
