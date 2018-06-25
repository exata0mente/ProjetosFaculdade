// Autor: Ricardo Bezerra
// Ano: 2018
// Descrição: Recebe um código ISBN e calcula o dígito verificador.

#include <stdio.h>
#include <stdlib.h>
#define T_13 12
#define T_10 9
#define U 20

void leitura_isbn(char []);
void inicializa_vetor(char [], int);
void mostra_vetor(char [], int);
void limpa_ISBN(char [], char [], int);
int digito_EAN13(char [], int);
int digito_EAN10(char [], int);

int main(void){
    
    char codISBN[T_13];
    char codTemp[U];
    int digitoVerificador = 0;
    int opc = 0;
    
    while(!opc){
        printf("Qual o padrão ISBN será digitado? [1] ISBN-10 ; [2] ISBN-13\nOpção: ");
        scanf("%d%*c", &opc);
        if(opc != 1 && opc != 2)
            opc = 0;
    }
    
    printf("Digite o código ISBN: ");
    leitura_isbn(codTemp);
    
    switch (opc){
        case 1:
            inicializa_vetor(codISBN, T_10);
            limpa_ISBN(codTemp, codISBN, T_10);
            digitoVerificador = digito_EAN10(codISBN, T_10);
            break;
        case 2:
            inicializa_vetor(codISBN, T_13);
            limpa_ISBN(codTemp, codISBN, T_13);
            digitoVerificador = digito_EAN13(codISBN, T_13);
            break;
        
    }
    if(digitoVerificador == 10)
        printf("O dígito verificador é: X\n");
    else
        printf("O dígito verificador é: %d\n", digitoVerificador);
    
    return 0;
}

void leitura_isbn(char vet[U]){
    fgets(vet, U, stdin);   
}
void limpa_ISBN(char vet_tmp[], char vet[], int tam){
/* Esta função fará a limpeza dos caracteres não aceitos digitados
 * pelo usuário. Fará também a atribuição dos T_13 primeiros números 
 * digitados, ignorando um possível dígito verificador
 */    
    
    int i = 0, j = 0;
    
    for(i = 0; i < U; i++){
        if(vet_tmp[i] >= 48 && vet_tmp[i] <= 57){
            /* Cabe um comentário nessa estrutura de decisão pois utilizamos
             * a tabela ASCII para validação do caractere digitado. O código
             * em decimal dos algarismos de 0 a 10 estão entre 48 e 57. Ver
             * tabela ASCII para referência. Esta é a forma mais prática de 
             * validar os caracteres digitados sem a necessidade de conver
             * são
             */
            vet[j] = vet_tmp[i];
            j++;
        }
        if(j == tam)
            break;
    }
}
int digito_EAN13(char vet[], int tam){
/* Parte chave do código. Aqui utilizamos a conversão implicita de 
 * char para int utilizando a tabela ASCII como referência. Para 
 * isso, utilizamos uma variável auxiliar para receber o valor char
 * convertido em int. A partir daí todas os cálculos do algoritmo
 * serão realizados sem necessidade de conversão.
 */
    int i = 0;
    int aux = 0;
    int k = 0;
    
    for(i = 0; i < tam; i++){
        aux = vet[i] - '0';
        /* O charactere '0', é representado pelo número 48 como deci-
         * mal na tabela ASCII. Assim, com uma simples regra de três,
         * conseguimos deslocar até os nove primeiro elementos da ta-
         * bela ASCII.
         * Exemplo: O '6' em decimal é 54. Logo, 54 - 48 dá 6. O mes-
         * mo se aplica a '6' - '0'.
         */
        if((i+1) % 2)   // É impar
            k = k + aux;
        else            // É par
            k = k + aux * 3;
    }
    
    k = 10 - (k % 10);
    
    if(k == 10)
        return 0;
    return k;
} 
int digito_EAN10(char vet[], int tam){
/* Parte chave do código. Aqui utilizamos a conversão implicita de 
 * char para int utilizando a tabela ASCII como referência. Para 
 * isso, utilizamos uma variável auxiliar para receber o valor char
 * convertido em int. A partir daí todas os cálculos do algoritmo
 * serão realizados sem necessidade de conversão.
 */
    int i = 0;
    int contador = 10;
    int aux = 0;
    int k = 0;
    
    for(i = 0; i < tam; i++){
        aux = vet[i] - '0';
        printf("aux = %d\n", aux);
        /* O charactere '0', é representado pelo número 48 como deci-
         * mal na tabela ASCII. Assim, com uma simples regra de três,
         * conseguimos deslocar até os nove primeiro elementos da ta-
         * bela ASCII.
         * Exemplo: O '6' em decimal é 54. Logo, 54 - 48 dá 6. O mes-
         * mo se aplica a '6' - '0'.
         */
        k = k + aux * contador;
        contador--;
    }
    printf("Somatório = %d\n", k);
    k = 11 - (k % 11);
    
    if(k == 10)
        return 40;
    return k;
} 

void inicializa_vetor(char vet[], int tam){
    int i = 0;
    
    for(i = 0; i < tam; i++)
        vet[i] = '0';
}
void mostra_vetor(char vet[], int tam){
    int i = 0;
    
    for(i = 0; i < tam; i++)
        printf("vet[%d] = %c", i, vet[i]);
}
