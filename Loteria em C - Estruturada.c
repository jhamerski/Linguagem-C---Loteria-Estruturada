#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
ESCREVER UM PROGRAMA QUE LE UM VETOR (G13) QUE É O GABARITO DE UM TESTE DE LOTERIA
ESPORTIVA, CONTENDO OS VALORES 1(COLUNA1), 2(COLUNA2) E 3(COLUNA DO MEIO), LER A SEGUIR,
PARA CADA APOSTADOR, O NUMERO DE SEU CARTAO E O CARTAO RESPOSTA R(13). VERIFICAR PARA 
CADA APOSTADOR O NUMERO DE ACERTOS E ESCREVER EM UM ARQUIVO O NUMERO DO APOSTADOR E SEU
NUMERO DE ACERTO. SE TIVER 13 ACERTOS ACRESCENTAR A MENSAGEM: "GANHADOR, PARABENS!".
*/

void acertos(int gabarito[], int resposta[], int cartao, int *cont){//Funcao para conferir o resultado.
	system("CLS");//Limpa a tela.	
	int contador = 0;
	int i = 0;	

	for (i = 0; i < 13; i++){
		if(resposta[i] == gabarito[i]){
			contador = contador + 1;
		}
	}

	printf("\nO apostador %d acertou %d jogos.\a\n\n", cartao, contador);
	if (contador == 13) {
		printf("GANHADOR, PARABENS!!!\n\n");
	}	
	*cont = contador;
}


void arquivo(int cartao, int cont){//Funcao para gerar o arquivo.
	FILE *txt; //Ponteiro do arquivo.
	txt = fopen("C:\\Users\\Jonas\\Desktop\\resultado.txt", "a");
	if(txt == NULL){   
		printf("ERRO! O arquivo não foi aberto!\n");
	}else{
     	printf("O arquivo foi aberto com sucesso!\n\n");
   	}
   
   fprintf(txt, "\nO apostador %d acertou %d jogos.\n\n", cartao, cont);
   if(cont == 13){
		fprintf(txt, "GANHADOR, PARABENS!!!\n\n");
   }
   fclose(txt);//Fechamento do arquivo.
}


int main(){
	int gabarito[13] = {0, 0, 2, 2, 1, 2, 1, 2, 0, 0, 1, 0, 0};
	int cartao, cont, i;
	int resposta[13];
	char opcao;
	cont = 0;
	
	do{
		printf("Digite o numero do seu cartao: ");
		scanf("%d", &cartao);
		
		for (i = 0; i < 13; i++) {
			printf("Qual sua aposta para o jogo %d : Coluna 1 - Zero(empate) Coluna 2\n",(i + 1));
			scanf("%d", &resposta[i]);	
			while(resposta[i] < 0 || resposta[i] > 2){
				printf("Voce digitou um numero invalido. Digite um valor entre (0 e 2) para o jogo %d : ", (i + 1));
				scanf("%d", &resposta[i]);
			}
		}
	
		acertos(gabarito, resposta, cartao, &cont);//Funcao para conferir o resultado.		
		arquivo(cartao, cont);//Funcao para gerar o arquivo.
				
		printf("Deseja conferir outro cartao?\n(S)Sim - (N)Nao -> \a");
		scanf("%s", &opcao);
	}while(opcao == 's' || opcao == 'S');
	
	system("pause");
	return 0;
}
