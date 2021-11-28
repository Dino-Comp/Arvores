[//]: # (--------Titulo--------)
<h1 align="center">
  <a>
    💻 Árvore 2-3-4 🌳
  </a>
</h1>

[//]: # (--------Descricao--------)
<p align="center">
  <a>
  A árvore 2-3-4 é uma árvore não binária onde cada nó suporta 2, 3 ou 4 nós filhos.
  </a>
</p>


[//]: # (--------Conteudos--------)
<!--ts-->
   * [a 2-3-4](#avl)
   * [Inserção](#inser--o)
<!--te-->


[//]: # (--------Badge--------)
<h1 align="center">
  
  ![Badge](https://img.shields.io/badge/Linguagem-C-F1CB7B)
  ![Badge](https://img.shields.io/badge/License-MIT-F1CB7B)
  
</h1>

## 2-3-4
A árvore 2,3,4 tem 1, 2 ou 3 chaves, de acordo com o número de filhos que o nó possui.  O custo para manter uma árvore balanceada após cada inserção é muito alto, por isso é necessário permitir que um nó contenha mais de um dado, contendo 2 ou 3 chaves (ex: nós-3/ nós-4).

### Inserção
   * Uma árvore com 3 chaves só exige um nó e em cada nó conterá uma lista de chaves. Ao inserir uma 4ª chave, ela será colocado num dos nós filhos e para balancear, toda vez que identificar um nó cheio é necessário desmembrá-lo, fazendo a chave central subir um nível. 
   * Se a raiz também estiver cheia a chave central sobe e fica isolada na raiz, e esta raiz vira dois nós filhos.

[//]: # (--------Banner--------)
<h1 align="center">
  
 ![ins1](https://user-images.githubusercontent.com/65466643/143783462-f34d78d1-8f82-4352-addd-6ff829682ccc.png)
 ![ins2](https://user-images.githubusercontent.com/65466643/143783463-aacd68bd-ee2e-41fe-81b6-2e6ab1310bd2.png)
   
</h1>

* O objetivo desse processo é manter os nós pais o mais livre possível para que os filhos possam ser inseridos sem que novos níveis tenham que ser criados e a transferência de chaves garanta o balanceamento da árvore.




---
#### Autora

<a href="https://github.com/lauramartinho">
 <img style="border-radius: 50%;" src="https://user-images.githubusercontent.com/65466643/143616931-de8587f0-bfb6-4015-8969-9df896c25247.jpg" width="80px;" alt=""/>
 <br />
 <sub><b>Laura Martinho</b></sub></a> <a href="https://github.com/lauramartinho//" title="Laura Martinho">🦕</a>

