#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Copia o CPF como nome do arquivo
    strcat(arquivo, ".txt"); // Adiciona extens�o .txt

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    // Grava todos os dados de uma vez no arquivo
    FILE *file = fopen(arquivo, "w");
    if (file == NULL)
    {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fprintf(file, "%s,%s,%s,%s\n", cpf, nome, sobrenome, cargo);
    fclose(file);

    printf("Cadastro realizado com sucesso!\n");
    system("pause");
    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    strcat(cpf, ".txt"); // Adiciona extens�o .txt

    FILE *file = fopen(cpf, "r");
    if (file == NULL)
    {
        printf("N�o localizado!\n");
        system("pause");
        return 1;
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL)
    {
        printf("%s", conteudo);
    }
    printf("\n\n");

    fclose(file);
    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do registro a ser deletado: ");
    scanf("%s", cpf);

    strcat(cpf, ".txt"); // Adiciona extens�o .txt

    if (remove(cpf) == 0)
    {
        printf("Registro deletado com sucesso!\n");
    }
    else
    {
        printf("Erro ao tentar deletar o registro!\n");
    }

    system("pause");
    return 0;
}

int closeprogram()
{
    printf("Saindo do programa...\n");
    system("pause");
    return 0;
}

int main()
{
    int opcao = 0; // Vari�vel para armazenar a op��o do menu
    int laco = 1;  // Vari�vel de controle do la�o

    setlocale(LC_ALL, "Portuguese");

    for (laco = 1; laco == 1;) // La�o para repetir o menu
    {
        printf("### Cart�rio da fam�lia LS!\n\n");
        printf(" Escolha a op��o desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t0 - Sair\n");

        scanf("%d", &opcao);
        system("cls"); // Limpa a tela

        switch (opcao)
        {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        case 0:
            closeprogram();
            laco = 0; // Sai do loop
            break;

        default:
            printf("Op��o Inv�lida\n");
            system("pause");
            break;
        }
    }

    return 0;
}

