#include "cub3d.h"

t_cub   cub_init(t_cub cub)
{
    cub.mlx = 0;
    cub.win = 0;
    cub.img_we.img = 0;
    cub.img_ea.img = 0;
    cub.img_s.img = 0;
    cub.img_no.img = 0;
    cub.img_so.img = 0;
    return (cub);
}

void    free_mlx(t_cub cub)
{
    if (cub.img_ea.img)
        mlx_destroy_image(cub.mlx, cub.img_ea.img);
    if (cub.img_no.img)
        mlx_destroy_image(cub.mlx, cub.img_no.img);
    if (cub.img_s.img)
        mlx_destroy_image(cub.mlx, cub.img_s.img);
    if (cub.img_so.img)
        mlx_destroy_image(cub.mlx, cub.img_so.img);
    if (cub.img_we.img)
        mlx_destroy_image(cub.mlx, cub.img_we.img);
    if (cub.win)
        mlx_destroy_window(cub.mlx, cub.win);
}

int     exit_pro(int keycode, t_cub *cub)
{
    printf("You clicked %d\n", keycode);
    if (keycode == 53)
    {
        free_all(cub->map);
        free_mlx(*cub);
        printf("bye~~\n");
        exit(0);
    }

        return (0);
}

// int singleline(t_cub cub, int ray_x)
// {
//     double deg;
//     double x = 1;
//     double y = 1;
//     double inc;
//     double inv;
//     double checkx;
//     double checky;
//     int     wall;
//     char    flag;

//     wall = 1;
// //나중에 플레이어보는 방향 담는 변수 구조체에 추가
//     if (cub.map.t_flag == 'S')
//         deg = (3 * M_PI / 2 + cub.fovh / 2) - cub.fovh / (cub.map.screen_x - 1) * ray_x;
//     inc = tan(deg);
//     inv = deg; //atan(inc) 랑 똑같은 거아님?
//     while (wall)
//     {
//         if (inc < 1) //tan(45)보다 작은 것
//         {
            
//             while (1)
//             {

//                 checky = inc * x;
//                 if (checky > y)
//                     y++;
//                 checky = (int)checky;
//                 while (checky)
//                 {
                    
//                     cub.map.map = cub.map.map->next;
//                     checky--;
//                 }
//                 if (*((char *)cub.map.map->content + (char)x) == '1')
//                     wall = 0; //여기에서 뛰쳐 나가야함 아마 return
//                 x++;
//             }
//         }

//     }
    

//     return (0);
// }

double shoot_a(t_cub cub, char *news, double deg) //어차피 나뉘어야 함.
{
    int x = 1;
    int y = 1;
    int block;
    double inv = 1 / tan(deg);
    t_list *curr;

    curr = cub.map.position_y;
    while (1)
    {
        block = (int)trunc(inv * y);
        while (x <= block)
        {
            if (*(char *)(curr->content + cub.map.position_x + x) == '1'
                || *(char *)(curr->content + cub.map.position_x + x) == ' ')
            {
                *news = 'e';
                return (hypot(x, tan(deg) * x));
            }
            x++;
        }
        curr = curr->prev;
        if (*(char *)(curr->content + cub.map.position_x + x - 1) == '1'
            || *(char *)(curr->content + cub.map.position_x + x) == ' ')
        {
            *news = 's';
            return (hypot(y, inv * y));
        }
        y++;
    }
    return (0);
}

double shoot_b(t_cub cub, char *news, double deg)
{
    int x = 1;
    int y = 1;
    int block;
    double inv = 1 / tan(deg);
    t_list *curr;

    curr = cub.map.position_y->prev;
    while (1)
    {
        block = (int)trunc(tan(deg) * x);
        while (y <= block)
        {
            if (*(char *)(curr->content + cub.map.position_x + x - 1) == '1'
                || *(char *)(curr->content + cub.map.position_x + x - 1) == ' ')
                {
                    *news = 's';
                    return (hypot(y, inv * y));
                }
            curr = curr->prev;
            y++;
        }
        if (*(char *)(curr->next->content + cub.map.position_x + x) == '1'
            || *(char *)(curr->next->content + cub.map.position_x + x) == ' ')
        {
            *news = 'e';
            return (hypot(x, tan(deg) * x));
        }
        x++;
    }
    return (0);
}

