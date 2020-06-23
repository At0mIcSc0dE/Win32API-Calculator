#pragma once

#include "BaseWindow.hpp"


class MainWindow : public BaseWindow<MainWindow>
{
public:
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	virtual PCWSTR ClassName() const override { return L"MainWindowClass"; }

	MainWindow() = default;
};