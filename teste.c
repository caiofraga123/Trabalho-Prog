
typedef struct{
    char tab[5][5];
} tTabuleiro;

void verficarVitoria(tTabuleiro tabuleiro);

tTabuleiro inicializaTabuleiroInicio();

tTabuleiro inicializaTabuleiroVazio();

void imprimirTabuleiro(tTabuleiro tabuleiro);

//+--------------------------------------------------------------------------------+

typedef struct{
    char nome[50];
}tJogador;

tJogador inicializaJogador();

//+--------------------------------------------------------------------------------+

typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
}tJogo;

void jogadaValida(tJogo);

//+---------------------------------------------------------------------------------+

#include <stdio.h>

tTabuleiro inicializaTabuleiroInicio();
tTabuleiro inicializaTabuleiroVazio();
void imprimirTabuleiro(tTabuleiro tabuleiro);

tJogador inicializaJogador();
tJogo inicializaJogo();

int main(){

    tTabuleiro tabuleiroInicio;
    tTabuleiro tabuleiroVazio;

   tabuleiroInicio = inicializaTabuleiroInicio();
   tabuleiroVazio = inicializaTabuleiroVazio();

   imprimirTabuleiro(tabuleiroInicio);

   printf("\n");

   imprimirTabuleiro(tabuleiroVazio);

   // Inicializa o jogo com os jogadores e tabuleiro
   tJogo jogo = inicializaJogo();

   // Chama a função que contém a lógica do jogo
   jogar(jogo);

    return 0;
}

//+---------------------------------------------------------------------------------+

void jogar(tJogo jogo){
    int jogadas = 0, posicao;
    char caracter;

}

//Função que inicializa o jogo
tJogo inicializaJogo(){
    tJogo jogo;
    
    // Inicializa o tabuleiro
    jogo.tabuleiro = inicializaTabuleiroInicio();
    jogo.tabuleiro = inicializaTabuleiroVazio();

    // Inicializa os jogadores
    printf("Jogador 1, ");
    jogo.jogador1 = inicializaJogador();

    printf("Jogador 2, ");
    jogo.jogador2 = inicializaJogador();

    return jogo;
}

// Função responsável por inicializar cada jogador
tJogador inicializaJogador(){
    tJogador jogador;

    printf("Digite o nome do jogador: ");
    fgets(jogador.nome, sizeof(jogador.nome), stdin);

    // Remove o caractere de nova linha, se presente
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';

    return jogador;
}

// Função que inicializa o tabuleiro mostrando o número de cada posição
tTabuleiro inicializaTabuleiroInicio(){

    int i = 0;
    int j = 0;
    tTabuleiro tabuleiro;
    
        //itera o tabuleiro e coloca as posicoes desejadas para serem printadas na primeira rodada

        for(i=0;i<=4;i++){

            for(j=0;j<=4;j++){
                if(i%2!= 0){
                    tabuleiro.tab[i][j] = '-';
                }
                else if(j%2!=0){
                    tabuleiro.tab[i][j] = '|';
              
                }           
        }
    }

    tabuleiro.tab[0][0] = '1';
    tabuleiro.tab[0][2] = '2';
    tabuleiro.tab[0][4] = '3';
    tabuleiro.tab[2][0] = '4';
    tabuleiro.tab[2][2] = '5';
    tabuleiro.tab[2][4] = '6';
    tabuleiro.tab[4][0] = '7';
    tabuleiro.tab[4][2] = '8';
    tabuleiro.tab[4][4] = '9';

    return tabuleiro;
}

//Função que inicializa o tabuleiro com as posições vazias
tTabuleiro inicializaTabuleiroVazio(){

    int i = 0;
    int j = 0;
    tTabuleiro tabuleiro;
    
        //itera o tabuleiro e coloca as posicoes desejadas para serem printadas na primeira rodada

        for(i=0;i<=4;i++){

            for(j=0;j<=4;j++){
                if(i%2!= 0){
                    tabuleiro.tab[i][j] = '-';
                }
                else if(j%2!=0){
                    tabuleiro.tab[i][j] = '|';
              
                }           
        }
    }

    tabuleiro.tab[0][0] = ' ';
    tabuleiro.tab[0][2] = ' ';
    tabuleiro.tab[0][4] = ' ';
    tabuleiro.tab[2][0] = ' ';
    tabuleiro.tab[2][2] = ' ';
    tabuleiro.tab[2][4] = ' ';
    tabuleiro.tab[4][0] = ' ';
    tabuleiro.tab[4][2] = ' ';
    tabuleiro.tab[4][4] = ' ';

    return tabuleiro;
}

// Função que imprime o tabuleiro após cada jogada
void imprimirTabuleiro(tTabuleiro tabuleiro){

    int i = 0;
    int j = 0;

    for(i=0;i<=4;i++){

        for(j=0;j<=4;j++){

            printf("%c",tabuleiro.tab[i][j]);
        }
        printf("\n");
    }
}