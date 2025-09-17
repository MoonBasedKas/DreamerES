# main:
# 	gcc -o main.exe main.cpp  -I include -L lib -lraylib -lgdi32 -lwinmm
main:
	gcc -o main.exe main.c cpu/cpu.c

clean:
	rm main.exe