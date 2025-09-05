#pragma once
#include <string>
#include <vector>
#include <optional>

struct Task {
    int id;
    std::string title;
    bool done = false;
};

class ITaskRepository {
public:
    virtual ~ITaskRepository() = default;

    virtual Task create(const std::string& title) = 0;
    virtual std::vector<Task> list(bool includeDone = true) = 0;
    virtual std::optional<Task> markDone(int id) = 0;
    virtual bool remove(int id) = 0;
};
