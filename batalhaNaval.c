#include <stdio.h>


#define TAMANHO 10 // Tamanho do tabuleiro
 
// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], char nome[]){
    printf("\n%s\n", nome);
    printf("  ");
    for(int i = 0; i < TAMANHO; i++){
        printf("%c ", 'A' + i);
    }
    printf("\n");


    for(int i = 0; i < TAMANHO; i++){
        printf("%d ", i + 1);
        for(int j = 0; j < TAMANHO; j++){
            printf("%d " ,tabuleiro[i][j]);
        }
        printf("\n");
    }
} 
// Posiciona um navio na horizontal
void posicionarNavioHorizontal (int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho){

    if(coluna + tamanho > TAMANHO){
        printf("O navio horizontal ultrapassa os limites.\n");
        return;
    }
    for(int i = 0; i < tamanho; i++){
        tabuleiro[linha][coluna + i] = 3; // Tamanho do navio
    }
}

// Posiciona um navio na vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho){

    if(linha + tamanho > TAMANHO){
        printf("O navio vertical ultrapassa os limites.\n");
        return;
    }
    for(int i = 0; i < tamanho; i++){
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Posiciona um navio na diagonal principal
void PosicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO] [TAMANHO], int linha, int coluna, int tamanho){
    if(linha + tamanho > TAMANHO || coluna + tamanho > TAMANHO){
        printf("Navio da diagonal principal passa os limites.\n");
        return;
    }
    for(int i = 0; i < tamanho; i++){
    tabuleiro[linha + i][coluna + i] = 3;
    }
}

// Posiciona o navio na diagonal secundária
void PosicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO] [TAMANHO], int linha, int coluna, int tamanho){
if(linha + tamanho > TAMANHO|| coluna - tamanho + 1 < 0){
    printf("Navio da diagonal secundária ultrapassa os limites.\n");
    return;
}
 for(int i = 0; i < tamanho; i++){
    tabuleiro[linha + i][coluna - i] = 3;
}
}

// Posiciona uma forma de cone
void PosicionaCone(int tabuleiro[TAMANHO] [TAMANHO], int linha, int coluna, int altura){
    if(linha + altura > TAMANHO || coluna - altura + 1 < 0 || coluna + altura - 1 >= TAMANHO){
        printf("Erro\n");
        return;
    }
 // 
    
for(int i = 0; i < altura; i++){
    int inicio = coluna - i; 
    int base = 2 * i + 1;



for(int j = 0; j < base ; j++){
    int x = linha +i;
    int y = inicio +j;

    if(x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO){
   tabuleiro[x][y] =1;
    }
}
  }
  }

  // Posiciona uma forma de cruz
  void PosicionaCruz (int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho){

    if(coluna - tamanho < 0|| coluna + tamanho >= TAMANHO || linha - tamanho < 0 || linha + tamanho >= TAMANHO){
        printf("ERRO\n");
        return;
    }

    for(int i = -tamanho; i <= tamanho; i++){
        tabuleiro[linha][coluna + i] = 1; // Áreas atingidas
        tabuleiro[linha + i][coluna] = 1;
         }


    }

// Posiciona uma forma de octaedro
  void posicionaOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int altura){

if(linha - altura < 0 || linha + altura >= TAMANHO || coluna - altura < 0 || coluna + altura >= TAMANHO){
    printf("Erro: O octaedro ultrapassa os limites do tabuleiro.\n");
    return;
}

// Triângulo apontado para cima
for(int i = 0; i < altura; i++){
    int base = 2 * i + 1;
    int inicio = coluna - i;

    for(int j = 0; j < base; j++){
        int x = linha - i;
        int y = inicio + j;

        if(x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO){
            tabuleiro[x][y] = 1;
        }
    }

}

// Triângulo apontado para baixo
for (int i = 0; i < altura; i++) {
    int base = 2 * i + 1;
    int inicio = coluna - i;

    
    for (int j = 0; j < base; j++) {
        int x = linha + i;
        int y = inicio + j;

        if(x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO){
            tabuleiro[x][y]=1;
        }
      }

  }
   }
int main(){

int tabuleiro[TAMANHO] [TAMANHO] = {0}; // Represta a água
int tabuleiro_diagonal[TAMANHO] [TAMANHO] = {0};
int tabuleiro_cone[TAMANHO] [TAMANHO] = {0};
int tabuleiro_cruz[TAMANHO] [TAMANHO] = {0};
int tabuleiro_octaedro[TAMANHO] [TAMANHO] = {0};

printf("**Jogo De Batalha Naval**\n");
posicionarNavioHorizontal(tabuleiro, 2, 4, 3); // Posição inicial e o tamanho do navio
posicionarNavioVertical(tabuleiro, 4, 4, 3);   // Posição inicial e o tamanho do navio
PosicionarNavioDiagonalPrincipal(tabuleiro_diagonal, 0, 0, 3); // Posição inicial e o tamanho do navio
PosicionarNavioDiagonalSecundaria(tabuleiro_diagonal,2, 7, 3); // Posição inicial e o tamanho do navio
PosicionaCruz(tabuleiro_cruz, 3, 3, 1);

PosicionaCone(tabuleiro_cone, 2, 2, 3);

posicionaOctaedro(tabuleiro_octaedro, 3, 5, 3);

imprimirTabuleiro(tabuleiro, "Tabuleiro horizontal e vertical");
imprimirTabuleiro(tabuleiro_diagonal, "Tabuleiro Diagonais");
imprimirTabuleiro(tabuleiro_cone, "Área atingida");
imprimirTabuleiro(tabuleiro_cruz, "Área atingida");
imprimirTabuleiro(tabuleiro_octaedro, "Área atingida");



return 0;



}