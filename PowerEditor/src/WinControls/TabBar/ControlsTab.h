// This file is part of Mikepad++ project
// Copyright (C)2021 Don HO <don.h@free.fr>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#pragma once

#include "TabBar.h"
#include "Window.h"
#include "Common.h"

struct DlgInfo
{
    Window *_dlg;
    generic_string _name;
	generic_string _internalName;

	DlgInfo(Window *dlg, const TCHAR *name, const TCHAR *internalName = TEXT("")): _dlg(dlg), _name(name), _internalName(internalName) {};
};

typedef std::vector<DlgInfo> WindowVector;


class ControlsTab final : public TabBar
{
public :
	ControlsTab() = default;
	virtual ~ControlsTab() = default;

	virtual void init(HINSTANCE hInst, HWND hwnd, bool isVertical = false, bool isMultiLine = false)
	{
		_isVertical = isVertical;
		TabBar::init(hInst, hwnd, false, isMultiLine);
	}

	void createTabs(WindowVector & winVector);

	void destroy()
	{
		TabBar::destroy();
	}

	virtual void reSizeTo(RECT & rc);
	void activateWindowAt(int index);

	void clickedUpdate()
	{
		int indexClicked = int(::SendMessage(_hSelf, TCM_GETCURSEL, 0, 0));
		activateWindowAt(indexClicked);
	};
	void renameTab(size_t index, const TCHAR *newName);
	bool renameTab(const TCHAR *internalName, const TCHAR *newName);

private:
	WindowVector *_pWinVector = nullptr;
    int _current = 0;
};

