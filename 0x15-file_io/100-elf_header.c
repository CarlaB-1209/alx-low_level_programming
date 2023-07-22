#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void is_elf(unsigned char *e_identifier);
void magic(unsigned char *e_identifier);
void class(unsigned char *e_identifier);
void data(unsigned char *e_identifier);
void version(unsigned char *e_identifier);
void abi(unsigned char *e_identifier);
void osabi(unsigned char *e_identifier);
void type(unsigned int elf_type, unsigned char *e_identifier);
void entry(unsigned long int elf_entry, unsigned char *e_identifier);
void closer(int elf);

/**
 * is_elf - is it an elf file
 * @e_ident: pointer to elf magic numbers
 */

void is_elf(unsigned char *e_identifier)
{
	int list;

	for (list = 0; list < 4; list++)
	{
		if (e_identifier[list] != 127 &&
		    e_identifier[list] != 'E' &&
		    e_identifier[list] != 'L' &&
		    e_identifier[list] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic - prints the elf magic numbers
 * @e_identifier: pointer to elf magic numbers
 */

void magic(unsigned char *e_identifier)
{
	int list;

	printf(" Magic: ");

	for (list = 0; list < EI_NIDENT; list++)
	{
		printf("%02x", e_identifier[list]);

		if (list == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class - prints elf header class
 * @e_identifier: pointer to elf class
 */

void class(unsigned char *e_identifier)
{
	printf(" Class: ");

	switch (e_identifier[EI_CLASS])
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
		printf("<unknown: %x>\n", e_identifier[EI_CLASS]);
	}
}

/**
 * data - prints elf header data
 * @e_identifier: pointer to data
 */
void data(unsigned char *e_identifier)
{
	printf(" Data: ");

	switch (e_identifier[EI_DATA])
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
		printf("<unknown: %x>\n", e_identifier[EI_CLASS]);
	}
}

/**
 * version - prints elf header version
 * @e_identifier: pointer to version
 */

void version(unsigned char *e_identifier)
{
	 printf(" Version: %d",
			  e_identifier[EI_VERSION]);

	switch (e_identifier[EI_VERSION])
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
 * osabi - prints the elf header OS/ABI
 * @e_identifier: pointer to OS/ABI
 */

void osabi(unsigned char *e_identifier)
{
	printf(" OS/ABI: ");

	switch (e_identifier[EI_OSABI])
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
		printf("<unknown: %x>\n", e_identifier[EI_OSABI]);
	}
}

/**
 * abi - prints the elf header ABI version
 * @e_identifier: pointer to the ABI version
 */

void abi(unsigned char *e_identifier)
{
	printf(" ABI Version: %d\n",
		e_identifier[EI_ABIVERSION]);
}

/**
 * type - prints the elf header type
 * @elf_type: the elf type
 * @e_identifier: pointer to elf type
 */

void type(unsigned int elf_type, unsigned char *e_identifier)
{
	if (e_identifier[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf(" Type: ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * entry - prints the entry point
 * @elf_entry: address of the entry point
 * @e_identifier: pointer to address of entry point
 */

void entry(unsigned long int elf_entry, unsigned char *e_identifier)
{
	printf(" Entry point address: ");

	if (e_identifier[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (e_identifier[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * closer - closes the elf header file
 * @elf: file descriptor
 */

void closer(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - shows infoath the start of elf file
 * @argc: argument number
 * @argv: list of arguments
 *
 * Return: 0 (success)
 */


int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *file_head;
	int opener, reader;

	opener = open(argv[1], O_RDONLY);
	if (opener == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	file_head = malloc(sizeof(Elf64_Ehdr));
	if (file_head == NULL)
	{
		closer(opener);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	reader = read(opener, file_head, sizeof(Elf64_Ehdr));
	if (reader == -1)
	{
		free(file_head);
		closer(opener);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	is_elf(file_head->e_identifier);
	printf("ELF Header:\n");
	magic(file_head->e_identifier);
	class(file_head->e_identifier);
	data(file_head->e_identifier);
	version(file_head->e_identifier);
	osabi(file_head->e_identifier);
	abi(file_head->e_identifier);
	type(file_head->e_identifier);
	entry(file_head->elf_entry, file_head->e_identifier;

	free(file_head);
	closer(opener);
	return (0);
}

