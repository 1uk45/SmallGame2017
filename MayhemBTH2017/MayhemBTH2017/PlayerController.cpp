#include "PlayerController.h"



PlayerController::PlayerController()
{
	Init();
}


PlayerController::~PlayerController()
{
	// Do nothing...
}

void PlayerController::FirstUpdate()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		switch (m_event.type)
		{
		case SDL_CONTROLLERDEVICEADDED:
			AddPlayerController(m_event.cdevice);
			break;

		case SDL_CONTROLLERDEVICEREMOVED:
			RemovePlayerController();
			break;

		case SDL_CONTROLLERBUTTONDOWN:
			ButtonDown(m_event.cbutton);
			break;

		case SDL_CONTROLLERBUTTONUP:
			ButtonUp(m_event.cbutton);
			break;

		case SDL_CONTROLLERAXISMOTION:
			AxisInput(m_event.caxis);
			break;
		}
	}
}

void PlayerController::AddPlayerController(SDL_ControllerDeviceEvent PlayerControllerID)
{
	if (SDL_IsGameController(PlayerControllerID.which))
	{
		SDL_GameController * m_controller = SDL_GameControllerOpen(PlayerControllerID.which);
	}
}

void PlayerController::RemovePlayerController()
{
	SDL_GameControllerClose(m_controller);
	m_controller = nullptr;
}


//::.. GET FUNCTIONS ..:://
bool PlayerController::GetButtonDown(size_t button)
{
	return m_button[button].isDown;
}

bool PlayerController::GetButtonHeld(size_t button)
{
	return m_button[button].isHeld;
}

bool PlayerController::GetButtonUp(size_t button)
{
	return m_button[button].isUp;
}


//::.. HELP FUNCTIONS ..:://
void PlayerController::Init()
{
	for (size_t i = 0; i < NUM_BUTTONS; i++)
	{
		m_button[i].isDown = false;
		m_button[i].isDown = false;
		m_button[i].isUp = false;
	}
}


void PlayerController::ButtonDown(const SDL_ControllerButtonEvent controllerEvent)
{
	switch (controllerEvent.button)
	{
	case SDL_CONTROLLER_BUTTON_A:
		m_button[CONTROLLER_BUTTON_A].isDown = true;
		m_button[CONTROLLER_BUTTON_A].isHeld = true;
		break;

	case SDL_CONTROLLER_BUTTON_B:
		m_button[CONTROLLER_BUTTON_B].isDown = true;
		m_button[CONTROLLER_BUTTON_B].isHeld = true;
		break;

	case SDL_CONTROLLER_BUTTON_X:
		m_button[CONTROLLER_BUTTON_X].isDown = true;
		m_button[CONTROLLER_BUTTON_X].isHeld = true;
		break;

	case SDL_CONTROLLER_BUTTON_Y:
		m_button[CONTROLLER_BUTTON_Y].isDown = true;
		m_button[CONTROLLER_BUTTON_Y].isHeld = true;
		break;

	case SDL_CONTROLLER_BUTTON_BACK:
		std::cout << "Pressed BACK!" << std::endl;
		break;

	case SDL_CONTROLLER_BUTTON_START:
		std::cout << "Pressed START!" << std::endl;
		break;

	}
}

void PlayerController::ButtonUp(const SDL_ControllerButtonEvent controllerEvent)
{
	switch (controllerEvent.button)
	{
	case SDL_CONTROLLER_BUTTON_A:
		m_button[CONTROLLER_BUTTON_A].isHeld = false;
		m_button[CONTROLLER_BUTTON_A].isUp = true;
		break;

	case SDL_CONTROLLER_BUTTON_B:
		m_button[CONTROLLER_BUTTON_B].isHeld = false;
		m_button[CONTROLLER_BUTTON_B].isUp = true;
		break;

	case SDL_CONTROLLER_BUTTON_X:
		m_button[CONTROLLER_BUTTON_X].isHeld = false;
		m_button[CONTROLLER_BUTTON_X].isUp = true;
		break;

	case SDL_CONTROLLER_BUTTON_Y:
		m_button[CONTROLLER_BUTTON_Y].isHeld = false;
		m_button[CONTROLLER_BUTTON_Y].isUp = true;
		break;

	case SDL_CONTROLLER_BUTTON_BACK:
		std::cout << "Pressed BACK!" << std::endl;
		break;

	case SDL_CONTROLLER_BUTTON_START:
		std::cout << "Pressed START!" << std::endl;
		break;

	}
}

void PlayerController::AxisInput(const SDL_ControllerAxisEvent controllerEvent)
{

	switch (controllerEvent.axis)
	{
		//Left Stick
	case SDL_CONTROLLER_AXIS_LEFTX:
		if (controllerEvent.value > 2500 || controllerEvent.value < -2500)
			std::cout << "AXIS_LEFTX Value: " << controllerEvent.value << std::endl;
		break;

	case SDL_CONTROLLER_AXIS_LEFTY:
		if (controllerEvent.value > 1500 || controllerEvent.value < -1500)
			std::cout << "AXIS_LEFTY Value: " << controllerEvent.value << std::endl;
		break;

		//Right Stick
	case SDL_CONTROLLER_AXIS_RIGHTX:
		if (controllerEvent.value > 3500 || controllerEvent.value < -3500)
			std::cout << "AXIS_RIGHTX Value: " << controllerEvent.value << std::endl;
		break;

	case SDL_CONTROLLER_AXIS_RIGHTY:
		if (controllerEvent.value > 3500 || controllerEvent.value < -3500)
			std::cout << "AXIS_RIGHTY Value: " << controllerEvent.value << std::endl;
		break;
	}
}
