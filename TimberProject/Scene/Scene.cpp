#include "Scene.h"
#include "SceneManager.h"

Scene::Scene(SceneManager& mgr)
	: mgr(mgr)
{
	size = mgr.GetSize();
}

Scene::~Scene()
{
	for (auto obj : objs)
	{
		delete obj;
	}
	for (auto ui : txts)
	{
		delete ui;
	}

	objs.clear();
	txts.clear();
}