double shoot_c(t_cub cub, char *news, double deg)
{
    int x = -1;
    int y = 1;
    int block;
    double inv = 1 / tan(deg);
    t_list *curr;

    curr = cub.map.position_y->prev;
    while (1)
    {
        block = (int)trunc(tan(deg) * x);
        while (y <= block)
        {
            if (*(char *)(curr->content + cub.map.position_x + x) == '1'
                || *(char *)(curr->content + cub.map.position_x + x) == ' ')
                {
                    *news = 's';
                    return (hypot(y, inv * y));
                }
            curr = curr->prev;
            y++;
        }
        if (*(char *)(curr->content + cub.map.position_x + x) == '1'
            || *(char *)(curr->content + cub.map.position_x + x) == ' ')
        {
            *news = 'e';
            return (hypot(x, tan(deg) * x));
        }
        x++;
    }
    return (0);
}

t_cub   singleline(t_cub cub, int ray_x)
{
    double deg;
    char news;
    double dist;

    if (cub.map.t_flag == 'S')
        cub.dir = 3 * M_PI_2;
    else if (cub.map.t_flag == 'N')
        cub.dir = M_PI_2;
    else if (cub.map.t_flag == 'E')
        cub.dir = 0;
    else
        cub.dir = M_PI;

    deg = (cub.dir + cub.fovh / 2) - cub.fovh / (cub.map.screen_x - 1) * ray_x;
    if (deg >= 2 * M_PI)
        deg -= 2 * M_PI;

    if (deg == 1 * M_PI_2)
        dist = shoot_up(cub, &news, deg);
    if (deg == 2 * M_PI_2)
        dist = shoot_left(cub, &news, deg);
    if (deg == 3 * M_PI_2)
        dist = shoot_down(cub, &news, deg);
    if (deg == 0)
        dist = shoot_right(cub, &news, deg);
    if (deg >= 0 * M_PI_4 && deg < 1 * M_PI_4)
        dist = shoot_a(cub, &news, deg);
    if (deg >= 1 * M_PI_4 && deg < 2 * M_PI_4) // 특정각도 처리해야함
        dist = shoot_b(cub, &news, deg);
    if (deg >= 2 * M_PI_4 && deg < 3 * M_PI_4)
        dist = shoot_c(cub, &news, deg);
    if (deg >= 3 * M_PI_4 && deg < 4 * M_PI_4)
        dist = shoot_d(cub, &news, deg);
    if (deg >= 4 * M_PI_4 && deg < 5 * M_PI_4)
        dist = shoot_e(cub, &news, deg);
    if (deg >= 5 * M_PI_4 && deg < 6 * M_PI_4)
        dist = shoot_f(cub, &news, deg);
    if (deg >= 6 * M_PI_4 && deg < 7 * M_PI_4)
        dist = shoot_g(cub, &news, deg);
    if (deg >= 7 * M_PI_4 && deg < 8 * M_PI_4)
        dist = shoot_h(cub, &news, deg);

    draw_vert(cub, dist, news);
    return (cub);
}

void    display(t_map map)
{
    t_cub cub;

    cub.map = map;
    cub = cub_init(cub);
    cub.mlx = mlx_init();
    cub.win = mlx_new_window(cub.mlx, map.screen_x, map.screen_y, "레이캐스팅");

    cub.fovh = M_PI / 3; //60도 마찌??
    cub.fovv = cub.fovh * cub.map.screen_y / cub.map.screen_x;

    int ray_x = 0;

    while (ray_x < cub.map.screen_x)
    {
        singleline(cub, ray_x);
        ray_x++;
    }

    mlx_hook(cub.win, 2, 0, exit_pro, &cub);
    mlx_loop(cub.mlx);
}

