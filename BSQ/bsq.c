/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:57:17 by cyun              #+#    #+#             */
/*   Updated: 2022/06/05 17:07:33 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_square
{
    int	x_point; // 정사각형이 끝나는 점의 x좌표
    int	y_point; // 정사각형이 끝나는 점의 y좌표
    int	square_length; // 정사각형의 한 변의 길이
}               t_square;

typedef struct s_map
{
    char	full_char; // 예제에서의 x
    char	empty_char; // 예제에서의 .
    char	obstacle_char; // 예제에서의 o
    char	**filled_map; // 최종 출력값이 담길 배열
    int		x_len; // map의 가로길이
    int		y_len; // map의 세로길이
}               t_map;

int	ft_strlen(char *str) // 문자열 길이 반환 함수
{
    int	idx;

    idx = 0;
    while (str[idx])
        idx++;
    return (idx);
}

void	ft_putchar(char c) // 문자 출력 함수
{
    write(1, &c, 1);
}

void	ft_putstr(char *str) // 문자열 출력 함수
{
    write(1, str, ft_strlen(str));
}

void	print_err_msg(void) // 에러메시지 출력 함수
{
    ft_putstr("map_error\n");
}

int	find_min(int a, int b, int c)
{
	int	min; // a, b, c 중 최솟값 반환 함수

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	change_square(t_square *square, int x_pos, int y_pos, int length)
{
	square->x_point = x_pos; // square에 각 값 저장
	square->y_point = y_pos;
	square->square_length = length;
}

int	check_square(int **dp, int x_pos, int y_pos)
{
	int	min; // 최솟값 찾고 +1 만큼 dp에 저장 후 반환

	min = find_min(dp[y_pos - 1][x_pos],
			dp[y_pos - 1][x_pos - 1], dp[y_pos][x_pos - 1]);
	dp[y_pos][x_pos] = min + 1;
	return (min + 1);
}

void	ft_strncpy(char *dest, char *src, int num)
{
    int	idx;

    idx = 0;
    while (idx < num) // 문자열 복사 함수
    {
        dest[idx] = src[idx];
        idx++;
    }
	dest[idx] = '\0';
}

int	ft_is_number(char c)
{
    if ('0' <= c && c <= '9') // 입력 문자가 0~9일경우 1반환
        return (1);
    return (0);
}

int	ft_atoi(char *str) // 문자를 정수로 반환
{
    int	num;
    int	idx;
	int	sign;

    idx = 0;
    num = 0;
	sign = 1;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
    while (str[idx] >= '0' && str[idx] <= '9')
    {
        num = num * 10 + (str[idx] - '0');
        idx++;
    }
    return (num);
}

int	ft_is_valid_map(char *line, t_map *map)
{
    int	idx;

    idx = 0;
    while (line[idx]) // line이 존재할 때
    {
        if (line[idx] != map->empty_char && line[idx] != map->obstacle_char) // line의 문자가 o나 .이 아닐경우 return (0)
            return (0);
        idx++;
    }
    return (1);
}

void	fill_square_map(t_map *map, t_square *square)
{
    int		x_pos;
    int		y_pos;
    char	full_char;

    full_char = map->full_char;
    y_pos = square->y_point - square->square_length; // 정사각형의 시작점 y좌표
    while (++y_pos <= square->y_point)
    {
        x_pos = square->x_point - square->square_length; // 정사각형의 시작점 x좌표
        while (++x_pos <= square->x_point)
            map->filled_map[y_pos][x_pos] = full_char; // 정사각형의 넓이부분에 full로 표시함
    }
}

void	print_map(t_map *map, t_square *square)
{
    int	y_pos;

    fill_square_map(map, square); // 정사각형에 맞춰서 map에 fill 채워넣기
    y_pos = -1;
    while (++y_pos < map->y_len) // map->y_len 만큼 반복
    {
        write(1, map->filled_map[y_pos], map->x_len); // 수정된 지도를 map->x_len만큼씩 출력
        ft_putchar('\n'); // 개행문자
    }
}

int	**make_integer_map(t_map *map)
{
    int	y_pos;
    int	x_pos;
    int	**buf; // find_bsq를 위해서 해당 map에서 장애물을 0, empty를 1로 변환 int형 배열로

    buf = (int **)malloc(sizeof(int *) * (map->y_len)); // map->y_len 만큼 buf의 세로길이 할당
    if (!buf)
        exit(0);
    y_pos = -1;
    while (++y_pos < map->y_len)
    {
        buf[y_pos] = (int *)malloc(sizeof(int) * (map->x_len)); // map->x_len 만큼 buf의 가로길이 각각 할당
        if (!buf[y_pos])
            exit(0);
        x_pos = -1;
        while (++x_pos < map->x_len) // 반복문을 돌면서 map의 정보가 담긴 값이 obstacle이라면 0저장
        {
            if (map->filled_map[y_pos][x_pos] == map->obstacle_char)
                buf[y_pos][x_pos] = 0;
            else // 아니면 1저장
                buf[y_pos][x_pos] = 1;
        }
    }
    return (buf);
}

void	find_max_square(int y_pos, t_map *map, int **dp, t_square *square)
{
	int	x_pos;
	int	max_len;

	x_pos = -1;
	while (++x_pos < map->x_len)
	{
		if (y_pos == 0 || x_pos == 0) // 0번 열 or 0 번 행일경우 square_length와 비교해서 square에 저장
			if (dp[y_pos][x_pos] > square->square_length)
				change_square(square, x_pos, y_pos, dp[y_pos][x_pos]);
		if (y_pos == 0 || x_pos == 0) 
			continue ;
		if (dp[y_pos][x_pos] == 1) // dp의 값이 1인경우
		{
			max_len = check_square(dp, x_pos, y_pos); // max_len에 최솟값 찾아서 저장
			if (max_len > square->square_length) // 비교해서 square에 저장
				change_square(square, x_pos, y_pos, max_len);
		}
	}
}

t_square	*setting_find_square(t_map *map)
{
    t_square	*square;
	int			**dp;
	int			y_pos;

	square = (t_square *)malloc(sizeof(t_square)); // 사각형이 담길 구조체 할당
	if (!square)
		exit(0); // 할당되지 않았다면 exit
	dp = make_integer_map(map); // map에 대한 정보를 바탕으로 dp배열 초기화
	y_pos = -1;
	while (++y_pos < map->y_len)
		find_max_square(y_pos, map, dp, square); // dp 알고리즘 시작
	y_pos = 0;
	while (y_pos < map->y_len) // dp에 할당된 메모리 해제
		free(dp[y_pos++]);
	free(dp);
	return (square);
}

void	free_map(t_map *map, int size)
{
    int	idx;

    idx = -1;
    while (++idx < size)
        free(map->filled_map[idx]); // map에 저장되어 있는 filled_map의 요소를 해제함
    free(map->filled_map); // map->filled_map을 해제함
    free (map); // map을 해제함
}

char	*free_line(char *line)
{
    free(line); // line의 메모리 해제
    return (0);
}

int	is_printable(char c)
{
    if (' ' <= c && c <= '~')
        return (1); // 출력가능하다면 1반환
    return (0);
}

int	is_valid_map_info(t_map *map) // map의 구성요소들이 출력가능하면 옳은 구성요소
{
    if (is_printable(map->full_char)) // map->full_char이 출력 가능할 때
        return (1);
    else if (is_printable(map->obstacle_char)) // map->obstacle_char이 출력 가능할 떄
        return (1);
    else if (is_printable(map->empty_char)) // map->empty_char이 출력 가능할 때
        return (1);
    return (0);
}

int	is_valid_char_info(t_map *map)
{
	if (map->empty_char == map->obstacle_char) // empty, obstacle, full 은 서로 중복 되지 않아야함
		return (0);
	else if (map->empty_char == map->full_char) 
		return (0);
	else if (map->obstacle_char == map->full_char)
		return (0);
	else if (!is_valid_map_info(map)) // map의 정보를 알려주는 line이 옳지 않을 때
		return (0);
	return (1);
}

int	init_map_info(t_map *map, char *info)
{
    int	len;

    len = ft_strlen(info);
    if (!info || len < 4) // len < 4 : n.ox가 최솟값이므로 4보다 작을 수 없음
        return (0);
    map->full_char = info[len - 1];
    map->obstacle_char = info[len - 2];
    map->empty_char = info[len - 3];
    if (map->empty_char == map->obstacle_char   // empty, obstacle, full은 중복되지 않아야함
            || map->empty_char == map->full_char
            || map->obstacle_char == map->full_char
            || !is_valid_map_info(map))
		return (0);				// map의 정보        return (0);
    map->y_len = ft_atoi(info); // 주어진 정보를 통해서 map->y_len을 구함
    if (!map->y_len || map->y_len < 0)
        return (0);
    return (1);
}

int	parse_map_info(t_map *map, char *info)
{
    int	tmp;

    tmp = init_map_info(map, info);
    if (!tmp)
        free(map);
    free(info);
    return (tmp);
}

char	*expand_line(char *origin_line, int *len)
{
    char	*new_line;

    new_line = (char *)malloc(sizeof(char) * (*len + 1)); // new_line에 원래 len + 1 만큼 공간할당
    if (!new_line)
        exit(0);
    ft_strncpy(new_line, origin_line, *len); // origin_line을 new_line에 복사
    *len += 1;
	free(origin_line); // origin_line 메모리 해제
    return (new_line);
}

char	*read_line(int fd)
{
    char	*line; // 한 줄이 저장 될 문자열
    char	c;
    int		idx;
    int		len;

    idx = 0;
    len = 2;
    line = (char *)malloc(sizeof(char) * len); // line의 공간을 최초 2만큼만 할당-> 문자 + 널문자 공간
    if (!line)
        exit(0);
    while (read(fd, &c, 1))
    {
        if (c == '\n') // 읽어온 문자가 개행문자라면 line[idx]에 널문자 넣고 break
        {
            line[idx] = '\0';
            break;
        }
        if (idx + 1 == len) // idx + 1이 len과 같으면 
            line = expand_line(line, &len); // expand_size로 line 확장
        line[idx++] = c; // line 문자열에 문자 하나 씩 저장
    }
    if (idx == 0) // idx가 그대로 0이라면 free_line으로 line의 메모리 해제
        return (free_line(line));
    return (line); // line 반환 (한줄)
}

int	check_read_map(int *idx, t_map *map, char *line)
{
    int	len;
    
    // 인자로 들어온 idx가 map->y_len과 같거나, map이 유효하지 않다면
    if (*idx == map->y_len || !ft_is_valid_map(line, map))
    {
        free(line); // line의 메모리 해제
        free_map(map, *idx); // map 메모리 해제
        return (0);
    }
    len = ft_strlen(line); // len에 line의 길이 저장
    if (map->x_len == 0) // map->x_len이 0이라면 map->x_len = len;
        map->x_len = len;
    if (len != map->x_len) // len 이 map->x_len과 다르다면
    {
        free(line); // line의 메모리 해제
        free_map(map, *idx); // map의 메모리 해제
        return (0);
    }
    map->filled_map[(*idx)++] = line; // map->filled_map[(*idx)++] = line
	return (1);
}

t_map	*read_map(int fd, int idx)
{
    char	*line;

    t_map   *map;
    map = (t_map *)malloc(sizeof(t_map)); // map에 대한 공간 할당을 진행
    if (!map)
        exit(0); // 할당되지 않았을 경우 exit로 프로그램 탈출
    if (!parse_map_info(map, read_line(fd))) // 해당 map과 read_line(fd)의 값이 올바르지 않을 경우 return (0);
        return (0);
    map->filled_map = (char **)malloc(sizeof(char *) * map->y_len); // map의 배열의 공간을 map->y_len 만큼 할당
    if (!map->filled_map)
        exit(0); // 할당되지 않았을 경우 exit로 프로그램 탈출
    map->x_len = 0; // map->x_len을 0으로 초기화
    line = read_line(fd); // line 을 read_line(fd)로 가져옴
	while (line)
    {
		printf("%s\n\n", line);
        if (!check_read_map(&idx, map, line)) // read_map_sub에서 메모리 해제당하고 0을 반환했다면 return 0
            return (0);
        line = read_line(fd);// line이 0이 될 때까지 반복
	}
    if (idx != map->y_len) // 최종 idx가 map->y_len과 다르다면 오류이므로
    {
        free_map(map, idx); //map의 메모리를 해제해주고 return (0)
        return (0);
    }
    return (map); // 읽어온 map을 반환함
}

t_map	*read_stdin(void)
{
    int	fd;
    int	idx;

    fd = 0;
    idx = 0;
    return (read_map(fd, idx)); // 표준입력을 입력받기 위해 fd에 0을 넣어 read_map(fd)을 반환한다.
}

t_map	*read_file(char *file)
{
    int	fd;
    int	idx;

    idx = 0;
    fd = open(file, O_RDONLY); // 전달받은 file을 읽기 전용으로 불러온다
	if (fd == -1)
        return (0);
    return (read_map(fd, idx)); // 올바르게 열렸다면 read_map(fd)의 값을 반환한다.
}

void	bsq(char *file)
{
    t_square    *square;
    t_map       *map;

    if (file)
        map = read_file(file); // file이 존재할 경우 read_file로 읽어온다
    else
        map = read_stdin(); // file이 존재하지 않을경우 read_stdin으로 표준입력을 읽어온다
    if (!map)
    {
        print_err_msg(); // map이 없을 경우 에러메시지 출력하고 return 한다
        return ;    
    }
    square = setting_find_square(map); // square에 find_square(map)을 통해 찾은 정사각형을 담는다.
    if (!square->square_length)
        print_err_msg(); // square의 최대 길이가 없다면 에러메시지 출력
    else
        print_map(map, square); // square이 표시된 map 출력
    free_map(map, map->y_len); // logic이 끝나고 할당된 map의 공간을 해제한다.
    free(square); // logic이 끝나고 할당된 square의 공간을 해제한다.
}

int	main(int argc, char *argv[])
{
    int	idx;

    if (argc == 1)
        bsq(0); // 인자가 하나일 경우 표준입력으로 입력받는다.
    else
    {
        idx = 0;
        while (++idx < argc)
        {
            bsq(argv[idx]); // 인자가 여러개일 경우 argv[1] ~ argv[argc - 1] 까지 bsq에 집어넣고 실행한다. 
            if (idx != argc - 1)
                ft_putchar('\n'); // 인자가 여러개일 경우 마지막을 제외한 결과값 후에는 개행문자를 출력한다.
        }
    }
    return (0);
}
