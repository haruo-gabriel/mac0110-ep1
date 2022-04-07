#include <stdio.h>
#include <stdlib.h>

void jogo();

int main(){
  int n = 1, dep = 0, opcao, jogados = 0, vencidos = 0;
  
  printf("Bem-vindo ao JOGO da FORCA !!\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  
  while (n == 1){
    if (dep == 0){
      printf("[ depuração = DESLIGADO / jogos jogados = %d ]\n   1. Continuar a jogar\n   2. Alternar modo depuração e continuar a jogar\n   3. Parar\nEscolha uma opção: ", jogados);
    }
    
    if (dep == 1){
      printf("[ depuração = LIGADO / jogos jogados = %d ]\n   1. Continuar a jogar\n   2. Alternar modo depuração e continuar a jogar\n   3. Parar\nEscolha uma opção: ", jogados);
    }
    scanf("%d", &opcao);

    if (opcao != 3){
      int num = rand() % 1000, dig1, dig2, dig3;
      
      if (num == 0){
        dig1 = 0; dig2 = 0; dig3 = 0;}
      else{
        if (num < 10){
          dig1 = num; dig2 = 0; dig3 = 0;}
        else{
          if (num < 100){
            dig1 = num % 10; dig2 = num / 10; dig3 = 0;}
          else{
            dig1 = num % 10; dig2 = (num / 10) % 10; dig3 = num / 100;}}
      }
      
      int chute, teste = 1, contador = 6, unidade = 10, dezena = 10, centena = 10;
      
      if (opcao == 2){
        if (dep == 0){
          dep = 1;}
        else{dep = 0;}
        }

      if (dep == 1){
        printf("Número a ser adivinhado: %d\n", num);
      }
      
      while (teste == 1){
        if (contador > 1){
          printf("Restam %d tentativas.\n", contador);}
        else{
          printf("Resta apenas uma tentativa.\n");}
        
        printf("Sua próxima tentativa (dígito de 0 a 9): ");
        scanf("%d", &chute);

        if (chute == dig1){unidade = chute;}
        if (chute == dig2){dezena = chute;}
        if (chute == dig3){centena = chute;}

        printf("Você já acertou os seguintes dígitos: ");
        
        if (unidade < 10){
          printf("%d ", unidade);} 
        else{
          printf("_ ");}
        if (dezena < 10){
          printf("%d ", dezena);}
        else{
          printf("_ ");}
        if (centena < 10){
          printf("%d\n\n", centena);}
        else{
          printf("_\n\n");}

        if (unidade == dig1 && dezena == dig2 && centena == dig3){
          printf("Você VENCEU!\n\n");
          vencidos++;
          jogados++;
          teste = 0;
        }

        else {
          contador -= 1;
          if (contador == 0){
            printf("Você PERDEU!\n\n");
            jogados++;
            teste = 0;
          }
        }
      }
    }
    
    else{
      n = 0;
      printf("Você jogou %d jogos e venceu %d vezes!\n", jogados, vencidos);
      }
  }
  return 0;
}
