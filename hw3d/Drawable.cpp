#include "Drawable.h"
#include "GraphicsThrowMacro.h"
#include "IndexBuffer.h"
#include <cassert>
#include <typeinfo>


void Drawable::Draw(Graphics & gfx) const noexcept(!IS_DEBUG)
{
	for (auto &b : binds) {
		b->Bind(gfx);
	}
	gfx.DrawIndexed(pIndexBuffer->GetCount());
}

void Drawable::AddBind(std::unique_ptr<Bindable> bind) noexcept(!IS_DEBUG)
{
	assert("Use AddIndexBuffer to bind index buffer" && typeid(*bind) != typeid(IndexBuffer));
	binds.push_back(std::move(bind));
}

void Drawable::AddIndexBuffer(std::unique_ptr<class IndexBuffer> ibuf) noexcept
{
	assert("Adding Index Buffer" && pIndexBuffer == nullptr);
	pIndexBuffer = ibuf.get();
	binds.push_back(std::move(ibuf));
}
