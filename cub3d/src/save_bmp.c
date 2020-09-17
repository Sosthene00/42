/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:55:27 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:55:29 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_bitmap_header(t_bmp *file, t_ima *screen)
{
	file->pixel_data_offset = 54;
	file->filesize = ((screen->size_line) * screen->height) +
		file->pixel_data_offset;
	file->headersize = 40;
	file->image_width = screen->width;
	file->image_height = screen->height;
	file->planes = 1;
	file->bpp = (unsigned short)screen->bpp;
}

static ssize_t	write_data(int fd, void *buffer, size_t n)
{
	ssize_t	temp;
	ssize_t	count;
	void	*to_free;

	if (buffer == NULL)
		return (-1);
	count = 0;
	to_free = buffer;
	while (n > 4096)
	{
		temp = write(fd, buffer, 4096);
		if (temp == -1)
			return (-1);
		buffer += temp;
		n -= temp;
		count += temp;
	}
	count += write(fd, buffer, n);
	free(to_free);
	return (count);
}

static void		*reverse_data(t_ima *screen)
{
	char	*res;
	int		i;
	int		m;
	int		n;

	n = screen->size_line * screen->height;
	m = 0;
	if (!(res = ft_calloc(n, sizeof(*res))))
		return (NULL);
	while ((n -= screen->size_line) >= 0)
	{
		i = 0;
		m += screen->size_line;
		while (i < screen->size_line)
		{
			res[i + m] = screen->data[i + n];
			i++;
		}
	}
	return (res);
}

static ssize_t	write_to_disk(int fd, t_bmp *f, t_ima *screen)
{
	ssize_t	count;
	size_t	data_size;

	count = 0;
	data_size = f->filesize - f->pixel_data_offset;
	count += write(fd, &("BM"), ft_strlen("BM"));
	count += write(fd, &(f->filesize), sizeof(f->filesize));
	count += write(fd, &(f->reserved1), sizeof(f->reserved1));
	count += write(fd, &(f->reserved2), sizeof(f->reserved2));
	count += write(fd, &(f->pixel_data_offset), sizeof(f->pixel_data_offset));
	count += write(fd, &(f->headersize), sizeof(f->headersize));
	count += write(fd, &(f->image_width), sizeof(f->image_width));
	count += write(fd, &(f->image_height), sizeof(f->image_height));
	count += write(fd, &(f->planes), sizeof(f->planes));
	count += write(fd, &(f->bpp), sizeof(f->bpp));
	count += write(fd, &(f->compression), sizeof(f->compression));
	count += write(fd, &(f->imagesize), sizeof(f->imagesize));
	count += write(fd, &(f->x_pixels_per_meter), sizeof(f->x_pixels_per_meter));
	count += write(fd, &(f->y_pixels_per_meter), sizeof(f->y_pixels_per_meter));
	count += write(fd, &(f->total_colors), sizeof(f->total_colors));
	count += write(fd, &(f->important_colors), sizeof(f->important_colors));
	count += write_data(fd, reverse_data(screen), data_size);
	return (count);
}

void			save_screenshot(t_ctx *c)
{
	int fd;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		exit_program(c, 3);
	init_img(c);
	raycasting(c);
	get_bitmap_header(&(c->screenshot), &(c->screen));
	if (write_to_disk(fd, &(c->screenshot), &(c->screen)) !=
		c->screenshot.filesize)
		exit_program(c, 3);
	if (close(fd) < 0)
		exit_program(c, 3);
	exit_program(c, 0);
}
