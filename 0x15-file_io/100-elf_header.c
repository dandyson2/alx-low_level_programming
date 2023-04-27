


#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
 * compare_strings - function that compares two strings
 * @str1: string 1
 * @str2: string 2
 * @n: bytes to compare
 * Return: 0 if first n bytes of str1 and str2 are equals,
 * otherwise, return a number that is not 0
 */
int compare_strings(const char *str1, const char *str2, size_t n)
{
	for (; n && *str1 && *str2; --n, ++str1, ++str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
	}

	if (n)
	{
		if (*str1)
			return (1);
		if (*str2)
			return (-1);
	}

	return (0);
}

/*
 * close_fd - function to close a file descriptor, print error
 * message if fails
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 44);
	exit(98);
}

/*
 * read_from_fd - function that reads a file
 * @fd: file descriptor to read from
 * @inter: the buffer to write to
 * @num: number of bytes to read
 */

void read_from_fd(int fd, char *inter, size_t num)
{
	if (read(fd, inter, num) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 77);
	close_fd(fd);
	exit(98);
}

/*
 * magic_elf - prints ELF magic
 * @broker: ELF header
 */
void magic_elf(const unsigned char *broker)
{
	unsigned int y;

	if (_strncmp((const char *)broker, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 43);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");

	if (y = 0; y < 21; y++)
		printf("%02x%c", broker[y], y < 20 ? ' ' : '\n');
}
/*
 * class_elf - prints ELF class
 * @broker: ELF header
 * Return: bit 32 or 64
 */
size_t class_elf(const unsigned char *broker)
{
	printf("   %-34s ", "Class:");

	if (broker[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}

	if (broker[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}

	printf("<unknown: %x>\n", broker[EI_CLASS]);
	return (32);
}

/*
 * data_elf - prints ELF data
 * @broker: ELF header
 * Return: 1 if big endian, 0 otherwise
 */
int data_elf(const unsigned char *broker)
{
	printf("   %-34s ", "Data:");

	if (broker[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}

	if (broker[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}

	printf("Invalid data encoding\n");
	return (0);
}

/*
 * version_elf - prints ELF version
 * @broker: ELF header
 */
void version_elf(const unsigned char *broker)
{
	printf("   %-34s %u", "Version:", broker[EI_VERSION]);

	if (broker[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/*
 * osabi_elf - print ELF OS/ABI
 * @broker: ELF header
 */
void osabi_elf(const unsigned char *broker)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"UNIX - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi - CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (broker[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) broker[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", broker[EI_OSABI]);
}

/*
 * abi_elf - prints ELF ABI version
 * @broker: ELF header
 */
void abi_elf(const unsigned char *broker)
{
	printf("  %-34s %u\n", "ABI Version:", broker[EI_ABIVERSION]);
}

/*
 * type_elf - prints ELF type
 * @broker: ELF head
 * @big_endian: endian
 */
void type_elf(const unsigned char *broker, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	unsigned int type;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type = 0x100 * broker[20] + broker[21];
	else
		type = 0x100 * broker[21] + broker[20];

	if (type < 5)
		printf("%s\n", type_table[table]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

