#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "keyboard.h"
#include "screen.h"
#include "timer.h"

struct Forca {
    char name[MAX_JOGADOR];
    int pontuacao;
    int erros;
    char palavra_secreta[20];
    char letra_certa[20];
    float tempo;
};

void initializeForca(struct Forca *forca);
void showPalavra_secreta(struct Forca *forca);
void showPontuacao(struct Forca *forca);
void showLetra_certa(struct Forca *forca, char letra_certa);
void showgameOver(struct Forca *forca);
int checkVictory(struct Forca *forca);
void savePontuacao(struct Forca *forca);
int getRandomPalavra_secreta(char *palavra_secreta);
void bemVindo(struct Forca *forca);
int keyhit(void);

int main() {
    struct Forca *forca = (struct Forca *)malloc(sizeof(struct Forca));
    if (forca == NULL) {
        printf("Erro ao alocar memoria para a estrutura Forca.\n");
        return 1;
    }

    srand(time(NULL));
    timerInit(150); 
    screenUpdate(forca->erros);

    initializeForca(forca);

    char ch = 0;
    while (forca->erros < MAX_TENTATIVAS && !timerTimeOver()) {
        screenClear();
        screenForca(forca->erros); 
        screenClear();

        showPalavra_secreta(forca);
        showPontuacao(forca);
        screenUpdate(forca->erros);
        if (keyhit()) {
            ch = get_input();

            if (ch >= 'a' && ch <= 'z') {
                showLetra_certa(forca, ch);
                screenUpdate(forca->erros); 
            }
        }

        if (checkVictory(forca)) {
            screenClear();
            screenTrofeu();
            printf("Você acertou a palavra! Parabéns, %s!\n", forca->name);
            break;
        }

        screenUpdate(forca->erros); 
    }

    showgameOver(forca);
    free(forca);

    return 0;
}

void initializeForca(struct Forca *forca) {
    int centerX = (MAXX - MINX) / 2 + MINX;
    int topY = MINY + 2;
    screenSetColor(LIGHTGREEN, DARKGRAY);

    screenGotoxy(centerX - 10, topY); 
    printf("Bem-vindo ao Mentes³!!");
    screenGotoxy(centerX - 10, topY + 1);
    printf("Vamos brincar de forca?");
    screenGotoxy(centerX - 10, topY + 2);
    printf("Nome do Jogador: ");

    if (fgets(forca->name, MAX_JOGADOR, stdin) != NULL) {
        forca->name[strcspn(forca->name, "\n")] = '\0';
    } else {
        printf("Erro ao ler o nome do jogador. Usando nome padrão.\n");
        strcpy(forca->name, "Fulano");
    }

    forca->pontuacao = 0;
    forca->erros = 0;
    getRandomPalavra_secreta(forca->palavra_secreta);
    memset(forca->letra_certa, '_', sizeof(forca->letra_certa));
    forca->letra_certa[strlen(forca->palavra_secreta)] = '\0';
    forca->tempo = 0;

    screenUpdate(forca->erros);
}

void showPalavra_secreta(struct Forca *forca) {
    screenSetColor(CYAN, DARKGRAY);
    printf("Palavra: ");
    for (int i = 0; i < strlen(forca->palavra_secreta); i++) {
        printf("%c ", forca->letra_certa[i]);
    }
    printf("\n");
}

void showPontuacao(struct Forca *forca) {
    screenSetColor(YELLOW, DARKGRAY);
    printf("Pontuação: %d\n", forca->pontuacao);
    printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - forca->erros);
}

void showLetra_certa(struct Forca *forca, char letra_certa) { 
    int correctLetra_certa = 0;
    int letraJaTentada = 0;

    for (int i = 0; i < strlen(forca->letra_certa); i++) {
        if (forca->letra_certa[i] == letra_certa) {
            letraJaTentada = 1;
            break;
        }
    }

    if (letraJaTentada) {
        printf("Você já tentou essa letra! Tente outra.\n");
        return;
    }

    for (int i = 0; i < strlen(forca->palavra_secreta); i++) {
        if (forca->palavra_secreta[i] == letra_certa) { 
            forca->letra_certa[i] = letra_certa;
            correctLetra_certa = 1;
        }
    }

    if (correctLetra_certa) {
        screenSetColor(LIGHTGREEN, DARKGRAY);
        forca->pontuacao += 5;
    } else {
        screenSetColor(LIGHTRED, DARKGRAY);
        forca->pontuacao -= 3;
        forca->erros++;
        forca->tempo++;
    }
}

int checkVictory(struct Forca *forca) {
    for (int i = 0; i < strlen(forca->palavra_secreta); i++) {
        if (forca->letra_certa[i] == ('_')) {
            return 0;
        }
    }
    return 1;
}

void showgameOver(struct Forca *forca) {
    if (forca->erros >= MAX_TENTATIVAS) {
        screenClear();
        screenCaveira();
        printf("Você perdeu, tente novamente!\n");
    }

    printf("Seu tempo: %f segundos\n", forca->tempo);
    printf("Pontuação final: %d\n", forca->pontuacao);
    savePontuacao(forca);
}

void savePontuacao(struct Forca *forca) {
    FILE *file = fopen("highscores.txt", "a+");
    if (file != NULL) {
        fprintf(file, "Nome: %s | Pontuação: %d | Tempo: %.2f\n", forca->name, forca->pontuacao, forca->tempo);
        fclose(file);
    } else {
        printf("Erro ao salvar a pontuação.\n");
    }
}

int getRandomPalavra_secreta(char *palavras_secreta) {
    const char *palavras_secretas[] = {"programacao", "forca", "jogo", "desenvolvimento", "computador"};
    srand(time(NULL));
    int index = rand() % 5;
    strcpy(palavras_secreta,palavras_secretas[index]);
    return index;
}
