# Questão 9 - P1_MD2

## Informações Acadêmicas

- **Aluno:** Davi Rodrigues da Rocha;
- **Matrícula:** 211061618;
- **Disciplina:** Matemática Discreta 2;
- **Professora:** Cristiane Loesch de Souza Costa;
- **Curso:** Engenharia de Sotware;  

## Descrição do Trabalho

Este projeto implementa um programa em C que realiza uma **verificação modular** para validar acessos em um sistema, utilizando conceitos matemáticos como congruência, primalidade, coprimalidade, Pequeno Teorema de Fermat, Teorema de Euler e exponenciação modular eficiente. O programa segue as etapas descritas na questão 9 da avaliação P1 de Matemática Discreta II.

## Funcionalidades

O programa realiza as seguintes etapas:

1. Verificação de Coprimalidade entre G e n usando o Algoritmo de Euclides.
2. Cálculo do Inverso Modular de G em Z_n (se existir).
3. Divisão Modular para calcular a base a = H ⊘ G em Z_n.
4. Verificação de Coprimalidade entre a e n₁.
5. Verificação de Primalidade de n₁.
6. Aplicação do Pequeno Teorema de Fermat (se n₁ for primo).
7. Cálculo da Função Totiente de Euler (se n₁ não for primo).
8. Decomposição do Expoente x usando o Teorema da Divisão Euclidiana.
9. Reescrita da Expressão a^x mod n₁ para simplificação.
10. Cálculo dos Valores Intermediários para exponenciação modular.
11. Resultado Final da congruência a^x mod n₁.

## Entradas do Progama

O programa solicitará os seguintes valores:

1. H, G, n (para calcular a base a).
2. x (expoente).
3. n₁ (módulo final).

Exemplo de entrada:

```bash
Digite os valores de H, G e n: 38 79 252  
Digite o valor do expoente x: 5  
Digite o valor de n₁: 17  
```

## Segunda opção para executar

https://onlinegdb.com/s1HX55H-1N