.code 

PUBLIC GetStdOut
PUBLIC NtWriteFile
	
GetStdOut PROC
	mov rax, gs:[60h]
	mov rax, [rax+20h]
	mov rax, [rax+28h]
	ret
GetStdOut ENDP

NtWriteFile PROC
	mov r10, rcx
	mov eax, 08h
	syscall
	ret
NtWriteFile ENDP

END