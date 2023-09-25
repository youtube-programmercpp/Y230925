// sample_2.cpp : Copyright(C) 2023 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory>

namespace deleter {
	struct fclose {
		void operator()(FILE* fp) const noexcept
		{
			(void)::fclose(fp);
		}
	};
}
int main()
{
	if (const std::unique_ptr<FILE, deleter::fclose> fp{ fopen(__FILE__, "r") }) {
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
