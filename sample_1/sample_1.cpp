// sample_1.cpp : Copyright(C) 2023 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory>

int main()
{
	if (const std::unique_ptr<FILE, decltype(fclose)*> fp{ fopen(__FILE__, "r"), fclose }) {
		printf("sizeof fp = %zu\n", sizeof fp);
		for (;;) {
			const auto ch = getc(fp.get());
			if (ch == EOF)
				break;
			else
				putchar(ch);
		}
	}
}
