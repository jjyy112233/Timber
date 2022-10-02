#include "LogsPool.h"
#include "../ResourceManager.h"
#include "Branch.h"

LogsPool::LogsPool() 
	: texLog(*ResourceManager::GetInstance()->GetTexture("graphics/log.png")), position({0,0})
{
	for (int i = 0; i < 10; ++i)
	{
		auto log = new EffectLog(texLog, 2.f);
		unuseLogs.push_back(log);
	}
}

LogsPool::~LogsPool()
{
	Release();
}
void LogsPool::Init()
{
	while (!useLogs.empty())
	{
		auto log = useLogs.back();
		useLogs.pop_back();
		unuseLogs.push_back(log);
	}
}

void LogsPool::ShowLogEffect(Sides side, Vector2f(position))
{
	if (unuseLogs.empty())
		return;

	auto log = unuseLogs.front();
	unuseLogs.pop_front();
	useLogs.push_back(log);
	Vector2f force;

	force.x = side == Sides::Left ? 1500 : -1500;
	force.y = -1500;

	float aForce = side == Sides::Left ? 360 * 5 : -360 * 5;

	log->SetPosition(position);
	log->Fire(force, aForce);
}
void LogsPool::Update(float dt)
{
	auto it = useLogs.begin();
	while (it != useLogs.end())
	{
		(*it)->Update(dt);
		if (!(*it)->GetActive())
		{
			unuseLogs.push_back(*it);
			it = useLogs.erase(it);
		}
		else
		{
			++it;
		}
	}

}
void LogsPool::Draw(RenderWindow& window)
{
	for (auto log : useLogs)
	{
		log->Draw(window);
	}
}

void LogsPool::Release()
{
	for (auto log : unuseLogs)
	{
		delete log;
	}
	unuseLogs.clear();

	for (auto log : useLogs)
	{
		delete log;
	}
	useLogs.clear();
}
