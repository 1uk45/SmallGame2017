#include "AMenu.h"



AMenu::AMenu()
{

}

AMenu::~AMenu()
{

}

//::.. SET FUNCTIONS ..:://
void AMenu::SetParent(uint32_t id)
{
	m_parent = id;
}

void AMenu::SetID(uint32_t id)
{
	m_id = id;
}

//::.. GET FUNCTIONS ..:://
uint32_t AMenu::GetParent()
{
	return m_parent;
}

void AMenu::AddChild(AMenu * child)
{
	m_children.push_back(child);
}

AMenu * AMenu::GetChildAt(uint32_t i)
{
	return m_children[i];
}
