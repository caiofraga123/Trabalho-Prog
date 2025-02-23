
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

void incializaJogo(tJogo jogo);

void jogar(tJogo jogo);

void jogadaValida(tJogo);

//+---------------------------------------------------------------------------------+

#include <stdio.h>

int main(){

    tTabuleiro tabuleiroInicio;
    tTabuleiro tabuleiroVazio;

   tabuleiroInicio = inicializaTabuleiroInicio();
   tabuleiroVazio = inicializaTabuleiroVazio();

   imprimirTabuleiro(tabuleiroInicio);

   printf("\n");

   imprimirTabuleiro(tabuleiroVazio);

    return 0;
}

//+---------------------------------------------------------------------------------+

tJogador inicializaJogador(){
    tJogador jogador;
    scanf("%s", jogador.nome);
    return jogador;
}

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