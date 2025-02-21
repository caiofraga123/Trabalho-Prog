
typedef struct{
    char tab[4][4];
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

void incializaJogo(tJogo jogo);

void jogar(tJogo jogo);

void jogadaValida(tJogo);

//+---------------------------------------------------------------------------------+

#include <stdio.h>

int main(){

    return 0;
}

tJogador inicializaJogador(){
    tJogador jogador;
    scanf("%s", jogador.nome);
    return jogador;
}
