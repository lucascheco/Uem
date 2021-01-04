#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MY_LIB1.h"


void le_pagina(int RRN, PAGINA *pag, FILE *arq_Avr_B)
{
    int byteoffset = RRN * (int)(sizeof(PAGINA)) + (int)(sizeof(CABECALHO));

    fseek(arq_Avr_B, byteoffset, SEEK_SET);

    fread(pag, sizeof(PAGINA), 1, arq_Avr_B);
}

void escreve_pagina(int RRN, PAGINA *pag, FILE *arq_Avr_B)
{
    int byteoffset = RRN * (int)(sizeof(PAGINA)) + (int)(sizeof(CABECALHO));
    fseek(arq_Avr_B, byteoffset, SEEK_SET);

    fwrite(pag, sizeof(PAGINA), 1, arq_Avr_B);
}

int RRN_novapag(FILE *arq_Avr_B)
{
    int tam_pag = (int)sizeof(PAGINA);
    int tam_cab = (int)sizeof(CABECALHO);
    int byteoff;

    fseek(arq_Avr_B, 0, SEEK_END);
    byteoff = (int)ftell(arq_Avr_B);

    return (byteoff - tam_cab) / tam_pag;
}

void inicializa_pagina(PAGINA *pag)
{
    int i;

    for (i = 0; i < ORDEM - 1; i++)
    {
        pag->chaves[i] = -1;
        pag->filhos[i] = -1;
    }

    pag->filhos[i]    = -1;
    pag->contaChaves = 0;
}

int pos_chave(int chave, int chaves[], int num_chaves)
{
    int i = 0;

    while (i < num_chaves && chaves[i] < chave)
        i++;

    return i;
}

void inserir_chave_promocao(int chave_Promovida, int RRN_Promovido, int chaves[], int filhos[], int *num_chaves)
{
    int pos, i;

    pos = pos_chave(chave_Promovida, chaves, *num_chaves);

    for (i = *num_chaves; i > pos; i--)
    {
        chaves[i]     = chaves[i - 1];
        filhos[i + 1] = filhos[i];
    }

    chaves[pos] = chave_Promovida;
    filhos[pos + 1] = RRN_Promovido;
    
    (*num_chaves)++;
}

void divide(int chave, int RRN, PAGINA *pag, int *chave_Promovida, int *filho_Direito_Promovido, PAGINA *novapag, FILE *arq_Avr_B)
{
    // PAGINA_AUX pagaux;
    int pagaux_chaves[ORDEM], pagaux_filhos[ORDEM + 1], pagaux_num_chaves;
    int meio, i;

    for (i = 0; i < pag->contaChaves; i++)
    {
        pagaux_chaves[i] = pag->chaves[i];
        pagaux_filhos[i] = pag->filhos[i];
    }

    pagaux_filhos[i]  = pag->filhos[i];
    pagaux_num_chaves = pag->contaChaves;

    inserir_chave_promocao(chave, RRN, pagaux_chaves, pagaux_filhos, &(pagaux_num_chaves));

    meio = pagaux_num_chaves / 2; 

    *chave_Promovida = pagaux_chaves[meio];
    

    inicializa_pagina(pag);
    
    for(i = 0; i < meio; i++)
    {
        pag->chaves[i] = pagaux_chaves[i];
        pag->filhos[i] = pagaux_filhos[i];
        pag->contaChaves++;
    }
    pag->filhos[i] = pagaux_filhos[i];
    
    inicializa_pagina(novapag);



    for (i = meio + 1; i < pagaux_num_chaves; i++)
    {
        novapag->chaves[novapag->contaChaves] = pagaux_chaves[i];
        novapag->filhos[novapag->contaChaves] = pagaux_filhos[i];
        novapag->contaChaves++;
    }
    novapag->filhos[novapag->contaChaves] = pagaux_filhos[i];

    *filho_Direito_Promovido = RRN_novapag(arq_Avr_B);
}

int insere(int RRN_Atual, int chave, int *chave_Promovida, int *filho_Direito_Promovido, FILE *arq_Avr_B)
{
    PAGINA pag, novapag;
    int  chv_pro, rrn_pro;
    int  pos;
    int  RETORNO;

    if (RRN_Atual == -1)
    {
        *filho_Direito_Promovido = -1;
        *chave_Promovida         = chave;

        return PROMOCAO;
    }

    le_pagina(RRN_Atual, &pag, arq_Avr_B);

    pos = pos_chave(RRN_Atual, pag.chaves, pag.contaChaves);

    if (pos < pag.contaChaves && pag.chaves[pos] == chave)
        return ERRO;

    RETORNO = insere(pag.filhos[pos], chave, &chv_pro, &rrn_pro, arq_Avr_B);

    if (RETORNO == SEM_PROMOCAO || RETORNO == ERRO)
    {
        return RETORNO;
    }
    else
    {
        if (pag.contaChaves < ORDEM - 1)
        {
            inserir_chave_promocao(chv_pro, rrn_pro, pag.chaves, pag.filhos, &(pag.contaChaves));
            escreve_pagina(RRN_Atual, &pag, arq_Avr_B);

            return SEM_PROMOCAO;
        }
        else
        {
            divide(chv_pro, rrn_pro, &pag, chave_Promovida, filho_Direito_Promovido, &novapag, arq_Avr_B);
            escreve_pagina(RRN_Atual, &pag, arq_Avr_B);
            escreve_pagina(*filho_Direito_Promovido, &novapag, arq_Avr_B);

            return PROMOCAO;
        }   
    }  
}

