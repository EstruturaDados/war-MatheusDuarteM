#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIO 5//definir a quantidade de territorios

struct Territorio{
    char nome[30];//definindo o tamanho dos nomes
    char cor[10];//o tamanho das cores
    int tropas;
};

void limparBufferEntrada() {//função para limpar buffer de entrada
	int c;
	while((c = getchar()) != '\n' && c!= EOF);
}

int main(){
    struct Territorio paises[MAX_TERRITORIO];//definindo que paises vai ter o tamanho 5
    int totalpaises = 0;
    int opcao;

    do{
        int printf(const char *__restrict__ _Format, ...);
		printf("===========================================\n");
		printf(" WAR - PARTE 1\n");
		printf("===========================================\n");
		printf("1 - CADASTRAR NOVO TERRITORIO\n");
		printf("2 - LISTAR TODOS OS PAISES\n");
		printf("0 - SAIR\n");
		printf("===========================================\n");
		printf("ESCOLHA UMA OPCAO: ");

		scanf("%d", &opcao);
		printf("\n");
		limparBufferEntrada();

		switch(opcao)
        {//escolhir fazer em partes você vai poder adicionar ate 5 paises
            case 1:
            printf("--- CADASTRO DE NOVO PAIS --- \n\n");

			if(totalpaises < MAX_TERRITORIO) {
				printf("DIGITE O NOME DO TERRITORIO: ");
				fgets(paises[totalpaises].nome,30,stdin);

				printf("DIGITE A COR: ");//o fgets vai ler a string que estiver na linha o stdin vai garantir que e uma string e o 10 e o tamanho dessa string
				fgets(paises[totalpaises].cor,10,stdin);

				printf("DIGITE O NUMERO DE TROPAS: ");
				printf(" ");
				scanf("%d",&paises[totalpaises].tropas);


				paises[totalpaises].nome[strcspn(paises[totalpaises].nome, "\n")];
				paises[totalpaises].cor[strcspn(paises[totalpaises].cor, "\n")];

				limparBufferEntrada();

				totalpaises++;

				printf("\n TERRITORIO CADASTRADO COM SUCESSO! \n");
			} else {
				printf("ATINGIU O LIMITE DE PAISES \n");
			}

			break;
			case 2://quando quiser vai poder listar os já cadastrados
		    printf("--- LISTA DE PAISES CADASTRADOS --- \n\n");
		    
		    if(totalpaises == 0){
		        printf("NENHUM PAIS CADASTRADO \n");
		    }else{
		        for(int i = 0; i < totalpaises; i++){
		            printf("--------------------------------------\n");
		            printf("PAIS %d\n", i + 1);
		            printf("NOME: %s", paises[i].nome);
		            printf("COR: %s", paises[i].cor);
		            printf("TROPAS: %d\n", paises[i].tropas);
		        }
		        printf("--------------------------------------------\n");
		    }
		    break;
		    
		 case 0://para sair basta digitar 0
		     printf("\n SAINDO DO SISTEMA...\n");
		     break;
		 default:
		    printf("\n OPCAO INVALIDA! TENTE NOVAMENTE... \n");
		    printf("\n PRESSIONE ENTER PARA CONTINUAR...");
		    getchar();
		    break;
        }
    }while(opcao != 0);
    return 0;
}
