#include "DualScene.h"
#include "SceneManager.h"

DualScene::DualScene(SceneManager& mgr, Texture& cloths1, Texture& cloths2)
	:Scene(mgr)
{
	/*
		배경, 구름, 벌, 만들어서 objs에 넣어주고
		트리도 new 로 만들고 위치 계산 (mgr.GetSize()) 로 위치 조정
		branchs 두 벡터 만들어주고(조정된 트리 위치 보내주고)
		각각 특정개수만큼 push_back 해주고
		플레이어한테 옷이랑 branchs[idx] 생성자로 주고

		플레이어 set으로 위치 중앙 만들어주고
		필요한 텍스트도 만들어서 uis에 넣어주고
		Timer도 만들어서 오브젝트에 넣어주고 아 타이머는 ui인데 왜 sprite인거냐고 짜증나
	*/
	
}

void DualScene::Init()
{
}

void DualScene::Draw()
{ 

}

void DualScene::Release()
{
}

DualScene::~DualScene()
{
}

void DualScene::Update()
{
}