int insere_chave(int chave, int *RRN_Raiz, FILE *arq_Arv_B)
{
    int chave_Promovida, filho_Direito_Promovido;
    int retorno;

    retorno = insere(*RRN_Raiz, chave, &chave_Promovida, &filho_Direito_Promovido, arq_Arv_B);

    if (retorno == ERRO)
    {
        return ERRO;
    }
    else if (retorno == PROMOCAO)
    {
        PAGINA novaraiz;

        inicializa_pagina(&novaraiz);
        novaraiz.chaves[0]   = chave_Promovida;
        novaraiz.filhos[0]   = *RRN_Raiz;
        novaraiz.filhos[1]   = filho_Direito_Promovido;
        novaraiz.contaChaves = 1;

        *RRN_Raiz = RRN_novapag(arq_Arv_B);

        escreve_pagina(*RRN_Raiz, &novaraiz, arq_Arv_B);
    }
    
    return INSERCAO;
}

int ler_chave(FILE *arq, int *chave)
{
    return fscanf(arq, "%d", chave);
}

void criar(char *nome_arq)
{
    FILE *arq_chaves, *arq_Avr_B;
    int i;
    int chave;

    CABECALHO cabecalho;
    PAGINA raiz;

    if ((arq_chaves = fopen(nome_arq, "rb")) == NULL)
    {
        fprintf(stderr, "Erro: o arquivo dados.dat nao foi encontrado.\n");
        exit(1);
    }
   
    if ((arq_Avr_B = fopen("btree.dat", "w+b")) == NULL)
    {
        fprintf(stderr, "Erro: nao foi possivel criar o arquivo btree.dat .\n");
        exit(1);
    }

    cabecalho.rrn_raiz = 0;

    fwrite(&cabecalho, sizeof(CABECALHO), 1, arq_Avr_B);
    
    inicializa_pagina(&raiz); /* Desenha os quadradinhos. */

    escreve_pagina(cabecalho.rrn_raiz, &raiz, arq_Avr_B);

    while (ler_chave(arq_chaves, &chave) > 0)
    {
        if (insere_chave(chave, &(cabecalho.rrn_raiz), arq_Avr_B) == ERRO)
        {
            fprintf(stderr, "Erro: chave \"%d\" ja existe.\n", chave);
        }
    }

    fseek(arq_Avr_B, 0, SEEK_SET);
    fwrite(&cabecalho, sizeof(CABECALHO), 1, arq_Avr_B);

    fclose(arq_chaves);
    fclose(arq_Avr_B);
}

void imprime(FILE *arq_Avr_B)
{
    CABECALHO cabecalho;
    PAGINA pag;

    int i, rrn = 0; /* Para achar a pagina raiz */

    fseek(arq_Avr_B, 0, SEEK_SET);
    fread(&cabecalho, sizeof(CABECALHO), 1, arq_Avr_B);
    fseek(arq_Avr_B, sizeof(CABECALHO), SEEK_SET);

    while (fread(&pag, sizeof(PAGINA), 1, arq_Avr_B) > 0)
    {
        if (rrn == cabecalho.rrn_raiz)
        {
            printf("- - - Pagina Raiz - - -\n");
        }

        printf("Pagina %d\n", rrn);

        printf("Chaves: ");
        for (i = 0; i < pag.contaChaves - 1; i++)
            printf("%d | ", pag.chaves[i]);

        printf("%d\n", pag.chaves[i]);

        printf("Filhos : ");
        for (i = 0; i < pag.contaChaves; i++)
            printf("%d | ", pag.filhos[i]);

        printf("%d\n", pag.filhos[i]);

        if (rrn == cabecalho.rrn_raiz)
            printf("- - - - - - - - - - - - - -\n");

        printf("\n");

        rrn++;
    }
}

int calcular_altura(FILE *arq_Avr_B)
{
    CABECALHO cabecalho;
    PAGINA pag;

    int i, rrn = 0, altura = -1;

    fseek(arq_Avr_B, 0, SEEK_SET);
    fread(&cabecalho, sizeof(CABECALHO), 1, arq_Avr_B);
    
    rrn = cabecalho.rrn_raiz;

    while (rrn != -1)
    {
        le_pagina(rrn, &pag, arq_Avr_B);
        rrn = pag.filhos[0];
        altura++;
    }

    return altura;
}

