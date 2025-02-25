#include <stdio.h>

struct Candidato {
    int numero;
    char nome[50];
    int votos;
};

int votar(struct Candidato candidatos[], int totalCandidatos) {
    int voto;
    printf("Digite o numero do candidato (1 a 99): ");
    if (scanf(" %d", &voto) != 1) { // Garante que a entrada é um número válido
        printf("Entrada invalida!\n");
        while (getchar() != '\n'); // Limpa o buffer do teclado
        return 0;
    }

    for (int i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].numero == voto) {
            candidatos[i].votos++;
            printf("Voto computado para %s!\n", candidatos[i].nome);
            return 1;
        }
    }

    printf("Numero de candidato invalido!\n");
    return 0;
}

void apurarVotos(struct Candidato candidatos[], int totalCandidatos) {
    printf("\nResultado da apuracao de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        printf("%s (numero %d): %d votos\n", candidatos[i].nome, candidatos[i].numero, candidatos[i].votos);
    }
}

void percentualVotos(struct Candidato candidatos[], int totalCandidatos, int totalVotos) {
    if (totalVotos == 0) {
        printf("Nenhum voto computado ainda.\n");
        return;
    }
    printf("\nPercentual de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        float percentual = ((float)candidatos[i].votos / totalVotos) * 100;
        printf("%s: %.2f%% dos votos\n", candidatos[i].nome, percentual);
    }
}

int main() {
    struct Candidato candidatos[3] = {
        {10, "Joao da Padaria", 0}, 
        {20, "Maria da Farmacia", 0}, 
        {30, "Ze do Gas", 0}
    };

    int opcao, totalVotos = 0, totalCandidatos = 3;

    do {
        printf("\nMenu de opcoes:\n");
        printf("1. Votar\n");
        printf("2. Apurar\n");
        printf("3. Emitir percentual de votos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf(" %d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

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