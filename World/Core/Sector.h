// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef Sector_h__
#define Sector_h__

#include <array>
#include "Block.h"
#include <glm/glm.hpp>
#include "RenderSector.h"

class Sector
{
public:
  enum 
  {
    SECTOR_RADIUS = 15,
    SECTOR_SIZE = SECTOR_RADIUS * 2 + 1,
  };

public:
  Sector(const glm::ivec3 &position, RenderSector &renderSector);
  ~Sector();

  const glm::ivec3 &GetSectorPosition() const;

  /// ������� ���� � ��������� ����������� �������.
  PBlock GetBlock(const glm::ivec3 &pos);

  /// ���������� ���� � �������� �������.
  /// ������������ ���� ����� ������.
  void SetBlock(const glm::ivec3 &pos, PBlock block);

  void Update(class World *world);

  RenderSector &GetRenderSector();

private:
  std::array<PBlock, SECTOR_SIZE * SECTOR_SIZE * SECTOR_SIZE> mBlocks;
  std::array<glm::ivec3, SECTOR_SIZE * SECTOR_SIZE * SECTOR_SIZE> mBlocksPos;

  glm::ivec3 mPos;

  RenderSector &mRenderSector;
};



#endif // Sector_h__