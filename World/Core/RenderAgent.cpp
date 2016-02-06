// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#include "RenderAgent.h"
#include "GameObject.h"
#include "Sector.h"
#include "MeshBlockGenerator.h"
#include "..\Graphic\RegistryGraphic.h"
#include "World.h"

RenderAgent::RenderAgent(GameObject *parent)
  : Agent(parent, "RenderAgent")
{
  mModel.SetTexture(std::get<0>(REGISTRY_GRAPHIC.GetTextureManager().GetTexture("Textures/stone.png")));
}


RenderAgent::~RenderAgent()
{
}

void RenderAgent::Update(const GameObjectParams &params)
{
  if (params.sector->GetRenderSector().IsNeedBuild())
  {
    const int32_t size = static_cast<int32_t>(Sector::SECTOR_SIZE);
    const int32_t radius = static_cast<int32_t>(Sector::SECTOR_RADIUS);

    size_t sides = MeshBlockGenerator::ALL;
    auto pos = static_cast<glm::ivec3>(params.pos) - params.sector->GetSectorPosition() * size;
    if (pos.x < radius)
    {
      ++pos.x;
      if (params.sector->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::RIGHT;
      }
      --pos.x;
    } 
    else
    {
      auto pos = static_cast<glm::ivec3>(params.pos);
      ++pos.x;
      if (params.world->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::RIGHT;
      }
    }
    if (pos.x > -radius)
    {
      --pos.x;
      if (params.sector->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::LEFT;
      }
      ++pos.x;
    }
    else
    {
      auto pos = static_cast<glm::ivec3>(params.pos);
      --pos.x;
      if (params.world->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::LEFT;
      }
    }

    if (pos.y < radius)
    {
      ++pos.y;
      if (params.sector->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::BACK;
      }
      --pos.y;
    }
    else
    {
      auto pos = static_cast<glm::ivec3>(params.pos);
      ++pos.y;
      if (params.world->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::BACK;
      }
    }
    if (pos.y > -radius)
    {
      --pos.y;
      if (params.sector->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::FRONT;
      }
      ++pos.y;
    }
    else
    {
      auto pos = static_cast<glm::ivec3>(params.pos);
      --pos.y;
      if (params.world->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::FRONT;
      }
    }

    if (pos.z < radius)
    {
      ++pos.z;
      if (params.sector->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::TOP;
      }
      --pos.z;
    }
    else
    {
      auto pos = static_cast<glm::ivec3>(params.pos);
      ++pos.z;
      if (params.world->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::TOP;
      }
    }
    if (pos.z > -radius)
    {
      --pos.z;
      if (params.sector->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::BOTTOM;
      }
      ++pos.z;
    }
    else
    {
      auto pos = static_cast<glm::ivec3>(params.pos);
      --pos.z;
      if (params.world->GetBlock(pos))
      {
        sides &= ~MeshBlockGenerator::BOTTOM;
      }
    }

    if (sides)
    {
      mModel.GetMesh() = mMeshBlockGenerator.Create(static_cast<MeshBlockGenerator::Side>(sides));
      params.sector->GetRenderSector().Push(mModel, params.pos);
    }
  }
}
