// Autor: Ricardo Bezerra
// Ano: 2018
// Descrição: Recebe um código ISBN e calcula o dígito verificador.

#include <stdio.h>
#include <stdlib.h>
#define T 12
#define U 20

void leitura_isbn(char []);
void limpa_isbn(char [], char []);
int calcula_digito_verificador(char []);

int main(void){
    
    char codISBN[T];
    char codTemp[U];
    int digitoVerificador = 0;
    
    printf("Digite o código ISBN: ");
    leitura_isbn(codTemp);
    limpa_isbn(codTemp, codISBN);
    digitoVerificador = calcula_digito_verificador(codISBN);
    
    printf("O dígito verificador é: %d\n", digitoVerificador );
    
    return 0;
}

void leitura_isbn(char vet[U]){
    fgets(vet, U, stdin);   
}

void limpa_isbn(char vet_tmp[], char vet[]){
/* Esta função fará a limpeza dos caracteres não aceitos digitados
 * pelo usuário. Fará também a atribuição dos T primeiros números 
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
        if(j == T)
            break;
    }
}

int calcula_digito_verificador(char vet[T]){
/* Parte chave do código. Aqui utilizamos a conversão implicita de 
 * char para int utilizando a tabela ASCII como referência. Para 
 * isso, utilizamos uma variável auxiliar para receber o valor char
 * convertido em int. A partir daí todas os cálculos do algoritmo
 * serão realizados sem necessidade de conversão.
 */
    int i = 0;
    int aux = 0;
    int k = 0;
    
    for(i = 0; i < T; i++){
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
    
    return k;
} 