#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 





float calcMedia( double nota1, double nota2){
    return (nota1 + nota2) / 2.0;

}

const char* situacaoAluno (float media){
    if (media >= 7.0){
        return "APROVADO";
    } else {
      return "REPROVADO";
    }
}


int main(){
    
    
     
     FILE *dadosDeEntrada = fopen("c:\\temp\\DadosEntrada.csv", "r");
     FILE *situacaoFinal = fopen("c:\\temp\\SituacaoFinal.csv",  "w");



    if (dadosDeEntrada == NULL ){
        fprintf(stderr, "ERRO AO ABRIR O ARQUIVO!\n");
        return EXIT_FAILURE;
    }


    if (situacaoFinal == NULL ){
        fprintf(stderr, "ERRO AO ABRIR O ARQUIVO!\n");
        return EXIT_FAILURE;
    }


    char linha[1024];
    int primeiraLinhaLeitura = 1;
    int primeiraLinhaSaida = 1;

    while (fgets(linha, sizeof(linha), dadosDeEntrada)) {

        if (primeiraLinhaLeitura == 1) {
            primeiraLinhaLeitura = 0;
            continue;
        }

        char *nome;
        char *telefone;
        char *curso;
        char *nota1_str;
        char *nota2_str;
        double nota1;
        double nota2;

        nome = strtok(linha, ",");
        telefone = strtok(NULL, ",");
        curso = strtok(NULL, ",");
        nota1_str = strtok(NULL, ",");
        nota2_str = strtok(NULL, ",");

        

        if (nome != NULL && telefone != NULL && curso != NULL && nota1_str != NULL && nota2_str != NULL) {
            nota1 = atof(nota1_str);
            nota2 = atof(nota2_str);
            float media = calcMedia(nota1, nota2);

            const char* situacao = situacaoAluno(media);   

            if (primeiraLinhaSaida == 1) {
                fprintf(situacaoFinal, "Nome,Media,Situacao\n");
                primeiraLinhaSaida = 0;
            }

            fprintf(situacaoFinal, "%s,%.2f,%s\n", nome, media, situacao);        

        }

    }


    fclose(dadosDeEntrada);
    fclose(situacaoFinal);
    printf("\nDados gravados no arquivo SituacaoFinal.csv\n");


    return 0;
}
    