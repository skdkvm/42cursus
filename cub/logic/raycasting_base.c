#include "../cub3d.h"

void ft_raycasting_set_info(t_main *m) //DDAgorithm 초기화
{
	m->v.camera_x = 2 * m->v.i / (double)m->w - 1;		//x값이 카메라 평면 상에 있을 때의 x좌표. cameraPlaneX == 0; cameraPlaneY == 0.66; dirVecX = -1; dirVecY = 0;
	m->v.ray_x = m->dir.x + m->plane.x * m->v.camera_x; //현재 위치에서 다음 x사이드까지의 거리
	m->v.ray_y = m->dir.y + m->plane.y * m->v.camera_x; //현재 위치에서 다음 y사이드까지의 거리
	m->v.map_x = (int)m->pos.x;							//현재 player가 위치한 맵 내 위치
	m->v.map_y = (int)m->pos.y;							//현재 player가 위치한 맵 내 위치
	m->v.delta_x = fabs(1 / m->v.ray_x);				//delta_x 첫 번째 x면에서 그 다음 x면까지의 광선의 이동거리.이 경우 x는 1만큼 이동.
	m->v.delta_y = fabs(1 / m->v.ray_y);				//delta_y 첫 번째 y면에서 그 다음 y면까지의 광선의 이동거리.이 경우 y는 1만큼 이동.
	m->v.hit = 0;										//hit은 벽과 부딪혔는지 판별하기 위한 변수.
														//부딪힌다는 것은 루프를 종료하기 위한 조건
														//만약 벽에 부딪혔는데 그게 x면에 부딪힌 거라면 side = 0 y면에 부딪혔다면 1
														//한편 x면, y면은 어떤 칸의 경계가 되는 선을 의미
}
/*
DDAgorithm을 시작하기 전에
stepX, Y 그리고 sideDistX, Y에 값을 넣어주는 부분이다.
rayDirectionX가 음수라는 말은 player기준 왼각이라는 뜻이고,
양수라는 말은 player기준 오른각이라는 뜻이다.
sideDistX의 값은 rayDirectionX 값이 양수인 경우
광선의 오른쪽으로 이동하다 처음 만나는 x면까지의 거리가 된다.
sideDistY의 값은 rayDirectionY 값이 양수인 경우
광선의 위쪽으로 이동하다 처음 만나는 y면까지의 거리가 된다.
rayDirectionX가 양수일 경우 sideDistX는
mapX + 1에서 실제 위치 playerPositionX를 빼주고 deltaDistX를 곱한 결과다.
반대의 경우 playerPositionX에서 mapX를 빼주고 deltaDistX를 곱한 결과다.
*/
void ft_raycasting_get_side_xy(t_main *m)
{
	if (m->v.ray_x < 0)
	{
		m->v.step_x = -1;
		m->v.side_x = (m->pos.x - m->v.map_x) * m->v.delta_x;
	}
	else
	{
		m->v.step_x = 1;
		m->v.side_x = (m->v.map_x + 1.0 - m->pos.x) * m->v.delta_x;
	}
	if (m->v.ray_y < 0)
	{
		m->v.step_y = -1;
		m->v.side_y = (m->pos.y - m->v.map_y) * m->v.delta_y;
	}
	else
	{
		m->v.step_y = 1;
		m->v.side_y = (m->v.map_y + 1.0 - m->pos.y) * m->v.delta_y;
	}
}
/*
DDAgorithm 세팅을 완료했고, 이제 그것을 시작하는 부분.
아래 while문은 `벽에 부딪힐 때까지` 매번 한 칸씩 광선 이동.
반복할 때마다 x방향으로 한 칸 또는 y방향으로 한 칸 점프.
만약 광선의 방향이 x축 방향과 완전히 일치한다면, x방향으로만 한 칸 점프하면 됨.
광선이 점프할 때마다 <sideDistX, Y>에는 <deltaDistX, Y>가 더해지면서 업데이트됨.
*/
void ft_raycasting_get_map_xy(t_main *m) //
{
	while (m->v.hit == 0)
	{
		//다음 map박스로 이동하거나 x,y방향 둘 중 하나로 이동한다.;
		if (m->v.side_x < m->v.side_y)
		{
			m->v.side_x += m->v.delta_x;
			m->v.map_x += m->v.step_x; //step_x는 1,-1중 하나;
			m->v.side = 0;			   //x면에 부딪혔다면 side=0;
		}
		else
		{
			m->v.side_y += m->v.delta_y;
			m->v.map_y += m->v.step_y; //step_y는 1,-1중 하나;
			m->v.side = 1;			   //y면에 부딪혔다면 side=1;
		}
		//ray가 벽을 만났는지 확인하는 작업
		if (m->map.map[m->v.map_x][m->v.map_y] == '1')
			m->v.hit = 1;
	}
	//벽을 만나 DDAgorithm이 완료됨.
	/*
	H------------ :wall
    | \          \: 실제거리
    |  \         |: 벽에서 camera plane까지의 거리.
    -----P------- :camera plane
	따라서 아래 if-else문은 fisheye (side)effect를 방지하는 코드.
	(1 - stepX) / 2는 stepX가 -1이면 1이되고 1이면 0이 된다.(-1 or 0)
    해당 연산은 mapX - playerPositionX가 < 0 일 때, 즉 벽 밖으로 갈 때
    길이에 1을 더해주기 위한 코드이다.
    수직거리를 계산하는 방법은 이렇다.
    만약 광선이 처음으로 부딪힌 면이 x면이면
    mapX - playerPositionX + (1 - stepX / 2)는
    광선이 x방향으로 몇 칸이나 갔는지를 나타낸다.(정수 아니어도 됨.)
    rayDirectionX로 나눠주는 이유는 구해진 값이 수직거리보다 크기 때문.
    y면에 처음 부딪혔을 때도 같은 원리로 동작.
    mapX - playerPostionX가 음수더라도 음수인 rayDirectionX로 나누기 때문에
    계산된 값은 항상 양수.
	*/
	if (m->v.side == 0)
		m->v.wall_dist =
			(m->v.map_x - m->pos.x + (1 - m->v.step_x) / 2) / m->v.ray_x;
	else
		m->v.wall_dist =
			(m->v.map_y - m->pos.y + (1 - m->v.step_y) / 2) / m->v.ray_y;
}
