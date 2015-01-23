# Libftasm

## Building
`make` -> builds libfts.a  
`make tests` -> builds the test suite

## Contributing
- USE 4 SPACES TO INDENT
- Use ".s" as a file extension for nasm files
- Put nasm files in the srcs folder
- Put c test files in the tests folder

## Calling conventions !BEWARE!
- Registers RAX, RCX, RDX, R8, R9, R10, and R11 are considered volatile and must be considered destroyed on function calls.
- RBX, RBP, RDI, RSI, R12, R13, R14, and R15 must be saved in any function using them.
