// Jogo da Velha 1.0
// Lucas Bitencourt Silveira

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

// Função para validar caracteres
char validac(char caractere, int qnt, char vetor[100]) {
	int aux=0,i;
	while (aux==0) {
		for(i=0;i<qnt;i++)
			if(caractere==vetor[i])
				aux=1;
		if(aux==0) {
			printf("\nCaractere inv%clido! Digite novamente: ",160);
			fflush(stdin);
			caractere=getch();
		}
	}
	return caractere;
}

// Função para validar posição da velha
char validap(char matriz[3][3], char posicao) {
	int aux=0;
	char opcoes[9] = {'1','2','3','4','5','6','7','8','9'};
	while (aux==0) {
		switch(posicao) {
			case '7'	: if (matriz[0][0]==0) aux=1; break;
			case '8'	: if (matriz[0][1]==0) aux=1; break;
			case '9'	: if (matriz[0][2]==0) aux=1; break;
			case '4'	: if (matriz[1][0]==0) aux=1; break;
			case '5'	: if (matriz[1][1]==0) aux=1; break;
			case '6'	: if (matriz[1][2]==0) aux=1; break;
			case '1'	: if (matriz[2][0]==0) aux=1; break;
			case '2'	: if (matriz[2][1]==0) aux=1; break;
			case '3'	: if (matriz[2][2]==0) aux=1; break;
			default		: ;
		}
		if(aux==0) {
			printf("\nPosi%c%co j%c ocupada! Digite novamente: ",135,198,160);
			fflush(stdin);
			posicao=getch();
			posicao=validac(posicao,9,opcoes);
		}
	}
	return posicao;
}

// Função para desenhar o jogo da velha
void desenhar(char matriz[3][3]) {
	int i,j;
	system("cls");
	printf("\n");
	for(i=0;i<5;i++)
		for(j=0;j<5;j++) {
			if(j==0)
				printf("\t");
			if(i%2==0){
				if(j%2==0)
					printf("%c",matriz[i/2][j/2]);
				else
					printf("%c",179);
			}
			else {
				if(j%2==0)
					printf("%c",196);
				else
					printf("%c",197);
			}
		if(j==4)
			printf("\n");
		}
	printf("\n");
}

