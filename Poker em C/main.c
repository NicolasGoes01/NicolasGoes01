#include <stdio.h>
#include <stdlib.h>

struct jogadores_
{
    char nome[30];
    int valor;
    int flag_rodada;
};

typedef struct jogadores_ JOGADORES;

int main()
{
    JOGADORES *jogadores;
    int inicial;
    int numero_jogadores;
    int opcao;
    int aposta_inicial;
    int aposta_total;

    printf("Quantos jogadores vao jogar?\n");
    scanf("%d", &numero_jogadores);

    jogadores = (JOGADORES *) malloc(numero_jogadores * sizeof(JOGADORES));

    for (int i = 0; i < numero_jogadores; i++)
    {
        printf("Nome jogador %d: ", i + 1);
        scanf(" %[^(\n|\r)]%*c", jogadores[i].nome);
    }

    printf("Valor inicial dos jogadores: ");
    scanf("%d", &inicial);

    printf("Valor da aposta obrigatoria: ");
    scanf("%d", &aposta_inicial);

    for (int i = 0; i < numero_jogadores; i++)
    {
        jogadores[i].valor = inicial;
    }

    do
    {
        aposta_total = 0;

        for (int i = 0; i < numero_jogadores; i++)
        {
            printf("%s: %d\n", jogadores[i].nome, jogadores[i].valor);
            jogadores[i].flag_rodada = 1;
        }

        printf("\n[1] Tirar dinheiro\n[2] Colocar dinheiro\n[3] Iniciar rodada\n[0] Fechar programa\n");
        scanf("%d", &opcao);

        //Tirar dinheiro
        if (opcao == 1)
        {
            int op;
            int valor;

            printf("Tirar de quem?\n");
            for (int i = 0; i < numero_jogadores; i++)
            {
                printf("[%d] %s\n", i, jogadores[i].nome);
            }
            scanf("%d", &op);

            printf("Quanto?\n");
            scanf("%d", &valor);

            for (int i = 0; i < numero_jogadores; i++)
            {
                if (op == i)
                {
                    jogadores[i].valor -= valor;
                }
            }
        }

        //Colocar dinheiro
        else if (opcao == 2)
        {
            int op;
            int valor;

            printf("Colocar pra quem?\n");
            for (int i = 0; i < numero_jogadores; i++)
            {
                printf("[%d] %s\n", i, jogadores[i].nome);
            }
            scanf("%d", &op);

            printf("Quanto?\n");
            scanf("%d", &valor);

            for (int i = 0; i < numero_jogadores; i++)
            {
                if (op == i)
                {
                    jogadores[i].valor += valor;
                }
            }
        }

        //Iniciar rodada
        else if (opcao == 3)
        {
            int op_foram;
            int obrigatoria;

            //Apostas iniciais
            do
            {
                printf("Quem nao foi?\n");
                for (int i = 0; i < numero_jogadores; i++)
                {
                    if (jogadores[i].flag_rodada == 1)
                    {
                        printf("[%d] %s\n", i + 1, jogadores[i].nome);
                    }
                }
                printf("[%d] Todos foram\n", numero_jogadores + 1);
                scanf("%d", &op_foram);
                op_foram--;

                if (op_foram != numero_jogadores)
                {
                    jogadores[op_foram].flag_rodada = 0;

                    printf("%s era aposta:\n\n[1] Nada\n[2] Obrigatoria\n[3] Parcial\n", jogadores[op_foram].nome);
                    scanf("%d", &obrigatoria);

                    if (obrigatoria == 2)
                    {
                        jogadores[op_foram].valor -= aposta_inicial;
                        aposta_total += aposta_inicial;
                    }
                    else if (obrigatoria == 3)
                    {
                        jogadores[op_foram].valor -= (aposta_inicial / 2);
                        aposta_total += (aposta_inicial / 2);
                    }
                }
            } while (op_foram != numero_jogadores);

            //Para os que foram
            for (int i = 0; i < numero_jogadores; i++)
            {
                if (jogadores[i].flag_rodada == 1)
                {
                    jogadores[i].valor -= aposta_inicial;
                    aposta_total += aposta_inicial;
                }
            }

            int opcao2;
            do
            {
                printf("[1] Aumentar aposta\n[0] Fim da rodada\n");
                scanf("%d", &opcao2);

                //Aumentar aposta
                if (opcao2 == 1)
                {
                    int aumentar;
                    printf("Valor aumentado: ");
                    scanf("%d", &aumentar);

                    int nao_aceitou;
                    do
                    {
                        printf("Quem nao foi?\n\n");
                        for (int i = 0; i < numero_jogadores; i++)
                        {
                            if (jogadores[i].flag_rodada == 1)
                            {
                                printf("[%d] %s\n", i + 1, jogadores[i].nome);
                            }
                        }
                        printf("[%d] Todos foram\n", numero_jogadores + 1);
                        scanf("%d", &nao_aceitou);
                        nao_aceitou--;

                        if (nao_aceitou != numero_jogadores)
                        {
                            jogadores[nao_aceitou].flag_rodada = 0;
                        }
                    } while(nao_aceitou != numero_jogadores);

                    //Para os que foram
                    for (int i = 0; i < numero_jogadores; i++)
                    {
                        if (jogadores[i].flag_rodada == 1)
                        {
                            jogadores[i].valor -= aumentar;
                            aposta_total += aumentar;
                        }
                    }
                }
            } while(opcao2 != 0);

            //Vencedor
            int vencedor;
            printf("Vencedor da rodada:\n\n");
            for (int i = 0; i < numero_jogadores; i++)
            {
                if (jogadores[i].flag_rodada == 1)
                {
                    printf("[%d] %s\n", i + 1, jogadores[i].nome);
                }
            }
            printf("[%d] Empate\n", numero_jogadores + 1);
            scanf("%d", &vencedor);
            vencedor--;

            if (vencedor != numero_jogadores)
            {
                jogadores[vencedor].valor += aposta_total;
            }

            //Empate
            else
            {
                int empate;
                int valor_dividido;
                int qtd_empates = 0;

                do
                {
                    printf("Quem empatou?\n");
                    for (int i = 0; i < numero_jogadores; i++)
                    {
                        if (jogadores[i].flag_rodada == 1)
                        {
                            printf("[%d] %s\n", i + 1, jogadores[i].nome);
                        }
                    }
                    printf("[%d] Sem mais empates\n", numero_jogadores + 1);
                    scanf("%d", &empate);
                    empate--;
                    qtd_empates++;

                    if (empate != numero_jogadores)
                    {
                        jogadores[empate].flag_rodada = 2;
                        valor_dividido = aposta_total / qtd_empates;
                    }
                } while(empate != numero_jogadores);

                for (int i = 0; i < numero_jogadores; i++)
                {
                    if (jogadores[i].flag_rodada == 2)
                    {
                        jogadores[i].valor += valor_dividido;
                    }
                }
            }
        }

        //Apagar perdedor
        for (int i = 0; i < numero_jogadores; i++)
        {
            if (jogadores[i].valor == 0)
            {
                for (int j = i; j < numero_jogadores - 1; j++)
                {
                    jogadores[j] = jogadores[j + 1];
                }
                numero_jogadores--;
                jogadores = (JOGADORES *) realloc(jogadores, numero_jogadores * sizeof(JOGADORES));
            }
        }
    } while(opcao != 0);

    free(jogadores);

    return 0;
}
