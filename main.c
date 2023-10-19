#include <stdio.h>

void metodoLagrange() {
    int pontos;
    printf("Quantidade de pontos que serão utilizados: ");
    scanf("%d", &pontos);
    
    double X[pontos], Y[pontos];
    
    for (int i = 0; i < pontos; i++) {
        printf("x%d = ", i);
        scanf("%lf", &X[i]);
        printf("y%d = ", i);
        scanf("%lf", &Y[i]);
    }
    
    double x;
    printf("Valor que se deseja interpolar: ");
    scanf("%lf", &x);
    
    double coeficiente[pontos];
    for (int indice = 0; indice < pontos; indice++) {
        double L = 1;
        for (int j = 0; j < pontos; j++) {
            if (indice != j) {
                L *= (x - X[j]) / (X[indice] - X[j]);
            }
        }
        coeficiente[indice] = L;
    }
    
    double pn = 0;
    for (int i = 0; i < pontos; i++) {
        pn += Y[i] * coeficiente[i];
    }
    
    printf("p(%lf) = %lf\n", x, pn);
}

int main() {
    metodoLagrange();
    return 0;
}