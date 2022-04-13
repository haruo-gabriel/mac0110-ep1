#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int parar = 0, depur = 0, jogados = 0, vencidos = 0, opcao, tentativas;
    int digito;
    int n1, n2, n3;
    int dig1, dig2, dig3;
    srand(time(NULL));


    printf("Bem-vindo ao JOGO da FORCA !!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


    while(parar == 0){

        /*Tela de início*/

        if(depur == 0){
            printf("[ depuração = DESLIGADO / jogos jogados = %d ]\n", jogados);
        }
        else{
            printf("[ depuração = LIGADO / jogos jogados = %d ]\n", jogados);
        }

        printf("1. Continuar a jogar\n");
        printf("2. Alternar modo depuração e continuar a jogar\n");
        printf("3. Parar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n\n");


        /*Seleção de valores para opção*/

        if(opcao == 3){
            parar = 1;
        }

        if(opcao == 2){
            if(depur == 0){
                depur = 1; 
            }
            else{
                depur = 0;
            }
        }
        
        if(opcao == 1 || opcao == 2){
           
            /*Início do jogo*/

            /*
            A variável "digito" armazena o input do usuário.
            As variáveis "nx" são os dígitos aleatórios.
            As variáveis "digx" mostram se o usuário adivinhou ou não os dígitos aleatórios.
            */

            n1 = rand() % 10;
            n2 = rand() % 10;
            n3 = rand() % 10;

            dig1 = dig2 = dig3 = -1;

            tentativas = 6;
            
            while(tentativas > 0 && (dig1 != n1 || dig2 != n2 || dig3 != n3) ){
                
                tentativas--;

                if(depur == 1){
                    printf("Número a ser adivinhado: %d %d %d\n", n1, n2, n3);
                }
                printf("Restam %d tentativa(s)\n", tentativas+1);
                printf("Sua próxima tentativa (dígito de 0 a 9): ");
                scanf("%d", &digito);

                if(digito == n1){
                    dig1 = n1;
                }
                if(digito == n2){
                    dig2 = n2;
                }
                if(digito == n3){
                    dig3 = n3;
                }


                printf("Você já acertou os seguintes dígitos: ");

                if(dig1 == n1){
                    printf("%d ", dig1);
                }
                else{
                    printf("_ ");
                }

                if(dig2 == n2){
                    printf("%d ", dig2);
                }
                else{
                    printf("_ ");
                }

                if(dig3 == n3){
                    printf("%d", dig3);
                }
                else{
                    printf("_");
                }

                printf("\n\n");

            }

            if(dig1 != n1 || dig2 != n2 || dig3 != n3){
                printf("Você PERDEU!\n\n");
            }
            else{
                printf("Você VENCEU!\n\n");
                vencidos++;
            }

            jogados++;

        }
    }
    
    printf("Você jogou %d jogo(s) e venceu %d vez(es)!\n\n", jogados, vencidos);

    return 0;

}
