#include <vr/RenderItem.h>
#include <vr/glErrorUtil.h>

using namespace vr;

RenderItem::RenderItem()
{
}

MeshVector &RenderItem::getMeshes()
{
    return m_meshes;
}

void RenderItem::add(std::shared_ptr<Mesh> &mesh)
{
    m_meshes.push_back(mesh);
}

void RenderItem::setInitialTransform(const glm::mat4 &m)
{
    this->object2world = m_initialTransform = m;
}

RenderItem::~RenderItem()
{
}

void RenderItem::resetTransform()
{
    this->object2world = m_initialTransform;
}

/**
 * Draw the node (all of its meshes)
 */
void RenderItem::render(std::shared_ptr<vr::Shader> shader)
{
    CHECK_GL_ERROR_LINE_FILE();

    for (auto m : m_meshes)
    {
        m->render(shader, this->object2world);
    }
}

/// Calculate and return a bounding box for this Node based on its Mesh objects
BoundingBox RenderItem::calculateBoundingBox()
{
    BoundingBox box;

    for (auto m : m_meshes)
    {
        BoundingBox meshBox = m->calculateBoundingBox();
        meshBox = meshBox * this->object2world;
        box.expand(meshBox);
    }

    return box;
}