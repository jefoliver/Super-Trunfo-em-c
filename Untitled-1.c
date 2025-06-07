
#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 10

struct Carta {
    char nome[Brasil];
    int populacao;       212 // em milhões
    float area;         8,5  // em km²
    float 3 trilhoes pib_per_capita; 
    float idh;
    char capital[Brasilia];
};
void cadastrarCarta(struct Carta *carta) {
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", carta->nome);
    printf("População (em milhões): ");
    scanf("%d", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    printf("PIB per capita: ");
    scanf("%f", &carta->pib_per_capita);
    printf("IDH: ");
    scanf("%f", &carta->idh);
    printf("Capital: ");
    scanf(" %[^\n]", carta->capital);
}

void exibirCarta(struct Carta carta) {
    printf("\n--- Carta do País ---\n");
    printf("Nome: %s\n", carta.nome);
    printf("População: %d milhões\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("IDH: %.2f\n", carta.idh);
    printf("Capital: %s\n", carta.capital);
}

void compararCartas(struct Carta c1, struct Carta c2) {
    printf("\nComparando %s e %s\n", c1.nome, c2.nome);
    
    if (c1.pib_per_capita > c2.pib_per_capita) {
        printf("%s vence no PIB per capita!\n", c1.nome);
    } else if (c2.pib_per_capita > c1.pib_per_capita) {
        printf("%s vence no PIB per capita!\n", c2.nome);
    } else {
        printf("Empate no PIB per capita!\n");
    }
}
int main() {
    struct Carta cartas[MAX_CARTAS];
    int total = 0, opcao;

    do {
        printf("\n1 - Cadastrar Carta\n2 - Exibir Cartas\n3 - Comparar Cartas\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total < MAX_CARTAS) {
                    cadastrarCarta(&cartas[total]);
                    total++;
                } else {
                    printf("Limite de cartas atingido.\n");
                }
                break;
            case 2:
                for (int i = 0; i < total; i++) {
                    exibirCarta(cartas[i]);
                }
                break;
            case 3:
                if (total >= 2) {
                    int i1, i2;
                    printf("Digite os índices das duas cartas (0 a %d): ", total - 1);
                    scanf("%d %d", &i1, &i2);
                    if (i1 >= 0 && i2 >= 0 && i1 < total && i2 < total) {
                        compararCartas(cartas[i1], cartas[i2]);
                    } else {
                        printf("Índices inválidos.\n");
                    }
                } else {
                    printf("Cadastre pelo menos 2 cartas para comparar.\n");
                }
                break;
        }
    } while (opcao != 0);

    return 0;
}
