#include <stdio.h>
#include <unistd.h>
#include <math.h>

// Etapa 1: Algoritmo de Euclides com saída detalhada no formato tradicional
int mdc(int a, int b) {
    printf("\n--- Etapa 1: Verificação de coprimalidade entre G = %d e n = %d usando o Algoritmo de Euclides ---\n\n", a, b);
    sleep(1);

    printf("OBJETIVO: Verificar se G e n são coprimos, ou seja, MDC = 1\n\n");
    sleep(1);
    printf("MÉTODO: Algoritmo de Euclides - calcula o MDC entre dois números inteiros\n\n");
    sleep(1);
    printf("FUNCIONAMENTO DO ALGORITMO:\n");
    sleep(1);
    printf("1. Divide-se o número maior (a = %d) pelo menor (b = %d)\n", a, b);
    sleep(1);
    printf("2. Se o resto for zero, o b do passo anterior é o MDC\n");
    sleep(1);
    printf("3. Caso contrário, repete-se com b e o resto, ou seja: mdc(b,resto)\n");
    sleep(1);
    printf("4. Continua até resto ser zero (último divisor não nulo é o MDC)\n\n");
    sleep(1);

    printf("NA PRÁTICA:\n");
    sleep(1);

    int passo = 1;
    while (b != 0) {
        int quociente = a / b;
        int resto = a % b;
        
        printf("Passo %d: mdc(%d, %d):\n", passo, a, b);
        printf("%d = %d * %d + %d", a, b, quociente, resto);
        if (resto != 0)
            printf(", r ≠ 0\n\n");
        else
            printf(", r = 0\n\n");

        sleep(1);
        a = b;
        b = resto;
        passo++;
    }

    printf("Resultado final: mdc = %d\n", a);
    sleep(1);
    return a;
}

// Etapa 2: Função para calcular o inverso de G em Z_n, com explicação detalhada
int inverso_modular(int G, int n) {
    printf("\n--- Etapa 2: Cálculo do inverso modular de G = %d em Z_%d usando o Algoritmo de Euclides Estendido ---\n\n", G, n);
    sleep(1);

    int r1 = n, r2 = G;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;

    int passo = 1;
    
    while (r2 > 0) {
        int q = r1 / r2;

        int r = r1 - q * r2;
        int s = s1 - q * s2;
        int t = t1 - q * t2;

        printf("Passo %d:\n", passo++);
        printf("q = %d\n", q);
        printf("r = %d - %d * %d = %d\n", r1, q, r2, r);
        printf("s = %d - %d * %d = %d\n", s1, q, s2, s);
        printf("t = %d - %d * %d = %d\n", t1, q, t2, t);
        printf("\n");

        sleep(1);

        // Atualiza para próxima iteração
        r1 = r2; r2 = r;
        s1 = s2; s2 = s;
        t1 = t2; t2 = t;
    }

    // Ao final, r1 deve ser 1 se G e n forem coprimos
    if (r1 != 1) {
        printf("Não foi possível encontrar inverso modular pois G e n não são coprimos.\n");
        return -1;
    }

    int inverso = t1;

    // Garante que o inverso esteja no conjunto Zn (positivo)
    if (inverso < 0) {
        inverso += n;
        printf("Como o inverso era negativo, ajustamos para o equivalente positivo em Z_%d.\n", n);
    }

    printf("Inverso modular de %d em Z_%d é: %d\n", G, n, inverso);
    sleep(1);
    return inverso;
}

// Etapa 3: Função para calcular a base 'a' = H * G^(-1) mod n
int calcular_base(int H, int G_inv, int n) {
    printf("\n--- Etapa 3: Divisão modular de H por G ---\n\n");
    sleep(1);

    printf("OBJETIVO: Calcular a base 'a' para a exponenciação modular através da divisão modular de H por G\n\n");
    sleep(1);
    
    printf("CONCEITO MATEMÁTICO: Dividir H por G módulo n equivale a multiplicar H pelo inverso modular de G (G⁻¹), pois:\n\n");
    sleep(1);
    printf("H/G ≡ H × G⁻¹ mod n (quando MDC(G,n) = 1)\n\n");
    sleep(1);
    
    printf("PASSO A PASSO:\n");
    sleep(1);
    printf("1. Já calculamos G⁻¹ = %d na etapa anterior\n", G_inv);
    sleep(1);
    printf("2. Agora nessa etapa, multiplicamos H (sendo %d) pelo inverso G⁻¹ (encontrado, sendo %d)\n", H, G_inv);
    sleep(1);
    printf("3. Aplicamos o módulo n (sendo %d) ao resultado\n", n);
    sleep(1);
    printf("4. Obtemos assim a base 'a' da exponenciação\n\n");
    sleep(1);

    printf("NA PRÁTICA:\n");
    sleep(1);
    printf("Usando: a = H × G⁻¹ mod n\n");
    sleep(1);
    printf("Com os valores, temos: a = %d × %d mod %d\n", H, G_inv, n);
    sleep(1);

    int a_intermediario = H * G_inv;
    printf("Multiplicação intermediária: %d × %d = %d\n", H, G_inv, a_intermediario);
    sleep(1);

    int a = a_intermediario % n;
    printf("Aplicando o módulo: %d mod %d = %d\n\n", a_intermediario, n, a);
    sleep(1);

    printf("Portanto, a base da exponenciação é: a = %d\n", a);
    return a;
}

