A árvore AVL é uma Árvore binária balanceada na qual as alturas de duas sub-árvores de todo nó nunca  são maiores que 1.

O balanceamento se trata da diferença entre a altura da sub-árvore esquerda e a altura subárvore direita de um nó.
Cada Nó de uma AVL tem balanceamento = 1; -1; ou 0. Caso contrário, a árvore não é uma AVL.

Para manter uma árvore balanceada, é necessário fazer uma Rotação, que transforma a árvore, mantendo seu percurso em ordem. A transformação e a quantidade de vezes que ela será realizada depende do desbalanceamento existente na árvore e com a condição de que a árvore transformada
continue sendo uma árvore tipo busca
binária.
Para o caso de necessidade de rebalancear, o cálculo de fator de balanceamento é importante para a verificaçãode qual rotação deve ser efetuada na próxima vez.
FB consiste na diferença entre as alturas da sub-árvore direita e esquerda.
* Note que: o cálculo do balanceamento é esquerda - direita; o FB é direita - esquerda. Não confunda, cuidado!
Se FB é negativo, rotações são feitas à direita, caso positivo, rotação à esquerda
