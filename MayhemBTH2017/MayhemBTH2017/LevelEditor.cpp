#include "LevelEditor.h"


//::.. CONSTRUCTORS ..:://
LevelEditor::LevelEditor()
{

	m_camera.SetPosition(glm::vec3(((SIZE_X / 2)), ((SIZE_Y / 2)), -51.2f));
	m_input = InputManager::Get();

	m_timer.SetTimer(0.1f, true, true);
}

LevelEditor::~LevelEditor()
{

}


//::.. UPDATE FUNCTIONS ..:://
void LevelEditor::Update()
{
	if (m_timer.Update())
	{
		AxisMove();
	}
	ButtonInput();
	m_levelMarker.Update(m_camera);

	m_level.Render(m_camera);
}


//::.. HELP FUNCTIONS ..:://
void LevelEditor::AxisMove()
{
	//Left stick
	if (m_input->GetAxisDirection(CONTROLLER_AXIS_LEFTY) != 0.0f || m_input->GetAxisDirection(CONTROLLER_AXIS_LEFTX) != 0.0f)
	{
		m_levelMarker.SetCurrentPosY(m_levelMarker.GetCurrentPosY() - m_input->GetAxisDirection(CONTROLLER_AXIS_LEFTY));
		m_levelMarker.SetCurrentPosX(m_levelMarker.GetCurrentPosX() - m_input->GetAxisDirection(CONTROLLER_AXIS_LEFTX));
	}

	//Right stick
	if (m_input->GetAxisDirection(CONTROLLER_AXIS_RIGHTY) != 0.0f || m_input->GetAxisDirection(CONTROLLER_AXIS_RIGHTX) != 0.0f)
	{
		m_levelMarker.SetCurrentPosY(m_levelMarker.GetCurrentPosY() - m_input->GetAxisDirection(CONTROLLER_AXIS_RIGHTY));
		m_levelMarker.SetCurrentPosX(m_levelMarker.GetCurrentPosX() - m_input->GetAxisDirection(CONTROLLER_AXIS_RIGHTX));
	}
}

void LevelEditor::ButtonInput()
{
	if (m_input->GetButtonDown(CONTROLLER_BUTTON_A))
	{
		m_levelMarker.SetSavedPosX(m_levelMarker.GetCurrentPosX());
		m_levelMarker.SetSavedPosY(m_levelMarker.GetCurrentPosY());
		m_levelMarker.SetMarkerMode(ADD_BLOCK);
	}

	if (m_input->GetButtonUp(CONTROLLER_BUTTON_A) && m_levelMarker.GetMarkerMode())
	{
		m_levelMarker.SetMarkerMode(NORMAL);

		for (size_t x = m_levelMarker.GetStartX(); x <= m_levelMarker.GetEndX(); x++)
		{
			for (size_t y = m_levelMarker.GetStartY(); y <= m_levelMarker.GetEndY(); y++)
			{
				m_level.AddBlock(x, y);
			}
		}
	}


	if (m_input->GetButtonDown(CONTROLLER_BUTTON_X))
	{
		m_levelMarker.SetSavedPosX(m_levelMarker.GetCurrentPosX());
		m_levelMarker.SetSavedPosY(m_levelMarker.GetCurrentPosY());
		m_levelMarker.SetMarkerMode(REMOVE_BLOCK);
	}

	if (m_input->GetButtonUp(CONTROLLER_BUTTON_X))
	{
		m_levelMarker.SetMarkerMode(NORMAL);
	}


	if (m_input->GetButtonHeld(CONTROLLER_BUTTON_X))
	{
		if (m_level.GetIsOccupied(m_levelMarker.GetCurrentPosX(), m_levelMarker.GetCurrentPosY()))
			m_level.RemoveBlock(m_levelMarker.GetCurrentPosX(), m_levelMarker.GetCurrentPosY());

	}

	if (m_input->GetButtonDown(CONTROLLER_BUTTON_B))
	{
		m_levelExporter.Export(m_level);
	}

	if (m_input->GetButtonDown(CONTROLLER_BUTTON_Y))
	{
		Reset();
		m_levelImporter.ImportLevel(m_level);
	}

	if (m_input->GetButtonDown(CONTROLLER_BUTTON_START))
	{
		Reset();
		StateManager * state = StateManager::Get();
		state->SetCurrentState(GameState::MAIN_MENU);
	}
}

void LevelEditor::Reset()
{
	for (size_t x = 1; x < SIZE_X; x++)
	{
		for (size_t y = 1; y < SIZE_Y; y++)
		{
			if (m_level.GetIsOccupied(x, y))
				m_level.RemoveBlock(x, y);
		}
	}
}

