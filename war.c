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

/**
 * @brief Simula um ataque entre dois territórios.
 * * @param atacante Ponteiro para o território que está atacando.
 * @param defensor Ponteiro para o território que está se defendendo.
 */
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    printf("\n--- SIMULANDO BATALHA: %s (%d tropas) vs %s (%d tropas) \n", 
           atacante->nome, atacante->tropas, defensor->nome, defensor->tropas);

    // Simula rolagens de dados (ex: soma de 2 dados de 6 lados)
    int forcaAtaque = (rand() % 6 + 1) + (rand() % 6 + 1);
    int forcaDefesa = (rand() % 6 + 1) + (rand() % 6 + 1);

    if (atacante->tropas > defensor->tropas) {
        printf("\n>>> VITORIA DO ATACANTE! <<<\n");
        printf("O territorio %s foi conquistado pelo %s\n", defensor->nome,atacante->nome);
        
        // Atualização de tropas: atacante move 1 tropa, defensor fica com 1
        defensor->tropas--;

    } else {
        printf("\n>>> VITORIA DO DEFENSOR! <<<\n");
        printf("O ataque foi repelido!\n");

		atacante->tropas--;
        printf("O atacante recuou e perdeu tropas.\n");
    }
}

int main(){
    struct Territorio *paises; // Ponteiro para o vetor de territórios
    int totalpaises = 0;
    int opcao;

    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    // Aloca memória para o número de territórios informado
    paises = (struct Territorio*) calloc(MAX_TERRITORIO, sizeof(struct Territorio));

    // Verifica se a alocação de memória falhou
    if (paises == NULL) {
        printf("Erro ao alocar memoria! O programa sera encerrado.\n");
        return 1; // Retorna um código de erro
    }

    do{
        int printf(const char *__restrict__ _Format, ...);
    	printf("===========================================\n");
    	printf(" BEM-VINDO AO WAR - CONFIGURACAO INICIAL\n");
    	printf("===========================================\n");
		printf("1 - CADASTRAR NOVO TERRITORIO\n");
		printf("2 - LISTAR TODOS OS PAISES\n");
		printf("3 - FASE DE ATAQUE\n");
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
			case 3:
 				printf("--- FASE DE ATAQUE --- \n\n");
                if (totalpaises < 2) {
                    printf("E necessario ter pelo menos 2 territorios cadastrados para atacar.\n");
                    break;
                }

                // Listar territórios para escolha
                printf("Territorios disponiveis:\n");
                for (int i = 0; i < totalpaises; i++) {
                    printf("%d - %s (Cor: %s, Tropas: %d)\n", i + 1, paises[i].nome, paises[i].cor, paises[i].tropas);
                }

                int indiceAtacante, indiceDefensor;
                printf("\nEscolha o territorio ATACANTE (pelo numero): ");
                scanf("%d", &indiceAtacante);
                printf("Escolha o territorio DEFENSOR (pelo numero): ");
                scanf("%d", &indiceDefensor);
                limparBufferEntrada();
                
                // Converte para índice de array (0 a N-1)
                indiceAtacante--; 
                indiceDefensor--;

                // Validações
                if (indiceAtacante < 0 || indiceAtacante >= totalpaises ||
                    indiceDefensor < 0 || indiceDefensor >= totalpaises) {
                    printf("\nERRO: Escolha invalida. Pelo menos um dos territorios nao existe.\n");
                    break;
                }
                if (indiceAtacante == indiceDefensor) {
                    printf("\nERRO: O territorio nao pode atacar a si mesmo.\n");
                    break;
                }
                if (paises[indiceAtacante].tropas <= 1) {
                    printf("\nERRO: O territorio atacante precisa de mais de 1 tropa para iniciar um ataque.\n");
                    break;
                }
                if (strcmp(paises[indiceAtacante].cor, paises[indiceDefensor].cor) == 0) {
                    printf("\nERRO: Nao e possivel atacar um territorio que ja e seu.\n");
                    break;
                }

                // Se todas as validações passaram, executa o ataque
                atacar(&paises[indiceAtacante], &paises[indiceDefensor]);

                // --- EXIBIÇÃO PÓS-ATAQUE ---
                printf("\n--- ESTADO ATUALIZADO DOS TERRITORIOS ENVOLVIDOS ---\n");
                printf("ATACANTE: %s | Cor: %s | Tropas: %d\n", paises[indiceAtacante].nome, paises[indiceAtacante].cor, paises[indiceAtacante].tropas);
                printf("DEFENSOR: %s | Cor: %s | Tropas: %d\n", paises[indiceDefensor].nome, paises[indiceDefensor].cor, paises[indiceDefensor].tropas);
                printf("---------------------------------------------------\n");

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
