
//Definição do tipo Tabuleiro
typedef struct{
    char tab[5][5];
} tTabuleiro;

//Definição do tipo Jogador
typedef struct{
    char nome[50];
}tJogador;

//Definição do tipo Jogo
typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
}tJogo;

//+--------------------------------------------------------------------------------+

//Declaração das funções

tJogador inicializaJogador();

int verificarVitoria(tTabuleiro tabuleiro);

tTabuleiro inicializaTabuleiroInicio();

tTabuleiro inicializaTabuleiroVazio();

void imprimirTabuleiro(tTabuleiro tabuleiro);

int atualizaTabuleiro(tTabuleiro *tabuleiro, int posicao, char caracter);

void jogar(tJogo *jogo);

void jogadaValida(tJogo);

int verificaPosicao(int posicao);

tJogo inicializaJogo();

//+---------------------------------------------------------------------------------+

#include <stdio.h>
#include <string.h>

int main(){

   // Inicializa o jogo com os jogadores e tabuleiro
   tJogo jogo = inicializaJogo();

   // Chama a função que contém a lógica do jogo
   // Passando jogo por referência. Isso será feito diversas vezes ao longo do código com jogo, tabuleiro e jogador
   jogar(&jogo);

    return 0;
}

//+---------------------------------------------------------------------------------+

//Função que realiza as jogadas do jogo
void jogar(tJogo *jogo){
    //Declaração das variáveis
    int jogadas = 0, posicao;
    char caracter = 'O';

    //Loop no qual o jogo ocorre
    while(jogadas < 9){
        printf("\n"); 

        //Imprime o tabuleiro
        imprimirTabuleiro(jogo->tabuleiro);

        printf("\n");

        //Imprime na tela o pedido para que o usuario digite a posição que ele quer marcar
        printf("Digite a posicao: ");

        //Entrada da posição desejada
        scanf("%d", &posicao);
        
        //Loop que confere se a posição é válida. Caso ela não seja válida, o usuário terá que digitar outra posição do tabuleiro
        while (verificaPosicao(posicao)){
            scanf("%d", &posicao);
        }

        //Loop que confere se é possível atualizar a posição do tabuleiro. Caso não seja possível, o usuário terá que digitar outra posição do tabuleiro
        while (atualizaTabuleiro(&jogo->tabuleiro, posicao, caracter)){
            printf("Digite a posicao: ");
            scanf("%d", &posicao);
        }

        //Incrementando jogadas
        jogadas += 1;

        //Condicional para determinar a vez de cada jogador
        if (!(jogadas % 2)){
            caracter = 'O';
        } else {
            caracter = 'X';
        }

        //Condicionais para verificar se algum dos dois jogadores venceu a partida
        if (verificarVitoria(jogo->tabuleiro) == 1) {
            //Funcionalidade extra: imprimir o nome do jogador vencedor na tela. Nesse caso, o nome do jogador 1 é impresso
            printf("\n");
            printf("O jogador %s venceu\n", jogo->jogador1.nome);
            printf("\n");
            //Fim do loop e depois o programa chegará ao fim da execução
            break;
        } else if (verificarVitoria(jogo->tabuleiro) == 2) {
            //Funcionalidade extra: imprimir o nome do jogador vencedor na tela. Nesse caso, o nome do jogador 2 é impresso
            printf("\n");
            printf("O jogador %s venceu\n", jogo->jogador2.nome);
            printf("\n");
            //Fim do loop e depois o programa chegará ao fim da execução
            break;
        }

    }

    //Impressão de tabuleiro
    imprimirTabuleiro(jogo->tabuleiro);

    //Condicional que averigua se houve vitória depois do loop das jogadas ter ocorrido
    //Caso haja vitória, será impressa a mensagem de que o jogo terminou empatado e depois o programa chegará ao fim da execução
    if (!verificarVitoria(jogo->tabuleiro)){
        printf("\n");
        printf("O jogo terminou empatado");
        printf("\n");
    }

}

