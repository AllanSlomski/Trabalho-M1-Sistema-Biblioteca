#include <iostream>
#include <vector>
#include "usuarios.hpp"  
using namespace std;

float multa;

void cadastrarUsuario(vector<Usuario> & usuarios) {
    Usuario novoUsuario;
    cin.ignore();
    cout << "Nome do Usuário: "; getline(cin, novoUsuario.nome);
    //novoUsuario.multa = 0.0;
    usuarios.push_back(novoUsuario);
}