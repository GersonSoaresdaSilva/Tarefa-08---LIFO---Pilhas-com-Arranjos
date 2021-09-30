/*Faça um programa estruturado para controlar uma pilha com arranjo simples contendo os atributos: IDADE, NOME e SALÁRIO.*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#define max 3  // definir tamanho da pilha

using namespace std;

typedef struct lifo pilha;

struct lifo {
    int topo = -1;
    string nome [max];
    int idade [max];
    double sal [max];
};
pilha p;

//minhas subrotinas
string ler_nome();
int ler_idade();
double ler_sal();
pilha push();
pilha pop();
void mostrar();
bool cheia();
bool vazia();
int tela();
void controle();

int main() {
    setlocale(LC_ALL, "Portuguese");
    controle();
    return 0;
}

string ler_nome() {
    string nomePil;
    cin.ignore();
    cout << "\nDigite o nome.: ";
    getline(cin, nomePil);
    return nomePil;
}

int ler_idade() {
    int idadePil;
    cout << "\nDigite a idade.: ";
    cin >> idadePil;
    return idadePil;
}

double ler_sal() {
    double salPil;
    cout << "\nDigite o salário.: ";
    cin >> salPil;
    return salPil;
}

pilha push() {
    if (cheia() == true) {
        cout << "\nErro: A Pilha está cheia!" << endl;
    } else {
        p.topo++;
        string auxNome = ler_nome();
        p.nome[p.topo] = auxNome;
        p.idade[p.topo] = ler_idade();
        p.sal[p.topo] = ler_sal();
        cout << "\nCadastro realizado com Sucesso!" << endl;
    }
    system("sleep 4");
    return p;
}

pilha pop() {
    if (vazia() == true) {
        cout << "\nErro: A pilha está vazia!" << endl;
    } else {
        cout << "\nO seguinte cadastro será removido:";
        cout << "\nPosição.: " << p.topo; 
        cout << "\nNome.: " << p.nome[p.topo];
        cout << "\nIdade.: " << p.idade[p.topo];
        cout << "\nSalário.: " << p.sal [p.topo] << endl;
        cout << "\nCadastro Removido!" << endl;
        p.topo--;
    }
    system("sleep 4");
    return p;
}

void mostrar() {
    if (vazia() == true) {
        cout << "\nErro: A pilha está vazia!" << endl;
    } else {
        cout << "\n***  Lista de Funcionários  ***" << endl;
        for (int i = 0; i <= p.topo; i++) {
            cout << "\nPosição.: [" << i << "]" << "\nNome.: " << p.nome [i] << "\nIdade.: " << p.idade [i] << "\nSalário.: " << p.sal [i] << endl;
        }
    }
    system("sleep 4");
}

bool cheia() {
    if (p.topo >= max-1) {
        return true;        
    }        
    else {
        return false; 
    }        
}

bool vazia() {
    if (p.topo == -1)
        return true;
    else
        return false;
}

int tela() {
    int opcMenu;
    system("clear");
    cout << "\n***  Menu de Controle  ***" << endl;
    cout << "\n1 - Push \n2 - Pop \n3 - Listar \n4 - Sair \nOpção.: ";
    cin >> opcMenu;
    return opcMenu;
}

void controle() {
    int opt;
    while (true) {
        opt = tela();
        switch (opt) {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: mostrar();
                break;
            case 4: exit(0);
                break;
            default: cout << "\nErro.: Opção Inválida!" << endl;
                system("sleep 4");
                break;
        }
    }
}