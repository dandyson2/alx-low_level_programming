/*
 * File: 100-elf_header.c
 * Author: Ozioma V. Chukwumezie
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void evaluate_elf(unsigned char *e_ident);
void dis_magic(unsigned char *e_ident);
void dis_class(unsigned char *e_ident);
void dis_data(unsigned char *e_ident);
void dis_version(unsigned char *e_ident);
void dis_os_abi(unsigned char *e_ident);
void dis_abi_v(unsigned char *e_ident);
void dis_type(unsigned int alt_path, unsigned char *e_ident);
void dis_entry_pa(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * evaluate_elf - Checks if file is an ELF file
 * @e_ident: ptr to array that contains ELF magic numbers
 * Descrip: If file is not an ELF file, exit with 98
 */
void evaluate_elf(unsigned char *e_ident)
{
	int first;

	for (first = 0; first < 4; first++)
	{
		if (e_ident[first] != 127 &&
		e_ident[first] != 'E' &&
		e_ident[first] != 'L' &&
		e_ident[first] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * dis_magic - Prints the magic numbers of an ELF header
 * @e_ident: ptr to array that contains ELF magic numbers
 * Descrip: Magic numbers seperated by spaces
 */
void dis_magic(unsigned char *e_ident)
{
	int first;

	printf("  Magic:   ");

	for (first = 0; first < EI_NIDENT; first++)
	{
		printf("%02x", e_ident[first]);

		if (first == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * dis_class - Prints the class of an ELF header
 * @e_ident: ptr to array that contains ELF class
 */
void dis_class(unsigned char *e_ident)
{
	printf("  Class:				");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * dis_data - Prints data of an ELF header
 * @e_ident: ptr to array that contains an ELF class
 */
void dis_data(unsigned char *e_ident)
{
	printf("  Data:					");
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
 * dis_version - Prints the version of an ELF header
 * @e_ident: ptr to array that contains an ELF version
 */
void dis_version(unsigned char *e_ident)
{
	printf("  Version:				%d",		e_ident[EI_VERSION]);
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
 * dis_os_abi - Prints the OS/ABI of an ELF header
 * @e_ident: ptr to array that contains an ELF version
 */
void dis_os_abi(unsigned char *e_ident)
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
 * dis_abi_v - Prints the ABI of an ELF header
 * @e_ident: ptr to array that contains the ELF ABI version
 */
void dis_abi_v(unsigned char *e_ident)
{
	printf("  ABI Version:				%d\n",	e_ident[EI_ABIVERSION]);
}

/**
 * dis_type - Prints type of an ELF header
 * @e_type: Type of ELF
 * @e_ident: ptr to array that contains the ELF class
 */
void dis_type(unsigned int e_type, unsigned char *e_ident)
{

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	e_type >>= 8;

		printf("  Type:				");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file\n");
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
 * dis_entry_pa - Prints the entry path of an ELF header
 * @e_entry: Address of the ELF entry point
 * @e_ident: ptr to array that contains the ELF class
 */
void dis_entry_pa(unsigned long int e_entry, unsigned char *e_ident)
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
 * close_elf - Function that close an ELF file
 * @elf: File descriptor of ELF
 * Descrip: If file cannot be closed, exit with code 98
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Prints the details of the ELF headerat the
 * start of an ELF file
 * @argc: Number of args contained in the programm
 * @argv: Array of ptrs to the arguments
 * Return: 0 if successful
 * Descrip: If not an ELF file or function fails,
 * exit with code 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int y, z;

	y = open(argv[1], O_RDONLY);
	if (y == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(y);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	z = read(y, header, sizeof(Elf64_Ehdr));
	if (z == -1)
	{
		free(header);
		close_elf(y);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	evaluate_elf(header->e_ident);
	printf("ELF Header:\n");
	dis_magic(header->e_ident);
	dis_class(header->e_ident);
	dis_data(header->e_ident);
	dis_version(header->e_ident);
	dis_os_abi(header->e_ident);
	dis_abi_v(header->e_ident);
	dis_type(header->e_type, header->e_ident);
	dis_entry_pa(header->e_entry, header->e_ident);

	free(header);
	close_elf(y);
	return (0);
}
