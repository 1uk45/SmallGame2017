#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__


enum class State
{
	START,
	MAIN_MENU,
	LEVEL_EDITOR,
	GAME,
	EXIT
};

class StateManager
{
public:
	//::.. DUMMY CONSTRUCTORS ..:://
	StateManager();
	virtual ~StateManager();

	//::.. FAKE CONSTRUCTORS ..:://
	void StartUp();
	void ShutDown();

	//::.. SET FUNCTIONS ..:://
	void SetCurrentState(State state);

	//::.. GET FUNCTIONS ..:://
	static StateManager * Get();
	State GetCurrentState();

private:
	void Init();

private:
	static StateManager * m_instance;

	State m_currentState;

};


#endif // __ STATEMANAGER_H__