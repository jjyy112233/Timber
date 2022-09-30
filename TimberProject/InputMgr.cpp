#include "InputMgr.h"
#include <iostream>
#include <algorithm>

vector<bool> InputMgr::downList(Keyboard::KeyCount, false); //����, �ʱ�ȭ(false)
vector<bool> InputMgr::ingList(Keyboard::KeyCount, false);
vector<bool> InputMgr::upList(Keyboard::KeyCount, false);
vector<int> InputMgr::ingIdx;

void InputMgr::ClearInput()
{
    //fill(downList.begin(), downList.end(), false);
    //fill(upList.begin(), upList.end(), false);
    for (auto idx : ingIdx)
    {
        downList[idx] = false;
        upList[idx] = false;
    }
    ingIdx.clear();

}

void InputMgr::UpdateInput(Event& ev)
{
    switch (ev.type)
    {
    case Event::EventType::KeyPressed:
        if (ev.key.code != Keyboard::Unknown && !ingList[ev.key.code]) //ó���� ��������
        {
            downList[ev.key.code] = true;  //�ٿ� true    ->  ����������(while�ٽý���) ���� clear�� false�� ����
            ingList[ev.key.code] = true;   //ing true
            ingIdx.push_back(ev.key.code);
        }
        break;
    case Event::EventType::KeyReleased:
        if (ev.key.code != Keyboard::Unknown)
        {
            ingList[ev.key.code] = false;
            upList[ev.key.code] = true;
            ingIdx.push_back(ev.key.code);
        }
        break;
    }
}

bool InputMgr::GetKeyDown(Keyboard::Key key)
{
    return downList[key];
}

bool InputMgr::GetKey(Keyboard::Key key)
{
    return ingList[key];
}

bool InputMgr::GetKeyUp(Keyboard::Key key)
{
    return upList[key];
}


/*
Ű A�� ������ ó�� ������ case Event::EventType::KeyPressed: �� �ɷ���
downList �� ingList�� ����,
main ���� GetKeyDown �� ȣ���ϸ� downList�� ��������� TRUE�� ��ȯ�ȴ�.
main �� while�� �� �����Ӹ��� down�� ing�� �ʱ�ȭ ���ִϱ�.
A�� ������ �ִ� ���� ���� �����ӿ����� downList�� A�� ������� ������
GetKeyDown�� ȣ���ص� false�� ������, GetKey�� ȣ���ϸ� ingList�� ��������ϱ� True�� ��ȯ.

AŰ�� ������ �����ÿ��� case Event::EventType::KeyReleased:�� �ɷ���
upList�� A�� �־��ְ�, ingList�� A�� remove���ش�.
�� ���Ŀ� GetKey�� ȣ���ϸ� A�� �����ϱ� False�� ��ȯ�Ǹ�,
GetKeyUp �� ȣ���ϸ� ��������ϱ� True�� ��ȯ�ȴ�.
���Ŀ� main���� clear���ִϱ� Ű�� �� ���Ŀ�
GetKey�� GetKeyUp�� ȣ���ص� �ƹ��͵� ������� �ʾƼ� false�� ��ȯ�ȴ�.

main�� while�帧��
Ű �Է� -> down,ing�� ���� -> GetKeyDwon, GetKey �� true , GetKeyUp�� false -> ����������
-> down, up Ŭ���� -> dwon, up �� false , GetKey�� true -> ����������
... Ű�� ���� -> up����, ing���� ���� -> GetKeyUp�� true, GetKeyDown GetKey�� false -> ���������� -> down, up Ŭ����
-> GetkeyDown, GetKey, GeyKeyUp �� false
*/
