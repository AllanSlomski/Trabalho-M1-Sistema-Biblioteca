#include <iostream>
#include <vector>
#include "biblioteca.hpp"
#include "usuarios.hpp"
#include <algorithm>
#include <map>
using namespace std;

vector<Livro> acervo;

int fecharDia = 0;

void menu(int &opcao){ 
    cout << "\n--- Menu ---\n";
    cout << "1. Cadastrar Livro\n"; // ok
    cout << "2. Cadastrar Usuario\n"; // ok
    cout << "3. Emprestar Livro\n"; // ok
    cout << "4. Devolver Livro\n"; // ok                                  
    cout << "5. Pesquisar Livro\n"; // ok
    cout << "6. Listar Livros\n"; // ok
    cout << "7. Verificar Livros Emprestados por Usuario\n"; // ok
    cout << "8. Relatorio de Emprestimos\n"; 
    cout << "9. Listar Usuários\n"; // ok
    cout << "10. Fechar o dia\n"; // ok
    cout << "0. Sair\n"; // ok
    cin >> opcao;
    cout << endl;
}

void cadastrarLivro(vector<Livro> &acervo){
  Livro novoLivro;
  string titulo, autor, categoria;
  int ano, paginas, quant;

  cout << "-Cadastrar Livro-\n";
  getline(cin, novoLivro.titulo = titulo);

  cout << "Título: ";
  getline(cin, novoLivro.titulo = titulo);
  cout << "\n";
  
  cout << "Autor: ";
  getline(cin, novoLivro.autor = autor);
  cout << "\n";

  cout << "Categoria: "; 
  getline(cin, novoLivro.categoria = categoria);
  cout << "\n";

  cout << "Ano de Publicação: "; 
  cin >> ano;
  novoLivro.ano = ano;
  cout << "\n";

  cout << "Número de páginas: ";
  cin >> paginas;
  novoLivro.paginas = paginas;
  cout << "\n";

  cout << "Número de Cópias: "; 
  cin >> quant;
  novoLivro.quantidade = quant;
  // novoLivro.emprestimos = 0;
  acervo.push_back(novoLivro);
};

void pesquisarLivros(vector<Livro>& acervo, string criterio){ 
  int i = 0;
  bool encontrado = false;
  if (acervo.empty()){
    cout << "Não há livros cadastrados ainda!";
  } else {
      for (Livro &livro : acervo){
        if (livro.titulo == criterio || livro.autor == criterio || to_string(livro.ano) == criterio || livro.categoria == criterio){
          cout << "-Livros Encontrados:- \n" 
               << "Índice: " << i+1 << endl
               << "Título: " << livro.titulo << endl
               << "Autor: " << livro.autor << endl
               << "Categoria: " << livro.categoria << endl
               << "Ano: " << livro.ano << endl << endl;
            encontrado = true;
        }
      i++;
    if(!encontrado){
      cout << "Nenhum registro encontrado." << endl;
    }
   }
  }
} 

void listagemDeLivros(vector<Livro>& acervo) {
  for (const auto& livro : acervo) {
      cout << "Título: " << livro.titulo << endl
           << "Autor: " << livro.autor << endl
           << "Categoria: " << livro.categoria << endl
           << "Número de páginas: " << livro.paginas << endl
           << "Ano: " << livro.ano << endl
           << "Quantidade: " << livro.quantidade << endl
           << endl;
  };
}

void emprestarLivro(vector<Livro>& acervo, vector<Usuario> &usuarios, string &criterio) {
  int livroSelecionado, usuarioSelecionado;
  if (usuarios.empty()){
    cout << "Não há usuários cadastrados ainda!" << endl;
  } else if (acervo.empty()){
      cout << "Não há livros cadastrados ainda!" << endl;
  } else {
      listarUsuarios(usuarios);
      cout << "Selecione o usuário (utilizando o ID): ";
      cin >> usuarioSelecionado;
      cout << "Pesquise o livro (titulo, autor ou ano, 0 para listar todos os livros): ";
      cin >> criterio;
      if (criterio == "0"){
        int i = 0;
        for (Livro livro : acervo){
          cout << "Índice: " << i+1 << endl
               << "Titulo: " << livro.titulo << endl
               << "Autor: " << livro.autor << endl
               << "Categoria: " << livro.categoria << endl << endl;
          i++;
        }
        cout << "Selecione o livro (utilizando o índice): " << endl;
        cin >> livroSelecionado;
        acervo[livroSelecionado-1].quantidade--;
        usuarios[usuarioSelecionado-1].livrosEmprestados.push_back(acervo[livroSelecionado-1].titulo);
        usuarios[usuarioSelecionado-1].diasParaMulta.push_back(fecharDia+2);
      }else {
        pesquisarLivros(acervo, criterio);
        cout << "Selecione o livro (utilizando o índice): " << endl;
        cin >> livroSelecionado;
        acervo[livroSelecionado-1].quantidade--;
        usuarios[usuarioSelecionado-1].livrosEmprestados.push_back(acervo[livroSelecionado-1].titulo);
        usuarios[usuarioSelecionado-1].diasParaMulta.push_back(fecharDia+2);
      }
    }
}


