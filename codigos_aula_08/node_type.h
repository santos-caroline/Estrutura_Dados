typedef char ItemType; //criando um 'apelido', ao invés de escrever char vai ser ItemType
/*
 Estrutura usada para guardar 
 a informação e o endereço do 
 próximo elemento.
*/
struct NodeType //unir variaveis diferentes em um só bloco
{
  ItemType info; // o dado que o nó vai armazenar (aqui é um 'char')
  NodeType* next; // um ponteiro para o próximo nó
};