// Etapa 4: Função para verificar se 'a' e 'n₁' são coprimos
int verificar_coprimos(int a, int n1) {
    printf("\n--- Etapa 4: Verificação de coprimalidade entre a = %d e n₁ = %d também usando o Algoritmo de Euclides ---\n\n", a, n1);
    sleep(1);

    printf("OBJETIVO: Verificar se a base 'a' e o novo módulo 'n₁' são coprimos (ou seja, se MDC(a, n₁) = 1)\n\n");
    sleep(1);

    printf("MÉTODO:\n");
    sleep(1);
    printf("Novamente usaremos o Algoritmo de Euclides para calcular o MDC\n");
    sleep(1);
    printf("O mesmo método da Etapa 1, mas agora com os valores a = %d e n₁ = %d\n\n", a, n1);
    sleep(1);


    printf("NA PRÁTICA:\n");
    sleep(1);
    int passo = 1;
    int x = a, y = n1;

    while (y != 0) {
        int quociente = x / y;
        int resto = x % y;

        printf("Passo %d: mdc(%d, %d):\n", passo, x, y);
        printf("%d = %d * %d + %d", x, y, quociente, resto);
        if (resto != 0)
            printf(", r ≠ 0\n\n");
        else
            printf(", r = 0\n\n");

        sleep(1);
        x = y;
        y = resto;
        passo++;
    }

    printf("Resultado final: mdc = %d\n\n", x);
    sleep(1);

    if (x == 1) {
        printf("Como mdc(a, n₁) = 1, a e n₁ são coprimos.\n");
        return 1;
    } else {
        printf("Como mdc(a, n₁) = %d ≠ 1, a e n₁ NÃO são coprimos.\n", x);
        return 0;
    }
}

