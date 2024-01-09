/*
삼각김밥을 너무나도 좋아하던 한 사람이 있었다. 그는 매일 편의점에서 삼각김밥을 먹으며, 삼각김밥만이 존재하는 세상을 꿈꿨다.
그러던 어느 날, 그는 삼각김밥에 대한 열정과 사랑으로, 삼각김밥 모양의 삼각김밥 월드를 만들었다.
삼각김밥 월드는 아래와 같이, 사각 모양으로 구역이 나누어져 있으며, 서로 붙어있는 구역으로만 이동할 수 있다.
예를 들어, 1번 구역은 2번, 3번과 붙어 있다. 또한, 8번 구역은 4번, 5번, 7번, 9번, 12번, 13번과 붙어 있다.
삼각김밥 월드에서는 삼각김밥이 화폐로 사용된다.
서로 붙어있는 구역 사이를 이동하기 위해서는 1개의 삼각김밥을 통행료로 지불해야 한다.
출발 지점(s)과 도착 지점(e)의 구역 번호가 주어질 때, 삼각김밥을 최대한 아끼면서 이동할 수 있는 방법을 찾아라.
[입력]
첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 1,000)가 주어진다.
각 테스트 케이스에 해당하는 줄에는 두 개의 구역 번호 s, e(1 ≤ s, e ≤ 10,000)가 주어진다. 두 구역 번호는 각각 출발 지점과 도착 지점의 구역 번호이다.
[출력]
각 테스트 케이스마다 해당하는 줄에 이동에 필요한 최소 삼각김밥 개수를 출력한다.
*/

#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int s, e;
        cin >> s >> e;

        if (s > e)
            swap(s, e);

        int sector_s = ceil((sqrt(8 * s + 1) - 1) / 2); // s가 속한 구역(층)
        int sector_e = ceil((sqrt(8 * e + 1) - 1) / 2); // e가 속한 구역(층)
        int distance = sector_e - sector_s;             // s와 e의 구역 차
        int max = s + (distance * (distance + 1)) / 2 + (sector_s) * (distance); // s부터 오른쪽 아래로 e구역까지 도달했을 때의 숫자
        int min = s +(distance * (distance + 1)) / 2 + (sector_s - 1) * (distance); // s부터 왼쪽 아래로 e구역까지 도달했을 때의 숫자
        int result = 0;

        /*
            s부터 시작해서 e가 속한 구역까지 왼쪽, 오른쪽으로 직선을 그엇을 때 삼각형이 그려진다
            e가 해당 삼각형 안에 속하면 최단 경로는 distance 값과 같다
            e가 삼각형 안에 속하지 않으면 구역 distance + (min or max 와의 거리) 가 최단경로이다
        */
        if (e >= min && e <= max)
            result = distance;
        else if (e > max)
            result = distance + (e - max);
        else
            result = distance + (min - e);

        cout << "#" << test_case << " " << result << endl;

	}
	return 0;
}