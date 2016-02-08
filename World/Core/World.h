// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef World_h__
#define World_h__

#include <unordered_map>
#include <glm/glm.hpp>
#include <memory>
#include <list>
#include "Sector.h"
#include "Player.h"

namespace std
{
  template <>
  struct hash<glm::ivec3>
  {
    std::size_t operator()(glm::ivec3 const& v) const
    {
      std::size_t h1 = std::hash<int32_t>()(v.x);
      std::size_t h2 = std::hash<int32_t>()(v.y);
      std::size_t h3 = std::hash<int32_t>()(v.z);
      return ((h1 ^ (h2 << 1)) >> 1) ^ (h3 << 1);
    }
  };
}

class World
{
public:
  World();
  ~World();

  void LoadSector(const glm::ivec3 &position);

  void Update();

  void Draw();

  /// �������� ������ �� ������� �������.
  Sector *GetSector(const glm::ivec3 &position);

  PBlock GetBlock(const glm::ivec3 &position);

  /// ���������� ���� � �������� �������.
  /// ������������ ���� ����� ������.
  void SetBlock(const glm::ivec3 &pos, PBlock block);

  Player *GetPlayer();

private:
  std::unordered_map<glm::ivec3, Sector> mSectors;
  std::unordered_map<glm::ivec3, RenderSector> mRenderSectors;

  glm::ivec3 mLastLoadPos;
  std::list<glm::ivec3> mListLoad;

  Sector *mCurrentSector;

  std::unique_ptr<Player> mPlayer;
};



#endif // World_h__