#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int x = 34, y = 12;
int incX = 1, incY = 1;
int pontos = 0;
float tempoTotal =0;


void printKey(int ch) {
  screenSetColor(YELLOW, DARKGRAY);
  screenGotoxy(35, 22);
  printf("Key code :");

  screenGotoxy(34, 23);
  printf("            ");

  if (ch == 27)
    screenGotoxy(36, 23);
  else
    screenGotoxy(39, 23);

  printf("%d ", ch);
  while (keyhit()) {
    printf("%d ", readch());
  }
}

void jogarForca(char* palavra, char* dica) {
    int tentativas = 6, acertos = 0;
    int tempoIniciado = time(NULL); // Iniciar o tempo
    char* palavraDescoberta = (char*)malloc(strlen(palavra) + 1); // Alocação dinâmica
    for (int i = 0; i < strlen(palavra); i++) palavraDescoberta[i] = '_';
    palavraDescoberta[strlen(palavra)] = '\0';

    printf("\nDica: %s\n", dica);
    printf("Palavra: %s\n", palavraDescoberta);

    while (tentativas > 0) {
        char letra;
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

        int acertou = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra && palavraDescoberta[i] == '_') {
                palavraDescoberta[i] = letra;
                acertou = 1;
                acertos++;
            }
        }

        if (!acertou) {
            tentativas--;
            screenDrawHangman(6 - tentativas);
        }

        printf("Palavra: %s\n", palavraDescoberta);

        if (acertos == strlen(palavra)) {
            printf("Você acertou a palavra!\n");
            pontos += 5;
            screenDrawTrophy();
            break;
        }
    }

    if (tentativas == 0) {
        screenDrawGameOver(palavra);
        pontos -= 3;
    }

    int tempoFinal = time(NULL) - tempoIniciado;
    tempoTotal += tempoFinal;
    free(palavraDescoberta);
}

void salvarResultado(char* nome, int pontos, int tempoTotal) {
    FILE* file = fopen("resultados.txt", "a");
    if (file != NULL) {
        fprintf(file, "Nome: %s, Pontos: %d, Tempo: %d segundos\n", nome, pontos, tempoTotal);
        fclose(file);
    } else {
        printf("Erro ao salvar o resultado.\n");
    }
}

int main() {
  char nome[50];
  static int ch = 0;

  screenInit(1);
  keyboardInit();
  timerInit(50);

  printf("Digite seu nome: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = '\0';

  char* palavras[] = {"laranja", "abacaxi", "melancia"};
  char* dicas[] = {"fruta", "fruta", "fruta"};

  for (int i = 0; i < 3; i++) {
      jogarForca(palavras[i], dicas[i]);
      screenUpdate();  
  }

   salvarResultado(nome, pontos, tempoTotal);

  keyboardDestroy();
  screenDestroy();
  timerDestroy();

  return 0;
}
