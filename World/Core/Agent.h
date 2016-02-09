// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef Agent_h__
#define Agent_h__

#include "..\tools\StringIntern.h"
#include "GameObjectParams.h"
#include <memory>
#include <type_traits>
#include <string>

class GameObject;


using PAgent = std::unique_ptr<class Agent>;

template<class T, class... Args>
inline std::unique_ptr<T> MakeAgent(Args&&... args)
{
  return std::make_unique<T>(std::forward<Args>(args)...);
}

/// �����.
/// ��� ������ �������� ��������� �� ����� ���������� � �� ��������. ���������� ���� �������.
/// ��� ������ �������� ��������� � ������������. ����� �������������� ��� �������������
/// ����������� �������. ����� ����� �������������.
/// � �������, ������� ����������� ������������ � ������� �������, ��� ������ �������������.
class Agent
{
public:
  /// ������� ����� � ��������� ����� � ������.
  Agent(GameObject *parent, const std::string &type, const std::string &name = "");
  virtual ~Agent();

  virtual PAgent Clone(GameObject *parent, const std::string &name = "") = 0;

  virtual void Update(const GameObjectParams &params) = 0;

  /// ������� ��� ���� ������.
  const StringIntern &GetTypeName();

  /// ������� ��� ������ ���������� ����.
  const StringIntern &GetName();

  /// ������� ������ ��� ������. �������� ��� ���� � ��� ������.
  const StringIntern &GetFullName();

protected:
  GameObject *mParent;

  const StringIntern mTypeName;
  const StringIntern mAgentName;
  const StringIntern mFullName;

};



#endif // Agent_h__