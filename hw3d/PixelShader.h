#pragma once
#include "Bindable.h"
#include "GraphicsThrowMacro.h"

class PixelShader :
	public Bindable
{
public:
	PixelShader(Graphics &gfx, std::wstring &path);
	void Bind(Graphics& gfx) noexcept override;

protected:
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader;
};

