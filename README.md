# PetShop Project
## Introdução
O presente projeto teve por objetivo o desenvolvimento de uma aplicação que demonstrasse conhecimentos gerais no domínio de programação e de desenvolvimento de software. Ele faz parte de uma etapa do processo seletivo de estagiários sediado pela empresa DTI.

O contexto consiste em um canil em Belo Horizonte gerenciado por Eduardo, o qual deseja avaliar o custo de se banhar cachorros pequenos e grandes em uma variedade de diferentes PetShops em uma determinada data, a fim de se determinar aquele com menor preço e, em caso de empate, com menor distância.

## Especificações Técnicas
O projeto foi inteiramente desenvolvido na linguagem de programação C++. Para tal, foi adotada uma arquitetura baseada no modelo MVC (model, vision, control), em que a camada de Visão compreende um front-end simples via linha de comando para interações com o usuário, enquanto as camadas de Controle (interpretação de inputs) e Modelo (regras de negócio e banco de dados) constituem o back-end da aplicação. O sistema de gerenciamento de banco de dados escolhido foi o SQLite3.

De maneira geral, o banco de dados armazena cada um dos PetShops enunciados com suas características básicas. O algoritmo em si, por sua vez, recebe as informações referentes a data, quantidade de cães pequenos e quantidades de cães grandes da entrada, extrai o conteúdo da base de dados para a memória, percorre cada uma das possíveis lojas avaliando seu custo e a distância do canil e, passo a passo, filtra aquela com o menor preço e/ou com a menor distância, retornando nome e custo ao usuário.

Há uma camada de proteção simples via expressões regulares no input, o qual é tratado mediante recebimento. Dessa forma, o backend sempre assume que os dados recebidos estarão no formato correto e pré-estabelecido. Também existe uma camada de proteção simples via wrappers nas operações da base de dados, as quais terminam a execução em caso de erro.
