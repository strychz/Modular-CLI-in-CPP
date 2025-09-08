#include <CLI/CLI.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include "adicionar.hpp"
#include "remover.hpp"
#include "listar.hpp"
#include "salvar.hpp"
#include "concluir.hpp"
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv){
    CLI::App app{"CLI Modular"};
    app.set_help_all_flag("--help-all", "Mostra todas as opções, incluindo as herdadas");

/*Criou o objeto principal da interface.*/
    
    string titulo;
    string nome_arquivo = "tarefas.json";
    auto* add = app.add_subcommand("add", "Adiciona uma nova tarefa");
    add->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON");
    add->add_option("titulo", titulo, "Título")->required();

/*Variável para armazenar o nome da tarefa, criação do subcomando "add" para adicionar o que for desejado, não necessariamente precisa ser uma tarefa.
Também adiciona a opção obrigatória chamada "tarefa" que o usuário deve fornecer ao usar o subcomando "add", posteriormente pretendo alterar o nome "tarefa" para deixar mais abrangente para o usuário.*/
    
    bool listar = false;
    auto* list = app.add_subcommand("list", "Lista de todas as tarefas");
    list->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON")->required();
    list->add_flag("-a, --all", listar, "Listar todas as tarefas concluídas também");

/*Cria subcomando "list" para listar todas as tarefas.*/

    auto* concluir_cmd = app.add_subcommand("concluir", "Marca como concluído/feito");
    concluir_cmd->add_option("titulo", titulo, "A ser concluída")->required();
    concluir_cmd->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON")->required();

/*Cria o comando que marca como concluido o que for desejado, agora podendo ser listando também as coisas concluidas*/

    auto* rm = app.add_subcommand("rm", "Remove o que o usuário solicitar dentro do arquivo");
    rm->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON")->required();

    CLI11_PARSE(app, argc, argv);

/*Faz o parsing do que for dado de entrada pelo usuário, como forma de teste estarei utilizando o CLI11, mas futuramente troco pro CLI20.*/

    if(*add){
        adicionar_tarefa(titulo);
        salvar_tarefas(titulo, nome_arquivo); 

    // Chama a função para salvar em JSON
    } else if (*list){
        listar_tarefas(nome_arquivo);
    }

    return 0;

}