//Função que inicializa o jogo
tJogo inicializaJogo(){
    //Declaração da variável
    tJogo jogo;
    
    // Inicializa o tabuleiro com os números nas casas
    jogo.tabuleiro = inicializaTabuleiroInicio();

    printf("Estas sao as posicoes do tabuleiro");
    printf("\n");

    //Imprime o tabuleiro
    imprimirTabuleiro(jogo.tabuleiro);
    printf("\n");

    //Inicializa o tabuleiro vazio
    jogo.tabuleiro = inicializaTabuleiroVazio();

    // Inicializa o jogador 1
    printf("Jogador 1, ");
    jogo.jogador1 = inicializaJogador();

    //Inicializa o jogador 2
    printf("Jogador 2, ");
    jogo.jogador2 = inicializaJogador();

    //Retorna o jogo inicializado
    return jogo;
}

// Função responsável por inicializar cada jogador
tJogador inicializaJogador(){
    //Declaração da variável
    tJogador jogador;

    //Entrada do nome do jogador
    printf("Digite o nome do jogador: ");
    scanf("%s", jogador.nome);

    //Retorna o jogador
    return jogador;
}

// Função que inicializa o tabuleiro mostrando o número de cada posição
tTabuleiro inicializaTabuleiroInicio(){

    //Declaração de variáveis
    int i = 0;
    int j = 0;
    tTabuleiro tabuleiro;
    
        //Loop preenche o tabuleiro com suas marcações
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

    //Referencia as posições a serem digitadas nas casas do tabuleiro para serem impressas na primeira rodada
    tabuleiro.tab[0][0] = '1';
    tabuleiro.tab[0][2] = '2';
    tabuleiro.tab[0][4] = '3';
    tabuleiro.tab[2][0] = '4';
    tabuleiro.tab[2][2] = '5';
    tabuleiro.tab[2][4] = '6';
    tabuleiro.tab[4][0] = '7';
    tabuleiro.tab[4][2] = '8';
    tabuleiro.tab[4][4] = '9';

    //Retorna o tabuleiro com as casas preenchidas
    return tabuleiro;
}

// Função que atualiza o tabuleiro com a posição marcada
int atualizaTabuleiro(tTabuleiro *tabuleiro, int posicao, char caracter){

    //Declaração de variáveis
    int i = 0;
    int j = 0;
    
    //Condicionais que colocam em i e em j o valor que faz com que a casa do tabuleiro em tabuleiro[i][j] seja igual a casa da posição
    if (posicao == 1){
        i = 0;
        j = 0;
    } else if (posicao == 2){
        i = 0;
        j = 2;
    } else if (posicao == 3){
        i = 0;
        j = 4;
    } else if (posicao == 4){
        i = 2;
        j = 0;
    } else if (posicao == 5){
        i = 2;
        j = 2;
    } else if (posicao == 6){
        i = 2;
        j = 4;
    } else if (posicao == 7){
        i = 4;
        j = 0;
    } else if (posicao == 8){
        i = 4;
        j = 2;
    } else if (posicao == 9){
        i = 4;
        j = 4;
    }

    // Verifica se a posição está vazia. Caso ela esteja, a função retorna 0. Caso ela não esteja, a função retorna 1.
    if (tabuleiro->tab[i][j] == ' ') {
        tabuleiro->tab[i][j] = caracter;
        return 0;
    } else {
        printf("Posicao ja ocupada. \n");
        return 1;
    }
}

