#include<stdio.h>
#include <locale.h>
#include "ListaDinDuplamenteEncadeada.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    TLista* vlista;
    vlista = cria_lista(10);
    printf("\nTamanho da lista: %i",tamanho(vlista));
    printf("\n\nInsercao de B: %i", inserir(vlista, 'B'));
    imprimir(vlista);
    printf("\n");
    printf("\n\nInsercao de H: %i", inserir(vlista, 'H'));
    imprimir(vlista);
    printf("\n");
    printf("\n\nInsercao de A: %i", inserir(vlista, 'A'));
    imprimir(vlista);
    printf("\n");
    printf("\n\nInsercao de I: %i", inserir(vlista, 'I'));
    imprimir(vlista);
    printf("\n");
    printf("\n\nInsercao de Z: %i", inserir(vlista, 'Z'));
    imprimir(vlista);
    printf("\n");


    printf("\n\nRemocao de A: %i", remover(vlista, 'A'));
    imprimir(vlista);
    printf("\n\nRemocao de I: %i", remover(vlista, 'I'));
    imprimir(vlista);
    printf("\n\nRemocao de H: %i", remover(vlista, 'H'));
    imprimir(vlista);
    printf("\n\nRemocao de Z: %i", remover(vlista, 'Z'));
    imprimir(vlista);
    printf("\n\nRemocao de B: %i", remover(vlista, 'B'));
    imprimir(vlista);

    // printf("\n\nInser��o de F: %i", inserir(vlista, 'F'));
    // printf("\n\nTamanho da lista: %i",tamanho(vlista));
    // imprimir(vlista);
    // printf("\n\nInser��o de D: %i", inserir(vlista, 'D'));
    // imprimir(vlista);
    // printf("\n\nInser��o de A: %i", inserir(vlista, 'A'));
    // imprimir(vlista);
    // printf("\n\nRemo��o de F: %i", remover(vlista, 'F'));
    // imprimir(vlista);
    // printf("\n\nInser��o de C: %i", inserir(vlista, 'C'));
    // imprimir(vlista);
    // printf("\n\nInser��o de R: %i", inserir(vlista, 'R'));

    // imprimir(vlista);
    // printf("\n\nInser��o de E: %i", inserir(vlista, 'E'));
    // imprimir(vlista);
    // char elemento;
    // printf("\n\nAcesso da 1� pos retorno: %i - elemento: ", acessar(vlista, 1, &elemento));
    // printf(" %c", elemento);
    // printf("\n\nAcesso da 3� pos retorno: %i - elemento: ", acessar(vlista, 3, &elemento));
    // printf(" %c", elemento);
    // printf("\n\nAcesso da 8� pos retorno: %i - elemento: ", acessar(vlista, 8, &elemento));
    // printf(" %c", elemento);
    // printf("\n\nAcesso da 2� pos retorno: %i - elemento: ", acessar(vlista, 2, &elemento));
    // printf(" %c", elemento);
    // printf("\n\nAcesso da 5� pos retorno: %i - elemento: ", acessar(vlista, 5, &elemento));
    // printf(" %c", elemento);
    // int pos;
    // printf("\n\nDevolve a posicao de 'B': %i - pos: ", devolver(vlista, 'B', &pos));
    // printf(" %i", pos);
    // printf("\n\nDevolve a posicao de 'R': %i - pos: ", devolver(vlista, 'R', &pos));
    // printf(" %i", pos);
    // printf("\n\nDevolve a posicao de 'K': %i - pos: ", devolver(vlista, 'K', &pos));
    // printf(" %i", pos);
    // printf("\n\nDevolve a posicao de 'D': %i - pos: ", devolver(vlista, 'D', &pos));
    // printf(" %i", pos);
return 0;
}
