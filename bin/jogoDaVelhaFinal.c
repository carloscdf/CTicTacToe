#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Essa função valida o resultado de cada jogada e informa quando houver vitória de algum jogador ou empate
int validationResult(char board[3][3], int playerOne, int playerTwo) {
	char winner = ' ';
	int theBreak = 0, count = 0, boardFilled = 0;

	//Compara os valores de uma linha para verificar se são iguais
	for(int i=0; i<3; i++) {
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if(board[i][0] == playerOne || board[i][0] == playerTwo) {
				winner = board[i][0];
			}
		}
	}

	//Compara os valores de uma coluna para verificar se são iguais
	for(int i=0; i<3; i++) {
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			if(board[0][i] == playerOne || board[0][i] == playerTwo) {
				winner = board[0][i];
			}
		}
	}

	//Compara os valores da diagonal principal para verificar se são iguais
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if(board[0][0] == playerOne || board[0][0] == playerTwo) {
			winner = board[0][0];
		}
	}

	//Compara os valores da diagonal secundaria para verificar se são iguais
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if(board[0][2] == playerOne || board[0][2] == playerTwo) {
			winner = board[0][2];
		}
	}

	//Verifica se houve empate, se a tabela inteira foi preenchida e não houve vencedor
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[i][j] != ' ') {
				boardFilled++;
			}
		}
	}

	//Define o ganhador ou se houve um empate
	if(winner != ' ') {
		if(winner == playerOne) {
			printf("\nJOGADOR NUMERO 1 (%c), VOCE VENCEU!", winner);
			theBreak = 1;
		} else if(winner == playerTwo) {
			printf("\nJOGADOR NUMERO 2 (%c), VOCE VENCEU!", winner);
			theBreak = 1;
		}
	} else if(boardFilled == 9) {
		printf("\nJOGADORES, DEU VELHA!");
		theBreak = 1;
	}

	//Retorna um valor para encerrar o loop principal, fazendo com que a partida seja encerrada também
	return theBreak;
}

//Essa função imprime a tablea do jogo atual a cada jogada
void printBoard(char board[3][3]) {
	printf("\nO tabuleiro esta atualmente assim:\n");
	printf("\n   0    1    2\n");
	printf("  -------------\n");
	for(int i=0; i<3; i++) {
		printf("%d ", i);
		for(int j=0; j<3; j++) {
			printf("| %c ", board[i][j]);
		}
		printf("|");
		printf("\n  -------------\n");
	}
}

//Essa função permite a jogada do jogador 1
int thePlayerOne(char board[3][3], int playerOne, int validation) {
	int line = 0, column = 0;
	while(1) {
		printf("\nJOGADOR NUMERO 1, SUA VEZ!\n");
		printf("\nJogador numero 1, selecione a linha do tabuleiro (0-2): ");
		scanf("%d", &line);
		printf("Jogador numero 1, selecione a coluna do tabuleiro (0-2): ");
		scanf("%d", &column);
		if(line >= 0 && line <= 2 && column <= 2 && column >=0) {
			if(board[line][column] == ' ') {
				board[line][column] = playerOne;
				printBoard(board); //Imprime a tabela após jogada do jogador 1
				break;
			} else {
				validation = 0;
				printf("\nJogador numero 1, a celula em questao ja foi selecionada anteriormente, selecione uma celula nova!\n");
			}
		} else {
			printf("\nJogador numero 1, linha e coluna fora do limite permitido!\n");
		}
	}

	return validation;
}

//Essa função permite a jogada do jogador 2
int thePlayerTwo(char board[3][3], int playerTwo, int validation) {
	int line = 0, column = 0;
	while(1) {
		printf("\nJOGADOR NUMERO 2, SUA VEZ!\n");
		printf("\nJogador numero 2, selecione a linha do tabuleiro (0-2): ");
		scanf("%d", &line);
		printf("Jogador numero 2, selecione a coluna do tabuleiro (0-2): ");
		scanf("%d", &column);
		if(line >= 0 && line <= 2 && column >=0 && column <= 2) {
			if(board[line][column] == ' ') {
				board[line][column] = playerTwo;
				printBoard(board); //Imprime a tabela após jogada do jogador 2
				break;
			} else {
				printf("\nJogador numero 2, a celula em questao ja foi selecionada anteriormente, selecione uma celula nova!\n");
			}
		} else {
			printf("\nJogador numero 2, linha e coluna fora do limite permitido!\n");
		}
	}

	return validation;
}

