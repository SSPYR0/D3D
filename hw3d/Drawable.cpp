#include "Drawable.h"
#include "GraphicsThrowMacro.h"



Drawable::Drawable()
{
}


Drawable::~Drawable()
{
}

void Drawable::Draw(Graphics & gfx) const noexcept(!IS_DEBUG)
{
}

void Drawable::AddBind(std::unique_ptr<Bindable> bind) noexcept(!IS_DEBUG)
{
}

void Drawable::AddIndexBuffer(std::unique_ptr<class IndexBuffer> ibuf) noexcept
{
}
