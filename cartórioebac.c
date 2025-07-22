#include <stdio.h>     // Comunicação com o usuário
#include <stdlib.h>    // Alocação de memória e funções como system()
#include <locale.h>    // Suporte a idiomas
#include <string.h>    // Manipulação de strings

int registrar()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Nome do arquivo será o CPF

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
        printf("Não foi possível abrir o arquivo. Usuário não localizado.\n");
        system("pause");
        return 1;
    }

    printf("\nEssas são as informações do usuário:\n");
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
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Erro ao tentar deletar. Arquivo não encontrado.\n");
    }

    system("pause");
    return 0;
}

int sair()
{
    printf("Saindo do programa...\n");
    system("pause");
    exit(0); // Termina a execução do programa
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    while (1)
    {
        system("cls"); // Limpa tela (Windows)
        printf("### Cartório da EBACC ###\n\n");
        printf("Escolha a opção desejada:\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t0 - Sair\n\n");
        printf("Digite a opção: ");
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
            printf("Essa opção não está disponível.\n");
            system("pause");
            break;
        }
    }

    return 0;
}

