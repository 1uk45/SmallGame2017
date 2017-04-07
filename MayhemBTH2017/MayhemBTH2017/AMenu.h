#ifndef __AMENU_H__
#define __AMENU_H__


#include "Canvas.h"


#include <vector>
#include <cstdint>


class AMenu
{
public:
	AMenu();
	virtual ~AMenu();
	
	virtual void Init() {};
	virtual void Update() {};
	virtual void Render() {};

	//::.. SET FUNCTIONS ..:://
	void SetParent(uint32_t id);
	void SetID(uint32_t id);

	//::.. GET FUNCTIONS ..:://
	uint32_t GetParent();

protected:
	void AddChild(AMenu* child);
	AMenu* GetChildAt(uint32_t i);

private:
	std::vector<AMenu*> m_children;
	uint32_t m_parent;
};


#endif // __AMENU_H__