// Função para a máquina jogar
char pcjogar(char matriz[3][3],int jogador,int movimento) {
	char posicao,caractere,outro;
	int i,j,jogou=0;
	if(jogador==1) {
		caractere='X';
		outro='O'; }
	else if (jogador==2) {
		caractere='O';
		outro='X'; }
		
	if(jogou==0 && movimento==1) {
		jogou=1;
		posicao='7'; }
		
	if(jogou==0 && movimento==2) {
		if(matriz[1][1]!='X')
			posicao='5';
		else posicao='7';
		jogou=1; }
	
	if(jogou==0 && movimento==3) {
		if(matriz[1][1]=='O')
			posicao='3';
		else if(matriz[0][1]=='O' || matriz[0][2]=='O')
			posicao='4';
		else if(matriz[1][0]=='O' || matriz[2][0]=='O')
			posicao='8';
		else posicao='5';
		jogou=1; }
		
	if(jogou==0 && movimento==4) {
		if((matriz[0][0]=='X' && matriz[2][2]=='X' && matriz[1][1]=='O') || (matriz[0][2]=='X' && matriz[2][0]=='X' && matriz[1][1]=='O')) {
			posicao='8'; jogou=1; } }
	
	if(jogou==0 && matriz[0][0]==caractere && matriz[1][1]==caractere && matriz[2][2]==0)
		posicao='3';
	if(jogou==0 && matriz[0][0]==caractere && matriz[1][1]==0 && matriz[2][2]==caractere)
		posicao='5';
	if(jogou==0 && matriz[0][0]==0 && matriz[1][1]==caractere && matriz[2][2]==caractere)
		posicao='7';
	
	if(jogou==0 && matriz[0][2]==caractere && matriz[1][1]==caractere && matriz[2][0]==0)
		posicao='1';
	if(jogou==0 && matriz[0][2]==caractere && matriz[1][1]==0 && matriz[2][0]==caractere)
		posicao='5';
	if(jogou==0 && matriz[0][2]==0 && matriz[1][1]==caractere && matriz[2][0]==caractere)
		posicao='9';
		
	if(jogou==0)
		for(i=0;i<3;i++) {
				if(jogou==0 && matriz[i][0]==caractere && matriz[i][1]==caractere && matriz[i][2]==0) {
					switch(i) {
						case 0: posicao='9'; break;
						case 1: posicao='6'; break;
						case 2: posicao='3'; break;
						default: ; }
					jogou=1; }
				if(jogou==0 && matriz[i][0]==caractere && matriz[i][1]==0 && matriz[i][2]==caractere) {
					switch(i) {
						case 0: posicao='8'; break;
						case 1: posicao='5'; break;
						case 2: posicao='2'; break; }
					jogou=1; }
				if(jogou==0 && matriz[i][0]==0 && matriz[i][1]==caractere && matriz[i][2]==caractere) {
					switch(i) {
						case 0: posicao='7'; break;
						case 1: posicao='4'; break;
						case 2: posicao='1'; break; }
					jogou=1; }
				if(jogou==0 && matriz[0][i]==caractere && matriz[1][i]==caractere && matriz[2][i]==0) {
					switch(i) {
						case 0: posicao='1'; break;
						case 1: posicao='2'; break;
						case 2: posicao='3'; break;
						default: ; }
					jogou=1; }
				if(jogou==0 && matriz[0][i]==caractere && matriz[1][i]==0 && matriz[2][i]==caractere) {
					switch(i) {
						case 0: posicao='4'; break;
						case 1: posicao='5'; break;
						case 2: posicao='6'; break; }
					jogou=1; }
				if(jogou==0 && matriz[0][i]==0 && matriz[1][i]==caractere && matriz[2][i]==caractere) {
					switch(i) {
						case 0: posicao='7'; break;
						case 1: posicao='8'; break;
						case 2: posicao='9'; break; }
					jogou=1; }	
					
				if(jogou==0 && matriz[i][0]==outro && matriz[i][1]==outro && matriz[i][2]==0) {
					switch(i) {
						case 0: posicao='9'; break;
						case 1: posicao='6'; break;
						case 2: posicao='3'; break;
						default: ; }
					jogou=1; }
				if(jogou==0 && matriz[i][0]==outro && matriz[i][1]==0 && matriz[i][2]==outro) {
					switch(i) {
						case 0: posicao='8'; break;
						case 1: posicao='5'; break;
						case 2: posicao='2'; break; }
					jogou=1; }
				if(jogou==0 && matriz[i][0]==0 && matriz[i][1]==outro && matriz[i][2]==outro) {
					switch(i) {
						case 0: posicao='7'; break;
						case 1: posicao='4'; break;
						case 2: posicao='1'; break; }
					jogou=1; }
				if(jogou==0 && matriz[0][i]==outro && matriz[1][i]==outro && matriz[2][i]==0) {
					switch(i) {
						case 0: posicao='1'; break;
						case 1: posicao='2'; break;
						case 2: posicao='3'; break;
						default: ; }
					jogou=1; }
				if(jogou==0 && matriz[0][i]==outro && matriz[1][i]==0 && matriz[2][i]==outro) {
					switch(i) {
						case 0: posicao='4'; break;
						case 1: posicao='5'; break;
						case 2: posicao='6'; break; }
					jogou=1; }
				if(jogou==0 && matriz[0][i]==0 && matriz[1][i]==outro && matriz[2][i]==outro) {
					switch(i) {
						case 0: posicao='7'; break;
						case 1: posicao='8'; break;
						case 2: posicao='9'; break; }
					jogou=1; }
		}		
		
	if(jogou==0 && matriz[0][0]==outro && matriz[1][1]==outro && matriz[2][2]==0)
		posicao='3';
	if(jogou==0 && matriz[0][0]==outro && matriz[1][1]==0 && matriz[2][2]==outro)
		posicao='5';
	if(jogou==0 && matriz[0][0]==0 && matriz[1][1]==outro && matriz[2][2]==outro)
		posicao='7';
		
	if(jogou==0 && matriz[0][2]==outro && matriz[1][1]==outro && matriz[2][0]==0)
		posicao='1';
	if(jogou==0 && matriz[0][2]==outro && matriz[1][1]==0 && matriz[2][0]==outro)
		posicao='5';
	if(jogou==0 && matriz[0][2]==0 && matriz[1][1]==outro && matriz[2][0]==outro)
		posicao='9';
		
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(jogou==0 && matriz[i][j]==0)
				switch(i) {
					case 0: switch(j) {
								case 0: posicao='7'; break;
								case 1: posicao='8'; break;
								case 2: posicao='9'; break; }
					case 1: switch(j) {
								case 0: posicao='4'; break;
								case 1: posicao='5'; break;
								case 2: posicao='6'; break; }
					case 2: switch(j) {
								case 0: posicao='1'; break;
								case 1: posicao='2'; break;
								case 2: posicao='3'; break; }
					jogou=1;
				}
			
	switch(posicao) {
		case '7':	matriz[0][0]=caractere; break;
		case '8':	matriz[0][1]=caractere; break;
		case '9':	matriz[0][2]=caractere; break;
		case '4':	matriz[1][0]=caractere; break;
		case '5':	matriz[1][1]=caractere; break;
		case '6':	matriz[1][2]=caractere; break;
		case '1':	matriz[2][0]=caractere; break;
		case '2':	matriz[2][1]=caractere; break;
		case '3':	matriz[2][2]=caractere; break;
		default :	;
	}
	return matriz[3][3];
}

// Função para ler opção do jogador e substituir posição da matriz
char jogar(char matriz[3][3],int jogador) {
	char posicao,caractere,opcoes[9] = {'1','2','3','4','5','6','7','8','9'};
	fflush(stdin);
	if(jogador==1)
		caractere='X';
	else if (jogador==2)
		caractere='O';
	posicao=getch();
	posicao=validac(posicao,9,opcoes);
	posicao=validap(matriz,posicao);
	switch(posicao) {
		case '7':	matriz[0][0]=caractere; break;
		case '8':	matriz[0][1]=caractere; break;
		case '9':	matriz[0][2]=caractere; break;
		case '4':	matriz[1][0]=caractere; break;
		case '5':	matriz[1][1]=caractere; break;
		case '6':	matriz[1][2]=caractere; break;
		case '1':	matriz[2][0]=caractere; break;
		case '2':	matriz[2][1]=caractere; break;
		case '3':	matriz[2][2]=caractere; break;
		default :	;
	}
	return matriz[3][3];
}

