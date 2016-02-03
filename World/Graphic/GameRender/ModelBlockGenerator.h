// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef ModelBlockGenerator_h__
#define ModelBlockGenerator_h__

#include "IModelGenerator.h"
#include <array>
#include "..\..\tools\StringIntern.h"


/// ��������� ������ ��� �����.
/// ��� ����������� �������������, ��� ������ ������� ����� ����� ������� ��������.
/// ��� �������� ������ ���������� � ����� ���������� ������.
/// ��� ������ ������� ����� ����� �������, ����� �� �������� �������. 
class ModelBlockGenerator : public IModelGenerator
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
  ModelBlockGenerator();
  ~ModelBlockGenerator();

  Model Create() const override;

  void SetPosition(const glm::vec3 &pos);

  void SetTexture(int side, std::string texture);

  void Enable(int side, bool enabled);

  const StringIntern &GetTypeName() const;

private:
  /// ������ ��������� ������� ��� ������ ���� � ������.
  std::array<std::string, 6> mTextures;

  /// ������� ������� ��� ���.
  std::array<bool, 6> mEnabled;

  PTexture mActiveTexture;

  glm::vec3 mPosition;

  const StringIntern mTypeName;
};



#endif // ModelBlockGenerator_h__