// typedef struct s_val
// {
//     void *mlx;
//     void *win;
//     void *img;
//     int bpp;
//     int sl;
//     int en;
//     char *imad;

//     int x;
//     int y;
//     unsigned int color;

//     char *dst;
//     int i;
//     int tcl;
// }              t_val;

// int print(int key, t_val *t)
// {
//     printf("key : %d\n", key);
// }

// int rendering(t_val *t)
// {
//     t->x = 0;
//     t->y = 0;
//     while (t->x < 480)
//     {
//         while (t->y < 360)
//         {
//             t->dst = t->imad + (t->y * t->sl + t->x * (t->bpp / 8));
//             *(unsigned int*)t->dst = t->color;
//             t->y += 1;
//             // t->color += 10;
//         }
//         t->x += 1;
//         t->y = 0;
//         // t->color += 10;
//     }
//     if (t->color <= 0x000000ff)
//     {
//         t->tcl = 1;
//         t->color += t->tcl;
//     }    
//     else if (t->color <= 0x0000ffff)
//     {
//         t->tcl = 0x00000100;
//         t->color += t->tcl;
//     }
//     else if (t->color <= 0x00ffffff)
//     {
//         t->tcl = 0x00010000;
//         t->color += t->tcl;
//     }
//     else
//     {
//         t->color = 0;
//     }
		
//     mlx_put_image_to_window(t->mlx, t->win, t->img, 120, 60);
// }
// void display(void)
// {
//     t_val t;

//     t.color = 0;
//     t.mlx = mlx_init();
// 	printf("what?\n");
//     t.win = mlx_new_window(t.mlx, 720, 480, "그림 그리기");
//     t.i = 0;
//     t.img = mlx_new_image(t.mlx, 480, 360);
//     t.imad = mlx_get_data_addr(t.img, &t.bpp, &t.sl, &t.en);
//     printf("bpp: %d, sl: %d, endian: %d\n", t.bpp, t.sl, t.en);
//     mlx_hook(t.win, 2, 1, print, &t);
//     mlx_loop_hook(t.mlx, rendering, &t);
//     mlx_loop(t.mlx);
// }

// 이미지 확대와 축소
    // cub.img_ea.img = mlx_xpm_file_to_image(cub.mlx, cub.map.i_ea, &cub.img_ea.width, &cub.img_ea.height);
    // cub.screen.img = mlx_new_image(cub.mlx, ga, se); //나중에는 창 크기에 맞춰서 크기를 잡게 되지 않을까.

    // cub.img_ea.img_adrr = mlx_get_data_addr(cub.img_ea.img, &cub.img_ea.bpp, &cub.img_ea.sl, &cub.img_ea.en);
    // cub.screen.img_adrr = mlx_get_data_addr(cub.screen.img, &cub.screen.bpp, &cub.screen.sl, &cub.screen.en);

    // int i = -1;
    // int j = -1;
    // char *dst;
    // char *srcs;
    // int x; 
    // int y;
    // while (++i < ga)
    // {
    //     j = -1;
    //     while (++j < se)
    //     {
    //         x = i * cub.img_ea.width / ga;
    //         y = j * cub.img_ea.height / se;
    //         printf("so xy : %d, %d\n", x, y);
    //         dst = cub.screen.img_adrr + (j * cub.screen.sl + i * (cub.screen.bpp / 8));
    //         srcs = cub.img_ea.img_adrr + (y * cub.img_ea.sl + x * (cub.img_ea.bpp / 8));
    //         *(unsigned int *)dst = *(unsigned int *)srcs;
    //     }
    // }
    // mlx_put_image_to_window(cub.mlx, cub.win, cub.img_ea.img, 60, 60);
    // mlx_put_image_to_window(cub.mlx, cub.win, cub.screen.img, 120, 60);