void devolverLivro(vector<Livro> &acervo, vector<Usuario> &usuarios){
  int livroSelecionado;
  size_t usuarioSelecionado;
  if (usuarios.empty()){
    cout << "Não há usuários cadastrados ainda!" << endl;
  } else {
      listarUsuarios(usuarios);
      cout << "Selecione o usuário (utilizando o ID): ";
      cin >> usuarioSelecionado;
      if (usuarioSelecionado > 0 && usuarioSelecionado <= usuarios.size()) {
        int i = 0;
        Usuario& usuario = usuarios[usuarioSelecionado - 1];
        cout << "Livros emprestados pelo usuário " << usuario.nome << ": " << endl;
        for (const string& livroTitulo : usuario.livrosEmprestados) {
            cout << i+1 << " "
                 << livroTitulo << endl;
        }
        if (usuario.livrosEmprestados.empty()){
          cout << "O usuário não tem livros para devolver!" << endl;
        } else {
            cout << "Selecione um livro para devolver (utilizando o índice): ";
            cin >> livroSelecionado;
            string livroParaDevolver = usuario.livrosEmprestados[livroSelecionado - 1];
            usuario.livrosEmprestados.erase(
                remove(usuario.livrosEmprestados.begin(), usuario.livrosEmprestados.end(), livroParaDevolver),
                usuario.livrosEmprestados.end()
            );
            for (Livro &livro : acervo){
              if (livro.titulo == livroParaDevolver){
                livro.quantidade++;
            }
          }
        }
    } else {
        cout << "Usuário não encontrado." << endl;
    }
  }
}

void aplicarMulta(vector <Usuario> &usuarios, int &fecharDia){
  float multa = 0.5;
  int i = 0;
  for (Usuario &usuario : usuarios){
    if (usuario.diasParaMulta[i] < fecharDia){
      usuario.multa += multa;
    }
    i++;
  }
}


void relatorioDeEmprestimos(vector<Livro> &acervo, vector<Usuario> &usuarios, int &fecharDia) {
    int totalEmprestimos = 0;
    string livroMaisPopular;
    string usuarioMaisAtivo;
    string categoriaMaisPopular;
    float mediaEmprestimosPorDia = 0;

    // Dicionário para contar as categorias
    map<string, int> categorias;
    
    // Variáveis auxiliares para popularidade
    int maxEmprestimosLivro = 0;
    int maxEmprestimosUsuario = 0;
    
    // Contagem de empréstimos total e identificação de categorias
    for (const Livro &livro : acervo) {
        totalEmprestimos += livro.emprestimos;
        if (livro.emprestimos > maxEmprestimosLivro) {
            maxEmprestimosLivro = livro.emprestimos;
            livroMaisPopular = livro.titulo;
        }
        categorias[livro.categoria] += livro.emprestimos;  // Contar por categoria
    }

    // Verificar categoria mais popular
    int maxCategoria = 0;
    for (const auto& categoria : categorias) {
        if (categoria.second > maxCategoria) {
            maxCategoria = categoria.second;
            categoriaMaisPopular = categoria.first;
        }
    }

    // Contagem de empréstimos por usuário
    for (const Usuario &usuario : usuarios) {
        int totalEmprestimosUsuario = usuario.livrosEmprestados.size();
        if (totalEmprestimosUsuario > maxEmprestimosUsuario) {
            maxEmprestimosUsuario = totalEmprestimosUsuario;
            usuarioMaisAtivo = usuario.nome;
        }
    }

    // Calcular a média de empréstimos por dia
    if (fecharDia > 0) {
        mediaEmprestimosPorDia = static_cast<float>(totalEmprestimos) / fecharDia;
    }

    // Exibir o relatório
    cout << "\n--- Relatório de Empréstimos ---\n";
    cout << "Total de Empréstimos: " << totalEmprestimos << endl;
    cout << "Livro mais Popular: " << livroMaisPopular << " com " << maxEmprestimosLivro << " empréstimos.\n";
    cout << "Usuário mais Ativo: " << usuarioMaisAtivo << " com " << maxEmprestimosUsuario << " empréstimos.\n";
    cout << "Categoria mais Emprestada: " << categoriaMaisPopular << " com " << maxCategoria << " empréstimos.\n";
    cout << "Média de Empréstimos por Dia: " << mediaEmprestimosPorDia << " empréstimos por dia.\n";
}