// Função para verificar se alguem venceu o jogo no ultimo movimento
int verificafim(char matriz[3][3]) {
	int i,j,fim=0,aux=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(matriz[i][j]==0)
				aux=1;
	if(aux==0) {
		fim=1;
	}
	for(i=0;i<3;i++) {
		if (matriz[i][0]==matriz[i][1] && matriz[i][0]==matriz[i][2] && matriz[i][0]!=0) {
			if(matriz[i][0]=='X')
				fim=2;
			else if(matriz[i][0]=='O')
				fim=3;
		}
		if (matriz[0][i]== matriz[1][i] && matriz[0][i]==matriz[2][i] && matriz[0][i]!=0) {
			if(matriz[0][i]=='X')
				fim=2;
			else if(matriz[0][i]=='O')
				fim=3;
		}
	}
	if(((matriz[0][0]==matriz[1][1] && matriz[0][0]==matriz[2][2]) || (matriz[0][2]==matriz[1][1] && matriz[1][1]==matriz[2][0])) && matriz[1][1]!=0) {
		if(matriz[1][1]=='X')
			fim=2;
		else if(matriz[1][1]=='O')
			fim=3;
	}
	return fim;
}

// Função: jogo com duas pessoas
void multiplayer() {
	char posicoes[3][3] = {{0,0,0},
						   {0,0,0},
						   {0,0,0}};
	int fimdejogo = 0, movimento = 0, jogador;	
	do {
		movimento++;
		if (movimento%2==0)
			jogador=2;
		else if (movimento%2==1)
			jogador=1;
		desenhar(posicoes);
		posicoes[3][3]=jogar(posicoes,jogador);
		fimdejogo=verificafim(posicoes);
	} while(fimdejogo==0);
	desenhar(posicoes);	
	if(fimdejogo==1) printf("\nFim de jogo: Empate\n");
		else if(fimdejogo==2) printf("\nFim de jogo: O jogador 1 venceu!\n");
			else if(fimdejogo==3) printf("\nFim de jogo: O jogador 2 venceu!\n");
			
	system("pause");
}

void singleplayer() {
	char posicoes[3][3] = {{0,0,0},
						   {0,0,0},
						   {0,0,0}};
	char play,opcoes[4] = {'s','S','n','N'};
	int fimdejogo = 0, movimento = 0, jogador,pc;
	fflush(stdin);
	printf("Voc%c deseja come%car o jogo? (S/N) ",136,135);
	play=getch();
	play=validac(play,4,opcoes);
	switch(play) {
		case 's':	;
		case 'S':	pc=2; break;
		case 'n':	;
		case 'N':	pc=1; break;
		default :	;
		}
	do {
		movimento++;
		if (movimento%2==0)
			jogador=2;
		else if (movimento%2==1)
			jogador=1;
		desenhar(posicoes);
		if(jogador!=pc)
			posicoes[3][3]=jogar(posicoes,jogador);
		else posicoes[3][3]=pcjogar(posicoes,jogador,movimento);
		fimdejogo=verificafim(posicoes);
	} while(fimdejogo==0);
	desenhar(posicoes);	
	if(fimdejogo==1) printf("\nFim de jogo: Empate\n");
		else if(fimdejogo==2) printf("\nFim de jogo: O jogador 1 venceu!\n");
			else if(fimdejogo==3) printf("\nFim de jogo: O jogador 2 venceu!\n");
			
	system("pause");
}

// Função principal
int main() {
	char opcao,opcoes[4] = {'1','2','3','4'};
	char teclas[3][3] = {{'7','8','9'},{'4','5','6'},{'1','2','3'}};
	do {
		system("cls");
		printf("\n\tBem vindo ao Jogo da Velha!\n");
		printf("\n\t1 - Um jogador\n\t2 - Dois jogadores\n\t3 - Sair\n\t4 - Instrun%c%ces\n\n",135,228);
		fflush(stdin);
		opcao=getch();
		opcao=validac(opcao,4,opcoes);
		switch(opcao) {
			case '1'	: singleplayer(); break;
			case '2'	: multiplayer(); break;
			case '3'	: break;
			case '4'	: system("cls"); printf("\nDurante o jogo, pressione no teclado o numero correspondente %c posi%c%co desejada.\n",133,135,198);
						  printf("Quando voc%c fizer sua jogada, no modo de um jogador, o computador jogar%c \nimediatamente.\n\n",136,160);
						  printf("Pressione qualquer tecla para ver as posi%c%ces do jogo.",135,228); getch();
						  desenhar(teclas); system("pause"); break;
			default		: ;
		}
	} while (opcao!='3');			
	return 0;
}
