
# Grafos 1 Leet Code AP

**Número da Lista**: 1<br>
**Conteúdo da Disciplina**: Grafos 1 <br>

obs: AP no titulo são as iniciais dos membros do grupo

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 20/2015868  |  Alexandre Lema Xavier Júnior |
| 21/1039671  |  Pedro Lopes da Cunha |

## Sobre 
Resolução de questões do LeetCode (2 difíceis e uma média) pelos integrantes do grupo com o objetivo de demonstrar o conhecimento adquirido nesse módulo (Grafos 1) da disciplina.

## Screenshots

### [2065 - Difícil](https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/) 
Implementei uma busca em profundidade (DFS) para explorar todos os caminhos possíveis em um grafo não direcionado, partindo do nó 0 e respeitando um tempo máximo de percurso. A cada caminho, calculei a qualidade somando os valores dos nós únicos visitados, garantindo que cada valor fosse contabilizado apenas uma vez por trajeto. Estruturei o grafo com listas de adjacência, respeitando a limitação de até quatro arestas por nó, e utilizei um vetor de controle para monitorar as visitas aos nós. Ao final, retornei a maior qualidade encontrada entre todos os caminhos válidos.

![Print da Resolução 2065](/assets/img2065.png)


obs: a marca d'água presente no vídeo é referente ao site que foi utilizado para comprimir o arquivo

https://github.com/user-attachments/assets/71e6d0f4-1c5a-4323-a677-6f7b46639537




### [785 - Média](https://leetcode.com/problems/is-graph-bipartite/submissions/1609926793/)
Verifiquei se um grafo é bipartido aplicando uma busca em profundidade (DFS) que tenta colorir os nós usando apenas duas cores, de forma alternada(usando um vetor de cores onde cada nó é marcado com 0 ou 1) e a cada passo, os vizinhos recebem a cor oposta. Caso algum vizinho já tenha sido colorido com a mesma cor do nó atual, o grafo não é bipartido (retorna false). Como o grafo pode ter componentes desconexas, percorri todos os nós, iniciando a DFS apenas nos que ainda não estavam coloridos. No final, a função retorna verdadeiro apenas se for possível bipartir todas as componentes do grafo.


![Print da Resolução 785](/assets/img785.png)


https://github.com/user-attachments/assets/8749378c-ea33-4058-b2ed-f2e802faa3fa




## Instalação 
**Linguagem**: C<br>


## Outros 
...




