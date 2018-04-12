// Autor: Ricardo Bezerra
// Ano: 2018
// Pendências: Efetuar a conversão de char para int.

#include <stdio.h>
#include <stdlib.h>
#define T 12
#define U 20

void leitura_isbn(char []);
void limpa_isbn(char [], char []);
int calcula_digito_verificador(char []);

int main(void){
    char isbn[T];
    char isbn_tmp[U];
    int digito_ver = 0;
    
    printf("Digite o código ISBN: ");
    leitura_isbn(isbn_tmp);
    printf("isbn_tmp = %s\n", isbn_tmp);
    limpa_isbn(isbn_tmp, isbn);
    printf("isbn_tmp = %s\nisbn = %s", isbn_tmp, isbn);
    digito_ver = calcula_digito_verificador(isbn);
    
    printf("O dígito verificador é: %d\n", digito_ver);
    
    return 0;
}

void leitura_isbn(char vet[U]){
    fgets(vet, U - 1, stdin);   
}

void limpa_isbn(char vet_tmp[], char vet[]){
    
    int i = 0, j = 0;
    
    for(i = 0; i < U; i++){
        if(vet_tmp[i] >= 48 && vet_tmp[i] <= 57){
            vet[j] = vet_tmp[i];
            printf("vet[%d] = %c\n", j,vet[j]);
            j++;
            if(j == T){
                break;
            }
        }
    }
}

int calcula_digito_verificador(char vet[T]){
    
    int digito = 0;
    int digito_verificador = 0;
    int aux = 0;
    double isbn_int = 0;
    
    isbn_int = atoi(vet);
    
    printf("\nISBN convertido = %lf\n", isbn_int);
    
    for(digito = T-1; digito > 0; digito--){
        aux = isbn_int % 10; 
        printf("aux = %d\n", aux);
        isbn_int /= 10;
        printf("isbn_int = %lf\n", isbn_int);
        if(digito % 2)//É par
            digito_verificador += aux * 3;
        else // É impar
            digito_verificador += aux;
        printf("****** Digito verificador = %d ********\n", digito_verificador);
        
        digito_verificador = 10 - digito_verificador % 10;
    }
    return digito_verificador;
    
}