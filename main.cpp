#include <iostream>
#include <vector>
#include "biblioteca.hpp"
// #include "usuarios.hpp"
using namespace std;
#define TAM 50

int main() {
    int opcao;
    cin >> opcao;
    menu(opcao);

    vector<Livro> acervo(TAM);
    
    Livro l1 = {"Nada de Novo no Front", "Erich Maria Remarque", "Romance", 1930, 220, 1, 0};
    acervo.push_back(l1);

    Livro l2 = {"Guerra Do Velho", "John Scalzi", "Ficção cientifica", 2016, 357, 1, 0};
    acervo.push_back(l2);

    Livro l3 = {"1984", "George Orwell", "Distopia", 1949, 328, 1, 0};
    acervo.push_back(l3);

    Livro l4 = {"Orgulho e Preconceito", "Jane Austen", "Romance", 1813, 432, 1, 0};
    acervo.push_back(l4);

    Livro l5 = {"O Senhor dos Anéis: A Sociedade do Anel", "J.R.R. Tolkien", "Fantasia", 1954, 423, 1, 0};
    acervo.push_back(l5);

    Livro l6 = {"A Revolução dos Bichos", "George Orwell", "Sátira", 1945, 112, 1, 0};
    acervo.push_back(l6);

    Livro l7 = {"Cem Anos de Solidão", "Gabriel García Márquez", "Realismo mágico", 1967, 417, 1, 0};
    acervo.push_back(l7);

    Livro l8 = {"O Sol é para Todos", "Harper Lee", "Drama", 1960, 281, 1, 0};
    acervo.push_back(l8);

    Livro l9 = {"O Código Da Vinci", "Dan Brown", "Thriller", 2003, 489, 1, 0};
    acervo.push_back(l9);

    Livro l10 = {"Matar um Rouxinol", "Harper Lee", "Drama", 1960, 281, 1, 0};
    acervo.push_back(l10);

    do {
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
        
            case 1:{
              cout << "-Cadastrar Livro\n-";
              cadastrarLivro(acervo);
            break;
            }
            
            case 2:{
                
                break;
            }
               
            case 3:{
                
                break;
            }
               
            case 4:{
                
                break;
            }
               
            case 5:{
            string criterio;
            cout << "-Pesquisar Livro\n-";
            cin>> criterio;
            pesquisarLivros(acervo);
            break;
            }
                
            case 6:{
                listagemDeLivros(acervo);
              break;
            }
               
            case 7:{
                
                break;
            }
               
            case 8:{
                
                break;
            }
              
            case 0:{
                
                break;
            }
                
            default:{
                
                break;
            }
            }

    } while (opcao != 0);

    return 0;
}
