// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#pragma once
#ifndef Mesh_h__
#define Mesh_h__

#include "IRenderMeshStrategy.h"
#include <memory>
#include <vector>

typedef std::shared_ptr<class MeshOld> PMesh;

class MeshOld
{
public:
  MeshOld(std::unique_ptr<IRenderMeshStrategy> renderMesh = nullptr);
  ~MeshOld();

  /// ���������� ������ ������� � ������.
  void SetVertexSize(size_t size);

  /// ���������� ������ ���������� � ���������� ������ � ���.
  void Set(const std::vector<float> &vertex, const std::vector<size_t> &index);

  /// �������� ������ ���������� � ���������� ������ � ����� �������.
  void Push(const std::vector<float> &vertex, const std::vector<size_t> &index);

  void Push(const MeshOld &mesh);

  void Reserve();

  /// �������� ������ ���������� � ���������� ������.
  void Release();

  /// ������� ��������� �����.
  const std::vector<float> &GetVertex() const;

  /// ������� ��������� �����.
  const std::vector<size_t> &GetIndex() const;

  std::vector<float> &GetVertex();

  std::vector<size_t> &GetIndex();

  void SetAttribute(AttributeType type, Attribute attribute);

  void Compile();

  bool IsCompiled();

  void Draw();

private:
  std::unique_ptr<IRenderMeshStrategy> mRenderMesh;

  std::vector<float> mVertex;
  std::vector<size_t> mIndex;

  size_t mVertexSize = 0;
};


template<class V>
class Mesh
{
public:
  Mesh()
  {
  }

  ~Mesh()
  {
  }

  inline V &Vertex(size_t i)
  {
    return mVertex[i];
  }

  inline size_t &Index(size_t i)
  {
    return mIndex[i];
  }

  inline void Release()
  {
    mVertex.clear();
    mIndex.clear();
  }

  inline void PushVertex(const V &vertex)
  {
    mVertex.push_back(vertex);
  }

  inline void PushIndex(size_t index)
  {
    mIndex.push_back(index);
  }

  void Push(const Mesh<V> &mesh)
  {
    mIndex.reserve(mesh.mIndex.size());
    size_t size = mVertex.size();
    for (const auto &i : mesh.mIndex)
    {
      mIndex.push_back(size + i);
    }

    mVertex.insert(mVertex.end(), mesh.mVertex.begin(), mesh.mVertex.end());
  }

protected:
  std::vector<V> mVertex;
  std::vector<size_t> mIndex;
};



#endif // Mesh_h__