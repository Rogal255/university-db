#pragma once
#include "PersonRandomBuilder.hpp"

class StudentRandomBuilder : public PersonRandomBuilder {
public:
    ~StudentRandomBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;

private:
    std::vector<size_t> usedIndexes;
    size_t maxNumberOfIndexes {10'000};
};
