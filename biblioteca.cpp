#include <iostream>
#include <vector>
#include "biblioteca.hpp"  
using namespace std;

int menu(int opcao){ 
    cout << "\n--- Menu ---\n";
    cout << "1. Cadastrar Livro\n";
    cout << "2. Cadastrar Usuário\n";
    cout << "3. Emprestar Livro\n";
    cout << "4. Devolver Livro\n";
    cout << "5. Pesquisar Livro\n";
    cout << "6. Listar Livros\n";
    cout << "7. Verificar Livros Emprestados por Usuário\n";
    cout << "8. Relatório de Empréstimos\n";
    cout << "0. Sair\n";
    cin >> opcao;
    return opcao;
}

void cadastrarLivro(vector<Livro> acervo){
  Livro novoLivro;
  string titulo, autor, categoria;
  int ano, paginas, quant;
  
  cin.ignore();
  cout << "Título: ";
  getline(cin, novoLivro.titulo = titulo);

  cout << "Autor: ";
  getline(cin, novoLivro.autor = autor);

  cout << "Categoria: "; 
  getline(cin, novoLivro.categoria = categoria);

  cout << "Ano de Publicação: "; 
  cin >> ano;
  novoLivro.ano = ano;

  cout << "Número de páginas: ";
  cin >> paginas;
  novoLivro.paginas = paginas;
  
  cout << "Número de Cópias: "; 
  cin >> quant;
  novoLivro.quantidade = quant;
  // novoLivro.emprestimos = 0;
  acervo.push_back(novoLivro);
}

void pesquisarLivros(const vector<Livro>& acervo, const string& criterio){ // utilizar a ideia da variavel criterio
  for(const auto& livro : acervo){
    if(livro.titulo == criterio || livro.autor == criterio || to_string(livro.ano) == criterio){
      cout <<"Titulo: " <<livro.titulo<<"Autor: "<<livro.autor<<"ano: "<<livro.ano<<endl;
    }
    };
  };  

void listagemDeLivros(const vector<Livro>& acervo){
  for(const auto& livro : acervo){
      cout << "Titulo: " << livro.titulo << endl 
      << "Autor: " << livro.autor << endl 
      << "Ano: " << livro.ano << endl << endl;
  };
}