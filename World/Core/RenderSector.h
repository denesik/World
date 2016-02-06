// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef RenderSector_h__
#define RenderSector_h__

#include "..\Graphic\Render\DinamicModel.h"
#include "..\Graphic\Render\RenderableMesh.h"
#include <atomic>


/// ������ ������.
/// ����� ������: ���� ���������� ����, ��������� �� ���� ������, ����������� ������ ������,
/// � ������ ������ ����������� ������, ������� ��� � ���� �����.
/// ����� �������: ����� ����������� � ������.
class RenderSector
{
public:
  RenderSector();
  ~RenderSector();

  /// ��������, ��� ��������� ����������.
  void Changed();

  /// ����� �� ����������� ���������?
  bool IsNeedBuild() const;

  void Push(const StaticModel &model, const glm::vec3 &pos);

  void Update();

  void Draw();

private:
  DinamicModel mModel;

  bool mIsChanged = true;
  bool mIsNeedBuild = false;

  std::atomic<bool> mRebuildBuffers = false;

};



#endif // RenderSector_h__