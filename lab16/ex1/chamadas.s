/*
int myopen (const char *pathname, int flags, int buffersize) {
  tamBufferAberto = buffersize;
  return open(pathname, flags);
}

ssize_t myread(int fd, void *buf) {
  return read(fd, buf, tamBufferAberto);
}
*/

.text

.global myopen, myread, mywrite, myclose

myopen:
  movq  %rdx,tamBufferAberto
  movq  $2,%rax

  syscall

  ret

myread:
  movq tamBufferAberto,%rdx
  movq $0,%rax

  syscall

  ret

mywrite:
  movq  $1,%rax

  syscall

  ret

myclose:
  movq $3,%rax

  syscall

  ret
