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


    return (EXIT_SUCCESS);
}

