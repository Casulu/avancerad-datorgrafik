#pragma once

#include <string>
#include <vr/Group.h>

class Transform : public Group
{
public:
    Transform(const std::string &name = "") : Group(name) {}
    void accept(Visitor &v) override
    {
        // push transform
        Group::accept(v);
        // Pop transform
    }
}