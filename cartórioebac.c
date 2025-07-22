#include <stdio.h>     // Comunica��o com o usu�rio
#include <stdlib.h>    // Aloca��o de mem�ria e fun��es como system()
#include <locale.h>    // Suporte a idiomas
#include <string.h>    // Manipula��o de strings

int registrar()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Nome do arquivo ser� o CPF

    FILE *file = fopen(arquivo, "w"); // Abre arquivo para escrita
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fprintf(file, "%s,", cpf); // Escreve CPF

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fprintf(file, "%s,", nome); // Escreve nome

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome); // Escreve sobrenome

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    fprintf(file, "%s", cargo); // Escreve cargo

    fclose(file); // Fecha o arquivo

    printf("Registro realizado com sucesso!\n");
    system("pause");
    return 0;
}

int consultar()
{
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo. Usu�rio n�o localizado.\n");
        system("pause");
        return 1;
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }

    fclose(file);
    printf("\n\n");
    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso.\n");
    } else {
        printf("Erro ao tentar deletar. Arquivo n�o encontrado.\n");
    }

    system("pause");
    return 0;
}

int sair()
{
    printf("Saindo do programa...\n");
    system("pause");
    exit(0); // Termina a execu��o do programa
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    while (1)
    {
        system("cls"); // Limpa tela (Windows)
        printf("### Cart�rio da EBACC ###\n\n");
        printf("Escolha a op��o desejada:\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t0 - Sair\n\n");
        printf("Digite a op��o: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            registrar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            deletar();
            break;
        case 0:
            sair();
            break;
        default:
            printf("Essa op��o n�o est� dispon�vel.\n");
            system("pause");
            break;
        }
    }

    return 0;
}

