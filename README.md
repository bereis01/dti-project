# PetShop Project
## Introdução
O presente projeto teve por objetivo o desenvolvimento de uma aplicação que demonstrasse conhecimentos gerais no domínio de programação e de desenvolvimento de software. Ele faz parte de uma etapa do processo seletivo de estagiários sediado pela empresa DTI.

O contexto consiste em um canil em Belo Horizonte gerenciado por Eduardo, o qual deseja avaliar o custo de se banhar cachorros pequenos e grandes em uma variedade de diferentes PetShops em uma determinada data, a fim de se determinar aquele com menor preço e, em caso de empate, com menor distância.

## Especificações Técnicas, Decisões de Projeto e Premissas
O projeto foi inteiramente desenvolvido na linguagem de programação C++. Para tal, foi adotada uma arquitetura baseada no modelo MVC (model, vision, control), em que a camada de Visão compreende um front-end simples via linha de comando para interações com o usuário, enquanto as camadas de Controle (interpretação de inputs) e Modelo (regras de negócio e banco de dados) constituem o back-end da aplicação. O sistema de gerenciamento de banco de dados escolhido foi o SQLite3.

De maneira geral, o banco de dados armazena cada um dos PetShops enunciados com suas características básicas. O algoritmo em si, por sua vez, recebe as informações referentes a data, quantidade de cães pequenos e quantidades de cães grandes da entrada, extrai o conteúdo da base de dados para a memória, percorre cada uma das possíveis lojas avaliando seu custo e a distância do canil e, passo a passo, filtra aquela com o menor preço e/ou com a menor distância, retornando nome e custo ao usuário.

Há uma camada de proteção simples via expressões regulares no input, o qual é tratado mediante recebimento. Dessa forma, o backend sempre assume que os dados recebidos estarão no formato correto e pré-estabelecido. Também existe uma camada de proteção simples via wrappers nas operações da base de dados, as quais terminam a execução em caso de erro.

Além dos detalhes supracitados, grande parte das informações fornecidas no enunciado foram tomadas como premissas de conhecimento do usuário, como PetShops presentes na base de dados, distâncias e preços. Mecanismos de manipulação dessas informações não foram implementados.

## Instruções
Executáveis para Linux (dtiLin) e para Windows (dtiWin) estão disponíveis para execução imediata, mas o código fonte pode ser compilado por meio do comando <$ make>, definido no Makefile fornecido. O executável resultado da compilação via Makefile será denominado "dti". O código é compatível tanto com Linux, quanto com Windows. É fundamental efetuar o download do repositório inteiro e, particularmente, manter a estrutura de diretórios e executar o programa no mesmo que a pasta "db", a qual contém a base de dados (para fins de manutenção dos nomes de arquivos utilizados internamente).

Ao ser inicializado, o programa fornecerá instruções de uso para o usuário. Em particular, deverá ser fornecido um input no seguinte formato: DD/MM/YYYY S B, em que DD é um dia, MM, um mês, YYYY, um ano e S B as quantidades de cachorros pequenos e grandes, respectivamente.

Caso as informações estejam corretas, o PetShop mais barato e/ou mais perto será retornado, juntamente com o custo total dos banhos. Logo em seguida, novas consultas poderão ser imediatamente realizadas. Caso haja algum erro no input, um aviso será retornado e, mais uma vez, novas consultas poderão ser realizadas.

## Outras Observações
Fui informado pelo pessoal do RH que não era necessário utilizar React para a construção do front-end, mesmo que no enunciado seja exigido tal. Além disso, peço perdão de imediato por estender um pouco o conceito de "Full-Stack". Estou ciente de que o foco desta vaga seria tecnologias web, porém não sou muito familiar com elas e não fui capaz de conseguir produzir um programa robusto as utilizando em apenas dois dias. Dadas essas condições, cheguei à conclusão de que o melhor que eu poderia fazer seria demonstrar meu domínio de arquitetura de software, dos conceitos por trás das terminologias "full-stack", "front-end" e "back-end", de boas práticas de programação, de bancos de dados relacionais e das linguagens com as quais sou mais familiar, sejam elas C, C++ e Python.
