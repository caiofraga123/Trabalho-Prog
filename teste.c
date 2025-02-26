
typedef struct{
    char tab[5][5];
} tTabuleiro;

int verficarVitoria(tTabuleiro tabuleiro);

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
#include <string.h>

void imprimirTabuleiro(tTabuleiro tabuleiro);
void atualizaTabuleiro(tTabuleiro *tabuleiro, int posicao, char caracter);
void jogar(tJogo *jogo);
int verificaPosicao(int posicao);


tTabuleiro inicializaTabuleiroInicio();
tTabuleiro inicializaTabuleiroVazio();
tJogador inicializaJogador();
tJogo inicializaJogo();

int main(){

   // Inicializa o jogo com os jogadores e tabuleiro
   tJogo jogo = inicializaJogo();

   // Chama a função que contém a lógica do jogo
   jogar(&jogo);

    return 0;
}

//+---------------------------------------------------------------------------------+

void jogar(tJogo *jogo){
    int jogadas = 0, posicao;
    char caracter = 'O';

    while(jogadas < 9){ 
        imprimirTabuleiro(jogo->tabuleiro);
        printf("Digite a posição: ");
        scanf("%d", &posicao);

        while (verificaPosicao(posicao)){
            scanf("%d", &posicao);
        }

        atualizaTabuleiro(&jogo->tabuleiro, posicao, caracter);
        //imprimirTabuleiro(jogo->tabuleiro);

        jogadas += 1;

        if (!(jogadas % 2)){
            caracter = 'O';
        } else {
            caracter = 'X';
        }

        if (verficarVitoria(jogo->tabuleiro) == 1) {
            printf("O jogador %s venceu", &jogo->jogador1.nome);
        }

        if (verficarVitoria(jogo->tabuleiro) == 2) {
            printf("O jogador %s venceu", &jogo->jogador2.nome);
        }

    }

    if (!verficarVitoria(jogo->tabuleiro)){
        printf("O jogo terminou empatado");
    }

}

//Função que inicializa o jogo
tJogo inicializaJogo(){
    tJogo jogo;
    
    // Inicializa o tabuleiro
    jogo.tabuleiro = inicializaTabuleiroInicio();

    imprimirTabuleiro(jogo.tabuleiro);

    printf("Estas são as posições do tabuleiro");

    printf("\n");

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
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';

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

// Função que atualiza o tabuleiro com a posição marcada
void atualizaTabuleiro(tTabuleiro *tabuleiro, int posicao, char caracter){
    int i = 2 * ((posicao - 1) / 3);
    int j = 2 * ((posicao - 1) % 3);

    // Verifica se a posição está vazia
    if (tabuleiro->tab[i][j] == ' ') {
        tabuleiro->tab[i][j] = caracter;
    } else {
        printf("Posição já ocupada.");
    }
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

int verificaPosicao(int posicao){
    if (!(posicao >= 1 && posicao <= 9)){
        printf ("Posição inválida, digite novamente");
        return 1;
    } else {
        return 0;
    }
}

int verificarVitoria(tTabuleiro tTabuleiro){

}