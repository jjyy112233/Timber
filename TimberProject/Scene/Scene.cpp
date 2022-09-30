#include "Scene.h"
#include "SceneManager.h"

Scene::Scene(SceneManager& mgr)
	: mgr(mgr)
{
	size = mgr.GetSize();
}

Scene::~Scene()
{
}
