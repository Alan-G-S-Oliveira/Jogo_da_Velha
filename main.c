#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void exibeTabuleiro(char tab[TAM][TAM]);
char naCasa(char tab[TAM][TAM], char posicao[]);
int verificaJogada(char tab[TAM][TAM], char posicao[]);
char verificaVitoria(char tab[TAM][TAM]);

int main(){

    int i, j, turno = 1;
    char jogador, vitoria, posicao[4], tabuleiro[TAM][TAM];

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++)
            tabuleiro[i][j] = ' ';
    }

    while(1){

        system("cls");

        if(turno % 2 == 0)
            jogador = 'O';
        else
            jogador = 'X';

        printf("JOGADOR %c\n\n", jogador);

        exibeTabuleiro(tabuleiro);
        printf("\n\n");

        printf("Digite a posicao: ");
        fgets(posicao, 4, stdin);
        fflush(stdin);

        while(verificaJogada(tabuleiro, posicao)){

            system("cls");
            printf("JOGADOR %c\n\n", jogador);

            exibeTabuleiro(tabuleiro);
            printf("\n\n");
            
            printf("ERRO!\n");
            if(verificaJogada(tabuleiro, posicao) == 1)
                printf("Posicao esclhida fora do tabuleiro. ");
            else
                printf("Posicao esolhida esta ocupada com a peca '%c'. ", naCasa(tabuleiro, posicao));
            printf("Digite novamente: ");
            fgets(posicao, 4, stdin);
            fflush(stdin);
        }

        i = posicao[0] - '1';
        j = posicao[1] - 'a';

        tabuleiro[i][j] = jogador;

        turno++;

        vitoria = verificaVitoria(tabuleiro);
        printf("%c", vitoria);
        if(vitoria != 'P')
            break;

    }

    system("cls");
    printf("Resultado final:\n\n");
    exibeTabuleiro(tabuleiro);
    printf("\n\n");

    if(vitoria != 'V')
        printf("o jogador '%c' venceu o jogo.\n\n", vitoria);
    else
        printf("A partida deu empate.\n\n");

    system("pause");
    return 0;
}

void exibeTabuleiro(char tab[TAM][TAM]){

    int i, j;

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(j != TAM - 1)
                printf(" %c |", tab[i][j]);
            else
                printf(" %c   %d", tab[i][j], i + 1);
        }
        if(i != TAM - 1)
            printf("\n---+---+---\n");
    }

    printf("\n A   B   C");

}

char naCasa(char tab[TAM][TAM], char posicao[]){

    int i, j;

    i = posicao[0] - '1';
    j = posicao[1] - 'a';

    return tab[i][j];
}

int verificaJogada(char tab[TAM][TAM], char posicao[]){

    int i, j;

    i = posicao[0] - '1';
    j = posicao[1] - 'a';

    if(i > 2 || i < 0 || j > 2 || j < 0)
        return 1;
    else if(naCasa(tab, posicao) != ' ')
        return 2;
    else
        return 0;
}

char verificaVitoria(char tab[TAM][TAM]){

    int i, j;
    char posicao[4];

    posicao[2] = '\n';
    posicao[3] = '\0';

    for(i = 0; i < TAM; i++){
        if(tab[i][0] == 'X' && tab[i][1] == 'X' && tab[i][2] == 'X')
            return 'X';
        else if(tab[0][i] == 'X' && tab[1][i] == 'X' && tab[2][i] == 'X')
            return 'X';
        else if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X')
            return 'X';
        else if(tab[2][0] == 'X' && tab[1][1] == 'X' && tab[0][2] == 'X')
            return 'X';
    }
    
    for(i = 0; i < TAM; i++){
    if(tab[i][0] == 'O' && tab[i][1] == 'O' && tab[i][2] == 'O')
        return 'O';
    else if(tab[0][i] == 'O' && tab[1][i] == 'O' && tab[2][i] == 'O')
        return 'O';
    else if(tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O')
        return 'O';
    else if(tab[2][0] == 'O' && tab[1][1] == 'O' && tab[0][2] == 'O')
        return 'O';
    }

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            posicao[0] = '1' + i;
            posicao[1] = 'a' + j;
            if(naCasa(tab, posicao) == ' ')
                return 'P';
        }
    }

    return 'V';

}
