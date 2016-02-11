// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef RenderMeshGL1_h__
#define RenderMeshGL1_h__

#include "IRenderMeshStrategy.h"
#include <array>

/// ��������� ��������� ���� � ������� ���������� �������.
class RenderMeshDList : public IRenderMeshStrategy
{
public:
  RenderMeshDList();
  virtual ~RenderMeshDList();

public:
  void SetAttribute(AttributeType type, Attribute attribute) override;

  void Compile(const float *vertex, size_t vertexCount, size_t vertexSize, const size_t *index, size_t indexCount) override;

  void Draw() const override;

private:
  std::array<Attribute, ATTRIBUTE_SIZE> mAttributeState;

  bool mCreated = false;
  uint32_t mList = 0;
};



#endif // RenderMeshGL1_h__