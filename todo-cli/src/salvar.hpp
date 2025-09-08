#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

void salvar_tarefas(const string & tarefa, const string & nome_arquivo) {
    nlohmann::json j;
    j["tarefa"] = tarefa;

    ofstream arquivo(nome_arquivo);
    arquivo << j.dump(4);
    arquivo.close();

}