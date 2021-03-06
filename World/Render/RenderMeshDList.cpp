// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#include "RenderMeshDList.h"

#include <assert.h>
#include <gl/glew.h>
#include "OpenGLCall.h"

RenderMeshDList::RenderMeshDList()
{
  for (auto &i : mAttributeState)
  {
    i = { false, 0, 0 };
  }
}


RenderMeshDList::~RenderMeshDList()
{
  GL_CALL(glDeleteLists(mList, 1));
}

void RenderMeshDList::SetAttribute(AttributeType type, Attribute attribute)
{
  mAttributeState[type] = attribute;
}

void RenderMeshDList::Compile(const float *vertex, size_t vertexCount, size_t vertexSize, const size_t *index, size_t indexCount)
{
  assert(vertex && "vertex pointer is null");
  assert(index && "index pointer is null");
  if (!mCreated)
  {
    GL_CALL(mList = glGenLists(1));
    mCreated = true;
  }

  /// ������� ������ ������ � ��������, ����� ������������ ���������� ������.
  /// ��� ����� ����� ������� � ������������������ �������.

  GL_CALL(glNewList(mList, GL_COMPILE));
  GL_CALL(glBegin(GL_TRIANGLES));
  for (size_t i = 0; i < indexCount; ++i)
  {
    if (mAttributeState[ATTRIBUTE_TEXTURE].enabled)
    {
      GL_CALL(glTexCoord2fv(&vertex[(vertexSize * index[i] + mAttributeState[ATTRIBUTE_TEXTURE].offset) / sizeof(float)]));
    }
    if (mAttributeState[ATTRIBUTE_VERTEX].enabled)
    {
      GL_CALL(glVertex3fv(&vertex[(vertexSize * index[i] + mAttributeState[ATTRIBUTE_VERTEX].offset) / sizeof(float)]));
    }
  }
  GL_CALL(glEnd());
  GL_CALL(glEndList());
}

void RenderMeshDList::Draw() const
{
  if (mCreated)
  {
    GL_CALL(glCallList(mList));
  }
}

