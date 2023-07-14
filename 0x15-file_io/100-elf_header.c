#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * print_elf_header_info - displays the information contained in the ELF header
 *				at the start of an ELF file.
 */

void print_error_exit(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

void print_elf_header_info(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", elf_header->e_ident[i]);
	}
	printf("\n");
	printf("Class: %d-bit\n", (elf_header->e_ident[EI_CLASS] == ELFCLASS64) ? 64 : 32);
	printf("Data: %s\n", (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);
	printf("OS/ABI: ");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX: printf("HP-UX");
			break;
		case ELFOSABI_NETBSD: printf("NetBSD");
			break;
		case ELFOSABI_LINUX: printf("Linux");
			break;
		case ELFOSABI_SOLARIS: printf("Solaris");
			break;
		case ELFOSABI_AIX: printf("AIX");
			break;
		case ELFOSABI_FREEBSD: printf("FreeBSD");
			break;
		case ELFOSABI_TRU64: printf("Tru64 UNIX");
			break;
		case ELFOSABI_ARM: printf("ARM architecture");
			break;
		case ELFOSABI_STANDALONE: printf("Stand-alone application");
			break;
		default: printf("Unknown");
	}
	printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("Type: ");
	switch (elf_header->e_type)
	{
		case ET_NONE: printf("No file type");
			break;
		case ET_REL: printf("Relocatable file");
			break;
		case ET_EXEC: printf("Executable file");
			break;
		case ET_DYN: printf("Shared object");
			break;
		case ET_CORE: printf("Core file");
			break;
		default: printf("Unknown");
	}
	printf("Entry point address: 0x%lx\n", elf_header->e_entry);
}
