#ifndef ITASKREPOSITORY_HPP
#define ITASKREPOSITORY_HPP

#include <vector>
#include <optional>
#include "../models/Task.hpp"

class ITaskRepository {
public:
    virtual ~ITaskRepository() = default;

    virtual void addTask(const Task& task) = 0;
    virtual bool removeTask(int taskId) = 0;
    virtual std::optional<Task> getTaskById(int taskId) const = 0;
    virtual std::vector<Task> getAllTasks() const = 0;
    virtual bool updateTask(int taskId, const Task& updatedTask) = 0;
};

#endif  //ITASKREPOSITORY_HPP
#ifndef ITASKREPOSITORY_HPP