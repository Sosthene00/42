#include "cube3d.h"

static void		get_bitmap_header(bmp *file, img *screen)
{
	file->PixelDataOffset = 54;
	file->FileSize = ((screen->size_line) * screen->height) +
		file->PixelDataOffset;
	file->HeaderSize = 40;
	file->ImageWidth = screen->width;
	file->ImageHeight = screen->height;
	file->Planes = 1;
	file->BitsPerPixel = (unsigned short)screen->bits_per_pixel;
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
	while (n > PIPE_BUF)
	{
		temp = write(fd, buffer, PIPE_BUF);
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

static void		*reverse_data(img *screen)
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

static ssize_t	write_to_disk(int fd, bmp *file, img *screen)
{
	ssize_t	count;
	size_t	data_size;

	count = 0;
	data_size = file->FileSize - file->PixelDataOffset;
	count += write(fd, &("BM"), ft_strlen("BM"));
	count += write(fd, &(file->FileSize), sizeof(file->FileSize));
	count += write(fd, &(file->Reserved1), sizeof(file->Reserved1));
	count += write(fd, &(file->Reserved2), sizeof(file->Reserved2));
	count += write(fd, &(file->PixelDataOffset), sizeof(file->PixelDataOffset));
	count += write(fd, &(file->HeaderSize), sizeof(file->HeaderSize));
	count += write(fd, &(file->ImageWidth), sizeof(file->ImageWidth));
	count += write(fd, &(file->ImageHeight), sizeof(file->ImageHeight));
	count += write(fd, &(file->Planes), sizeof(file->Planes));
	count += write(fd, &(file->BitsPerPixel), sizeof(file->BitsPerPixel));
	count += write(fd, &(file->Compression), sizeof(file->Compression));
	count += write(fd, &(file->ImageSize), sizeof(file->ImageSize));
	count += write(fd, &(file->XpixelsPerMeter), sizeof(file->XpixelsPerMeter));
	count += write(fd, &(file->YpixelsPerMeter), sizeof(file->YpixelsPerMeter));
	count += write(fd, &(file->TotalColors), sizeof(file->TotalColors));
	count += write(fd, &(file->ImportantColors), sizeof(file->ImportantColors));
	count += write_data(fd, reverse_data(screen), data_size);
	return (count);
}

int				save_screenshot(ctx *c)
{
	int fd;
	bmp *file;

	c->screenshot = 0;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		exit_program(c, 3);
	if (!(file = ft_calloc(1, sizeof(*file))))
		exit_program(c, 9);
	get_bitmap_header(file, &(c->screen));
	if (write_to_disk(fd, file, &(c->screen)) != file->FileSize)
		exit_program(c, 3);
	if (close(fd) < 0)
		exit_program(c, 3);
	free(file);
	return (0);
}
