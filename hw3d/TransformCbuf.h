#pragma once
#include "Bindable.h"
#include "ConstantBuffers.h"
#include <DirectXMath.h>
#include "Drawable.h"

class TransformCbuf :
	public Bindable
{
public:
	TransformCbuf(Graphics & gfx, const Drawable & parent);
	void Bind(Graphics &gfx) noexcept override;
private:
	VertexConstantBuffer<DirectX::XMMATRIX> vcbuf;
	const Drawable &parent;

};

