// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef ModelBlockGenerator_h__
#define ModelBlockGenerator_h__

#include "IMeshGenerator.h"
#include <array>
#include "..\tools\StringIntern.h"


/// ��������� ������ ��� �����.
/// ��� ����������� �������������, ��� ������ ������� ����� ����� ������� ��������.
/// ��� �������� ������ ���������� � ����� ���������� ������.
/// ��� ������ ������� ����� ����� �������, ����� �� �������� �������. 
class MeshBlockGenerator : public IMeshGenerator
{
public:
  enum Side
  {
    EMPTY = 0,

    FRONT = 1 << 0,
    RIGHT = 1 << 1,
    BACK = 1 << 2,
    LEFT = 1 << 3,
    TOP = 1 << 4,
    BOTTOM = 1 << 5,

    ALL = 0x3F,
  };

public:
  MeshBlockGenerator();
  ~MeshBlockGenerator();

  void Create(const glm::vec3 &pos, Mesh<VertexVT> &mesh) override;

  void SetTexture(int side, std::string texture);

  void Enable(int side, bool enabled);

  const StringIntern &GetTypeName() const;

private:
  /// ������ ��������� ������� ��� ������ ���� � ������.
  std::array<glm::vec4, 6> mTextures;

  /// ������� ������� ��� ���.
  std::array<bool, 6> mEnabled;

  const StringIntern mTypeName;
};



#endif // ModelBlockGenerator_h__