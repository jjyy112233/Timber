#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

using namespace sf;
using namespace std;

// ����ƽ �Լ��� �̿��ؼ� Ű���� �� ���콺 �Է��� �˻��Ҽ� �ִ� Ŭ����

class InputMgr
{
private:
    static vector<bool> downList;  
    static vector<bool> ingList;   
    static vector<bool> upList;    
    static vector<int> ingIdx;
public:
    static void ClearInput();
    static void UpdateInput(Event& ev);

    static bool GetKeyDown(Keyboard::Key key);
    static bool GetKey(Keyboard::Key key);
    static bool GetKeyUp(Keyboard::Key key);

};
