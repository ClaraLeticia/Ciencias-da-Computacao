#include <iostream>
#include <cstring>
#include "Rapizinho.h"
#include "Estoque.h"

using namespace std;

int main(int argc, char** argv) {

	if (argc == 1 ) // Caso entre apenas com o nome do aplicativo
	{
		Rapizinho_cliente(); // Tela para o cliente fazer o pedido
	}
	else if (argc == 2 && strcmp(argv[1], "-c") == 0) { // Caso entre com o comando -c irá para a tela de controle de estoque
		controle_estoque();
	}

	return 0;
}