//Função que inicializa o tabuleiro com as posições vazias
tTabuleiro inicializaTabuleiroVazio(){

    //Declaração das variáveis
    int i = 0;
    int j = 0;
    tTabuleiro tabuleiro;
    
        //Loop preenche o tabuleiro com suas marcações
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

    //Referencia as casas do tabuleiro com o caracter vazio
    tabuleiro.tab[0][0] = ' ';
    tabuleiro.tab[0][2] = ' ';
    tabuleiro.tab[0][4] = ' ';
    tabuleiro.tab[2][0] = ' ';
    tabuleiro.tab[2][2] = ' ';
    tabuleiro.tab[2][4] = ' ';
    tabuleiro.tab[4][0] = ' ';
    tabuleiro.tab[4][2] = ' ';
    tabuleiro.tab[4][4] = ' ';

    //Retorna o tabuleiro com as casas vazias
    return tabuleiro;
}

// Função que imprime o tabuleiro após cada jogada
void imprimirTabuleiro(tTabuleiro tabuleiro){

    //Declaração de variáveis
    int i = 0;
    int j = 0;

    //Loop que imprime todas as casas do tabuleiro
    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            printf("%c",tabuleiro.tab[i][j]);
        }
        printf("\n");
    }
}

//Função que verifica se a posição digitada é válida
int verificaPosicao(int posicao){
    //Condicional que averigua se o número está entre 1 e 9. Caso esteja, a função retorna 0. Caso não esteja, a função retorna 1
    if (!(posicao >= 1 && posicao <= 9)){
        printf ("Posicao invalida, digite novamente: ");
        return 1;
    } else {
        return 0;
    }
}

//Função que verifica se algum dos jogadores preencheu três casas em sequência(seja na vertical, seja na horizontal ou seja na diagonal)
//Caso 'O' seja repetido 3 vezes nos sentidos já referenciados, a função retorna 1
//Caso 'X' seja repetido 3 vezes nos sentidos já referenciados, a função retorna 2
int verificarVitoria(tTabuleiro tabuleiro){

    //Loop que verifica se há 3 caracteres iguais('X' ou 'O') em sequência, tanto no sentido vertical quanto no sentido horizontal
    for (int k = 0; k < 5; k++){
        if (tabuleiro.tab[k][0] == 'O' && tabuleiro.tab[k][2] == tabuleiro.tab[k][0] && tabuleiro.tab[k][4] == tabuleiro.tab[k][0]){
            return 1;
        } else if (tabuleiro.tab[0][k] == 'O' && tabuleiro.tab[2][k] == tabuleiro.tab[0][k] && tabuleiro.tab[4][k] == tabuleiro.tab[0][k]){
            return 1;
        }

        if (tabuleiro.tab[k][0] == 'X' && tabuleiro.tab[k][2] == tabuleiro.tab[k][0] && tabuleiro.tab[k][4] == tabuleiro.tab[k][0]){
            return 2;
        } else if (tabuleiro.tab[0][k] == 'X' && tabuleiro.tab[2][k] == tabuleiro.tab[0][k] && tabuleiro.tab[4][k] == tabuleiro.tab[0][k]){
            return 2;
        }
    }

    //Dois condicionais para averiguar se há 3 caracteres iguais('X' ou 'O') em sequência, dessa vez, nas diagonais
    if (tabuleiro.tab[0][0] == 'O' && tabuleiro.tab[2][2] == tabuleiro.tab[0][0] && tabuleiro.tab[4][4] == tabuleiro.tab[0][0]){
        return 1;
    } else if (tabuleiro.tab[0][4] == 'O' && tabuleiro.tab[2][2] == tabuleiro.tab[0][4] && tabuleiro.tab[4][0] == tabuleiro.tab[0][4]){
        return 1;
    }

    if (tabuleiro.tab[0][0] == 'X' && tabuleiro.tab[2][2] == tabuleiro.tab[0][0] && tabuleiro.tab[4][4] == tabuleiro.tab[0][0]){
        return 2;
    } else if (tabuleiro.tab[0][4] == 'X' && tabuleiro.tab[2][2] == tabuleiro.tab[0][4] && tabuleiro.tab[4][0] == tabuleiro.tab[0][4]){
        return 2;
    }

    //Caso nenhuma das condições seja verdade, a função retorna 0
    return 0;
}