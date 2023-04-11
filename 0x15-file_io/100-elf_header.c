#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void evaluate_elf(unsigned char *alt_v);
void dis_magic(unsigned char *alt_v);
void dis_class(unsigned char *alt_v);
void dis_data(unsigned char *alt_v);
void dis_version(unsigned char *alt_v);
void dis_os_abi(unsigned char *alt_v);
void dis_abi_v(unsigned char *alt_v);
void dis_type(unsigned int alt_path, unsigned char *alt_v);
void dis_entry_pa(unsigned long int alt_path2, unsigned char *alt_v);
void close_elf(int elf);

/**
 * evaluate_elf - Checks if file is an ELF file
 * @alt_v: ptr to array that contains ELF magic numbers
 * Descrip: If file is not an ELF file, exit with 98
 */
void evaluate_elf(unsigned char *alt_v)
{
	int first;

	for (first = 0; first < 4; first++)
	{
		if (alt_v[first] != 127 &&
		alt_v[first] != 'E' &&
		alt_v[first] != 'L' &&
		alt_v[first] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * dis_magic - Prints the magic numbers of an ELF header
 * @alt_v: ptr to array that contains ELF magic numbers
 * Descrip: Magic numbers seperated by spaces
 */
void dis_magic(unsigned char *alt_v)
{
	int first;

	printf("  Magic:   ");

	for (first = 0; first < EI_NIDENT; first++)
	{
		printf("%02x", alt_v[first]);

		if (first == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * dis_class - Prints the class of an ELF header
 * @alt_v: ptr to array that contains ELF class
 */
void dis_class(unsigned char *alt_v)
{
	printf("  Class:				");

	switch (alt_v[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", alt_v[EI_CLASS]);
	}
}

/**
 * dis_data - Prints data of an ELF header
 * @alt_v: ptr to array that contains an ELF class
 */
void dis_data(unsigned char *alt_v)
{
	printf("  Data:					");
	switch (alt_v[EI_DATA])
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
			printf("<unknown: %x>\n", alt_v[EI_CLASS]);
	}
}

/**
 * dis_version - Prints the version of an ELF header
 * @alt_v: ptr to array that contains an ELF version
 */
void dis_version(unsigned char *alt_v)
{
	printf("  Version:				%d",		alt_v[EI_VERSION]);
	switch (alt_v[EI_VERSION])
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
 * @alt_v: ptr to array that contains an ELF version
 */
void dis_os_abi(unsigned char *alt_v)
{
	printf("  OS/ABI:				");
	switch (alt_v[EI_OSABI])
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
			printf("<unknown: %x>\n", alt_v[EI_OSABI]);
	}
}

/**
 * dis_abi_v - Prints the ABI of an ELF header
 * @alt_v: ptr to array that contains the ELF ABI version
 */
void dis_abi_v(unsigned char *alt_v)
{
	printf("  ABI Version:				%d\n",	alt_v[EI_ABIVERSION]);
}

/**
 * dis_type - Prints type of an ELF header
 * @alt_path: Type of ELF
 * @alt_v: ptr to array that contains the ELF class
 */
void dis_type(unsigned int alt_path, unsigned char *alt_v)
{
	if (alt_v[EI_DATA] == ELFDATA2MSB)
		alt_path >>= 8;

		printf("  Type:			");

	switch (alt_path)
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
			printf("<unknown: %x>\n", alt_path);
		}
}

/**
 * dis_entry_pa - Prints the entry path of an ELF header
 * @alt_path2: Address of the ELF entry point
 * @alt_v: ptr to array that contains the ELF class
 */
void dis_entry_pa(unsigned long int alt_path2, unsigned char *alt_v)
{
	printf("  Entry point address:			");

	if (alt_v[EI_DATA] == ELFDATA2MSB)
	{
		alt_path2 = ((alt_path2 << 8) & 0xFF00FF00) | ((alt_path2 >> 8) & 0xFF00FF);
		alt_path2 = (alt_path2 << 16) | (alt_path2 >> 16);
	}

	if (alt_v[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)alt_path2);

	else
		printf("%#lx\n", alt_path2);
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

	evaluate_elf(header->alt_v);
	printf("ELF Header:\n");
	dis_magic(header->alt_v);
	dis_class(header->alt_v);
	dis_data(header->alt_v);
	dis_version(header->alt_v);
	dis_os_abi(header->alt_v);
	dis_abi_v(header->alt_v);
	dis_type(header->alt_path, header->alt_v);
	dis_entry_pa(header->alt_path2, header->alt_v);

	free(header);
	close_elf(y);
	return (0);
}
