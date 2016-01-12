// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef BlocksLibrary_h__
#define BlocksLibrary_h__

#include "GameObject.h"
#include "..\tools\StringIntern.h"
#include <unordered_map>


class BlocksLibrary
{
public:
  BlocksLibrary();
  ~BlocksLibrary();

  void Registry(const StringIntern &name, PGameObject block, bool isStatic = true);


  /// ������� ����.
  /// ���� ���� �����������, ������������ ��������� �� ��������� �����, ���������� � ����������.
  /// ���� ���� ������������, ��������� ����� �����.
  /// @param blockId ������������� �����.
  PGameObject Create(const StringIntern &name);

private:
  std::unordered_map<StringIntern, PGameObject> mBlocks;

};



#endif // BlocksLibrary_h__