/**
* File containing the Button class and declarations
*/

#pragma once

#include "Widget.h"



namespace Calculator
{

	class Button : Widget
	{
	public:
		/**
		* Button should be created in MainWindow.h and then Initialized in WM_CREATE
		*/
		Button() = default;

		/**
		* Should be called to construct window
		*
		* @param name is the button text
		* @param rect is the button's transform
		* @param parent is the parent, often the main window
		*/
		void Init(
			_In_ const LPCWSTR& name, 
			_In_ const Rect& rect, 
			_In_ HWND& parent, 
			_In_opt_ const int& flags = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON
		);

		/**
		* Changes button's width and height
		*
		* @param width is the target button width
		* @param height is the target button height
		*/
		virtual void Resize(
			_In_ const int& width, 
			_In_ const int& height
		) override;

		/**
		* Hides the button after it was shown, does nothing if button is already hidden
		*/
		virtual void Hide() const override;

		/**
		* Shows the button after it was hidden, does nothing if button is already displayed
		*/
		virtual void Show() const override;

		/**
		* Sets text which is displayed when the button is rendered
		* @param text is the new button text
		*/
		virtual void SetText(
			_In_ const LPCWSTR& text
		) override;

		/**
		* Getter for buttonID
		* @returns the current button's buttonID
		*/
		int GetButtonID() const { return m_ButtonID; }

	private:
		HWND m_hwndButton;
		int m_ButtonID;
	};

}