// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef IRenderMesh_h__
#define IRenderMesh_h__

#include "Vertex.h"

class IRenderMesh
{
public:
  virtual ~IRenderMesh() {};

  /// ��������� � �������� �������.
  /// ��� ������� ���� �������� ���������� ������������� �������, 
  /// �� ������� ������ ����� ����� ����� ������.
  /// Attribute::size ������ �������� � ������.
  /// Attribute::offset �������� �������� � ������.
  /// Attribute::enabled �������� ��� ��������� �������.
  virtual void SetAttribute(AttributeType type, Attribute attribute) = 0;

  /// ������� ����� � �����������.
  /// @param vertex ��������� �� ������ ������ ������.
  /// @param vertexSize ���������� ��������� � ������ ������.
  /// @param index ��������� �� ������ ������ ��������.
  /// @param indexSize ���������� ��������� � ������ ��������.
  virtual void Compile(const float *vertex, size_t vertexCount, size_t vertexSize, const size_t *index, size_t indexCount) = 0;

  /// ������������� �� �����.
  virtual bool IsCompiled() = 0;

  /// ���������� �����.
  virtual void Draw() = 0;

};


#endif // IRenderMesh_h__