[//]: # (--------Titulo--------)
<h1 align="center">
  <a>
    💻 Árvore AVL 🌳
  </a>
</h1>

[//]: # (--------Descricao--------)
<p align="center">
  <a>
  A árvore AVL é uma Árvore binária balanceada.
  </a>
</p>


[//]: # (--------Conteudos--------)
<!--ts-->
   * [a AVL](#avl)
   * [Balanceamento](#balanceamento)
   * [Rotação](#rotacao)
   * [Fator de Balanceamento](#fator-de-balanceamento)
<!--te-->


[//]: # (--------Badge--------)
<h1 align="center">
  
  ![Badge](https://img.shields.io/badge/Linguagem-C-F1CB7B)
  ![Badge](https://img.shields.io/badge/License-MIT-F1CB7B)
  
</h1>

## AVL
A árvore AVL é uma Árvore binária balanceada na qual as alturas de duas sub-árvores de todo nó nunca  são maiores que 1.

### Balanceamento
   * O balanceamento se trata da diferença entre a altura da sub-árvore esquerda e a altura subárvore direita de um nó.
   * Cada Nó de uma AVL tem balanceamento = 1; -1; ou 0. Caso contrário, a árvore não é uma AVL.


### Rotação
* Para manter uma árvore balanceada, é necessário fazer uma Rotação, que transforma a árvore, mantendo seu percurso em ordem. 
* A transformação e a quantidade de vezes que ela será realizada depende do desbalanceamento existente na árvore e com a condição de que a árvore transformada
continue sendo uma árvore tipo busca
binária.

### Fator de Balanceamento
* Para o caso de necessidade de rebalancear, o cálculo de fator de balanceamento é importante para a verificaçãode qual rotação deve ser efetuada na próxima vez.
* FB consiste na diferença entre as alturas da sub-árvore direita e esquerda. (*Note que:o cálculo do balanceamento é esquerda - direita; o FB é direita - esquerda. Não confunda, cuidado!*)
* Se FB é negativo, rotações são feitas à direita, caso positivo, rotação à esquerda

[//]: # (--------Banner--------)
<h1 align="center">
  
  ![oi](https://user-images.githubusercontent.com/65466643/143596914-a1962f23-7386-46c8-89e6-0cc4232f5ddd.png)
  
</h1>


---
#### Autora

<a href="https://github.com/lauramartinho">
 <img style="border-radius: 50%;" src="https://user-images.githubusercontent.com/65466643/143616931-de8587f0-bfb6-4015-8969-9df896c25247.jpg" width="80px;" alt=""/>
 <br />
 <sub><b>Laura Martinho</b></sub></a> <a href="https://github.com/lauramartinho//" title="Laura Martinho">🦕</a>