// Verifica se um número é primo de forma simples (auxiliar)
int eh_primo_simples(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Etapa 5: Função para verificar se n₁ é primo
int verificar_primalidade(int n1) {
    printf("\n--- Etapa 5: Verificando se n₁ = %d é primo ---\n\n", n1);
    sleep(1);

    printf("OBJETIVO: Determinar se n₁ é um número primo\n\n");
    sleep(1);
    
    printf("TEOREMA FUNDAMENTAL:\n");
    sleep(1);
    printf("Um número n é primo se não for divisível por nenhum primo p ≤ √n\n\n");
    sleep(1);
    
    printf("MÉTODO UTILIZADO:\n");
    sleep(1);
    printf("1. Calcular √n₁ (limite máximo para testar divisores)\n");
    sleep(1);
    printf("2. Verificar divisibilidade por todos os primos até este limite\n");
    sleep(1);
    printf("3. Se nenhum divisor for encontrado, n₁ é primo\n\n");
    sleep(1);
    
    printf("RAZÃO PARA O MÉTODO:\n");
    sleep(1);
    printf("Testar até √n é suficiente porque:\n");
    sleep(1);
    printf("- Se n tiver um divisor maior que √n, seu par seria menor que √n, e já teria sido encontrado anteriormente.\n\n");
    sleep(1);

    printf("NA PRÁTICA:\n");
    int limite = (int) sqrt(n1);
    printf("Calculando √n₁ ≈ √%d = %d.\n", n1, limite);
    sleep(1);
    printf("Portanto o limite de teste é %d\n\n", limite);
    sleep(1);

    printf("Agora, vamos verificar se os primos até %d dividem %d\n", limite, n1);
    sleep(1);

    for (int i = 2; i <= limite; i++) {
        if (eh_primo_simples(i)) {
            printf("→ %d|%d? - ", i, n1);
            if (n1 % i == 0) {
                printf("Sim! Pois %d ÷ %d = %d\n", n1, i, n1 / i);
                sleep(1);
                printf("\nPortanto, %d NÃO é primo, pois é divisível por %d.\n", n1, i);
                return 0;
            } else {
                printf("Não, pois o resto = %d\n", n1 % i);
            }
            sleep(1);
        }
    }

    printf("\nNenhum primo até %d divide %d\n\n", limite, n1);
    sleep(1);
    printf("Portanto, %d é primo.\n", n1);
    return 1;
}

// Etapa 6: Função para aplicar o Pequeno Teorema de Fermat
int aplicar_fermat(int n1) {
    printf("\n--- Etapa 6: Aplicação do Pequeno Teorema de Fermat ---\n\n");
    
    printf("OBJETIVO: Calcular o expoente x₁ para a exponenciação modular usando as propriedades dos números primos\n\n");
    sleep(1);
    
    printf("PEQUENO TEOREMA DE FERMAT:\n");
    sleep(1);
    printf("Se p é primo e a não é múltiplo de p, então:\n\n");
    sleep(1);
    printf("a^(p-1) ≡ 1 mod p\n\n");
    sleep(1);
    
    printf("APLICAÇÃO NO NOSSO CASO:\n");
    sleep(1);
    printf("Como n₁ = %d é primo (verificado na etapa anterior), podemos usar o teorema para simplificar o cálculo:\n\n", n1);
    sleep(1);
    
    printf("CÁLCULO DO EXPOENTE:\n");
    sleep(1);
    printf("x₁ = n₁ - 1 = %d - 1 = %d\n", n1, n1-1);
    sleep(1);
    printf("\nEste será nosso expoente para a exponenciação modular\n\n");
    sleep(1);
    
    printf("SIGNIFICADO:\n");
    sleep(1);
    printf("Para qualquer base a coprima com n₁, teremos:\n\n");
    sleep(1);
    printf("a^%d ≡ 1 mod %d\n\n", n1-1, n1);
    sleep(1);
    printf("Esta propriedade será fundamental para a solução final\n");
    sleep(1);

    return n1 - 1;
}

// Etapa 7: Função para calcular o totiente φ(n₁) usando o Teorema de Euler
int calcular_totiente(int n1) {
    printf("\n--- Etapa 7: Cálculo da Função Totiente φ(%d) ---\n\n", n1);
    
    printf("OBJETIVO: Calcular φ(n₁) - quantidade de inteiros positivos menores que n₁ que são coprimos com n₁ (Teorema de Euler)\n\n");
    sleep(1);

    printf("CONTEXTO:\n");
    sleep(1);
    printf("Como n₁ = %d NÃO é primo (verificado na etapa 5),\n", n1);
    sleep(1);
    printf("não podemos usar simplesmente φ(p) = p-1.\n");
    sleep(1);
    printf("Precisamos fatorar n₁ e usar a propriedade multiplicativa:\n\n");
    sleep(1);
    
    printf("FÓRMULA DO TOTIENTE:\n");
    sleep(1);
    printf("Para n₁ = p₁^k₁ * p₂^k₂ * ... * p_m^k_m (fatoração prima):\n");
    sleep(1);
    printf("φ(n₁) = n₁ * (1 - 1/p₁) * (1 - 1/p₂) * ... * (1 - 1/p_m)\n\n");
    sleep(1);
    
    printf("MÉTODO DE CÁLCULO:\n");
    sleep(1);
    printf("1. Iniciar com φ = n₁\n");
    sleep(1);
    printf("2. Encontrar cada fator primo p de n₁\n");
    sleep(1);
    printf("3. Para cada fator primo p encontrado:\n\n");
    sleep(1);
    printf("   φ = φ * (1 - 1/p) ⇨ φ = φ - φ/p\n\n");
    sleep(1);
    printf("4. Repetir até processar todos os fatores primos\n\n");
    sleep(1);
    
    printf("VAMOS EXECUTAR PASSO A PASSO PARA n₁ = %d:\n", n1);
    sleep(1);

    int resultado = n1;
    int copia = n1;

    printf("\n[Início] φ(%d) = %d (valor inicial)\n", n1, resultado);
    sleep(1);

    for (int p = 2; p * p <= copia; p++) {
        if (copia % p == 0) {
            printf("\nFator primo encontrado: %d\n\n", p);
            sleep(1);
            printf("Processando todas as potências de %d em %d...\n", p, n1);
            sleep(1);
            
            while (copia % p == 0) {
                printf("%d ÷ %d = %d\n", copia, p, copia/p);
                sleep(1);
                copia /= p;
            }
            
            printf("\nAplicando fórmula: φ = φ - φ/%d\n", p);
            sleep(1);
            printf("φ = %d - %d/%d = %d - %d = %d\n", 
                  resultado, resultado, p, resultado, resultado/p, resultado - resultado/p);
            
            resultado = resultado - (resultado / p);
            sleep(2);
        }
    }

    // Tratamento do último fator primo > √n1
    if (copia > 1) {
        printf("\nFator primo remanescente: %d\n", copia);
        sleep(1);
        printf("Aplicando fórmula: φ = φ - φ/%d\n", copia);
        sleep(1);
        printf("φ = %d - %d/%d = %d - %d = %d\n", 
              resultado, resultado, copia, resultado, resultado/copia, resultado - resultado/copia);
        
        resultado = resultado - (resultado / copia);
        sleep(2);
    }

    printf("\nRESULTADO FINAL:\n");
    sleep(1);
    printf("φ(%d) = %d\n", n1, resultado);
    sleep(1);
    printf("\nINTERPRETAÇÃO:\n");
    sleep(1);
    printf("Existem %d números entre 1 e %d que são coprimos com %d\n", resultado, n1, n1);

    printf("\nDefinimos então x₁ = φ(%d) = %d\n", n1, resultado);
    sleep(1);
    
    return resultado;
}

void decompor_expoente(int x, int x1, int *q, int *r) {
    printf("\n--- Etapa 8: Decomposição do Expoente x = %d ---\n\n", x);
    
    printf("OBJETIVO: Decompor o expoente x usando o Teorema da Divisão Euclidiana para aplicar propriedades de exponenciação modular\n\n");
    sleep(1);
    printf("FUNDAMENTAÇÃO MATEMÁTICA:\n");
    sleep(1);
    printf("Teorema da Divisão: Para quaisquer inteiros a e b (b > 0),\n");
    sleep(1);
    printf("existem únicos inteiros q (quociente) e r (resto) tais que:\n");
    sleep(1);
    printf("a = b × q + r, onde 0 ≤ r < b\n\n");
    sleep(1);
    
    printf("APLICAÇÃO NO NOSSO CASO:\n");
    sleep(1);
    printf("Queremos expressar x = %d como:\n", x);
    sleep(1);
    printf("x = x₁ × q + r, onde x₁ = %d\n", x1);
    sleep(1);
    printf("Isso permitirá reescrever a expressão a^x mod n\n\n");
    sleep(1);
    
    printf("PASSO-A-PASSO DO CÁLCULO:\n");
    sleep(1);

    printf("\n[1] Cálculo do quociente (q):\n");
    *q = x / x1;
    printf("%d ÷ %d = %d (divisão inteira)\n", x, x1, *q);
    sleep(1);
    
    printf("\n[2] Cálculo do resto (r):\n");
    *r = x % x1;
    printf("%d mod %d = %d\n", x, x1, *r);
    sleep(2);
    
    printf("\n[3] Verificação da equação:\n\n");
    printf("%d = %d × %d + %d\n\n", x, x1, *q, *r);
    printf("Verificando: %d × %d + %d = %d + %d = %d\n", 
           x1, *q, *r, x1 * (*q), *r, x1 * (*q) + *r);
    sleep(2);
    
    printf("\nPODEMOS ENTÃO DIZER:\n");
    sleep(1);
    printf("x = %d pode ser expresso como:\n", x);
    sleep(1);
    printf("x = %d × %d + %d\n", x1, *q, *r);
}

// Etapa 9: Função para calcular a exponenciação modular
void reescrever_expressao(int a, int x, int x1, int q, int r, int n1) {
    printf("\n--- Etapa 9: Reescrevendo a expressão a^x mod n₁ ---\n\n");
    sleep(1);
    printf("Sabemos que x = x₁ * q + r = %d * %d + %d\n\n", x1, q, r);
    sleep(1);
    printf("Logo, a^x ≡ (((a^x₁)^q mod n₁) ⋅ (a^r mod n₁)) mod n₁\n\n");
    sleep(1);
    printf("Ou seja:\n");
    sleep(1);
    printf("a^%d mod %d ≡ (((a^%d)^%d mod %d) ⋅ (a^%d mod %d)) mod %d\n", x, n1, x1, q, n1, r, n1, n1);
}

// Função para calcular a^b mod m de forma eficiente (exponenciação rápida)
int exponenciacao_modular(int base, int expoente, int modulo) {
    int resultado = 1;
    base = base % modulo;

    while (expoente > 0) {
        if (expoente % 2 == 1) {
            resultado = (resultado * base) % modulo;
        }
        base = (base * base) % modulo;
        expoente = expoente / 2;
    }

    return resultado;
}

// Etapa 10: Cálculo dos valores intermediários
void calcular_valores_intermediarios(int a, int x1, int q, int r, int n1) {
    printf("\n--- Etapa 10: Cálculo dos Valores Intermediários ---\n\n");

    sleep(1);
    printf("Vamos agora calcular valores intermediários importantes para a exponenciação modular:\n\n");

    // a^x1 mod n1
    int x2 = exponenciacao_modular(a, x1, n1);
    printf("1. a^x₁ mod n₁ = %d^%d mod %d = %d\n", a, x1, n1, x2);
    sleep(1);

    // x2^q mod n1
    int parte1 = exponenciacao_modular(x2, q, n1);
    printf("2. x₂^q mod n₁ = %d^%d mod %d = %d\n", x2, q, n1, parte1);
    sleep(1);

    // a^r mod n1
    int parte2 = exponenciacao_modular(a, r, n1);
    printf("3. a^r mod n₁ = %d^%d mod %d = %d\n", a, r, n1, parte2);
    sleep(1);
}

// Etapa 11: Combinar os valores e imprimir o resultado final da congruência
void calcular_resultado_final(int x2_q_mod, int a_r_mod, int n1) {
    printf("\n--- Etapa 11: Resultado Final da Congruência ---\n\n");

    sleep(1);
    printf("Vamos combinar os valores obtidos:\n\n");

    printf("x₂^q mod n₁ = %d\n", x2_q_mod);
    printf("a^r mod n₁ = %d\n\n", a_r_mod);

    sleep(1);
    int resultado = (x2_q_mod * a_r_mod) % n1;

    printf("Resultado final:\n");
    printf("((x₂^q) · (a^r)) mod n₁ = (%d · %d) mod %d = %d mod %d = %d\n\n",
           x2_q_mod, a_r_mod, n1, x2_q_mod * a_r_mod, n1, resultado);

    sleep(1);
    printf("Portanto, a^x mod n₁ = %d ✅\n", resultado);
}

// Função principal
int main() {
    int H, G, n;  // Entrada do usuário
    int x, n1;
    int q, r;

    printf("Digite os valores de H, G e n: ");
    scanf("%d %d %d", &H, &G, &n);
    printf("Digite o valor do expoente x: ");
    scanf("%d", &x);
    printf("Digite o valor de n₁: ");
    scanf("%d", &n1);

    // Etapa 1: Verificação de coprimalidade
    int resultado_mdc = (G > n) ? mdc(G, n) : mdc(n, G);

    if (resultado_mdc != 1) {
        printf("\nComo mdc(a, b) = %d ≠ 1, G e n NÃO são coprimos.\n", resultado_mdc);
        sleep(1);
        printf("Portanto, a divisão modular H ⊘ G em Z_%d NÃO é possível.\n", n);
        return 1;
    }

    printf("\nComo mdc(a, b) = 1, G e n são coprimos.\n");
    sleep(1);
    printf("A divisão modular H ⊘ G em Z_%d é possível.\n", n);

    sleep(1);
    // Etapa 2: Inverso modular
    int inverso_G = inverso_modular(G, n);
    if (inverso_G == -1) {
        printf("Erro: não foi possível calcular o inverso modular.\n");
        return 1;
    }

    // Etapa 3: Calcular a base a = H * G⁻¹ mod n
    int inv = inverso_G;
    int a = calcular_base(H, inv, n);
    
    sleep(1);
    // Etapa 4: Verificação de coprimalidade entre a e n₁
    if (!verificar_coprimos(a, n1)) {
        printf("Não é possível prosseguir com a exponenciação modular.\n");
        return 1;
    }

    sleep(1);

    // Etapa 5, 6 e 7: Verificação de primalidade de n₁
    int x1;
    if (verificar_primalidade(n1)) {
        x1 = aplicar_fermat(n1);
    } else {
        printf("Como n₁ não é primo, pode haver restrições no uso de algumas propriedades.\n");
        x1 = calcular_totiente(n1);
    }

    sleep(1);

    // Etapa 8: Decomposição do expoente x
    decompor_expoente(x, x1, &q, &r);  // onde x e x1 já foram calculados nas etapas anteriores

    sleep(1);
    // Etapa 9: Reescrever a expressão
    reescrever_expressao(a, x, x1, q, r, n1);

    sleep(1);

    // Etapa 10: Cálculo dos valores intermediários
    calcular_valores_intermediarios(a, x1, q, r, n1);

    int x2 = exponenciacao_modular(a, x1, n1);
    int x2_q_mod = exponenciacao_modular(x2, q, n1);
    int a_r_mod = exponenciacao_modular(a, r, n1);

    // Etapa 11: Combinar os valores e imprimir o resultado final
    calcular_resultado_final(x2_q_mod, a_r_mod, n1);
}