#ifndef USUARIOS_HPP  
#define USUARIOS_HPP
#include <iostream>
#include <vector>

using namespace std;

struct Usuario {
  string nome;
  int idade;
  int livrosUsuario;
  string email;
  string senha;
};

void pesquisarUsuario(string nome);
void imprimirUsuario(Usuario usuarios);
void cadastrarUsuario(string nome, int idade);
void pesquisarLivrosPorUsuario();

#endif