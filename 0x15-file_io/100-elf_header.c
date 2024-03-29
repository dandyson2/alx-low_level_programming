#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


void check_elf(unsigned char *e_ident);
void stmp_magic(unsigned char *e_ident);
void stmp_class(unsigned char *e_ident);
void stmp_data(unsigned char *e_ident);
void stmp_version(unsigned char *e_ident);
void stmp_abi(unsigned char *e_ident);
void stmp_osabi(unsigned char *e_ident);
void stmp_type(unsigned int e_type, unsigned char *e_ident);
void stmp_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - check if a file is an ELF file
 * @e_ident: ptr to an array
 * Descrip: if file is not an ELF file, exit with code 98
 */

void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * stmp_magic - print magic numbers of an ELF header
 * @e_ident: ptr to array that contains ELF magic numbers
 * Descrip: magic numbers are seperated by spaces
 */
void stmp_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * stmp_class - print class of an ELF header
 * @e_ident: ptr to array that contains the ELF class
 */
void stmp_class(unsigned char *e_ident)
{
	printf("  Class:				");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * stmp_data - print the data of an ELF header
 * @e_ident: ptr to array containing an ELF data
 */
void stmp_data(unsigned char *e_ident)
{
	printf("  Data:				");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * stmp_version - print version of an ELF header
 * @e_ident: ptr to array that contains an ELF version
 */
void stmp_version(unsigned char *e_ident)
{
	printf("  Version:				%d",				e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * stmp_osabi - print the OS/ABI of an ELF header
 * @e_ident: ptr to array that contains OS/ABI
 */
void stmp_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:				");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * stmp_abi - print the ABI version of an ELF header
 * @e_ident: ptr to array that contains ABI version of ELF
 */
void stmp_abi(unsigned char *e_ident)
{
	printf("  ABI Version:				%d\n",					e_ident[EI_ABIVERSION]);
}

/**
 * stmp_type - print type of an ELF header
 * @e_ident: ptr to array that contains an ELF type
 * @e_type: ELF type
 */
void stmp_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:				");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (none)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * stmp_entry - print entry point of an ELF header
 * @e_ident: ptr to array that contains an ELF class
 * @e_entry: address of ELF entry point
 */
void stmp_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:			");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - close an ELF file
 * @elf: ELF file descriptor
 * Descrip: if file cannot be closed, exit with code 98
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - display contents in the ELF header
 * at the start of an ELF file
 * @argc: argument number to programm
 * @argv: array of pointers to arguments
 * Return: 0
 * Descrip: if file is not an ELF file,
 * if function fails, exit with code 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf32_Ehdr *header;
	int r, w;

	r = open(argv[1], O_RDONLY);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf32_Ehdr));
	if (header == NULL)
	{
		close_elf(r);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	w = read(r, header, sizeof(Elf32_Ehdr));
	if (w == -1)
	{
		free(header);
		close_elf(r);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	stmp_magic(header->e_ident);
	stmp_class(header->e_ident);
	stmp_data(header->e_ident);
	stmp_version(header->e_ident);
	stmp_osabi(header->e_ident);
	stmp_abi(header->e_ident);
	stmp_type(header->e_type, header->e_ident);
	stmp_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(r);
	return (0);
}
