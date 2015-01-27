# Libftasm

## Building
`make` (#ez)

## Memos

available registers for our architecture:

64 bits register | 32 bits access | 16 bits access | 8 bits access | volatile           | function calls (integer)
---------------- | -------------- | -------------- | ------------- | ------------------ | -------------- 
rax              | eax            | ax             | ah / al       | :white_check_mark: | 
rbx              | ebx            | bx             | bh / bl       | :x:                | 
rcx              | ecx            | cx             | ch / cl       | :white_check_mark: | 4th argument
rdx              | edx            | dx             | dh / dl       | :white_check_mark: | 3rd argument
rsp              | esp            | sp             | spl           | :white_check_mark: | 
rbp              | ebp            | bp             | bpl           | :x:                | 
rsi              | esi            | si             | sil           | :white_check_mark: | 2nd argument
rdi              | edi            | di             | dil           | :white_check_mark: | 1st argument
r8               | r8d            | r8w            | r8b           | :white_check_mark: | 5th argument
r9               | r9d            | r9w            | r9b           | :white_check_mark: | 6th argument
r10              | r10d           | r10w           | r10b          | :white_check_mark: | 
r11              | r11d           | r11w           | r11b          | :white_check_mark: | 
r12              | r12d           | r12w           | r12b          | :x:                | 
r13              | r13d           | r13w           | r13b          | :x:                | 
r14              | r14d           | r14w           | r14b          | :x:                | 
r15              | r15d           | r15w           | r15b          | :x:                | 

:warning: When using a non volatile register, be sure to save its previous value (push it on the stack) before changing it and be sure to restore it after a `ret`

:warning: Do not count on volatile registers to keep their values after a `call` or a `syscall`

## Contributing
- Use 4 spaces to indent (for both asm and c++ code)
- Use ".s" as a file extension for nasm files
- Put nasm files in the srcs folder
- Put c++ test files in the tests folder
- Respect the calling conventions mentionned above
- Write thorough tests

