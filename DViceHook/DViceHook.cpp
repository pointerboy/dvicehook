/*
	DViceHook - written by pointerboy (2019) (https://github.com/pointerboy)

	For all Vice City lovers!
*/

#include "plugin.h"
#include "CHud.h"

#include "RenderWare.h"

#include "CCamera.h"
#include "CPickups.h"
#include "CMessages.h"
#include "CModelInfo.h"
#include "extensions/ScriptCommands.h"

#include "Audio.h"
#include "DVLogging.h"

using namespace plugin;

class DViceHook {
public:
	DViceHook()
	{

		Events::initGameEvent += []
		{
			Logging::AddLogMessage("\n -- DViceHook has started!");
		};

		static bool VehInfoDisplay = false;

		Events::gameProcessEvent += []
		{
			CVehicle* vehicle; CVector posn; float angle;
			CPed* player = FindPlayerPed();
			CPickup* cp;
			CCamera* ccm;

			float
				veh_speed,
				car_health
				;

			if (KeyPressed('M'))
			{
				if (VehInfoDisplay)
				{
					VehInfoDisplay = false;
					CHud::SetHelpMessage("Vehicle info off!", true, false);
				} else 
				{
					VehInfoDisplay = true;
					CHud::SetHelpMessage("Vehicle info is on!", true, false);
				}
			}

			if (KeyPressed('R'))
			{
				Audio::PlayWavFile("test.wav", false);

				Logging::AddLogMessage("started playing audio file (loc)" );

				Logging::AddDebugMessage("test", true, true, true, true, true);

				CHud::SetHelpMessage("DViceHook plugin has loaded. If you have any issues report them to the GitHub issue report list. Keep in mind that this is still in early alpha version and that you will most likely experience crashes.", false, false);
				
				ccm->Init();

				ccm->RotateX(20);
				return;
			}

			if (VehInfoDisplay)
			{
				if (Command<Commands::IS_PLAYER_PLAYING>(0))
				{
					Command<0x01F5>(0, &player);
					if (Command<Commands::IS_CHAR_IN_ANY_CAR>(player))
					{
						float
							veh_speed;

						Command<Commands::STORE_CAR_CHAR_IS_IN_NO_SAVE>(player, &vehicle); // use pointers instead of 'handles'
						Command<Commands::GET_CAR_COORDINATES>(vehicle, &posn.x, &posn.y, &posn.z);
						Command<Commands::GET_CAR_HEADING>(vehicle, &angle);
						Command<Commands::GET_CAR_SPEED>(vehicle, &veh_speed);
						Command <Commands::GET_CAR_HEALTH>(vehicle, &car_health);

						static char message[256];
						snprintf(message, 256, "Position: %.2f %.2f %.2f Angle: %.2f Model: %d (~r~%s~w~) Speed: %.2f Health(%.2f)",
							posn.x, posn.y, posn.z, angle, vehicle->m_nModelIndex,
							reinterpret_cast<CVehicleModelInfo*>(
								CModelInfo::GetModelInfo(vehicle->m_nModelIndex))->m_szGameName, veh_speed, car_health);

						CMessages::AddMessageJumpQ(message, 0, 0);
					}
				}
			}
		};
	
	}
} dViceHook;
