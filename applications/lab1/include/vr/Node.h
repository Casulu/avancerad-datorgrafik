#pragma once

#include <string>

#include <vr/Visitor.h>

class Node
{
public:
    Node(const std::string &name = "") : m_name(name)
    {
    }
    virtual void accept(Visitor &v) = 0;
    std::string getName() { return m_name; }

private:
    std::string m_name
}