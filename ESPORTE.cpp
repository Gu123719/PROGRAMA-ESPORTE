#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REGISTROS 100

typedef struct {
    int id;
    char nome[50];
    int idade;
    char esporte[30];
} Registro;

Registro registros[MAX_REGISTROS];
int totalRegistros = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void CADASTRAR() {
    if (totalRegistros >= MAX_REGISTROS) {
        printf("LIMITE DE REGISTROS EXCEDIDO!\n");
        return;
    }

    Registro novo;
    novo.id = totalRegistros + 1;

    printf("DIGITE O SEU NOME: \n");
    limparBuffer(); 
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("DIGITE A SUA IDADE: \n");
    while (scanf("%d", &novo.idade) != 1 || novo.idade <= 0) {
        printf("IDADE INVALIDA, POR FAVOR TENTE OUTRA IDADE: \n");
        limparBuffer();
    }

    printf("DIGITE UM ESPORTE FAVORITO: \n");
    limparBuffer(); 
    fgets(novo.esporte, sizeof(novo.esporte), stdin);
    novo.esporte[strcspn(novo.esporte, "\n")] = '\0'; 

    registros[totalRegistros++] = novo;
    printf("PARABENS, CADASTRO VALIDADO COM SUCESSO!!!\n");
}

void CONSULTAR() {
    if (totalRegistros == 0) {
        printf("NENHUM REGISTRO ENCONTRADO!\n");
        return;
    }

    printf("=== CONSULTA DOS REGISTROS ===\n");
    for (int i = 0; i < totalRegistros; i++) {
        printf("ID: %d, Nome: %s, Idade: %d, Esporte: %s\n",
               registros[i].id, registros[i].nome, registros[i].idade, registros[i].esporte);
    }
}

void GERAR_RELATORIO() {
    if (totalRegistros == 0) {
        printf("NENHUM REGISTRO CADASTRADO!\n");
        return;
    }

    printf("=== RELATORIO DE ESPORTES ===\n");
    for (int i = 0; i < totalRegistros; i++) {
        printf("Esporte: %s, Nome do Atleta: %s\n", registros[i].esporte, registros[i].nome);
    }
}

void EXCLUIR() {
    if (totalRegistros == 0) {
        printf("NENHUM REGISTRO A SER APAGADO!\n");
        return;
    }

    int id;
    printf("DIGITE O ID A SER APAGADO: \n");
    while (scanf("%d", &id) != 1) {
        printf("ENTRADA ERRADA, POR FAVOR DIGITE UM NUMERO CORRETO\n: ");
        limparBuffer();
    }

    int encontrado = 0;
    for (int i = 0; i < totalRegistros; i++) {
        if (registros[i].id == id) {
            encontrado = 1;
            for (int j = i; j < totalRegistros - 1; j++) {
                registros[j] = registros[j + 1];
            }
            totalRegistros--;
            printf("REGISTRO EXCLUIDO!!!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("REGISTRO COM ID %d NAO ENCONTRADO.\n", id);
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 CADASTRO\n");
        printf("2 CONSULTA\n");
        printf("3 GERAR_RELATORIO\n");
        printf("4 EXCLUIR\n");
        printf("5 SAIR\n");
        printf("ESCOLHA UMA OPCAO: ");
        while (scanf("%d", &opcao) != 1) {
            printf("ENTRADA INVALIDA, POR FAVOR DIGITE UM NUMERO VALIDO: \n");
            limparBuffer();
        }

        switch (opcao) {
            case 1:
                CADASTRAR();
                break;
            case 2:
                CONSULTAR();
                break;
            case 3:
                GERAR_RELATORIO();
                break;
            case 4:
                EXCLUIR();
                break;
            case 5:
                printf("Encerrando o programa!!!\n");
                break;
            default:
                printf("OPCAO INVALIDA, TENTE NOVAMENTE.\n");
        }
    } while (opcao != 5);

    return 0;
}
