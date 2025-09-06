#include <CLI/CLI.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;

void adicionar_tarefa(const string & tarefa){
    cout << "Sua(s) tarefa(s) foi/foram adicionada(s): " << tarefa << endl;
/*Mostrará para o usuário que sua tarefa foi adicionada com sucesso;
Para adicionar a lógica para salvar a tarefa em um arquivo ou banco de dados.*/
}

void remover_tarefa(const string & tarefa){
    cout << "Removendo tarefa: " << tarefa << endl;

/*Implementaria a lógica para remover a tarefa de um arquivo ou banco de dados. Entretanto, ainda não está configurada e ainda não foi inserida no objeto principal da interface*/
}

void listar_tarefas(const string & nome_arquivo){
    cout << "Listando tarefa(s)..." << endl;
    ifstream arquivo(nome_arquivo);
    if (!arquivo) {
        cout << "Nenhuma tarefa encontrada." << endl;
        return;
    }
    nlohmann::json j;
    arquivo >> j;
    cout << "Tarefas salvas:" << endl;
    cout << j.dump(4) << endl; 
// Imprime o conteúdo do JSON formatado
    arquivo.close();

//Implementaria a lógica para ler as tarefas de um arquivo ou banco de dados e exibi-las.
}

void salvar_tarefas(const string & tarefa, const string & nome_arquivo) {
    nlohmann::json j;
    j["tarefa"] = tarefa;

    ofstream arquivo(nome_arquivo);
    arquivo << j.dump(4);
    arquivo.close();

}

int main(int argc, char** argv){
    CLI::App app{"CLI Modular"};

//Criou o objeto principal da interface.
    string tarefa;
    string nome_arquivo = "tarefas.json";
    auto* add = app.add_subcommand("add", "Adiciona uma nova tarefa");
    add->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON");
    add->add_option("tarefa", tarefa, "Nome da tarefa")->required();
/*Variável para armazenar o nome da tarefa, criação do subcomando "add" para adicionar o que for desejado, não necessariamente precisa ser uma tarefa.
Também adiciona a opção obrigatória chamada "tarefa" que o usuário deve fornecer ao usar o subcomando "add", posteriormente pretendo alterar o nome "tarefa" para deixar mais abrangente para o usuário.*/

    auto* list = app.add_subcommand("list", "Lista de todas as tarefas");
    list->add_option("-f, --file", nome_arquivo, "Nome do arquivo JSON")->required();
    //Cria subcomando "list" para listar todas as tarefas.

    CLI11_PARSE(app, argc, argv);

/*Faz o parsing do que for dado de entrada pelo usuário, como forma de teste estarei utilizando o CLI11, mas futuramente troco pro CLI20.*/

    if(*add){
        adicionar_tarefa(tarefa);
        salvar_tarefas(tarefa, nome_arquivo); 

    // Chama a função para salvar em JSON
    } else if (*list){
        listar_tarefas(nome_arquivo);
    }

    return 0;

}