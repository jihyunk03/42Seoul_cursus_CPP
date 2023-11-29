#include "./mlx/mlx.h"
#include "./tutorial/mlx_example/key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 1920
#define height 1080

#define TRUE 1
#define FALSE 0

typedef struct	s_img
{
	void	*image;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;

	t_img	img;
	int		**buf;
	int		texture[8][texHeight * texWidth];
	int		re_buf;
}				t_info;

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

void	init_values(t_info *info);
int		calc(t_info *info);
void	re_init_buf(t_info *info);
void	verLine(t_info *info, int x, int y1, int y2, int color);
int		key_press(int key, t_info *info);

int	main(void)
{
	t_info	info;

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, width, height, "mlx");

	info.posX = 22.0;
	info.posY = 11.5;

	info.dirX = -1.0;
	info.dirY = 0.0;

	info.planeX = 0.0;
	info.planeY = 0.66;

	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;

	init_values(&info);
	info.img.image = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.image, &info.img.bpp, &info.img.size_l, &info.img.endian);

	// start
	mlx_loop_hook(info.mlx, &calc, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
}

void	init_values(t_info *info)
{
	// buf 초기화
	info->buf = calloc(height, sizeof(int *));
	for (int i = 0; i < height; i++)
		info->buf[i] = calloc(width, sizeof(int));

	// texture 초기화
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < texWidth * texHeight; j++)
			info->texture[i][j] = 0;

	// 색 정하기...?
	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
			int ycolor = y * 256 / texHeight;
			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			info->texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
			info->texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			info->texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			info->texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			info->texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
			info->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			info->texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
			info->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}
}

int	calc(t_info *info)
{
	// 0 <= x < width: 화면 상의 한 pixel 값을 의미
	int	x;

	re_init_buf(info);
	x = 0;
	while (x < width)
	{
	/* [현재 상황에서의 광선 방향을 정하기] */
		// 1. cameraX (상수): camera 평면의 x방향 좌표(가운데가 0)로, plane vector의 크기 조절 상수 값
		double	cameraX = 2 * x / (double)width - 1;

		// 2. rayDir (광선 방향 벡터): dir vector + plane vector * cameraX
		double	rayDirX = info->dirX + info->planeX * cameraX;
		double	rayDirY = info->dirY + info->planeY * cameraX;

	/* [광선을 그리기 위해 방향 정하기]*/
		// 1. map (벡터, 좌표): 지도 상에서의 pos가 포함된 좌표(int)
		int	mapX = (int)info->posX;
		int	mapY = (int)info->posY;

		// 2. sideDist (첫 이동 거리): 현재 위치에서 처음으로 만나는 x, y 선상의 거리
		double	sideDistX, sideDistY;

		// 3. deltaDist (이동 거리 단위): 각 방향으로 단위 1만큼 옮길 때마다 각 x, y선상에 닿는 거리의 단위: 정확한 값은 아니지만, 여기서는 모든 좌표의 단위가 1이므로 이와 같은 유사한 공식을 사용해도 됨(유도는 따로)
		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);

		// 4. step (이동 방향 단위): 방향 벡터의 방향에 따라 이동할 방향을 정한 단위 벡터
		int	stepX, stepY;

		// 5. 이제 첫 이동 거리와 앞으로의 이동 방향에 대한 단위 값을 구하자
		if (rayDirX < 0)	// 방향 벡터의 "x"의 부호에 따라 이동 방향 결정
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)	// 방향 벡터의 "y"의 부호에 따라 이동 방향 결정
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

	/* [광선의 길이를 구하고, 실제 화면상에 비춰지도록 거리를 계산하자] */
		// 1. 이제 hit가 0이 될 때까지 짧은 거리로 이동
		int	side = 0;		// side가 동-서(0)인지 남-북(1)인지에 대한 여부
		while (TRUE)
		{
			// 이동한 값을 기준으로 현재 위치를 선정
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// 현재 위치가 벽을 만났는지 확인
			if (worldMap[mapX][mapY] != 0)
				break ;
		}

		// 2. 벽까지의 광선 거리를 알았으니, 이젠 실제 화면에 왜곡되지 않게 보이도록 거리를 평행하게 조정
		double	perpWallDist;	// 실제 컴퓨터 화면과 벽의 거리 비율(평행한 화면에 보이도록)
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

	/* [이제 해당 광선에 대한 화면에 보이는 벽을 그리자] */
		// 1. lineHeight(길이): 수직선 상의 벽 길이로 위에서 구한 비율로 계산
		int	lineHeight = (int)(height / perpWallDist);

		// 2. 화면 상에서 그리기 위한 시작지점과 끝지점의 값(y)
		int	drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;

		// 3. 지정된 벽의 색깔에 맞춰 그리자
		// texNum: 벽의 텍스쳐를 선택하기 위한 값
		int texNum = worldMap[mapX][mapY];

		// wallX: 벽의 int형 좌표가 아닌 double형으로, 정확히 어디에 부딪쳤는지 나타내는 값 -> 텍스처를 적용할 때, 어떤 x좌표를 이용해야 하는지 판단 시 사용




		x++;
	}
	return (0);
}

void	re_init_buf(t_info *info)
{
	if (info->re_buf == 0)
		return ;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			info->buf[i][j] = 0;
	info->re_buf = 0;
}

void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

int	key_press(int key, t_info *info)
{
	if (key == K_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	mlx_clear_window(info->mlx, info->win);
	calc(info);
	return (0);
}
