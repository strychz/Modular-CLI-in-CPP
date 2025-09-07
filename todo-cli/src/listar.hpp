#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

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