// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef Block_h__
#define Block_h__

#include "GameObject.h"
#include "StaticRenderAgent.h"
#include "..\tools\StringIntern.h"

using PBlock = std::shared_ptr<class Block>;

/// ����. ����� ���� ����������� ��� ������������.
/// � ������������ ����� ���� ����������� ������ �����.
/// � ������������� ����� ���� ����������� ���� ������������ ������ �����.
/// ���������� ������������ ������ ������ ������������ �������� 
/// ������ ��� ��� ��������� ����������� ��������� �������.
/// ���������� ������������� ������ ������ ������������ ������ ������ �����.
class Block : public GameObject
{
public:
  Block();
  ~Block();

  void Update(GameObjectParams &params) override;

  void UpdateGraphic(GameObjectParams &params);

  inline bool IsStatic() const noexcept
  {
    return mIsStatic;
  }

private:
  static const StringIntern mRenderAgentName;
  const bool mIsStatic = true;
};



#endif // Block_h__