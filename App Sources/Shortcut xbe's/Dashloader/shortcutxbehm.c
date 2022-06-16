#ifdef _MSC_VER
#include "msxdk.h"
#else
#include <hal/xbox.h>
#include <hal/fileio.h>
#include <openxdk/debug.h>
#include <xboxkrnl/xboxkrnl.h>
#include <xboxkrnl/types.h>
#define MAX_PATH 256
#include "xmount.h"
#include "msxdk.h"
#endif
#include <string.h>
#include <stdio.h>
#include <sys\stat.h>
#include <fstream>
#include <iostream>
#include "shortcutxbe.h"
#include "dismountxbe.h"
#include "kernelpatcher.h"
#define ES_IGR	"E:\\CACHE\\LocalCache20.bin"
#define dashloader_Files_path	"C:\\dashloader\\"
static FILE* logfile = NULL;
int file_exist(char *name)
{
	struct stat   buffer;   
	return (stat (name, &buffer) == 0);
}
void debuglog(const char* format, ...)
{
	char buffer[1024];
	va_list va;
	va_start(va, format);
	vsprintf(buffer, format, va);
	va_end(va);
	strcat(buffer, "\n");
	if( logfile )
	{
		fputs(buffer, logfile);
		fflush(logfile);
	}
#ifdef _MSC_VER
	OutputDebugString(buffer);
#endif
}
void ErrorHandler(char *xbepath)
{
	debuglog("\n------------------------------------------------");
	debuglog("Dashboard Locations");
	debuglog("------------------------------------------------");
	/**/
	debuglog("Loading C:\\XBMC-Emustation\\Default.xbe");
	XLaunchXBE("C:\\XBMC-Emustation\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\XBMC-Emustation\\Default.xbe");
	XLaunchXBE("E:\\XBMC-Emustation\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading F:\\XBMC-Emustation\\Default.xbe");
	XLaunchXBE("F:\\XBMC-Emustation\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading C:\\XBMC4Gamers\\Default.xbe");
	XLaunchXBE("C:\\XBMC4Gamers\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\XBMC4Gamers\\Default.xbe");
	XLaunchXBE("E:\\XBMC4Gamers\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading F:\\XBMC4Gamers\\Default.xbe");
	XLaunchXBE("F:\\XBMC4Gamers\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading C:\\XBMC4Xbox\\Default.xbe");
	XLaunchXBE("C:\\XBMC4Xbox\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\XBMC4Xbox\\Default.xbe");
	XLaunchXBE("E:\\XBMC4Xbox\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading F:\\XBMC4Xbox\\Default.xbe");
	XLaunchXBE("F:\\XBMC4Xbox\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading C:\\XBMC\\Default.xbe");
	XLaunchXBE("C:\\XBMC\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\XBMC\\Default.xbe");
	XLaunchXBE("E:\\XBMC\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading F:\\XBMC\\Default.xbe");
	XLaunchXBE("F:\\XBMC\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading C:\\Dashboard\\Default.xbe");
	XLaunchXBE("C:\\Dashboard\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\Dashboard\\Default.xbe");
	XLaunchXBE("E:\\Dashboard\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading F:\\Dashboard\\Default.xbe");
	XLaunchXBE("F:\\Dashboard\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading C:\\Dash\\Default.xbe");
	XLaunchXBE("C:\\Dash\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\Dash\\Default.xbe");
	XLaunchXBE("E:\\Dash\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading F:\\Dash\\Default.xbe");
	XLaunchXBE("F:\\Dash\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\Default.xbe");
	XLaunchXBE("E:\\Default.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\Dashboard.xbe");
	XLaunchXBE("E:\\Dashboard.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\Evoxdash.xbe");
	XLaunchXBE("E:\\Evoxdash.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading C:\\XBMC.xbe");
	XLaunchXBE("C:\\XBMC.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("Loading E:\\XBMC.xbe");
	XLaunchXBE("E:\\XBMC.xbe");
	debuglog("Dashboard doesn't Exist\n");
	/**/
	debuglog("\n------------------------------------------------");
	debuglog("All failed :( - trying to reboot");
	debuglog("------------------------------------------------");
	XReboot();
}
int LaunchShortcut(char* filename)
{
	FILE* file;
	char target[MAX_PATH];
	unsigned int length;
	file = fopen(filename, "r+t");
	if(file == NULL)
	{
		/* debuglog("ERROR - Unable to open cutfile"); */
		return -1;
	}
	/* read first line untill linebreak */
	length = 0;
	while(1)
	{
		target[length] = fgetc(file);
		if( target[length] == EOF || target[length] == '\n' || target[length] == '\r' )
		break;
		length++;
	}
	fclose(file);
	if(length <= 0)
	{
		return -1;
	}
	/* null terminate string, and chop of any trailing blanks */
	target[length] = '\0';
	/* remove ES_File */
	remove(ES_IGR);
	/* launching xbe */
	XLaunchXBE(target);
	/* if we get here something went wrong */
	return -1;
}
int LaunchRecovery(char* filename)
{
	FILE* file;
	char target[MAX_PATH];
	unsigned int length;
	file = fopen(filename, "r+t");
	if(file == NULL)
	{
		/* debuglog("ERROR - Unable to open cutfile"); */
		return -1;
	}
	/* read first line untill linebreak */
	length = 0;
	while(1)
	{
		target[length] = fgetc(file);
		if( target[length] == EOF || target[length] == '\n' || target[length] == '\r' )
		break;
		length++;
	}
	fclose(file);
	if(length <= 0)
	{
		return -1;
	}
	/* null terminate string, and chop of any trailing blanks */
	target[length] = '\0';
	/* launching xbe */
	XLaunchXBE(target);
	/* if we get here something went wrong */
	return -1;
}
/* initial starting point of program */
int main(int argc,char* argv[])
{
	XInitDevices( 0, NULL );
	if( FAILED( XBInput_CreateGamepads( &m_Gamepad ) ) )
	{
		debuglog("ERROR - Cant create gamepad");
	}
	XMount("C:", "\\Device\\Harddisk0\\Partition2");
	XMount("E:", "\\Device\\Harddisk0\\Partition1");
	logfile = fopen(dashloader_Files_path"Dashloader.log", "w+t");
	char shortcut[MAX_PATH];
	// Ind-Bios 5003 with virtual disc loader patch		
	if (file_exist(dashloader_Files_path"Patch Virtual ISO Support.bin"))
	{
		if(file_exist("C:\\ind-bios.cfg") || file_exist("C:\\ind-bios\\ind-bios.cfg"))
		{
			char *patched_value = (char *)0x8002B4B7;
			if (*patched_value=='�')
			{
				XMount("D:", "\\Device\\Cdrom0");
				XMount("VD:", "\\Device\\Cdrom1");
				CreateDirectory("E:\\CACHE", NULL);
				if (file_exist("VD:\\default.xbe"))
				{
					if (!file_exist("E:\\CACHE\\LocalCache30.bin"))
					{
						debuglog("Creating De-mounter");
						int i;
						std::ofstream DismountXBEFile("E:\\CACHE\\LocalCache30.bin", std::ios::binary);
						for(i = 0; i < sizeof(dismount_xbe); i++)
						{
							DismountXBEFile << dismount_xbe[i];
						}
						DismountXBEFile.close();
						XLaunchXBE("D:\\default.xbe");
					}
					if (!file_exist(dashloader_Files_path"Disabled Virtual-ISO Dismount.bin"))
					{
						debuglog("Unmounting Virtual Drive");
						XLaunchXBE("E:\\CACHE\\LocalCache30.bin");
					}
				}
			}
			else
			{
				int i;
				std::ofstream PatcherXBEFile("E:\\CACHE\\LocalCache40.bin", std::ios::binary);
				for(i = 0; i < sizeof(kernel_patcher); i++)
				{
					PatcherXBEFile << kernel_patcher[i];
				}
				PatcherXBEFile.close();
				XLaunchXBE("E:\\CACHE\\LocalCache40.bin");
			}
		}
		remove("E:\\CACHE\\LocalCache30.bin");
		remove("E:\\CACHE\\LocalCache40.bin");
	}
	/* move to xbepath buffer */
	if (file_exist(ES_IGR))
	{
		strcpy(shortcut, ES_IGR);
	}
	else
	{
		strcpy(shortcut, dashloader_Files_path"Custom_Dash.cfg");
	}
	debuglog("Dashloader Build 1.4");
	int timer = 0;
	while(timer++ <= 2000)
	{
		//-----------------------------------------
		// Handle input
		//-----------------------------------------
		// Read the input for all connected gampads
		XBInput_GetInput( m_Gamepad );
		// Lump inputs of all connected gamepads into one common structure.
		// This is done so apps that need only one gamepad can function with
		// any gamepad.
		ZeroMemory( &m_DefaultGamepad, sizeof(m_DefaultGamepad) );
		for( DWORD i=0; i<4; i++ )
		{
			if( m_Gamepad[i].hDevice )
			{
				// Only account for thumbstick info beyond the deadzone
				m_DefaultGamepad.fX1 += m_Gamepad[i].fX1;
				m_DefaultGamepad.fY1 += m_Gamepad[i].fY1;
				m_DefaultGamepad.fX2 += m_Gamepad[i].fX2;
				m_DefaultGamepad.fY2 += m_Gamepad[i].fY2;
				m_DefaultGamepad.wButtons        |= m_Gamepad[i].wButtons;
				m_DefaultGamepad.wPressedButtons |= m_Gamepad[i].wPressedButtons;
				m_DefaultGamepad.wLastButtons    |= m_Gamepad[i].wLastButtons;
				for( DWORD b=0; b<8; b++ )
				{
					m_DefaultGamepad.bAnalogButtons[b]        |= m_Gamepad[i].bAnalogButtons[b];
					m_DefaultGamepad.bPressedAnalogButtons[b] |= m_Gamepad[i].bPressedAnalogButtons[b];
					m_DefaultGamepad.bLastAnalogButtons[b]    |= m_Gamepad[i].bLastAnalogButtons[b];
				}
			}
		}
		if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_Y] && (m_DefaultGamepad.wPressedButtons & XINPUT_GAMEPAD_START) )
		{
			debuglog("\n------------------------------------------------");
			debuglog("Rescue Dashboard Locations");
			debuglog("------------------------------------------------");
			debuglog("Loading Custom Rescue Dashboard\n");
			LaunchRecovery(dashloader_Files_path"Custom_Recovery.cfg");
			debuglog("Custom Rescue Dashboard doesn't Exist\n");
			/**/
			debuglog("Loading Rescue Dashboard TDATA");
			XLaunchXBE("E:\\TDATA\\Rescuedash\\Default.xbe");
			debuglog("Rescue Dashboard doesn't Exist\n");
			/**/
			debuglog("Loading Rescue Dashboard UDATA");
			XLaunchXBE("E:\\UDATA\\Rescuedash\\Default.xbe");
			debuglog("RescueDashboard doesn't Exist\n");
		}
		if( !m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_X] || !m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_Y] )
		{
			if( !m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_WHITE] || !m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_Y] )
			{
				if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_A] )
				{
					strcpy(shortcut, dashloader_Files_path"A_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_B] )
				{
					strcpy(shortcut, dashloader_Files_path"B_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_X] )
				{
					strcpy(shortcut, dashloader_Files_path"X_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_Y] )
				{
					strcpy(shortcut, dashloader_Files_path"Y_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.wPressedButtons & XINPUT_GAMEPAD_START )
				{
					strcpy(shortcut, dashloader_Files_path"Start_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.wPressedButtons & XINPUT_GAMEPAD_BACK )
				{
					strcpy(shortcut, dashloader_Files_path"Back_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_BLACK] )
				{
					strcpy(shortcut, dashloader_Files_path"Black_Button_Dash.cfg");
					break;
				}
				if( m_DefaultGamepad.bPressedAnalogButtons[XINPUT_GAMEPAD_WHITE] )
				{
					strcpy(shortcut, dashloader_Files_path"White_Button_Dash.cfg");
					break;
				}
			}
		}
		Sleep(1);
	}
	LaunchShortcut(shortcut);
	ErrorHandler(dashloader_Files_path"Dashloader.log");
}