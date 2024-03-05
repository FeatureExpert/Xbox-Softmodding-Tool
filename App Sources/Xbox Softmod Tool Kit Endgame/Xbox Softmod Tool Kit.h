/*
**********************************
**********************************
**      BROUGHT TO YOU BY:		**
**********************************
**********************************
**								**
**		  [TEAM ASSEMBLY]		**
**								**
**		www.team-assembly.com	**
**								**
******************************************************************************************************
* This is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
******************************************************************************************************
*/

#pragma once

#include <xtl.h>
#include <xfont.h>
#include "StdString.h"

#include "XKBaseApp.h"

#include "XKUtils.h"
#include "XKGeneral.h"
#include "XKEEPROM.h"
#include "XKHDD.h"
#include "XKCRC.h"

#include "XKControl.h"
#include "XKControl_Panel.h"
#include "XKControl_TextBox.h"
#include "XKControl_Menu.h"
#include "XKControl_Keyboard.h"

struct Bios
{
 char Name[50];
 char Signature[33];
};

class ConfigMagicApp : public XKBaseApp  
{

int file_exist(const char *name);

private:

	void	InitScreen();
	void	INIT_SCREEN();
	void	ResetLocations(LONG xoffset, LONG yoffset);
	void	ProcessMenuSelect(LPCSTR MenuItemSelected);
	void	LoadSettings();
	
	/////////////////////////////////////////
	void	SaveFiles();
	void	CreateFiles(const char *output, unsigned char *input, unsigned int size);
	
	UCHAR				m_EEPROM_BIN_FileName[FILENAME_MAX];
	UCHAR				m_EEPROM_CFG_FileName[FILENAME_MAX];
	UCHAR				m_EEPROM_Backup_Path[FILENAME_MAX];
	
	BOOL				m_EnryptedRegionValid;
	BOOL				m_XBOX_EEPROM_Current;

	long				XConfSections;
	XKEEPROM*			m_pXKEEPROM;
	XBOX_VERSION		m_XBOX_Version;
	
	ULONG				m_MenuXOffset;
	ULONG				m_MenuYOffset;
	LPXKControl_Menu	m_pMainMenu;
	BOOL				ShowMenu;
	BOOL				bios_dumped;

	LPXKControl_Panel	m_ActiveForm;
	LPXKControl_Panel	m_pFrmInfo;
	LPXKControl_Panel	m_pFrmStatus;

	CXBFont				m_XBFont;
	CXBFont				m_XBFont1;
	CXBFont				m_XBFont2;

	D3DCOLOR m_clrMessageTextColor;
	D3DCOLOR m_clrStatusTextColor;
	LPXKControl_TextBox	txtStatus;
	LPXKControl_TextBox	txtStatusMsg;
    LPXKControl_TextBox txtStatusMsg2;
	LPXKControl_TextBox	txtTitle;	
	LPD3DXSPRITE		m_bgSprite;
    LPDIRECT3DTEXTURE8  m_pOverlay[2];		// Overlay textures
    LPDIRECT3DSURFACE8  m_pSurface[2];		// Overlay Surfaces
    DWORD               m_dwCurrent;		// Current surface

public:
	virtual HRESULT		Initialize();
	virtual HRESULT		Render();
};
