/*
Criado e editado por: Marcos Diógenes;

Referências:
https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
https://stackoverflow.com/questions/2795382/enter-custom-file-name-to-be-read
https://www.geeksforgeeks.org/c-program-print-contents-file/
*/
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(void)
{
    FILE *fptr;
    char nome_arquivo[100], c; //Nome do arquivo a ser lido
    struct dirent *entrada_diretorio;  // Ponteiro para entrada entrada_diretorio diretório
    // opendir() retorna poteiros do tipo DIR
    DIR *diretorio = opendir(".");
  
    if (diretorio == NULL)  // opendir retorna NULL caso não consiga abrir o diretório
    {
        printf("Não foi possível abrir o diretório" );
        return 0;
    }

    while ((entrada_diretorio = readdir(diretorio)) != NULL)
            printf("%s\n", entrada_diretorio->d_name);
  
    closedir(diretorio);    

    printf("informar o nome do arquivo: ");
    scanf("%s", nome_arquivo);


    // Ler arquivo
    fptr = fopen(nome_arquivo, "r");
    if (fptr == NULL)
    {
        printf("Erro 404 - Não foi possível abrir o arquivo \n");
        exit(0);
    }
  
    // Ler conteúdos do arquivo
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
  
    fclose(fptr);

    return 0;
}
