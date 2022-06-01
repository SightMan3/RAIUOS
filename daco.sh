x86_64-elf-gcc -ffreestanding -m32 -g -c "kernel/krl.cpp" -o "out/kernel.o"
nasm "base/krl_entry.asm" -f elf -o "out/krl_entry.o"

cd out/
ls

x86_64-elf-ld -m elf_i386 -o "full_kernel.bin" -Ttext 0x1000 "krl_entry.o" "kernel.o" --oformat binary

nasm "../base/boot.asm" -f bin -o "boot.bin"
nasm "../base/zeros.asm" -f bin -o "zeros.bin"
cat "boot.bin" "full_kernel.bin" "zeros.bin" > "DISK_ERR.bin"

ls

qemu-system-x86_64 -drive format=raw,file="DISK_ERR.bin",index=0,if=floppy,  -m 256M
