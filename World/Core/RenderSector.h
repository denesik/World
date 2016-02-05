// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef RenderSector_h__
#define RenderSector_h__

#include "..\Graphic\Render\MultiModel.h"


/// ������ ������.
/// ����� ������: ���� ���������� ����, ��������� �� ���� ������, ����������� ������ ������,
/// � ������ ������ ����������� ������, ������� ��� � ���� �����.
/// ����� �������: ����� ����������� � ������.
class RenderSector
{
public:
  RenderSector();
  ~RenderSector();

  /// �������� �������, ��� ��� ��������� ����������.
  void Changed();

  /// ����� �� ����������� ���������?
  bool IsNeedBuild() const;

  void Push(const Model &model);

  void Update();

private:
  MultiModel mModel;

  bool mIsChanged = false;
  bool mIsNeedBuild = true;

};



#endif // RenderSector_h__