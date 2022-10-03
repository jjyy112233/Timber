#pragma once
#include "EffectLog.h"
#include "../SingleTon.h"
#include <list>

enum class Sides;
class LogsPool : public Singleton<LogsPool>
{
private:
	Texture& texLog;
	list<EffectLog*> unuseLogs;
	list<EffectLog*> useLogs;
	Vector2f position;
	float scale;
public:
	LogsPool();
	~LogsPool();
	void Release();
	void Init(float scale = 1);
	void ShowLogEffect(Sides side, Vector2f(position));
	void Update(float dt);
	void Draw(RenderWindow& window);
};