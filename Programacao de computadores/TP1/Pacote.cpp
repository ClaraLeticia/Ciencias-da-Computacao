

unsigned int Empacotar(unsigned int passos, unsigned int cor, unsigned int pos, unsigned int vel, unsigned int oil) {

	unsigned int pack_passos = passos << 24; // Isso faz com que os bits de "passo" andem 24 casas para a frente. Ex: passos = 1, depois de pular as 24 casas assume o valor de 16.777.216 (1 * 2^24)
	unsigned int pack_cor = cor << 16; // Usando a mesma l�gica de "pack_passos" por�m s� andando 16 bits pois cor corresponde aos bits entre 16 e 23 
	unsigned int pack_pos = pos << 9; // Posi��o est� entre a 9� e 15� posi��o
	unsigned int pack_vel = vel << 5; // Velocidade est� 5� e 8� posi��o
	unsigned int pack_oil = oil << 4; // Est� na 4� posi��o
	// Os 4 bits restantes s�o preenchidos com 0

	unsigned int pack = pack_passos + pack_cor + pack_pos + pack_vel + pack_oil; // Somando os valores 
	return unsigned int(pack);
}

unsigned int passos(unsigned int rede) {
	unsigned int qtd_passos = rede >> 24;
	// Os bits que est�o entre 24� e 32�(8 bits correspondentes ao passo), 
	//descem as 24 casas, fazendo o processo inverso de "pack_passos", dessa forma, antes era 16.777.216, depois da opera��o fica = 1

	return unsigned int(qtd_passos);

}

unsigned int cor(unsigned int rede) {
	unsigned int bit_cor = rede >> 16; // Empurrando os 16 bits de maior import�ncia 16 casas abaixo

	unsigned char mask = 255; // 255 corresponde a 0000000011111111

	unsigned int n_cor = bit_cor & mask; // Como os bits correspondente a cor s�o os 8 menos importante, 
	//quando utilizar "mask" e o operador and, ele s� vai considerar os 8 valores correspondentes a cor

	return n_cor;
}

unsigned int pos(unsigned int rede) {
	// Utilizando a mesma l�gica da fun��o "cor"
	unsigned int bit_pos = rede >> 9;

	unsigned char mask = 127; // Corresponde a 0000000000000000111111111

	unsigned int n_pos = bit_pos & mask; // Apenas os 9 ser�o considerados

	return n_pos;
}

unsigned int vel(unsigned int rede) {
	// Utilizando a mesma l�gica da fun��o "cor"
	unsigned int bit_vel = rede >> 5;

	unsigned char mask = 15; // Corresponde a 0000000000000000000001111

	unsigned int n_vel = bit_vel & mask; // Apenas os 4 ser�o considerados

	return n_vel;
}

unsigned int oil(unsigned int rede) {
	// Utilizando a mesma l�gica da fun��o "cor"
	unsigned int bit_oil = rede >> 4;

	unsigned int n_oil = bit_oil & 1; // Como o �leo s� corresponde a um bit, apenas o valor 1 � necess�rio para fazer a compara��o


	return n_oil;
}