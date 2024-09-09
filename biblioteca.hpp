#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#define TAM 50

#include <string>
#include <vector>

using namespace std;

struct Livro {
    string titulo;
    string autor;
    string categoria;
    int quantidade;
    int ano;
    int id;
    int paginas;
};

int menu(int opcao); 
void listagemDeLivros(vector<Livro> & acervo); 
void pesquisarLivros(string acervo & string criterio);
void imprimirLivro(Livro livro);
void cadastrarLivro(vector<Livro> & acervo); 
void emprestimoDeLivro();  // dentro do empréstimo deve-se aparecer uma pesquisa, para poder escolher qual livro
void devolucaoDeLivro(int opcao);  // escolher qual usuário vai devolver, depois escolher o livro

#endif
/* 
1. **👍Cadastro de Livros:** implemente uma função para cadastrar informações sobre livros, incluindo título, autor, ano de publicação e número de cópias disponíveis. feito
2. **👍Cadastro de Usuários:** implemente uma função para cadastrar informações dos usuários da biblioteca, como nome e  histórico de livros emprestados.
3. **Empréstimo de Livros:** implemente uma função que permita a biblioteca emprestar livros. 
4. **Devolução de Livros:** implemente uma função que permita aos usuários devolverem livros. 
5. **👍Pesquisa de Livros:** implemente uma função que permita aos usuários pesquisar livros por título, autor ou ano de publicação na biblioteca. feito
6. **Pesquisa de Livros por Usuário:** implemente uma função que permita aos usuários verificar quais livros estão alugados por ele.
7. **☝️🤓Listagem de Livros:** implemente uma função que lista todos os livros que a biblioteca possui. 
8. **Controle de Multas:** implemente um sistema de controle de multas para os usuários que devolvem livros em atraso.
9. **Relatórios de empréstimo:** implemente uma função que gera um relatório de estatísticas de uso dos livros, incluindo o número total de empréstimos, livros mais populares  e usuários mais ativos no sistema. Considere implementar mais duas outras estatísticas a serem apresentadas no relatório.
10. **👍Menu de seleção**: implemente um menu textual apresentando as opções que o usuário do sistema pode realizar
*/