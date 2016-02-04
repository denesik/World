// ============================================================================
// ==                   Copyright (c) 2015, Smirnov Denis                    ==
// ==                  See license.txt for more information                  ==
// ============================================================================
#include "Mesh.h"



Mesh::Mesh(std::unique_ptr<IRenderMesh> renderMesh)
  : mRenderMesh(std::move(renderMesh))
{

}

Mesh::~Mesh()
{

}

void Mesh::SetVertexSize(size_t size)
{
  mVertexSize = size;
}

void Mesh::Set(const std::vector<float> &vertex, const std::vector<size_t> &index)
{
  mVertex = vertex;
  mIndex = index;
}

void Mesh::Push(const std::vector<float> &vertex, const std::vector<size_t> &index)
{
  mIndex.reserve(index.size());
  size_t size = mVertex.size() / (mVertexSize / sizeof(float));
  for (const auto &i : index)
  {
    mIndex.push_back(size + i);
  }

  mVertex.insert(mVertex.end(), vertex.begin(), vertex.end());
}

void Mesh::Push(const Mesh &mesh)
{
  assert(mVertexSize == mesh.mVertexSize && "������� ������ �� ��������� ��� ������� �����.");
  mIndex.reserve(mesh.mIndex.size());
  size_t size = mVertex.size() / (mVertexSize / sizeof(float));
  for (const auto &i : mesh.mIndex)
  {
    mIndex.push_back(size + i);
  }

  mVertex.insert(mVertex.end(), mesh.mVertex.begin(), mesh.mVertex.end());
}

void Mesh::Reserve()
{
	mVertex.reserve(150 * 21 * 21 * 21);
	mIndex.reserve(40 * 21 * 21 * 21);
}

void Mesh::Release()
{
  mVertex.swap(decltype(mVertex){});
  mIndex.swap(decltype(mIndex){});
}

const std::vector<float> &Mesh::GetVertex() const
{
  return mVertex;
}

const std::vector<size_t> &Mesh::GetIndex() const
{
  return mIndex;
}

void Mesh::SetAttribute(AttributeType type, Attribute attribute)
{
  assert(mRenderMesh != nullptr && "����������� ������ ��� ��������� ������.");
  mRenderMesh->SetAttribute(type, attribute);
}

void Mesh::Compile()
{
  assert(mRenderMesh != nullptr && "����������� ������ ��� ��������� ������.");
  mRenderMesh->Compile(mVertex.data(), mVertex.size(), mVertexSize, mIndex.data(), mIndex.size());
}

bool Mesh::IsCompiled()
{
  assert(mRenderMesh != nullptr && "����������� ������ ��� ��������� ������.");
  return mRenderMesh->IsCompiled();
}

void Mesh::Draw()
{
  assert(mRenderMesh != nullptr && "����������� ������ ��� ��������� ������.");
  mRenderMesh->Draw();
}

