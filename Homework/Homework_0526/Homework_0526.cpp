#include <iostream>
#include <conio.h>
#include "int4.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"
#include <Windows.h>

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.

// 1. 파일 정리
// 
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.
// 
// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요.
//
// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.


int main()
{
    srand(time(NULL));

    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ 10, 5 });

    // 벽 10개 랜덤한 위치에 생성
    for (size_t i = 0; i < wallCount; i++)
    {
        int posX = rand() % XLine;
        int posY = rand() % YLine;

        Wall* obstacle = new Wall();
        obstacle->SetPos({ posX, posY });
        MainPlayer.SetObstacle(i, obstacle);

        for (size_t j = 0; j < i; j++)
        {
            if (MainPlayer.GetObstacle(i)->GetPos() == MainPlayer.GetObstacle(j)->GetPos())
            {
                i -= 1;
                break;
            }
        }
    }

    while (true)
    {
        Screen.Clear();

        // 총알로 인해 소멸된 벽은 제외하고 출력
        for (size_t i = 0; i < wallCount; i++)
        {
            if (MainPlayer.GetObstacle(i) != nullptr)
            {
                Screen.SetPixel(MainPlayer.GetObstacle(i)->GetPos(), 'W');
            }
        }

        Screen.SetPixel(MainPlayer.GetPos(), 'a');

        // 총알을 발사했을 경우 화면에 표시
        if (MainPlayer.GetShotState())
        {
            MainPlayer.ShotBullet();
            Screen.SetPixel(MainPlayer.GetBullet(), '<');
        }

        Screen.Print();

        if (_kbhit() != 0)
        {
            MainPlayer.Input();
        }

        Sleep(3);
    }
}