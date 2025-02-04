#pragma once

#include <vr/Transform.h>

#include <vr/Group.h>

#include <vr/Geometry.h>

class Visitor
{
public:
    virtual void visit(Group &) = 0;
    virtual void visit(Transform &) = 0;
    virtual void visit(Geometry &) = 0;
}