void estatisticas(FILE *arq_Avr_B)
{
    int qtd_chaves = 0, qtd_paginas = 0;
    PAGINA pag;
    
    fseek(arq_Avr_B, sizeof(CABECALHO), SEEK_SET);

    while (fread(&pag, sizeof(PAGINA), 1, arq_Avr_B) > 0)
    {
        qtd_paginas++;
        qtd_chaves += pag.contaChaves;
    }

    printf("\n- - - - - - - - - - - - - -\n");
    printf("Estatisticas da ArvoreB:\n");
    printf("-> Altura: %d\n", calcular_altura(arq_Avr_B));
    printf("-> Numero de chaves: %d\n", qtd_chaves);
    printf("-> Numero de paginas: %d\n", qtd_paginas);
    printf("-> Taxa de ocupacao: %.2f%%\n", 100 * ((float)qtd_chaves) / ((float)qtd_paginas * (ORDEM - 1)));
}

void imprimir_relatorio()
{
    FILE *arq_Avr_B;

    if ((arq_Avr_B = fopen("btree.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo btree.dat\n");
        exit(1);
    }

    imprime(arq_Avr_B);
    estatisticas(arq_Avr_B);

    fclose(arq_Avr_B);
}


// void insere_na_pagina(int chave, int filho_Direito, PAGINA *pag)
// {
//     int i = pag->contaChaves;

//     while ((i > 0) && (chave < pag->chaves[i - 1]))
//     {
//         pag->chaves[i]     = pag->chaves[i - 1];
//         pag->filhos[i + 1] = pag->filhos[i];
//         i--;
//     }

//     pag->contaChaves++;

//     pag->chaves[i]     = chave;
//     pag->filhos[i + 1] = filho_Direito;
// }

// void insere_na_pagina_aux(int chave, int filho_Direito, PAGINA_AUX *pagaux)
// {
//     int i = ORDEM - 1;

//     while ((i > 0) && (chave < pagaux->chaves[i - 1]))
//     {
//         pagaux->chaves[i]     = pagaux->chaves[i - 1];
//         pagaux->filhos[i + 1] = pagaux->filhos[i];
//         i--;
//     }

//     pagaux->chaves[i]     = chave;
//     pagaux->filhos[i + 1] = filho_Direito;
// }

// int busca_na_pagina(int chave, PAGINA pag, int *pos)
// {
//     int i = 0;

//     while (i < pag.contaChaves && chave > pag.chaves[i])
//         i++;

//     *pos = i;

//     if (*pos < pag.contaChaves && chave == pag.chaves[*pos])
//         return ENCONTRADO;
//     else
//         return NAO_ENCONTRADO;
    
// }

// int busca(int RRN, int chave, int *rrn_Encontrado, int *pos_Encontrada, FILE *arq_Avr_B)
// {
//     if (RRN == -1)
//         return NAO_ENCONTRADO;
//     else
//     {
//         PAGINA *pag;
//         int pos;
        
//         /* fazer funcao le pagina aqui.*/
//         le_pagina(RRN, pag, arq_Avr_B);
        
//         int encontrada = busca_na_pagina(chave, *pag, &pos);

//         if (encontrada)
//         {
//             *rrn_Encontrado  = RRN;
//             *pos_Encontrada  = pos;

//             return ENCONTRADO;
//         }
//         else
//             return busca(pag->filhos[pos], chave, rrn_Encontrado, pos_Encontrada, arq_Avr_B);

//     }
// }

// void gerenciador(int RRN, int chave, int *filho_Direito_Promovido, int *chave_Promovida, FILE *arq_Avr_B)
// {
//     PAGINA novapag;
//     int raiz;
    
//     if (arq_Avr_B != NULL)
//     {
//         arq_Avr_B = fopen("arq.dat", "r+b");
//         /* ler o cabecalho */
//     }
//     else
//     {
//         arq_Avr_B = fopen("arq.dat", "wb");
        
//         raiz = 0;
//         /* escrever cabecalho */

//         inicializa_pagina(&novapag);

//         fwrite(&novapag, sizeof(PAGINA), 1, arq_Avr_B);
//     }

//     scanf("%d", &chave); /* Usar fscanf(arq_chaves, "%d", &chave); */

//     while (chave != - 1)
//     {
//         if (insere(raiz, chave, filho_Direito_Promovido, chave_Promovida, arq_Avr_B))
//         {
//             inicializa_pagina(&novapag);

//             novapag.chaves[0] = *chave_Promovida;
//             novapag.filhos[0] = raiz;
//             novapag.filhos[1] = *filho_Direito_Promovido;

//             fwrite(&novapag, sizeof(PAGINA), 1, arq_Avr_B);

//             raiz = RRN_novapag(arq_Avr_B);
//         }

//         scanf("%d", &chave); /* Usar fscanf(arq_chaves, "%d", &chave); */
//     }

//     fwrite(&raiz, sizeof(int), 1, arq_Avr_B);
//     fclose(arq_Avr_B);
// }