// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef MultiModel_h__
#define MultiModel_h__

#include "StaticModel.h"
#include "RenderableMesh.h"



class DinamicModel
{
public:
  inline const PRenderableMesh<VertexVT> &GetMesh() const noexcept
  {
    return mMesh;
  }

  inline PRenderableMesh<VertexVT> &GetMesh() noexcept
  {
    return mMesh;
  }

  inline const PTexture &GetTexture() const noexcept
  {
    return mTexture;
  }

  inline void SetTexture(const PTexture &texture) noexcept
  {
    mTexture = texture;
  }

private:
  PRenderableMesh<VertexVT> mMesh;
  PTexture mTexture;
};



#endif // MultiModel_h__