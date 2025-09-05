#include <catch2/catch_test_macros.hpp>
#include "ITaskRepository.hpp"

class FakeRepo : public ITaskRepository {
    std::vector<Task> tasks;
    int nextId = 1;
public:
    Task create(const std::string& title) override {
        Task t{nextId++, title, false};
        tasks.push_back(t);
        return t;
    }

    std::vector<Task> list(bool includeDone = true) override {
        return tasks;
    }

    std::optional<Task> markDone(int id) override {
        for (auto& t : tasks)
            if (t.id == id) {
                t.done = true;
                return t;
            }
        return std::nullopt;
    }

    bool remove(int id) override {
        auto size = tasks.size();
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                                   [&](const Task& t) { return t.id == id; }),
                                   tasks.end());
        return tasks.size() < size;
    }
};

TEST_CASE("Task repository works") {
    FakeRepo repo;

    auto t = repo.create("Test task");
    REQUIRE(t.id == 1);
    REQUIRE(repo.list().size() == 1);

    auto done = repo.markDone(1);
    REQUIRE(done->done == true);

    REQUIRE(repo.remove(1) == true);
    REQUIRE(repo.list().empty());
}