//Essa função sorteia quem vai começar a jogar, se vai ser o jogador 1 ou o jogador 2
int randValue() {
	int startPlayer = 0;
	printf("\nSorteando o inicio entre Jogador 1 e Jogador 2...\n");
	srand(time(NULL)); // Função que reseta o rand a cada execução
	startPlayer = rand() % 2;
	startPlayer += 1; //Sorteia aleatoriamente um valor sendo os respectivos numeros dos jogadores 1 e 2
	if(startPlayer == 1) {
		printf("\nJOGADOR NUMERO 1, VOCE FOI SORTEADO!\n");
	} else if(startPlayer == 2) {
		printf("\nJOGADOR NUMERO 2, VOCE FOI SORTEADO!\n");
	} else {
		printf("\nO sorteio não ocorreu como deveria \n");
		printf("Reinicie o programa\n");
	}

	return startPlayer;
}

int main(void) {
	char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int validation = 0;

	printf("=============================================\n");
	printf("==       	 JOGO DA VELHA	           ==\n");
	printf("=============================================\n");

	printf("\n==========COMO JOGAR========================\n");
	printf("O jogador deve informar a linha e a coluna em\nque a celula que ele deseja selecionar esta");
	printf("\n============================================\n");
	printf("\n\nVoce quer jogar o jogo da velha? (1 - SIM ou QUALQUER VALOR - NAO): ");
	scanf("%d", &validation);


	if(validation == 1) {
		validation = 0;

		char playerOne, playerTwo;

		while(1) {
			int startPlayer = randValue();
			//O jogador inicial seleciona o simbolo que quer usar
			while(1) {
				validation = 0;
				if (startPlayer == 1) {
					printf("\nJogador numero 1, selecione seu simbolo (X - O): ");
					scanf(" %c", &playerOne);
					if (playerOne == 'X' || playerOne == 'x') {
						playerOne = 'X';
						playerTwo = 'O';
						printf("\nJogador numero 1, seu simbolo eh: %c", playerOne);
						printf("\nJogador numero 2, seu simbolo eh: %c\n", playerTwo);
						validation = 1;
					} else if (playerOne == 'O' || playerOne == 'o') {
						playerOne = 'O';
						playerTwo = 'X';
						printf("\nJogador numero 1, seu simbolo eh: %c", playerOne);
						printf("\nJogador numero 2, seu simbolo eh: %c\n", playerTwo);
						validation = 1;
					} else {
						printf("\nSimbolo invalido!\n");
					}
				} else if (startPlayer == 2) {
					printf("\nJogador numero 2, selecione seu simbolo (X - O): ");
					scanf(" %c", &playerTwo);
					if (playerTwo == 'X' || playerTwo == 'x') {
						playerTwo = 'X';
						playerOne = 'O';
						printf("\nJogador numero 1, seu simbolo eh: %c", playerOne);
						printf("\nJogador numero 2, seu simbolo eh: %c\n", playerTwo);
						validation = 1;
					} else if (playerTwo == 'O' || playerTwo == 'o') {
						playerTwo = 'O';
						playerOne = 'X';
						printf("\nJogador numero 1, seu simbolo eh: %c", playerOne);
						printf("\nJogador numero 2, seu simbolo eh: %c\n", playerTwo);
						validation = 1;
					} else {
						printf("\nSimbolo invalido!\n");
					}
				} else {
					printf("\nO sorteio não ocorreu como deveria \n");
					printf("Reinicie o programa\n");
				}
				if(validation == 1) {
					break;
				}
			}


			//Reseta a matriz board a cada recomeço de jogo
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					board[i][j] = ' ';
				}
			}

			printBoard(board); //imprime o tabuleiro antes das jogadas para visualizção

			//Inicia a partida
			while(1) {
				validation = 1;

				if(startPlayer == 1) {
					startPlayer = 2; //Manda a próxima jogada para o Jogador número 2

					//Inicia a partida do Jogador número 1
					thePlayerOne(board,playerOne,validation);

					//Valida o resultado a cada jogada, e informa um ganhador se verdadeiro
					int result = validationResult(board, playerOne, playerTwo);

					//Encerra a partida caso vitória do jogador 1
					if(result == 1) {
						break;
					}

				} else if(startPlayer == 2) {
					startPlayer = 1; //Manda a próxima jogada para o Jogador número 1

					//Inicia a partida do Jogador número 2
					thePlayerTwo(board,playerTwo,validation);

					//Valida o resultado a cada jogada, e informa um ganhador se verdadeiro
					int result = validationResult(board, playerOne, playerTwo);
					//Encerra a partida caso vitória do jogador 2
					if(result == 1) {
						break;
					}
				} else {
					printf("\nO sorteio não ocorreu como deveria \n");
					printf("Reinicie o programa\n");
				}
			}

			//Fim da partida
			printf("\n\n============ FIM DE JOGO ============\n");
			printf("\nDeseja jogar novamente? (1 - SIM ou QUALQUER VALOR - NAO): ");
			scanf("%d", &validation);

			if(validation != 1) {
				printf("\n============ JOGO ENCERRADO! ============");
				break;
			}
		}
	} else {
		printf("\n\n\n============ JOGO ENCERRADO! ============\n\n");
	}

	return 0;
}
