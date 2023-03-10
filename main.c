#include "monty.h"

global_t vglo;

/**
 * free_vglo - frees the global variables
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	freee(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 * @fd: file description
 * Return: no return
 */
void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}
/**
 * check_input - checks if the file exists and if the file can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (fd);
}
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *line[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_vglo(fd);
	nlines = getline(&vglo.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.count);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vgloo();
				exit(EXIT_FAILURE)
