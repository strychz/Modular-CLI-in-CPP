#pragma once
#include <string>
#include <vector>

// Interface para comandos CLI
class ICommand {
public:
    virtual ~ICommand() = default;

    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
    virtual int run(const std::vector<std::string>& args) = 0;
};
