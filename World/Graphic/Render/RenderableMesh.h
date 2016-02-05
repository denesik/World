// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef RenderableMesh_h__
#define RenderableMesh_h__

#include <memory>
#include "IRenderMeshStrategy.h"
#include "RenderMeshGL1.h"


/// ����������� � ������ ���.
template<class V>
class RenderableMesh : public Mesh<V>
{
public:
  inline RenderableMesh()
  {
    mRenderMesh = std::make_unique<RenderMeshGL1>();

    mRenderMesh->SetAttribute(ATTRIBUTE_VERTEX, { true, sizeof(VertexVT{}.vertex), offsetof(VertexVT, vertex) });
    mRenderMesh->SetAttribute(ATTRIBUTE_TEXTURE, { true, sizeof(VertexVT{}.texture), offsetof(VertexVT, texture) });
  }

  /// �������������� ���.
  inline void Compile()
  {
    mRenderMesh->Compile(reinterpret_cast<float *>(mVertex.data()), mVertex.size(), sizeof(V),
      reinterpret_cast<size_t *>(mIndex.data()), mIndex.size());
  }

  /// ���������� ���.
  inline void Draw() const
  {
    mRenderMesh->Draw();
  }

private:
  std::unique_ptr<IRenderMeshStrategy> mRenderMesh;

};



#endif // RenderableMesh_h__