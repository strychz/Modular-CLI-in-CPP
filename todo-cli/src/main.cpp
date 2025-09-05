#include <CLI/CLI.hpp>
#include <iostream>

using namespace std;

void adicionar_tarefa(const string & tarefa){
    cout << "Sua(s) tarefa(s) foi/foram adicionada(s): " << tarefa << endl;
// Mostrará para o usuário que sua tarefa foi adicionada com sucesso;
//Para adicionar a lógica para salvar a tarefa em um arquivo ou banco de dados.
}

void listar_tarefas(){
    cout << "Listando tarefa(s)..." << endl;
//Implementaria a lógica para ler as tarefas de um arquivo ou banco de dados e exibi-las.
}

int main(int argc, char** argv){
    CLI::App app{"CLI Modular"};

//Criou o objeto principal da interface.

    string tarefa;
    auto* add = app.add_subcommand("add", "Adiciona uma nova tarefa");
    add->add_option("tarefa", tarefa, "Nome da tarefa")->required();

/*Variável para armazenar o nome da tarefa, criação do subcomando "add" para adicionar o que for desejado, não necessariamente precisa ser uma tarefa.
Também adiciona a opção obrigatória chamada "tarefa" que o usuário deve fornecer ao usar o subcomando "add", posteriormente pretendo alterar o nome "tarefa" para deixar mais abrangente para o usuário.*/

    auto* list = app.add_subcommand("list", "Lista de todas as tarefas");

    //Cria subcomando "list" para listar todas as tarefas.

    CLI11_PARSE(app, argc, argv);

/*Faz o parsing do que for dado de entrada pelo usuário, como forma de teste estarei utilizando o CLI11, mas futuramente troco pro CLI20.*/

    if(*add){
        adicionar_tarefa(tarefa);
    } else if (*list){
        listar_tarefas();
    }

    return 0;

}