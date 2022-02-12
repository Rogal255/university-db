#pragma once
#include "PersonRandomBuilder.hpp"

class StudentRandomBuilder : public PersonRandomBuilder {
public:
    ~StudentRandomBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;

private:
    std::vector<std::size_t> usedIndexes;
    int maxNumberOfIndexes {10'000};
};
