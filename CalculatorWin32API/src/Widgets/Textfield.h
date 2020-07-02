#pragma once

#include "Widget.h"


namespace Calculator
{

	class Textfield : public Widget
	{
	public:
		Textfield();

		virtual void Resize(
			_In_ const int& width,
			_In_ const int& height
		) override;

		virtual void Show() const override;
		virtual void Hide() const override;

		virtual void SetText(
			_In_ const LPCWSTR& text
		) override;
		

		virtual const WidgetType GetWidgetType() const override { return GetStaticWidgetType(); }
		static WidgetType GetStaticWidgetType() { return WidgetType::Textfield; }

		virtual const wchar_t* GetName() const { return L"Textfield"; }

		virtual const int& GetID() const override { return m_TextfieldID; }

	private:
		int m_TextfieldID;
	};

}
