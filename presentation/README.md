## Input
8 10 5 30 25 35

memo vai ser uma tabela onde na primeira coluna vão estar a melhor venda de ações até aquele dia e na segunda dali pra n, executando o algoritmo a tabela vai ficar assim:

| first  | second |
| :----: | :----: |
| 0      | 0      |
| 2      | 0      |
| 2      | 30     |
| 25     | 10     |
| 25     | 10     |
| 30     | 0      |

tendo a tabela e sabendo que o first é a melhor venda 0 até a posição da tabela e second é a melhor venda da posição da tabela pro final, basta pegar a maior soma da linha e isso resulta no melhor lucro possivel, pra esse caso de entrada é 35 ganhando 25 fazendo a compra no terceiro dia e vendendo no quarto e, em seguida, comprando no quinto dia e vendendo no sexto.