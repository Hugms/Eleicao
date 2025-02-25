#include <stdio.h>

struct Candidato {
    int numero;
    char nome[50];
    int votos;
};

int votar(struct candidato candidatos[], int totalCandidatos) {
    int voto;
    printf("Digite o numero do candidato (1 a 99): ");
    scanf("%d", &voto);
    int encontrado = 0;
    for (int i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].numero == voto) {
            candidatos[i].votos++;
            encontrado = 1;
            printf("Voto computado para %s!\n", candidatos[i].nome);
            return 1; // Retorna 1 para contar o voto no total
        }
    }
    if (!encontrado) {
        printf("Numero de candidato invalido!\n");
    }
    return 0;
}

void apurarVotos(struct candidato candidatos[], int totalCandidatos) {
    printf("\nResultado da apuracao de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) { // Corrigido para "i < totalCandidatos"
        printf("%s (numero %d): %d votos\n", candidatos[i].nome, candidatos[i].numero, candidatos[i].votos);
    }
}

void percentualVotos(struct candidato candidatos[], int totalCandidatos, int totalVotos) {
    if (totalVotos == 0) {
        printf("Nenhum voto computado ainda.\n");
        return;
    }
    printf("\nPercentual de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        float percentual = ((float)candidatos[i].votos / totalVotos) * 100; // Cálculo correto do percentual
        printf("%s: %.2f%% dos votos\n", candidatos[i].nome, percentual);
    }
}

int main() {
    struct candidato candidatos[3] = {{10, "Joao da Padaria", 0}, {20, "Maria da Farmacia", 0}, {30, "Ze do Gas", 0}};
    int opcao;
    int totalVotos = 0;
    int totalCandidatos = 3;

    do {
        printf("\nMenu de opcoes:\n");
        printf("1. Votar\n");
        printf("2. Apurar\n");
        printf("3. Emitir percentual de votos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                totalVotos += votar(candidatos, totalCandidatos);
                break;
            case 2:
                apurarVotos(candidatos, totalCandidatos);
                break;
            case 3:
                percentualVotos(candidatos, totalCandidatos, totalVotos);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}