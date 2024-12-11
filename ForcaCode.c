#define TAMANHO_MAXIMO 50
#define MAX_JOGADORES 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char nome[TAMANHO_MAXIMO];
  // char palavra[TAMANHO_MAXIMO];
  int pontuacao;
  int vezes_ganhas;
} Jogador;

int main() {

  char palavras_animais[10][7] = {"baleia",  "kanguru", "morcego", "cobra",
                                  "pato",    "girafa",  "coelho",  "sapo",
                                  "tubarao", "arraia"};
  char palavras_objetos[10][7] = {"relogio", "teclado", "monitor", "lapis",
                                  "caneta",  "espelho", "oculos",  "moeda",
                                  "livro",   "caderno"};
  char palavras_paises[10][7] = {"italia", "japao",   "brasil", "chile",
                                 "coreia", "espanha", "franca", "canada",
                                 "angola", "russia"};
  char palavras_frutas[10][7] = {"mamao",   "pessego", "maca",  "melao",
                                 "laranja", "banana",  "amora", "pera",
                                 "jaca",    "goiaba"};
  int menu;
  int jogar_novamente;
  Jogador jogadores[MAX_JOGADORES];
  int num_jogadores = 0;
  char nome[TAMANHO_MAXIMO];

  system("clear");

  printf("****************************************\n");
  printf("*                                      *\n");
  printf("*               BEM VINDO              *\n");
  printf("*           AO JOGO DA FORCA!          *\n");
  printf("*                                      *\n");
  printf("*                                      *\n");
  printf("*      APERTE ENTER PARA CONTINUAR     *\n");
  printf("*                                      *\n");
  printf("****************************************\n");
  getchar();

  do {
 
    printf("****************************************\n");
    printf("*            REGRAS DO JOGO            *\n");
    printf("*                                      *\n");
    printf("*       O jogo deverá entrar com o     *\n");
    printf("*   seu nome e entao escolher uma      *\n");
    printf("*   categoria de palavras. então o     *\n");
    printf("*   mesmo devera tentar adivinhar a    *\n");
    printf("*   palavra letra por letra. Cada      *\n");
    printf("*   partida vale 1 ponto, e se voce    *\n");
    printf("*   não acertar, perdera um ponto.     *\n");
    printf("*   Até 10 jogadores serão aceitos.    *\n");
    printf("*                                      *\n");
    printf("*    1  para JOGAR                     *\n");
    printf("*    2  para HISTÓRICO                 *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
    scanf(" %i", &menu);
    getchar();

    if (menu == 1) {

      char palavra_escolhida[TAMANHO_MAXIMO] = {};
      int tentativas_erradas = 0;
      int categoria = 0;

      int numero_aleatorio = 0;
      srand(time(NULL));
      numero_aleatorio = rand() % 11;

      printf("\nEntre com o nome do jogador: ");
      fgets(nome, sizeof(nome), stdin);

      printf("****************************************\n");
      printf("*     ESCOLHA A CATEGORIA DESEJADA     *\n");
      printf("*                                      *\n");
      printf("*     1 para ANIMAIS                   *\n");
      printf("*     2 para OBJETOS                   *\n");
      printf("*     3 para PAISES                    *\n");
      printf("*     4 para FRUTAS                    *\n");
      printf("*                                      *\n");
      printf("****************************************\n");

      scanf("%d", &categoria);

      if (categoria == 1) {
        strcpy(palavra_escolhida, palavras_animais[numero_aleatorio]);
      } else if (categoria == 2) {
        strcpy(palavra_escolhida, palavras_objetos[numero_aleatorio]);
      } else if (categoria == 3) {
        strcpy(palavra_escolhida, palavras_paises[numero_aleatorio]);
      } else if (categoria == 4) {
        strcpy(palavra_escolhida, palavras_frutas[numero_aleatorio]);
      }

      else {
        printf("caractere invalido.\n");
      }

      int numero_de_casa = strlen(palavra_escolhida);

      char palavra_secreta[TAMANHO_MAXIMO] = {};

      for (int i = 0; i < numero_de_casa; i++) {
        palavra_secreta[i] = '_';
      }

      palavra_secreta[numero_de_casa] = '\0';

      puts(" ");
      system("clear");
      printf("Vamos começar o jogo!\n");

      char letra_adivinhada;
      int letra_existe = 0;
      int numero_de_jogadas = 0;
      char letras_usadas[TAMANHO_MAXIMO] = {};

      // Verifica se o jogador já existe na matriz de jogadores
      int indice_jogador = -1;
      for (int i = 0; i < num_jogadores; i++) {
        if (strcmp(jogadores[i].nome, nome) == 0) {
          indice_jogador = i;
          break;
        }
      }

      // Se o jogador não for encontrado, adiciona um novo jogador
      if (indice_jogador == -1) {
        if (num_jogadores < MAX_JOGADORES) {
          strcpy(jogadores[num_jogadores].nome, nome);
          // strcpy(jogadores[num_jogadores].palavra, palavra_escolhida);
          jogadores[num_jogadores].pontuacao = 0;
          jogadores[num_jogadores].vezes_ganhas = 0;
          indice_jogador = num_jogadores;
          num_jogadores++;
        } else {
          printf("Não é possível adicionar mais jogadores.\n");
          continue;
        }
      }

      while (tentativas_erradas < 6) {
        if (tentativas_erradas == 0) {
          printf("\n---------");
          printf("\n|       |");
          printf("\n|");
          printf("\n|");
          printf("\n|");
          printf("\n|");
          printf("\n|");
          printf("\n-");
        } else if (tentativas_erradas == 1) {
          printf("\n---------");
          printf("\n|       |");
          printf("\n|       O");
          printf("\n|");
          printf("\n|");
          printf("\n|");
          printf("\n|");
          printf("\n-");
        } else if (tentativas_erradas == 2) {
          printf("\n_________");
          printf("\n|       |");
          printf("\n|       O");
          printf("\n|       |");
          printf("\n|       |");
          printf("\n|");
          printf("\n|");
          printf("\n-");
        } else if (tentativas_erradas == 3) {
          printf("\n_________");
          printf("\n|       |");
          printf("\n|       O");
          printf("\n|      /|");
          printf("\n|       |");
          printf("\n|");
          printf("\n|");
          printf("\n-");
        } else if (tentativas_erradas == 4) {
          printf("\n_________");
          printf("\n|       |");
          printf("\n|       O");
          printf("\n|      /|\\");
          printf("\n|       |");
          printf("\n|");
          printf("\n|");
          printf("\n-");
        } else if (tentativas_erradas == 5) {
          printf("\n_________");
          printf("\n|       |");
          printf("\n|       O");
          printf("\n|      /|\\");
          printf("\n|       |");
          printf("\n|      / \\");
          printf("\n|");
          printf("\n-");
        }

        printf("Letras usadas: %s\n", letras_usadas);
        printf("%s\n", palavra_secreta);
        printf("Escolha uma letra: ");
        scanf(" %c", &letra_adivinhada);
        getchar();

        int repetido = 0;

        for (int i = 0; i < numero_de_jogadas; i++) {
          if (letra_adivinhada == letras_usadas[i]) {
            repetido = 1;
            break;
          }
        }

        system("clear");

        if (repetido == 1) {
          printf("Letra já utilizada. Tente outra letra.\n");
          continue;
        }

        letras_usadas[numero_de_jogadas] = letra_adivinhada;
        letras_usadas[numero_de_jogadas + 1] = '\0';
        numero_de_jogadas++;

        int letra_encontrada = 0;

        for (int c = 0; c < numero_de_casa; c++) {
          if (letra_adivinhada == palavra_escolhida[c]) {
            letra_encontrada = 1;
            palavra_secreta[c] = letra_adivinhada;
          }
        }

        if (letra_encontrada == 0) {
          tentativas_erradas++;
        }

        if (strcmp(palavra_secreta, palavra_escolhida) == 0) {
          printf("Parabéns, você adivinhou a palavra secreta \"%s\"!\n",
                 palavra_escolhida);

          jogadores[indice_jogador].pontuacao += 1;
          jogadores[indice_jogador].vezes_ganhas += 1;

          break;
        }
      }

      if (tentativas_erradas == 6) {
        printf("Suas tentativas acabaram. A palavra secreta era \"%s\".\n",
               palavra_escolhida);
        jogadores[indice_jogador].pontuacao -= 1;
      }

      printf("****************************************\n");
      printf("*                                      *\n");
      printf("*        DESEJA JOGAR NOVAMENTE?       *\n");
      printf("*                                      *\n");
      printf("*        1 para SIM                    *\n");
      printf("*        2 para NÃO                    *\n");
      printf("*                                      *\n");
      printf("****************************************\n");
      scanf(" %i", &jogar_novamente);
      getchar();
      system("clear");

    } else if (menu == 2) {

      if (num_jogadores == 0) {
        printf("Nenhum histórico encontrado.\n");
        continue;
      }

      printf("****************************************\n");
      printf("*                                      *\n");
      printf("*                HISTÓRICO             *\n");
      printf("*                                      *\n");
      printf("****************************************\n");

      for (int i = 0; i < num_jogadores; i++) {
        printf("\nJogador: %s\n", jogadores[i].nome);
        printf("Pontuação: %d\n", jogadores[i].pontuacao);
        printf("Vezes ganhas: %d\n", jogadores[i].vezes_ganhas);
        printf("****************************************\n");
        printf("\n");
      }
    }
  } while (jogar_novamente == 1);

  printf("Obrigado por jogar!\n");

  return 0;
}
