#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
    public:
        int id;
        std::string titulo;
        bool done;

        Task(int id, const std::string & titulo, bool done)
            : id(id), titulo(titulo(titulo)), done(done) {}

/* é o construtor padrão, vai ser necessário para alguns vetores, opções, etc.*/
        Task() = default;
}

#endif //TASK_HPP