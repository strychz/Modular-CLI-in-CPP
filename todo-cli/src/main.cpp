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

int main(int argc, char** argv){
    CLI::App app{"CLI Modular"};
    app.set_help_all_flag("--help-all", "Mostra todas as opções, incluindo as herdadas");

/*Criou o objeto principal da interface.*/
    
    std::string titulo;
    std::string nome_arquivo = "tarefas.json";
    auto* add = app.add_subcommand("add", "Adiciona uma nova tarefa");
    add->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON");
    add->add_option("titulo", titulo, "Título")->required();
    add->callback([&](){
        adicionar_tarefa(titulo);
        salvar_tarefas(titulo, nome_arquivo);
    });

/*Variável para armazenar o nome da tarefa, criação do subcomando "add" para adicionar o que for desejado, não necessariamente precisa ser uma tarefa.
Também adiciona a opção obrigatória chamada "tarefa" que o usuário deve fornecer ao usar o subcomando "add", posteriormente pretendo alterar o nome "tarefa" para deixar mais abrangente para o usuário.*/
    
    bool listar = false;
    auto* list = app.add_subcommand("list", "Lista de todas as tarefas");
    list->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON");
    list->add_flag("-a, --all", listar, "Listar todas as tarefas concluídas também");
    list->callback([&](){
        listar_tarefas(nome_arquivo);
    });

/*Cria subcomando "list" para listar todas as tarefas.*/

    int concluir_id=-1;
    auto* concluir = app.add_subcommand("concluir", "Marca o ID como concluída");
    concluir->add_option("id", concluir_id, "ID da tarefa a ser marcada como concluída")->required();
    concluir->callback([&](){
        concluir_tarefa(concluir_id, nome_arquivo);
    });

/*Cria o comando que marca como concluido o que for desejado, agora podendo ser listando também as coisas concluidas*/

    int remover_id=-1;
    auto* remover = app.add_subcommand("rm", "Remove a tarefa pelo ID");
    remover->add_option("id", remover_id, "ID da tarefa a ser removida")->required();
    remover->callback([&](){
        remover_tarefa(remover_id, nome_arquivo);
    });

/*Cria o comando que remove o que for desejado, agora podendo ser listando também as coisas concluidas*/
    
    CLI11_PARSE(app, argc, argv);

/*Faz o parsing do que for dado de entrada pelo usuário, como forma de teste estarei utilizando o CLI11.*/

    return 0;

}