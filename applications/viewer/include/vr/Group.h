#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include <vr/Node.h>

class Group : public Node
{
public:
    Group(const std::string &name = "") : Node(name) {}
    void addChild(Node *n)
    {
        m_children.push_back(std::shared_ptr(n));
    }
    void accept(Visitor &v)
    {
        std::cerr << "Accept: " << getName() << std::endl;
        v.visit(*this);
    }
    std::vector<std::shared_ptr<Node>> getChildren() { return m_children; }

private:
    std::vector<std::shared_ptr<Node>> m_children
}