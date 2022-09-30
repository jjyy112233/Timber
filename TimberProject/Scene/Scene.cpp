#include "Scene.h"
#include "SceneManager.h"

Scene::Scene(SceneManager& mgr)
	: mgr(mgr),window(mgr.GetWindow())
{
	size = mgr.GetSize();
}

Scene::~Scene()
{
}
