/*
#include "gameScript.h"

gameScript::gameScript()
{
	m_LUA = luaL_newstate();
	m_GameObject = m_GameObjectFactory.Create(GameObjectFactory::OBJECT3D);
}

gameScript::~gameScript()
{
}

void gameScript::load(std::string s)
{
	m_LUA = lua_open();

	luaL_openlibs(m_LUA);

	luabind::open(m_LUA);
	/*luabind::module(m_LUA)
	[
		luabind::def("setTranslate", &gameScript::setTranslate)
	];*
	luabind::module(m_LUA)
	[
		luabind::class_<GameObject>("GameObject"),
		luabind::class_<Object2D, GameObject>("GameObject2D"),
		luabind::class_<Object3D, GameObject>("GameObject3D"),
		luabind::class_<Effect, GameObject>("GameEffect")
		.def(luabind::constructor<>())
		.def("load", &GameObject::draw)
		.def("translate", &GameObject::translate)
		.def("setPos", &GameObject::setPos)
	];

	luabind::call_function<void>(m_LUA, "load", m_GameObject);
	luabind::call_function<void>(m_LUA, "translate", m_GameObject);
	luabind::call_function<void>(m_LUA, "setPos", m_GameObject);

	const char* tempChar = s.c_str();

	luaL_dofile(m_LUA, tempChar);
	lua_close(m_LUA);
}

void gameScript::assignGameObject(GameObject* go)
{
	m_GameObject = go;
}
*/