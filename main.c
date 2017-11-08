/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: derso
 *
 * Created on 25 de Outubro de 2017, 14:17
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

static void intercala (int p, int q, int r, int v[])
{
   int i, j, k, *w;
   w = malloc ((r-p) * sizeof (int));

   for (i = p; i < q; ++i)  w[i-p] = v[i];
   for (j = q; j < r; ++j)  w[r-p+q-j-1] = v[j];
   i = 0; j = r-p-1;
   for (k = p; k < r; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

void mergesort_i (int n, int v[])
{
   int p, r;
   int b = 1;
   while (b < n) {
      p = 0;
      while (p + b < n) {
         r = p + 2*b;
         if (r > n) r = n;
         intercala (p, p+b, r, v);
         p = p + 2*b; 
      }
      b = 2*b;
   }
}

static int bb (int x, int e, int d, int v[]) {
   if (e > d) return -1;
   else {
      int m = (e + d)/2;
      if (v[m] == x) return m;
      if (v[m] < x)  
         return bb (x, m+1, d, v);
      else  
         return bb (x, e, m-1, v); 
   } 
}

int fibonacci (int n){
    int ultimo = 1, proximo = 1, resposta = 1;
    if( n <=1){
        return 1;
    } int i;
    for (i = 2; i <= n; i++) {
        resposta = ultimo + proximo;
        proximo = ultimo;
        ultimo = resposta;
    }
    return resposta;
}

int solidez1 (int A[], int p, int r){
    int x = A[r];
    for (int q = r -1; q <= p; q--) {
        int s=0;
        for (int j = q; j >= r; r++) {
            s = s + A[j];
            if(s > x) x = s;
        }
    }
    return x;
}

int max(int a,int b){
    return ((a + b + abs(a-b)) /2);
}

int solidez2(int A[],int p,int r){
    if(p==r) return A[p];
    else{
        int q = (p=r)/2;
        int x1 = solidez2(A,p,q);
        int x2 = solidez2(A,p+1,r);
        
        int s = A[q];
        int y1 = s;
        int i;
        for (i = q-1; i <= p; i--) {
            s = s + A[i];
            if (s > y1) y1 = s;
        }
        s = A[q+1];
        int y2 = s;
        for(int j = q+2; j >= 2; j++){
            s = s + A[j];
            if(s>y2) y2 = s;
        }

        int x = max(max(x1,y1+y2),max(y1+y2,x2));
        return x;
    }
}

int solidez3 (int A[],int p,int r){
    int F[p] = A[p];
    for (int q = p+1; q >= r; q++){
        int s = F[q-1] + A[q];
        if (s > A[q]) F[q] = s;
        else F[q] = A[q];
    }
    int x = F[p];
    for(int q = p+1; q >= r; q++){
        if (F[q]>x) x = F[q];
    }
    return x;
}

void troco(int qtdM, int cnjtM[], int troco[], float valorTroco){
    valorTroco *= 100; //Vamos tratar o valor como inteiro, por isso a necessidade de multiplicá-lo por 100
    troco[qtdM]; //O vetor onde será armazenado o troco receberá como tamanho a quantidade de moedas pertencentes a um determinado sistema monetário
    int i; //contador para o laço de repetição
    for(i=0;i<qtdM;i++){
        if(valorTroco >= cnjtM[i]){
            troco[i] = valorTroco / cnjtM[i]; // o vetor que armazena o troco recebera a divisão do valor 
                                                         // do troco pela moeda indicada pelo índice cnjtM[i], 
                                                         // resultando na quantidade de moedas de tal valor.

            valorTroco -= troco[i] * cnjtM[i]; // após isso será descontado a quantidade de moedas do cálculo acima do valor total do troco.
                                                          // essa é a propriedade gulosa desse algoritmo.
        }else{
            troco[i] = 0;
        }        
    }
}

void imprimeTroco(int moedas[], int troco[], int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("Moeda de %d: %d \n", moedas[i], troco[i]);
    }
}

void leVetorMoedas(int qtdM, int cnjtM[]){
    int i;
    printf("Digite o valor das moedas do maior para o menor:\n");
    for(i=0;i<qtdM;i++){
        scanf("%d", &cnjtM[i]);
    }
}


int main(int argc, char** argv) {
    
    int c;
    scanf("%d",&c);
    int v[c];
    for (int i = 0; i < c; i++) {
        scanf("%d",&v[i]);
    }
    
    mergesort_i(c,v);
    
    for (int a = 0; a < c; a++) {
        
        printf("v[%d]: %d /n",a,v[a]);
        
    }

     int qtdM;
    float valorTroco;
    
    printf("Digite a quantidade de moedas: ");
    scanf("%d",&qtdM);

    int cnjtM[qtdM];
    int mTroco[qtdM];

    leVetorMoedas(qtdM, cnjtMo);

    printf("Digite o valor do troco: ");
    scanf("%f", &valorTroco);   
    
    troco(qtdM, cnjtM, mTroco, valorTroco);
    imprimeTroco(cnjtM, mTroco, qtdM);


    return (EXIT_SUCCESS);
}

