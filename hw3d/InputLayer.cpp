#include "InputLayer.h"
#include "GraphicsThrowMacro.h"


InputLayer::InputLayer(Graphics & gfx, const std::vector<D3D11_INPUT_ELEMENT_DESC>& layout, ID3DBlob * pVertexShaderBytecode)
{
	INFOMAN(gfx);

	GFX_THROW_INFO(GetDevice(gfx)->CreateInputLayout(
		layout.data(), (UINT)layout.size(),
		pVertexShaderBytecode->GetBufferPointer(),
		pVertexShaderBytecode -> GetBufferSize(),
		&pInputLayout
	));
}

void InputLayer::Bind(Graphics &gfx) noexcept {
	
	GetContext(gfx)->IASetInputLayout(pInputLayout.Get());
}