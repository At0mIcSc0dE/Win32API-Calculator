#pragma once

#include "Calculator/Core.h"
#include "Widget.h"


namespace Calculator
{

	class CL_API Textfield : public Widget
	{
	public:
		
		/**
		* Default constructor for Textfield
		*/
		Textfield() = default;

		/**
		* Should be called to construct window
		*
		* @param name is the textfield's text
		* @param rect is the textfield's transform
		* @param parent is the parent, often the main window
		*/
		[[noreturn]] void Init(
			_In_ const LPCWSTR& name,
			_In_ const Rect& rect,
			_In_ HWND& parent,
			_In_opt_ const int& flags = WS_CHILD | WS_VISIBLE | WS_BORDER
		);
		
		/**
		* Should be called to construct window
		*
		* @param name is the textfield;s text
		* @param x is the textfield's x-position
		* @param y is the textfield's y-position
		* @param width is the textfield's width
		* @param height is the textfield's height
		* @param parent is the parent, often the main window
		*/
		[[noreturn]] void Init(
			_In_ const LPCWSTR& name, 
			_In_ const int& x, 
			_In_ const int& y, 
			_In_ const int& width,
			_In_ const int& height, 
			_In_ HWND& parent, 
			_In_opt_ const int& flags = WS_CHILD | WS_VISIBLE | WS_BORDER
		);

		/**
		* Changes button's width and height
		*
		* @param width is the target button width
		* @param height is the target button height
		*/
		[[noreturn]] virtual void Resize(
			_In_ const int& width,
			_In_ const int& height
		) override;

		/**
		* Hides the button after it was shown, does nothing if button is already hidden
		*/
		[[noreturn]] virtual void Hide() const override;
		
		/**
		* Shows the button after it was hidden, does nothing if button is already displayed
		*/
		[[noreturn]] virtual void Show() const override;


		/**
		* Sets text textboxes displayed text
		*
		* @param text is the new button text
		*/
		[[noreturn]] void SetText(
			_In_ const LPCWSTR& text
		);
		
		/**
		* Function to get the current widget type, in this case Textfield
		*
		* @returns the widget's type
		*/
		virtual const WidgetType GetWidgetType() const override { return GetStaticWidgetType(); }
		
		/**
		* Static function to get the current widget type, in this case Textfield
		*
		* @returns the widget's type
		*/
		static WidgetType GetStaticWidgetType() { return WidgetType::Textfield; }

		/**
		* Method to get the name of the current class
		*
		* @returns L"Textfield"
		*/
		virtual const wchar_t* GetName() const { return L"Textfield"; }

		/**
		* Getter for textfieldID
		*
		* @returns the current textfield's textfieldID
		*/
		virtual const int& GetID() const override { return m_TextfieldID; }

	private:
		int m_TextfieldID;
		HWND m_hwndTextfield;
	};

}
