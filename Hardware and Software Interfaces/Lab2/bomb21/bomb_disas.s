
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000400b18 <_init>:
  400b18:	f3 0f 1e fa          	endbr64 
  400b1c:	48 83 ec 08          	sub    $0x8,%rsp
  400b20:	48 8b 05 c9 24 20 00 	mov    0x2024c9(%rip),%rax        # 602ff0 <__gmon_start__>
  400b27:	48 85 c0             	test   %rax,%rax
  400b2a:	74 02                	je     400b2e <_init+0x16>
  400b2c:	ff d0                	callq  *%rax
  400b2e:	48 83 c4 08          	add    $0x8,%rsp
  400b32:	c3                   	retq   

Disassembly of section .plt:

0000000000400b40 <.plt>:
  400b40:	ff 35 c2 24 20 00    	pushq  0x2024c2(%rip)        # 603008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400b46:	ff 25 c4 24 20 00    	jmpq   *0x2024c4(%rip)        # 603010 <_GLOBAL_OFFSET_TABLE_+0x10>
  400b4c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400b50 <getenv@plt>:
  400b50:	ff 25 c2 24 20 00    	jmpq   *0x2024c2(%rip)        # 603018 <getenv@GLIBC_2.2.5>
  400b56:	68 00 00 00 00       	pushq  $0x0
  400b5b:	e9 e0 ff ff ff       	jmpq   400b40 <.plt>

0000000000400b60 <strcpy@plt>:
  400b60:	ff 25 ba 24 20 00    	jmpq   *0x2024ba(%rip)        # 603020 <strcpy@GLIBC_2.2.5>
  400b66:	68 01 00 00 00       	pushq  $0x1
  400b6b:	e9 d0 ff ff ff       	jmpq   400b40 <.plt>

0000000000400b70 <puts@plt>:
  400b70:	ff 25 b2 24 20 00    	jmpq   *0x2024b2(%rip)        # 603028 <puts@GLIBC_2.2.5>
  400b76:	68 02 00 00 00       	pushq  $0x2
  400b7b:	e9 c0 ff ff ff       	jmpq   400b40 <.plt>

0000000000400b80 <fclose@plt>:
  400b80:	ff 25 aa 24 20 00    	jmpq   *0x2024aa(%rip)        # 603030 <fclose@GLIBC_2.2.5>
  400b86:	68 03 00 00 00       	pushq  $0x3
  400b8b:	e9 b0 ff ff ff       	jmpq   400b40 <.plt>

0000000000400b90 <system@plt>:
  400b90:	ff 25 a2 24 20 00    	jmpq   *0x2024a2(%rip)        # 603038 <system@GLIBC_2.2.5>
  400b96:	68 04 00 00 00       	pushq  $0x4
  400b9b:	e9 a0 ff ff ff       	jmpq   400b40 <.plt>

0000000000400ba0 <printf@plt>:
  400ba0:	ff 25 9a 24 20 00    	jmpq   *0x20249a(%rip)        # 603040 <printf@GLIBC_2.2.5>
  400ba6:	68 05 00 00 00       	pushq  $0x5
  400bab:	e9 90 ff ff ff       	jmpq   400b40 <.plt>

0000000000400bb0 <rewind@plt>:
  400bb0:	ff 25 92 24 20 00    	jmpq   *0x202492(%rip)        # 603048 <rewind@GLIBC_2.2.5>
  400bb6:	68 06 00 00 00       	pushq  $0x6
  400bbb:	e9 80 ff ff ff       	jmpq   400b40 <.plt>

0000000000400bc0 <dup@plt>:
  400bc0:	ff 25 8a 24 20 00    	jmpq   *0x20248a(%rip)        # 603050 <dup@GLIBC_2.2.5>
  400bc6:	68 07 00 00 00       	pushq  $0x7
  400bcb:	e9 70 ff ff ff       	jmpq   400b40 <.plt>

0000000000400bd0 <close@plt>:
  400bd0:	ff 25 82 24 20 00    	jmpq   *0x202482(%rip)        # 603058 <close@GLIBC_2.2.5>
  400bd6:	68 08 00 00 00       	pushq  $0x8
  400bdb:	e9 60 ff ff ff       	jmpq   400b40 <.plt>

0000000000400be0 <fputc@plt>:
  400be0:	ff 25 7a 24 20 00    	jmpq   *0x20247a(%rip)        # 603060 <fputc@GLIBC_2.2.5>
  400be6:	68 09 00 00 00       	pushq  $0x9
  400beb:	e9 50 ff ff ff       	jmpq   400b40 <.plt>

0000000000400bf0 <fgets@plt>:
  400bf0:	ff 25 72 24 20 00    	jmpq   *0x202472(%rip)        # 603068 <fgets@GLIBC_2.2.5>
  400bf6:	68 0a 00 00 00       	pushq  $0xa
  400bfb:	e9 40 ff ff ff       	jmpq   400b40 <.plt>

0000000000400c00 <tmpfile@plt>:
  400c00:	ff 25 6a 24 20 00    	jmpq   *0x20246a(%rip)        # 603070 <tmpfile@GLIBC_2.2.5>
  400c06:	68 0b 00 00 00       	pushq  $0xb
  400c0b:	e9 30 ff ff ff       	jmpq   400b40 <.plt>

0000000000400c10 <signal@plt>:
  400c10:	ff 25 62 24 20 00    	jmpq   *0x202462(%rip)        # 603078 <signal@GLIBC_2.2.5>
  400c16:	68 0c 00 00 00       	pushq  $0xc
  400c1b:	e9 20 ff ff ff       	jmpq   400b40 <.plt>

0000000000400c20 <gethostbyname@plt>:
  400c20:	ff 25 5a 24 20 00    	jmpq   *0x20245a(%rip)        # 603080 <gethostbyname@GLIBC_2.2.5>
  400c26:	68 0d 00 00 00       	pushq  $0xd
  400c2b:	e9 10 ff ff ff       	jmpq   400b40 <.plt>

0000000000400c30 <fprintf@plt>:
  400c30:	ff 25 52 24 20 00    	jmpq   *0x202452(%rip)        # 603088 <fprintf@GLIBC_2.2.5>
  400c36:	68 0e 00 00 00       	pushq  $0xe
  400c3b:	e9 00 ff ff ff       	jmpq   400b40 <.plt>

0000000000400c40 <strtol@plt>:
  400c40:	ff 25 4a 24 20 00    	jmpq   *0x20244a(%rip)        # 603090 <strtol@GLIBC_2.2.5>
  400c46:	68 0f 00 00 00       	pushq  $0xf
  400c4b:	e9 f0 fe ff ff       	jmpq   400b40 <.plt>

0000000000400c50 <fflush@plt>:
  400c50:	ff 25 42 24 20 00    	jmpq   *0x202442(%rip)        # 603098 <fflush@GLIBC_2.2.5>
  400c56:	68 10 00 00 00       	pushq  $0x10
  400c5b:	e9 e0 fe ff ff       	jmpq   400b40 <.plt>

0000000000400c60 <__isoc99_sscanf@plt>:
  400c60:	ff 25 3a 24 20 00    	jmpq   *0x20243a(%rip)        # 6030a0 <__isoc99_sscanf@GLIBC_2.7>
  400c66:	68 11 00 00 00       	pushq  $0x11
  400c6b:	e9 d0 fe ff ff       	jmpq   400b40 <.plt>

0000000000400c70 <memmove@plt>:
  400c70:	ff 25 32 24 20 00    	jmpq   *0x202432(%rip)        # 6030a8 <memmove@GLIBC_2.2.5>
  400c76:	68 12 00 00 00       	pushq  $0x12
  400c7b:	e9 c0 fe ff ff       	jmpq   400b40 <.plt>

0000000000400c80 <cuserid@plt>:
  400c80:	ff 25 2a 24 20 00    	jmpq   *0x20242a(%rip)        # 6030b0 <cuserid@GLIBC_2.2.5>
  400c86:	68 13 00 00 00       	pushq  $0x13
  400c8b:	e9 b0 fe ff ff       	jmpq   400b40 <.plt>

0000000000400c90 <fopen@plt>:
  400c90:	ff 25 22 24 20 00    	jmpq   *0x202422(%rip)        # 6030b8 <fopen@GLIBC_2.2.5>
  400c96:	68 14 00 00 00       	pushq  $0x14
  400c9b:	e9 a0 fe ff ff       	jmpq   400b40 <.plt>

0000000000400ca0 <sprintf@plt>:
  400ca0:	ff 25 1a 24 20 00    	jmpq   *0x20241a(%rip)        # 6030c0 <sprintf@GLIBC_2.2.5>
  400ca6:	68 15 00 00 00       	pushq  $0x15
  400cab:	e9 90 fe ff ff       	jmpq   400b40 <.plt>

0000000000400cb0 <exit@plt>:
  400cb0:	ff 25 12 24 20 00    	jmpq   *0x202412(%rip)        # 6030c8 <exit@GLIBC_2.2.5>
  400cb6:	68 16 00 00 00       	pushq  $0x16
  400cbb:	e9 80 fe ff ff       	jmpq   400b40 <.plt>

0000000000400cc0 <connect@plt>:
  400cc0:	ff 25 0a 24 20 00    	jmpq   *0x20240a(%rip)        # 6030d0 <connect@GLIBC_2.2.5>
  400cc6:	68 17 00 00 00       	pushq  $0x17
  400ccb:	e9 70 fe ff ff       	jmpq   400b40 <.plt>

0000000000400cd0 <fwrite@plt>:
  400cd0:	ff 25 02 24 20 00    	jmpq   *0x202402(%rip)        # 6030d8 <fwrite@GLIBC_2.2.5>
  400cd6:	68 18 00 00 00       	pushq  $0x18
  400cdb:	e9 60 fe ff ff       	jmpq   400b40 <.plt>

0000000000400ce0 <sleep@plt>:
  400ce0:	ff 25 fa 23 20 00    	jmpq   *0x2023fa(%rip)        # 6030e0 <sleep@GLIBC_2.2.5>
  400ce6:	68 19 00 00 00       	pushq  $0x19
  400ceb:	e9 50 fe ff ff       	jmpq   400b40 <.plt>

0000000000400cf0 <__ctype_b_loc@plt>:
  400cf0:	ff 25 f2 23 20 00    	jmpq   *0x2023f2(%rip)        # 6030e8 <__ctype_b_loc@GLIBC_2.3>
  400cf6:	68 1a 00 00 00       	pushq  $0x1a
  400cfb:	e9 40 fe ff ff       	jmpq   400b40 <.plt>

0000000000400d00 <socket@plt>:
  400d00:	ff 25 ea 23 20 00    	jmpq   *0x2023ea(%rip)        # 6030f0 <socket@GLIBC_2.2.5>
  400d06:	68 1b 00 00 00       	pushq  $0x1b
  400d0b:	e9 30 fe ff ff       	jmpq   400b40 <.plt>

Disassembly of section .text:

0000000000400d10 <_start>:
  400d10:	f3 0f 1e fa          	endbr64 
  400d14:	31 ed                	xor    %ebp,%ebp
  400d16:	49 89 d1             	mov    %rdx,%r9
  400d19:	5e                   	pop    %rsi
  400d1a:	48 89 e2             	mov    %rsp,%rdx
  400d1d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400d21:	50                   	push   %rax
  400d22:	54                   	push   %rsp
  400d23:	49 c7 c0 20 19 40 00 	mov    $0x401920,%r8
  400d2a:	48 c7 c1 b0 18 40 00 	mov    $0x4018b0,%rcx
  400d31:	48 c7 c7 f6 0d 40 00 	mov    $0x400df6,%rdi
  400d38:	ff 15 aa 22 20 00    	callq  *0x2022aa(%rip)        # 602fe8 <__libc_start_main@GLIBC_2.2.5>
  400d3e:	f4                   	hlt    

0000000000400d3f <.annobin_init.c>:
  400d3f:	90                   	nop

0000000000400d40 <_dl_relocate_static_pie>:
  400d40:	f3 0f 1e fa          	endbr64 
  400d44:	c3                   	retq   

0000000000400d45 <.annobin__dl_relocate_static_pie.end>:
  400d45:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400d4c:	00 00 00 
  400d4f:	90                   	nop

0000000000400d50 <deregister_tm_clones>:
  400d50:	48 8d 3d e9 2c 20 00 	lea    0x202ce9(%rip),%rdi        # 603a40 <stdout@@GLIBC_2.2.5>
  400d57:	48 8d 05 e2 2c 20 00 	lea    0x202ce2(%rip),%rax        # 603a40 <stdout@@GLIBC_2.2.5>
  400d5e:	48 39 f8             	cmp    %rdi,%rax
  400d61:	74 15                	je     400d78 <deregister_tm_clones+0x28>
  400d63:	48 8b 05 76 22 20 00 	mov    0x202276(%rip),%rax        # 602fe0 <_ITM_deregisterTMCloneTable>
  400d6a:	48 85 c0             	test   %rax,%rax
  400d6d:	74 09                	je     400d78 <deregister_tm_clones+0x28>
  400d6f:	ff e0                	jmpq   *%rax
  400d71:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  400d78:	c3                   	retq   
  400d79:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400d80 <register_tm_clones>:
  400d80:	48 8d 3d b9 2c 20 00 	lea    0x202cb9(%rip),%rdi        # 603a40 <stdout@@GLIBC_2.2.5>
  400d87:	48 8d 35 b2 2c 20 00 	lea    0x202cb2(%rip),%rsi        # 603a40 <stdout@@GLIBC_2.2.5>
  400d8e:	48 29 fe             	sub    %rdi,%rsi
  400d91:	48 c1 fe 03          	sar    $0x3,%rsi
  400d95:	48 89 f0             	mov    %rsi,%rax
  400d98:	48 c1 e8 3f          	shr    $0x3f,%rax
  400d9c:	48 01 c6             	add    %rax,%rsi
  400d9f:	48 d1 fe             	sar    %rsi
  400da2:	74 14                	je     400db8 <register_tm_clones+0x38>
  400da4:	48 8b 05 4d 22 20 00 	mov    0x20224d(%rip),%rax        # 602ff8 <_ITM_registerTMCloneTable>
  400dab:	48 85 c0             	test   %rax,%rax
  400dae:	74 08                	je     400db8 <register_tm_clones+0x38>
  400db0:	ff e0                	jmpq   *%rax
  400db2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  400db8:	c3                   	retq   
  400db9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400dc0 <__do_global_dtors_aux>:
  400dc0:	f3 0f 1e fa          	endbr64 
  400dc4:	80 3d 8d 2c 20 00 00 	cmpb   $0x0,0x202c8d(%rip)        # 603a58 <completed.7294>
  400dcb:	75 13                	jne    400de0 <__do_global_dtors_aux+0x20>
  400dcd:	55                   	push   %rbp
  400dce:	48 89 e5             	mov    %rsp,%rbp
  400dd1:	e8 7a ff ff ff       	callq  400d50 <deregister_tm_clones>
  400dd6:	c6 05 7b 2c 20 00 01 	movb   $0x1,0x202c7b(%rip)        # 603a58 <completed.7294>
  400ddd:	5d                   	pop    %rbp
  400dde:	c3                   	retq   
  400ddf:	90                   	nop
  400de0:	c3                   	retq   
  400de1:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400de6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400ded:	00 00 00 

0000000000400df0 <frame_dummy>:
  400df0:	f3 0f 1e fa          	endbr64 
  400df4:	eb 8a                	jmp    400d80 <register_tm_clones>

0000000000400df6 <main>:
  400df6:	53                   	push   %rbx
  400df7:	83 ff 01             	cmp    $0x1,%edi
  400dfa:	0f 84 fc 00 00 00    	je     400efc <main+0x106>
  400e00:	48 89 f3             	mov    %rsi,%rbx
  400e03:	83 ff 02             	cmp    $0x2,%edi
  400e06:	0f 85 1e 01 00 00    	jne    400f2a <main+0x134>
  400e0c:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
  400e10:	be 86 1d 40 00       	mov    $0x401d86,%esi
  400e15:	e8 76 fe ff ff       	callq  400c90 <fopen@plt>
  400e1a:	48 89 05 3f 2c 20 00 	mov    %rax,0x202c3f(%rip)        # 603a60 <infile>
  400e21:	48 85 c0             	test   %rax,%rax
  400e24:	0f 84 e5 00 00 00    	je     400f0f <main+0x119>
  400e2a:	e8 ef 05 00 00       	callq  40141e <initialize_bomb>
  400e2f:	bf b8 19 40 00       	mov    $0x4019b8,%edi
  400e34:	e8 37 fd ff ff       	callq  400b70 <puts@plt>
  400e39:	bf f8 19 40 00       	mov    $0x4019f8,%edi
  400e3e:	e8 2d fd ff ff       	callq  400b70 <puts@plt>
  400e43:	e8 02 09 00 00       	callq  40174a <read_line>
  400e48:	48 89 c7             	mov    %rax,%rdi
  400e4b:	e8 f6 00 00 00       	callq  400f46 <phase_1>
  400e50:	e8 e2 09 00 00       	callq  401837 <phase_defused>
  400e55:	bf 28 1a 40 00       	mov    $0x401a28,%edi
  400e5a:	e8 11 fd ff ff       	callq  400b70 <puts@plt>
  400e5f:	e8 e6 08 00 00       	callq  40174a <read_line>
  400e64:	48 89 c7             	mov    %rax,%rdi
  400e67:	e8 f8 00 00 00       	callq  400f64 <phase_2>
  400e6c:	e8 c6 09 00 00       	callq  401837 <phase_defused>
  400e71:	bf 87 19 40 00       	mov    $0x401987,%edi
  400e76:	e8 f5 fc ff ff       	callq  400b70 <puts@plt>
  400e7b:	e8 ca 08 00 00       	callq  40174a <read_line>
  400e80:	48 89 c7             	mov    %rax,%rdi
  400e83:	e8 31 01 00 00       	callq  400fb9 <phase_3>
  400e88:	e8 aa 09 00 00       	callq  401837 <phase_defused>
  400e8d:	bf a5 19 40 00       	mov    $0x4019a5,%edi
  400e92:	e8 d9 fc ff ff       	callq  400b70 <puts@plt>
  400e97:	e8 ae 08 00 00       	callq  40174a <read_line>
  400e9c:	48 89 c7             	mov    %rax,%rdi
  400e9f:	e8 fe 01 00 00       	callq  4010a2 <phase_4>
  400ea4:	e8 8e 09 00 00       	callq  401837 <phase_defused>
  400ea9:	bf 58 1a 40 00       	mov    $0x401a58,%edi
  400eae:	e8 bd fc ff ff       	callq  400b70 <puts@plt>
  400eb3:	e8 92 08 00 00       	callq  40174a <read_line>
  400eb8:	48 89 c7             	mov    %rax,%rdi
  400ebb:	e8 27 02 00 00       	callq  4010e7 <phase_5>
  400ec0:	e8 72 09 00 00       	callq  401837 <phase_defused>
  400ec5:	bf 80 1a 40 00       	mov    $0x401a80,%edi
  400eca:	e8 a1 fc ff ff       	callq  400b70 <puts@plt>
  400ecf:	bf b8 1a 40 00       	mov    $0x401ab8,%edi
  400ed4:	e8 97 fc ff ff       	callq  400b70 <puts@plt>
  400ed9:	bf f8 1a 40 00       	mov    $0x401af8,%edi
  400ede:	e8 8d fc ff ff       	callq  400b70 <puts@plt>
  400ee3:	e8 62 08 00 00       	callq  40174a <read_line>
  400ee8:	48 89 c7             	mov    %rax,%rdi
  400eeb:	e8 97 02 00 00       	callq  401187 <phase_6>
  400ef0:	e8 42 09 00 00       	callq  401837 <phase_defused>
  400ef5:	b8 00 00 00 00       	mov    $0x0,%eax
  400efa:	5b                   	pop    %rbx
  400efb:	c3                   	retq   
  400efc:	48 8b 05 4d 2b 20 00 	mov    0x202b4d(%rip),%rax        # 603a50 <stdin@@GLIBC_2.2.5>
  400f03:	48 89 05 56 2b 20 00 	mov    %rax,0x202b56(%rip)        # 603a60 <infile>
  400f0a:	e9 1b ff ff ff       	jmpq   400e2a <main+0x34>
  400f0f:	48 8b 53 08          	mov    0x8(%rbx),%rdx
  400f13:	48 8b 33             	mov    (%rbx),%rsi
  400f16:	bf 50 19 40 00       	mov    $0x401950,%edi
  400f1b:	e8 80 fc ff ff       	callq  400ba0 <printf@plt>
  400f20:	bf 08 00 00 00       	mov    $0x8,%edi
  400f25:	e8 86 fd ff ff       	callq  400cb0 <exit@plt>
  400f2a:	48 8b 36             	mov    (%rsi),%rsi
  400f2d:	bf 6d 19 40 00       	mov    $0x40196d,%edi
  400f32:	b8 00 00 00 00       	mov    $0x0,%eax
  400f37:	e8 64 fc ff ff       	callq  400ba0 <printf@plt>
  400f3c:	bf 08 00 00 00       	mov    $0x8,%edi
  400f41:	e8 6a fd ff ff       	callq  400cb0 <exit@plt>

0000000000400f46 <phase_1>:
  400f46:	48 83 ec 08          	sub    $0x8,%rsp
  400f4a:	be 38 1b 40 00       	mov    $0x401b38,%esi
  400f4f:	e8 98 03 00 00       	callq  4012ec <strings_not_equal>
  400f54:	85 c0                	test   %eax,%eax
  400f56:	75 05                	jne    400f5d <phase_1+0x17>
  400f58:	48 83 c4 08          	add    $0x8,%rsp
  400f5c:	c3                   	retq   
  400f5d:	e8 87 07 00 00       	callq  4016e9 <explode_bomb>
  400f62:	eb f4                	jmp    400f58 <phase_1+0x12>

0000000000400f64 <phase_2>:
  400f64:	41 55                	push   %r13
  400f66:	41 54                	push   %r12
  400f68:	55                   	push   %rbp
  400f69:	53                   	push   %rbx
  400f6a:	48 83 ec 28          	sub    $0x28,%rsp
  400f6e:	48 89 e6             	mov    %rsp,%rsi
  400f71:	e8 95 07 00 00       	callq  40170b <read_six_numbers>
  400f76:	48 89 e3             	mov    %rsp,%rbx
  400f79:	4c 8d 64 24 0c       	lea    0xc(%rsp),%r12
  400f7e:	bd 00 00 00 00       	mov    $0x0,%ebp
  400f83:	eb 12                	jmp    400f97 <phase_2+0x33>
  400f85:	e8 5f 07 00 00       	callq  4016e9 <explode_bomb>
  400f8a:	41 03 6d 00          	add    0x0(%r13),%ebp
  400f8e:	48 83 c3 04          	add    $0x4,%rbx
  400f92:	4c 39 e3             	cmp    %r12,%rbx
  400f95:	74 0c                	je     400fa3 <phase_2+0x3f>
  400f97:	49 89 dd             	mov    %rbx,%r13
  400f9a:	8b 43 0c             	mov    0xc(%rbx),%eax
  400f9d:	39 03                	cmp    %eax,(%rbx)
  400f9f:	74 e9                	je     400f8a <phase_2+0x26>
  400fa1:	eb e2                	jmp    400f85 <phase_2+0x21>
  400fa3:	85 ed                	test   %ebp,%ebp
  400fa5:	74 0b                	je     400fb2 <phase_2+0x4e>
  400fa7:	48 83 c4 28          	add    $0x28,%rsp
  400fab:	5b                   	pop    %rbx
  400fac:	5d                   	pop    %rbp
  400fad:	41 5c                	pop    %r12
  400faf:	41 5d                	pop    %r13
  400fb1:	c3                   	retq   
  400fb2:	e8 32 07 00 00       	callq  4016e9 <explode_bomb>
  400fb7:	eb ee                	jmp    400fa7 <phase_2+0x43>

0000000000400fb9 <phase_3>:
  400fb9:	48 83 ec 18          	sub    $0x18,%rsp
  400fbd:	48 8d 4c 24 08       	lea    0x8(%rsp),%rcx
  400fc2:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  400fc7:	be ba 1e 40 00       	mov    $0x401eba,%esi
  400fcc:	b8 00 00 00 00       	mov    $0x0,%eax
  400fd1:	e8 8a fc ff ff       	callq  400c60 <__isoc99_sscanf@plt>
  400fd6:	83 f8 01             	cmp    $0x1,%eax
  400fd9:	7e 16                	jle    400ff1 <phase_3+0x38>
  400fdb:	83 7c 24 0c 07       	cmpl   $0x7,0xc(%rsp)
  400fe0:	0f 87 82 00 00 00    	ja     401068 <phase_3+0xaf>
  400fe6:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  400fea:	ff 24 c5 a0 1b 40 00 	jmpq   *0x401ba0(,%rax,8)
  400ff1:	e8 f3 06 00 00       	callq  4016e9 <explode_bomb>
  400ff6:	eb e3                	jmp    400fdb <phase_3+0x22>
  400ff8:	b8 22 02 00 00       	mov    $0x222,%eax
  400ffd:	eb 05                	jmp    401004 <phase_3+0x4b>
  400fff:	b8 00 00 00 00       	mov    $0x0,%eax
  401004:	2d d1 02 00 00       	sub    $0x2d1,%eax
  401009:	05 cd 02 00 00       	add    $0x2cd,%eax
  40100e:	2d db 02 00 00       	sub    $0x2db,%eax
  401013:	05 85 03 00 00       	add    $0x385,%eax
  401018:	2d dd 00 00 00       	sub    $0xdd,%eax
  40101d:	05 dd 00 00 00       	add    $0xdd,%eax
  401022:	2d a6 00 00 00       	sub    $0xa6,%eax
  401027:	83 7c 24 0c 05       	cmpl   $0x5,0xc(%rsp)
  40102c:	7f 06                	jg     401034 <phase_3+0x7b>
  40102e:	39 44 24 08          	cmp    %eax,0x8(%rsp)
  401032:	74 05                	je     401039 <phase_3+0x80>
  401034:	e8 b0 06 00 00       	callq  4016e9 <explode_bomb>
  401039:	48 83 c4 18          	add    $0x18,%rsp
  40103d:	c3                   	retq   
  40103e:	b8 00 00 00 00       	mov    $0x0,%eax
  401043:	eb c4                	jmp    401009 <phase_3+0x50>
  401045:	b8 00 00 00 00       	mov    $0x0,%eax
  40104a:	eb c2                	jmp    40100e <phase_3+0x55>
  40104c:	b8 00 00 00 00       	mov    $0x0,%eax
  401051:	eb c0                	jmp    401013 <phase_3+0x5a>
  401053:	b8 00 00 00 00       	mov    $0x0,%eax
  401058:	eb be                	jmp    401018 <phase_3+0x5f>
  40105a:	b8 00 00 00 00       	mov    $0x0,%eax
  40105f:	eb bc                	jmp    40101d <phase_3+0x64>
  401061:	b8 00 00 00 00       	mov    $0x0,%eax
  401066:	eb ba                	jmp    401022 <phase_3+0x69>
  401068:	e8 7c 06 00 00       	callq  4016e9 <explode_bomb>
  40106d:	b8 00 00 00 00       	mov    $0x0,%eax
  401072:	eb b3                	jmp    401027 <phase_3+0x6e>

0000000000401074 <func4>:
  401074:	b8 01 00 00 00       	mov    $0x1,%eax
  401079:	83 ff 01             	cmp    $0x1,%edi
  40107c:	7e 23                	jle    4010a1 <func4+0x2d>
  40107e:	55                   	push   %rbp
  40107f:	53                   	push   %rbx
  401080:	48 83 ec 08          	sub    $0x8,%rsp
  401084:	89 fb                	mov    %edi,%ebx
  401086:	8d 7f ff             	lea    -0x1(%rdi),%edi
  401089:	e8 e6 ff ff ff       	callq  401074 <func4>
  40108e:	89 c5                	mov    %eax,%ebp
  401090:	8d 7b fe             	lea    -0x2(%rbx),%edi
  401093:	e8 dc ff ff ff       	callq  401074 <func4>
  401098:	01 e8                	add    %ebp,%eax
  40109a:	48 83 c4 08          	add    $0x8,%rsp
  40109e:	5b                   	pop    %rbx
  40109f:	5d                   	pop    %rbp
  4010a0:	c3                   	retq   
  4010a1:	c3                   	retq   

00000000004010a2 <phase_4>:
  4010a2:	48 83 ec 18          	sub    $0x18,%rsp
  4010a6:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  4010ab:	be bd 1e 40 00       	mov    $0x401ebd,%esi
  4010b0:	b8 00 00 00 00       	mov    $0x0,%eax
  4010b5:	e8 a6 fb ff ff       	callq  400c60 <__isoc99_sscanf@plt>
  4010ba:	83 f8 01             	cmp    $0x1,%eax
  4010bd:	75 07                	jne    4010c6 <phase_4+0x24>
  4010bf:	83 7c 24 0c 00       	cmpl   $0x0,0xc(%rsp)
  4010c4:	7f 05                	jg     4010cb <phase_4+0x29>
  4010c6:	e8 1e 06 00 00       	callq  4016e9 <explode_bomb>
  4010cb:	8b 7c 24 0c          	mov    0xc(%rsp),%edi
  4010cf:	e8 a0 ff ff ff       	callq  401074 <func4>
  4010d4:	3d 18 0a 00 00       	cmp    $0xa18,%eax
  4010d9:	75 05                	jne    4010e0 <phase_4+0x3e>
  4010db:	48 83 c4 18          	add    $0x18,%rsp
  4010df:	c3                   	retq   
  4010e0:	e8 04 06 00 00       	callq  4016e9 <explode_bomb>
  4010e5:	eb f4                	jmp    4010db <phase_4+0x39>

00000000004010e7 <phase_5>:
  4010e7:	53                   	push   %rbx
  4010e8:	48 89 fb             	mov    %rdi,%rbx
  4010eb:	e8 df 01 00 00       	callq  4012cf <string_length>
  4010f0:	83 f8 06             	cmp    $0x6,%eax
  4010f3:	75 29                	jne    40111e <phase_5+0x37>
  4010f5:	48 89 d8             	mov    %rbx,%rax
  4010f8:	48 8d 7b 06          	lea    0x6(%rbx),%rdi
  4010fc:	b9 00 00 00 00       	mov    $0x0,%ecx
  401101:	0f b6 10             	movzbl (%rax),%edx
  401104:	83 e2 0f             	and    $0xf,%edx
  401107:	03 0c 95 e0 1b 40 00 	add    0x401be0(,%rdx,4),%ecx
  40110e:	48 83 c0 01          	add    $0x1,%rax
  401112:	48 39 f8             	cmp    %rdi,%rax
  401115:	75 ea                	jne    401101 <phase_5+0x1a>
  401117:	83 f9 3a             	cmp    $0x3a,%ecx
  40111a:	75 09                	jne    401125 <phase_5+0x3e>
  40111c:	5b                   	pop    %rbx
  40111d:	c3                   	retq   
  40111e:	e8 c6 05 00 00       	callq  4016e9 <explode_bomb>
  401123:	eb d0                	jmp    4010f5 <phase_5+0xe>
  401125:	e8 bf 05 00 00       	callq  4016e9 <explode_bomb>
  40112a:	eb f0                	jmp    40111c <phase_5+0x35>

000000000040112c <fun6>:
  40112c:	48 89 f8             	mov    %rdi,%rax
  40112f:	4c 8b 47 08          	mov    0x8(%rdi),%r8
  401133:	48 c7 47 08 00 00 00 	movq   $0x0,0x8(%rdi)
  40113a:	00 
  40113b:	4d 85 c0             	test   %r8,%r8
  40113e:	75 2a                	jne    40116a <fun6+0x3e>
  401140:	c3                   	retq   
  401141:	48 89 d1             	mov    %rdx,%rcx
  401144:	48 8b 51 08          	mov    0x8(%rcx),%rdx
  401148:	48 85 d2             	test   %rdx,%rdx
  40114b:	74 09                	je     401156 <fun6+0x2a>
  40114d:	39 32                	cmp    %esi,(%rdx)
  40114f:	7f f0                	jg     401141 <fun6+0x15>
  401151:	48 39 ca             	cmp    %rcx,%rdx
  401154:	74 2b                	je     401181 <fun6+0x55>
  401156:	4c 89 41 08          	mov    %r8,0x8(%rcx)
  40115a:	49 8b 48 08          	mov    0x8(%r8),%rcx
  40115e:	49 89 50 08          	mov    %rdx,0x8(%r8)
  401162:	49 89 c8             	mov    %rcx,%r8
  401165:	48 85 c9             	test   %rcx,%rcx
  401168:	74 1c                	je     401186 <fun6+0x5a>
  40116a:	48 85 c0             	test   %rax,%rax
  40116d:	74 0a                	je     401179 <fun6+0x4d>
  40116f:	41 8b 30             	mov    (%r8),%esi
  401172:	48 89 c1             	mov    %rax,%rcx
  401175:	39 30                	cmp    %esi,(%rax)
  401177:	7f cb                	jg     401144 <fun6+0x18>
  401179:	48 89 c2             	mov    %rax,%rdx
  40117c:	4c 89 c0             	mov    %r8,%rax
  40117f:	eb d9                	jmp    40115a <fun6+0x2e>
  401181:	4c 89 c0             	mov    %r8,%rax
  401184:	eb d4                	jmp    40115a <fun6+0x2e>
  401186:	c3                   	retq   

0000000000401187 <phase_6>:
  401187:	48 83 ec 08          	sub    $0x8,%rsp
  40118b:	ba 0a 00 00 00       	mov    $0xa,%edx
  401190:	be 00 00 00 00       	mov    $0x0,%esi
  401195:	e8 a6 fa ff ff       	callq  400c40 <strtol@plt>
  40119a:	89 05 60 21 20 00    	mov    %eax,0x202160(%rip)        # 603300 <node0>
  4011a0:	bf 00 33 60 00       	mov    $0x603300,%edi
  4011a5:	e8 82 ff ff ff       	callq  40112c <fun6>
  4011aa:	48 8b 40 08          	mov    0x8(%rax),%rax
  4011ae:	48 8b 40 08          	mov    0x8(%rax),%rax
  4011b2:	48 8b 40 08          	mov    0x8(%rax),%rax
  4011b6:	8b 0d 44 21 20 00    	mov    0x202144(%rip),%ecx        # 603300 <node0>
  4011bc:	39 08                	cmp    %ecx,(%rax)
  4011be:	75 05                	jne    4011c5 <phase_6+0x3e>
  4011c0:	48 83 c4 08          	add    $0x8,%rsp
  4011c4:	c3                   	retq   
  4011c5:	e8 1f 05 00 00       	callq  4016e9 <explode_bomb>
  4011ca:	eb f4                	jmp    4011c0 <phase_6+0x39>

00000000004011cc <fun7>:
  4011cc:	48 85 ff             	test   %rdi,%rdi
  4011cf:	74 32                	je     401203 <fun7+0x37>
  4011d1:	48 83 ec 08          	sub    $0x8,%rsp
  4011d5:	8b 17                	mov    (%rdi),%edx
  4011d7:	39 f2                	cmp    %esi,%edx
  4011d9:	7f 0c                	jg     4011e7 <fun7+0x1b>
  4011db:	b8 00 00 00 00       	mov    $0x0,%eax
  4011e0:	75 12                	jne    4011f4 <fun7+0x28>
  4011e2:	48 83 c4 08          	add    $0x8,%rsp
  4011e6:	c3                   	retq   
  4011e7:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
  4011eb:	e8 dc ff ff ff       	callq  4011cc <fun7>
  4011f0:	01 c0                	add    %eax,%eax
  4011f2:	eb ee                	jmp    4011e2 <fun7+0x16>
  4011f4:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
  4011f8:	e8 cf ff ff ff       	callq  4011cc <fun7>
  4011fd:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
  401201:	eb df                	jmp    4011e2 <fun7+0x16>
  401203:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401208:	c3                   	retq   

0000000000401209 <secret_phase>:
  401209:	53                   	push   %rbx
  40120a:	e8 3b 05 00 00       	callq  40174a <read_line>
  40120f:	ba 0a 00 00 00       	mov    $0xa,%edx
  401214:	be 00 00 00 00       	mov    $0x0,%esi
  401219:	48 89 c7             	mov    %rax,%rdi
  40121c:	e8 1f fa ff ff       	callq  400c40 <strtol@plt>
  401221:	48 89 c3             	mov    %rax,%rbx
  401224:	8d 40 ff             	lea    -0x1(%rax),%eax
  401227:	3d e8 03 00 00       	cmp    $0x3e8,%eax
  40122c:	77 22                	ja     401250 <secret_phase+0x47>
  40122e:	89 de                	mov    %ebx,%esi
  401230:	bf 20 31 60 00       	mov    $0x603120,%edi
  401235:	e8 92 ff ff ff       	callq  4011cc <fun7>
  40123a:	83 f8 01             	cmp    $0x1,%eax
  40123d:	75 18                	jne    401257 <secret_phase+0x4e>
  40123f:	bf 68 1b 40 00       	mov    $0x401b68,%edi
  401244:	e8 27 f9 ff ff       	callq  400b70 <puts@plt>
  401249:	e8 e9 05 00 00       	callq  401837 <phase_defused>
  40124e:	5b                   	pop    %rbx
  40124f:	c3                   	retq   
  401250:	e8 94 04 00 00       	callq  4016e9 <explode_bomb>
  401255:	eb d7                	jmp    40122e <secret_phase+0x25>
  401257:	e8 8d 04 00 00       	callq  4016e9 <explode_bomb>
  40125c:	eb e1                	jmp    40123f <secret_phase+0x36>

000000000040125e <sig_handler>:
  40125e:	48 83 ec 08          	sub    $0x8,%rsp
  401262:	bf 20 1c 40 00       	mov    $0x401c20,%edi
  401267:	e8 04 f9 ff ff       	callq  400b70 <puts@plt>
  40126c:	bf 03 00 00 00       	mov    $0x3,%edi
  401271:	e8 6a fa ff ff       	callq  400ce0 <sleep@plt>
  401276:	bf 18 1d 40 00       	mov    $0x401d18,%edi
  40127b:	b8 00 00 00 00       	mov    $0x0,%eax
  401280:	e8 1b f9 ff ff       	callq  400ba0 <printf@plt>
  401285:	48 8b 3d b4 27 20 00 	mov    0x2027b4(%rip),%rdi        # 603a40 <stdout@@GLIBC_2.2.5>
  40128c:	e8 bf f9 ff ff       	callq  400c50 <fflush@plt>
  401291:	bf 01 00 00 00       	mov    $0x1,%edi
  401296:	e8 45 fa ff ff       	callq  400ce0 <sleep@plt>
  40129b:	bf 20 1d 40 00       	mov    $0x401d20,%edi
  4012a0:	e8 cb f8 ff ff       	callq  400b70 <puts@plt>
  4012a5:	bf 10 00 00 00       	mov    $0x10,%edi
  4012aa:	e8 01 fa ff ff       	callq  400cb0 <exit@plt>

00000000004012af <invalid_phase>:
  4012af:	48 83 ec 08          	sub    $0x8,%rsp
  4012b3:	48 89 fe             	mov    %rdi,%rsi
  4012b6:	bf 28 1d 40 00       	mov    $0x401d28,%edi
  4012bb:	b8 00 00 00 00       	mov    $0x0,%eax
  4012c0:	e8 db f8 ff ff       	callq  400ba0 <printf@plt>
  4012c5:	bf 08 00 00 00       	mov    $0x8,%edi
  4012ca:	e8 e1 f9 ff ff       	callq  400cb0 <exit@plt>

00000000004012cf <string_length>:
  4012cf:	80 3f 00             	cmpb   $0x0,(%rdi)
  4012d2:	74 12                	je     4012e6 <string_length+0x17>
  4012d4:	b8 00 00 00 00       	mov    $0x0,%eax
  4012d9:	48 83 c7 01          	add    $0x1,%rdi
  4012dd:	83 c0 01             	add    $0x1,%eax
  4012e0:	80 3f 00             	cmpb   $0x0,(%rdi)
  4012e3:	75 f4                	jne    4012d9 <string_length+0xa>
  4012e5:	c3                   	retq   
  4012e6:	b8 00 00 00 00       	mov    $0x0,%eax
  4012eb:	c3                   	retq   

00000000004012ec <strings_not_equal>:
  4012ec:	41 54                	push   %r12
  4012ee:	55                   	push   %rbp
  4012ef:	53                   	push   %rbx
  4012f0:	48 89 fb             	mov    %rdi,%rbx
  4012f3:	48 89 f5             	mov    %rsi,%rbp
  4012f6:	e8 d4 ff ff ff       	callq  4012cf <string_length>
  4012fb:	41 89 c4             	mov    %eax,%r12d
  4012fe:	48 89 ef             	mov    %rbp,%rdi
  401301:	e8 c9 ff ff ff       	callq  4012cf <string_length>
  401306:	ba 01 00 00 00       	mov    $0x1,%edx
  40130b:	41 39 c4             	cmp    %eax,%r12d
  40130e:	75 2f                	jne    40133f <strings_not_equal+0x53>
  401310:	0f b6 03             	movzbl (%rbx),%eax
  401313:	84 c0                	test   %al,%al
  401315:	74 2f                	je     401346 <strings_not_equal+0x5a>
  401317:	3a 45 00             	cmp    0x0(%rbp),%al
  40131a:	75 31                	jne    40134d <strings_not_equal+0x61>
  40131c:	b8 01 00 00 00       	mov    $0x1,%eax
  401321:	0f b6 14 03          	movzbl (%rbx,%rax,1),%edx
  401325:	84 d2                	test   %dl,%dl
  401327:	74 11                	je     40133a <strings_not_equal+0x4e>
  401329:	48 83 c0 01          	add    $0x1,%rax
  40132d:	38 54 05 ff          	cmp    %dl,-0x1(%rbp,%rax,1)
  401331:	74 ee                	je     401321 <strings_not_equal+0x35>
  401333:	ba 01 00 00 00       	mov    $0x1,%edx
  401338:	eb 05                	jmp    40133f <strings_not_equal+0x53>
  40133a:	ba 00 00 00 00       	mov    $0x0,%edx
  40133f:	89 d0                	mov    %edx,%eax
  401341:	5b                   	pop    %rbx
  401342:	5d                   	pop    %rbp
  401343:	41 5c                	pop    %r12
  401345:	c3                   	retq   
  401346:	ba 00 00 00 00       	mov    $0x0,%edx
  40134b:	eb f2                	jmp    40133f <strings_not_equal+0x53>
  40134d:	ba 01 00 00 00       	mov    $0x1,%edx
  401352:	eb eb                	jmp    40133f <strings_not_equal+0x53>

0000000000401354 <open_clientfd>:
  401354:	41 54                	push   %r12
  401356:	55                   	push   %rbp
  401357:	53                   	push   %rbx
  401358:	48 83 ec 10          	sub    $0x10,%rsp
  40135c:	49 89 fc             	mov    %rdi,%r12
  40135f:	89 f5                	mov    %esi,%ebp
  401361:	ba 00 00 00 00       	mov    $0x0,%edx
  401366:	be 01 00 00 00       	mov    $0x1,%esi
  40136b:	bf 02 00 00 00       	mov    $0x2,%edi
  401370:	e8 8b f9 ff ff       	callq  400d00 <socket@plt>
  401375:	85 c0                	test   %eax,%eax
  401377:	78 69                	js     4013e2 <open_clientfd+0x8e>
  401379:	89 c3                	mov    %eax,%ebx
  40137b:	4c 89 e7             	mov    %r12,%rdi
  40137e:	e8 9d f8 ff ff       	callq  400c20 <gethostbyname@plt>
  401383:	48 85 c0             	test   %rax,%rax
  401386:	74 6e                	je     4013f6 <open_clientfd+0xa2>
  401388:	48 c7 44 24 02 00 00 	movq   $0x0,0x2(%rsp)
  40138f:	00 00 
  401391:	c7 44 24 0a 00 00 00 	movl   $0x0,0xa(%rsp)
  401398:	00 
  401399:	66 c7 44 24 0e 00 00 	movw   $0x0,0xe(%rsp)
  4013a0:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
  4013a6:	48 63 50 14          	movslq 0x14(%rax),%rdx
  4013aa:	48 8b 40 18          	mov    0x18(%rax),%rax
  4013ae:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
  4013b3:	48 8b 30             	mov    (%rax),%rsi
  4013b6:	e8 b5 f8 ff ff       	callq  400c70 <memmove@plt>
  4013bb:	66 c1 c5 08          	rol    $0x8,%bp
  4013bf:	66 89 6c 24 02       	mov    %bp,0x2(%rsp)
  4013c4:	ba 10 00 00 00       	mov    $0x10,%edx
  4013c9:	48 89 e6             	mov    %rsp,%rsi
  4013cc:	89 df                	mov    %ebx,%edi
  4013ce:	e8 ed f8 ff ff       	callq  400cc0 <connect@plt>
  4013d3:	85 c0                	test   %eax,%eax
  4013d5:	78 33                	js     40140a <open_clientfd+0xb6>
  4013d7:	89 d8                	mov    %ebx,%eax
  4013d9:	48 83 c4 10          	add    $0x10,%rsp
  4013dd:	5b                   	pop    %rbx
  4013de:	5d                   	pop    %rbp
  4013df:	41 5c                	pop    %r12
  4013e1:	c3                   	retq   
  4013e2:	bf 39 1d 40 00       	mov    $0x401d39,%edi
  4013e7:	e8 84 f7 ff ff       	callq  400b70 <puts@plt>
  4013ec:	bf 08 00 00 00       	mov    $0x8,%edi
  4013f1:	e8 ba f8 ff ff       	callq  400cb0 <exit@plt>
  4013f6:	bf 47 1d 40 00       	mov    $0x401d47,%edi
  4013fb:	e8 70 f7 ff ff       	callq  400b70 <puts@plt>
  401400:	bf 08 00 00 00       	mov    $0x8,%edi
  401405:	e8 a6 f8 ff ff       	callq  400cb0 <exit@plt>
  40140a:	bf 55 1d 40 00       	mov    $0x401d55,%edi
  40140f:	e8 5c f7 ff ff       	callq  400b70 <puts@plt>
  401414:	bf 08 00 00 00       	mov    $0x8,%edi
  401419:	e8 92 f8 ff ff       	callq  400cb0 <exit@plt>

000000000040141e <initialize_bomb>:
  40141e:	48 83 ec 08          	sub    $0x8,%rsp
  401422:	be 5e 12 40 00       	mov    $0x40125e,%esi
  401427:	bf 02 00 00 00       	mov    $0x2,%edi
  40142c:	e8 df f7 ff ff       	callq  400c10 <signal@plt>
  401431:	48 83 c4 08          	add    $0x8,%rsp
  401435:	c3                   	retq   

0000000000401436 <blank_line>:
  401436:	55                   	push   %rbp
  401437:	53                   	push   %rbx
  401438:	48 83 ec 08          	sub    $0x8,%rsp
  40143c:	48 89 fd             	mov    %rdi,%rbp
  40143f:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
  401443:	84 db                	test   %bl,%bl
  401445:	74 1e                	je     401465 <blank_line+0x2f>
  401447:	e8 a4 f8 ff ff       	callq  400cf0 <__ctype_b_loc@plt>
  40144c:	48 83 c5 01          	add    $0x1,%rbp
  401450:	48 0f be db          	movsbq %bl,%rbx
  401454:	48 8b 00             	mov    (%rax),%rax
  401457:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
  40145c:	75 e1                	jne    40143f <blank_line+0x9>
  40145e:	b8 00 00 00 00       	mov    $0x0,%eax
  401463:	eb 05                	jmp    40146a <blank_line+0x34>
  401465:	b8 01 00 00 00       	mov    $0x1,%eax
  40146a:	48 83 c4 08          	add    $0x8,%rsp
  40146e:	5b                   	pop    %rbx
  40146f:	5d                   	pop    %rbp
  401470:	c3                   	retq   

0000000000401471 <skip>:
  401471:	53                   	push   %rbx
  401472:	48 63 05 e3 25 20 00 	movslq 0x2025e3(%rip),%rax        # 603a5c <num_input_strings>
  401479:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
  40147d:	48 c1 e7 04          	shl    $0x4,%rdi
  401481:	48 81 c7 80 3a 60 00 	add    $0x603a80,%rdi
  401488:	48 8b 15 d1 25 20 00 	mov    0x2025d1(%rip),%rdx        # 603a60 <infile>
  40148f:	be 50 00 00 00       	mov    $0x50,%esi
  401494:	e8 57 f7 ff ff       	callq  400bf0 <fgets@plt>
  401499:	48 89 c3             	mov    %rax,%rbx
  40149c:	48 85 c0             	test   %rax,%rax
  40149f:	74 0c                	je     4014ad <skip+0x3c>
  4014a1:	48 89 c7             	mov    %rax,%rdi
  4014a4:	e8 8d ff ff ff       	callq  401436 <blank_line>
  4014a9:	85 c0                	test   %eax,%eax
  4014ab:	75 c5                	jne    401472 <skip+0x1>
  4014ad:	48 89 d8             	mov    %rbx,%rax
  4014b0:	5b                   	pop    %rbx
  4014b1:	c3                   	retq   

00000000004014b2 <send_msg>:
  4014b2:	41 55                	push   %r13
  4014b4:	41 54                	push   %r12
  4014b6:	55                   	push   %rbp
  4014b7:	53                   	push   %rbx
  4014b8:	48 83 ec 58          	sub    $0x58,%rsp
  4014bc:	89 fb                	mov    %edi,%ebx
  4014be:	bf 00 00 00 00       	mov    $0x0,%edi
  4014c3:	e8 f8 f6 ff ff       	callq  400bc0 <dup@plt>
  4014c8:	83 f8 ff             	cmp    $0xffffffff,%eax
  4014cb:	0f 84 74 01 00 00    	je     401645 <send_msg+0x193>
  4014d1:	41 89 c5             	mov    %eax,%r13d
  4014d4:	bf 00 00 00 00       	mov    $0x0,%edi
  4014d9:	e8 f2 f6 ff ff       	callq  400bd0 <close@plt>
  4014de:	83 f8 ff             	cmp    $0xffffffff,%eax
  4014e1:	0f 84 72 01 00 00    	je     401659 <send_msg+0x1a7>
  4014e7:	e8 14 f7 ff ff       	callq  400c00 <tmpfile@plt>
  4014ec:	49 89 c4             	mov    %rax,%r12
  4014ef:	48 85 c0             	test   %rax,%rax
  4014f2:	0f 84 75 01 00 00    	je     40166d <send_msg+0x1bb>
  4014f8:	48 89 c1             	mov    %rax,%rcx
  4014fb:	ba 1b 00 00 00       	mov    $0x1b,%edx
  401500:	be 01 00 00 00       	mov    $0x1,%esi
  401505:	bf b0 1d 40 00       	mov    $0x401db0,%edi
  40150a:	e8 c1 f7 ff ff       	callq  400cd0 <fwrite@plt>
  40150f:	4c 89 e6             	mov    %r12,%rsi
  401512:	bf 0a 00 00 00       	mov    $0xa,%edi
  401517:	e8 c4 f6 ff ff       	callq  400be0 <fputc@plt>
  40151c:	bf 00 00 00 00       	mov    $0x0,%edi
  401521:	e8 5a f7 ff ff       	callq  400c80 <cuserid@plt>
  401526:	48 85 c0             	test   %rax,%rax
  401529:	0f 84 52 01 00 00    	je     401681 <send_msg+0x1cf>
  40152f:	48 89 c6             	mov    %rax,%rsi
  401532:	48 89 e7             	mov    %rsp,%rdi
  401535:	e8 26 f6 ff ff       	callq  400b60 <strcpy@plt>
  40153a:	85 db                	test   %ebx,%ebx
  40153c:	41 b9 63 1d 40 00    	mov    $0x401d63,%r9d
  401542:	b8 6b 1d 40 00       	mov    $0x401d6b,%eax
  401547:	4c 0f 44 c8          	cmove  %rax,%r9
  40154b:	48 83 ec 08          	sub    $0x8,%rsp
  40154f:	8b 05 07 25 20 00    	mov    0x202507(%rip),%eax        # 603a5c <num_input_strings>
  401555:	50                   	push   %rax
  401556:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
  40155b:	8b 0d 3f 22 20 00    	mov    0x20223f(%rip),%ecx        # 6037a0 <bomb_id>
  401561:	ba a0 33 60 00       	mov    $0x6033a0,%edx
  401566:	be cc 1d 40 00       	mov    $0x401dcc,%esi
  40156b:	4c 89 e7             	mov    %r12,%rdi
  40156e:	b8 00 00 00 00       	mov    $0x0,%eax
  401573:	e8 b8 f6 ff ff       	callq  400c30 <fprintf@plt>
  401578:	48 83 c4 10          	add    $0x10,%rsp
  40157c:	83 3d d9 24 20 00 00 	cmpl   $0x0,0x2024d9(%rip)        # 603a5c <num_input_strings>
  401583:	7e 47                	jle    4015cc <send_msg+0x11a>
  401585:	bd 80 3a 60 00       	mov    $0x603a80,%ebp
  40158a:	bb 00 00 00 00       	mov    $0x0,%ebx
  40158f:	83 c3 01             	add    $0x1,%ebx
  401592:	48 83 ec 08          	sub    $0x8,%rsp
  401596:	55                   	push   %rbp
  401597:	41 89 d9             	mov    %ebx,%r9d
  40159a:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
  40159f:	8b 0d fb 21 20 00    	mov    0x2021fb(%rip),%ecx        # 6037a0 <bomb_id>
  4015a5:	ba a0 33 60 00       	mov    $0x6033a0,%edx
  4015aa:	be e8 1d 40 00       	mov    $0x401de8,%esi
  4015af:	4c 89 e7             	mov    %r12,%rdi
  4015b2:	b8 00 00 00 00       	mov    $0x0,%eax
  4015b7:	e8 74 f6 ff ff       	callq  400c30 <fprintf@plt>
  4015bc:	48 83 c5 50          	add    $0x50,%rbp
  4015c0:	48 83 c4 10          	add    $0x10,%rsp
  4015c4:	3b 1d 92 24 20 00    	cmp    0x202492(%rip),%ebx        # 603a5c <num_input_strings>
  4015ca:	7c c3                	jl     40158f <send_msg+0xdd>
  4015cc:	4c 89 e7             	mov    %r12,%rdi
  4015cf:	e8 dc f5 ff ff       	callq  400bb0 <rewind@plt>
  4015d4:	41 b8 58 1c 40 00    	mov    $0x401c58,%r8d
  4015da:	b9 04 1e 40 00       	mov    $0x401e04,%ecx
  4015df:	ba 09 1e 40 00       	mov    $0x401e09,%edx
  4015e4:	be 20 1e 40 00       	mov    $0x401e20,%esi
  4015e9:	bf c0 40 60 00       	mov    $0x6040c0,%edi
  4015ee:	b8 00 00 00 00       	mov    $0x0,%eax
  4015f3:	e8 a8 f6 ff ff       	callq  400ca0 <sprintf@plt>
  4015f8:	bf c0 40 60 00       	mov    $0x6040c0,%edi
  4015fd:	e8 8e f5 ff ff       	callq  400b90 <system@plt>
  401602:	85 c0                	test   %eax,%eax
  401604:	0f 85 8f 00 00 00    	jne    401699 <send_msg+0x1e7>
  40160a:	4c 89 e7             	mov    %r12,%rdi
  40160d:	e8 6e f5 ff ff       	callq  400b80 <fclose@plt>
  401612:	85 c0                	test   %eax,%eax
  401614:	0f 85 93 00 00 00    	jne    4016ad <send_msg+0x1fb>
  40161a:	44 89 ef             	mov    %r13d,%edi
  40161d:	e8 9e f5 ff ff       	callq  400bc0 <dup@plt>
  401622:	85 c0                	test   %eax,%eax
  401624:	0f 85 97 00 00 00    	jne    4016c1 <send_msg+0x20f>
  40162a:	44 89 ef             	mov    %r13d,%edi
  40162d:	e8 9e f5 ff ff       	callq  400bd0 <close@plt>
  401632:	85 c0                	test   %eax,%eax
  401634:	0f 85 9b 00 00 00    	jne    4016d5 <send_msg+0x223>
  40163a:	48 83 c4 58          	add    $0x58,%rsp
  40163e:	5b                   	pop    %rbx
  40163f:	5d                   	pop    %rbp
  401640:	41 5c                	pop    %r12
  401642:	41 5d                	pop    %r13
  401644:	c3                   	retq   
  401645:	bf 74 1d 40 00       	mov    $0x401d74,%edi
  40164a:	e8 21 f5 ff ff       	callq  400b70 <puts@plt>
  40164f:	bf 08 00 00 00       	mov    $0x8,%edi
  401654:	e8 57 f6 ff ff       	callq  400cb0 <exit@plt>
  401659:	bf 88 1d 40 00       	mov    $0x401d88,%edi
  40165e:	e8 0d f5 ff ff       	callq  400b70 <puts@plt>
  401663:	bf 08 00 00 00       	mov    $0x8,%edi
  401668:	e8 43 f6 ff ff       	callq  400cb0 <exit@plt>
  40166d:	bf 9b 1d 40 00       	mov    $0x401d9b,%edi
  401672:	e8 f9 f4 ff ff       	callq  400b70 <puts@plt>
  401677:	bf 08 00 00 00       	mov    $0x8,%edi
  40167c:	e8 2f f6 ff ff       	callq  400cb0 <exit@plt>
  401681:	c7 04 24 6e 6f 62 6f 	movl   $0x6f626f6e,(%rsp)
  401688:	66 c7 44 24 04 64 79 	movw   $0x7964,0x4(%rsp)
  40168f:	c6 44 24 06 00       	movb   $0x0,0x6(%rsp)
  401694:	e9 a1 fe ff ff       	jmpq   40153a <send_msg+0x88>
  401699:	bf 29 1e 40 00       	mov    $0x401e29,%edi
  40169e:	e8 cd f4 ff ff       	callq  400b70 <puts@plt>
  4016a3:	bf 08 00 00 00       	mov    $0x8,%edi
  4016a8:	e8 03 f6 ff ff       	callq  400cb0 <exit@plt>
  4016ad:	bf 43 1e 40 00       	mov    $0x401e43,%edi
  4016b2:	e8 b9 f4 ff ff       	callq  400b70 <puts@plt>
  4016b7:	bf 08 00 00 00       	mov    $0x8,%edi
  4016bc:	e8 ef f5 ff ff       	callq  400cb0 <exit@plt>
  4016c1:	bf 5c 1e 40 00       	mov    $0x401e5c,%edi
  4016c6:	e8 a5 f4 ff ff       	callq  400b70 <puts@plt>
  4016cb:	bf 08 00 00 00       	mov    $0x8,%edi
  4016d0:	e8 db f5 ff ff       	callq  400cb0 <exit@plt>
  4016d5:	bf 77 1e 40 00       	mov    $0x401e77,%edi
  4016da:	e8 91 f4 ff ff       	callq  400b70 <puts@plt>
  4016df:	bf 08 00 00 00       	mov    $0x8,%edi
  4016e4:	e8 c7 f5 ff ff       	callq  400cb0 <exit@plt>

00000000004016e9 <explode_bomb>:
  4016e9:	48 83 ec 08          	sub    $0x8,%rsp
  4016ed:	bf 8e 1e 40 00       	mov    $0x401e8e,%edi
  4016f2:	e8 79 f4 ff ff       	callq  400b70 <puts@plt>
  4016f7:	bf 97 1e 40 00       	mov    $0x401e97,%edi
  4016fc:	e8 6f f4 ff ff       	callq  400b70 <puts@plt>
  401701:	bf 08 00 00 00       	mov    $0x8,%edi
  401706:	e8 a5 f5 ff ff       	callq  400cb0 <exit@plt>

000000000040170b <read_six_numbers>:
  40170b:	48 83 ec 08          	sub    $0x8,%rsp
  40170f:	48 89 f2             	mov    %rsi,%rdx
  401712:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
  401716:	48 8d 46 14          	lea    0x14(%rsi),%rax
  40171a:	50                   	push   %rax
  40171b:	48 8d 46 10          	lea    0x10(%rsi),%rax
  40171f:	50                   	push   %rax
  401720:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
  401724:	4c 8d 46 08          	lea    0x8(%rsi),%r8
  401728:	be ae 1e 40 00       	mov    $0x401eae,%esi
  40172d:	b8 00 00 00 00       	mov    $0x0,%eax
  401732:	e8 29 f5 ff ff       	callq  400c60 <__isoc99_sscanf@plt>
  401737:	48 83 c4 10          	add    $0x10,%rsp
  40173b:	83 f8 05             	cmp    $0x5,%eax
  40173e:	7e 05                	jle    401745 <read_six_numbers+0x3a>
  401740:	48 83 c4 08          	add    $0x8,%rsp
  401744:	c3                   	retq   
  401745:	e8 9f ff ff ff       	callq  4016e9 <explode_bomb>

000000000040174a <read_line>:
  40174a:	48 83 ec 08          	sub    $0x8,%rsp
  40174e:	b8 00 00 00 00       	mov    $0x0,%eax
  401753:	e8 19 fd ff ff       	callq  401471 <skip>
  401758:	48 85 c0             	test   %rax,%rax
  40175b:	74 63                	je     4017c0 <read_line+0x76>
  40175d:	8b 35 f9 22 20 00    	mov    0x2022f9(%rip),%esi        # 603a5c <num_input_strings>
  401763:	48 63 c6             	movslq %esi,%rax
  401766:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  40176a:	48 c1 e2 04          	shl    $0x4,%rdx
  40176e:	48 81 c2 80 3a 60 00 	add    $0x603a80,%rdx
  401775:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  40177c:	b8 00 00 00 00       	mov    $0x0,%eax
  401781:	48 89 d7             	mov    %rdx,%rdi
  401784:	f2 ae                	repnz scas %es:(%rdi),%al
  401786:	48 f7 d1             	not    %rcx
  401789:	48 83 e9 01          	sub    $0x1,%rcx
  40178d:	83 f9 4f             	cmp    $0x4f,%ecx
  401790:	0f 84 92 00 00 00    	je     401828 <read_line+0xde>
  401796:	83 e9 01             	sub    $0x1,%ecx
  401799:	48 63 c9             	movslq %ecx,%rcx
  40179c:	48 63 c6             	movslq %esi,%rax
  40179f:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
  4017a3:	48 c1 e0 04          	shl    $0x4,%rax
  4017a7:	c6 84 01 80 3a 60 00 	movb   $0x0,0x603a80(%rcx,%rax,1)
  4017ae:	00 
  4017af:	8d 46 01             	lea    0x1(%rsi),%eax
  4017b2:	89 05 a4 22 20 00    	mov    %eax,0x2022a4(%rip)        # 603a5c <num_input_strings>
  4017b8:	48 89 d0             	mov    %rdx,%rax
  4017bb:	48 83 c4 08          	add    $0x8,%rsp
  4017bf:	c3                   	retq   
  4017c0:	48 8b 05 89 22 20 00 	mov    0x202289(%rip),%rax        # 603a50 <stdin@@GLIBC_2.2.5>
  4017c7:	48 39 05 92 22 20 00 	cmp    %rax,0x202292(%rip)        # 603a60 <infile>
  4017ce:	74 19                	je     4017e9 <read_line+0x9f>
  4017d0:	bf de 1e 40 00       	mov    $0x401ede,%edi
  4017d5:	e8 76 f3 ff ff       	callq  400b50 <getenv@plt>
  4017da:	48 85 c0             	test   %rax,%rax
  4017dd:	74 19                	je     4017f8 <read_line+0xae>
  4017df:	bf 00 00 00 00       	mov    $0x0,%edi
  4017e4:	e8 c7 f4 ff ff       	callq  400cb0 <exit@plt>
  4017e9:	bf c0 1e 40 00       	mov    $0x401ec0,%edi
  4017ee:	e8 7d f3 ff ff       	callq  400b70 <puts@plt>
  4017f3:	e8 f1 fe ff ff       	callq  4016e9 <explode_bomb>
  4017f8:	48 8b 05 51 22 20 00 	mov    0x202251(%rip),%rax        # 603a50 <stdin@@GLIBC_2.2.5>
  4017ff:	48 89 05 5a 22 20 00 	mov    %rax,0x20225a(%rip)        # 603a60 <infile>
  401806:	b8 00 00 00 00       	mov    $0x0,%eax
  40180b:	e8 61 fc ff ff       	callq  401471 <skip>
  401810:	48 85 c0             	test   %rax,%rax
  401813:	0f 85 44 ff ff ff    	jne    40175d <read_line+0x13>
  401819:	bf c0 1e 40 00       	mov    $0x401ec0,%edi
  40181e:	e8 4d f3 ff ff       	callq  400b70 <puts@plt>
  401823:	e8 c1 fe ff ff       	callq  4016e9 <explode_bomb>
  401828:	bf e9 1e 40 00       	mov    $0x401ee9,%edi
  40182d:	e8 3e f3 ff ff       	callq  400b70 <puts@plt>
  401832:	e8 b2 fe ff ff       	callq  4016e9 <explode_bomb>

0000000000401837 <phase_defused>:
  401837:	83 3d 1e 22 20 00 06 	cmpl   $0x6,0x20221e(%rip)        # 603a5c <num_input_strings>
  40183e:	74 01                	je     401841 <phase_defused+0xa>
  401840:	c3                   	retq   
  401841:	48 83 ec 68          	sub    $0x68,%rsp
  401845:	48 8d 4c 24 10       	lea    0x10(%rsp),%rcx
  40184a:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  40184f:	be 04 1f 40 00       	mov    $0x401f04,%esi
  401854:	bf 70 3b 60 00       	mov    $0x603b70,%edi
  401859:	b8 00 00 00 00       	mov    $0x0,%eax
  40185e:	e8 fd f3 ff ff       	callq  400c60 <__isoc99_sscanf@plt>
  401863:	83 f8 02             	cmp    $0x2,%eax
  401866:	74 0f                	je     401877 <phase_defused+0x40>
  401868:	bf e0 1c 40 00       	mov    $0x401ce0,%edi
  40186d:	e8 fe f2 ff ff       	callq  400b70 <puts@plt>
  401872:	48 83 c4 68          	add    $0x68,%rsp
  401876:	c3                   	retq   
  401877:	be 0a 1f 40 00       	mov    $0x401f0a,%esi
  40187c:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401881:	e8 66 fa ff ff       	callq  4012ec <strings_not_equal>
  401886:	85 c0                	test   %eax,%eax
  401888:	75 de                	jne    401868 <phase_defused+0x31>
  40188a:	bf 80 1c 40 00       	mov    $0x401c80,%edi
  40188f:	e8 dc f2 ff ff       	callq  400b70 <puts@plt>
  401894:	bf a8 1c 40 00       	mov    $0x401ca8,%edi
  401899:	e8 d2 f2 ff ff       	callq  400b70 <puts@plt>
  40189e:	b8 00 00 00 00       	mov    $0x0,%eax
  4018a3:	e8 61 f9 ff ff       	callq  401209 <secret_phase>
  4018a8:	eb be                	jmp    401868 <phase_defused+0x31>
  4018aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004018b0 <__libc_csu_init>:
  4018b0:	f3 0f 1e fa          	endbr64 
  4018b4:	41 57                	push   %r15
  4018b6:	49 89 d7             	mov    %rdx,%r15
  4018b9:	41 56                	push   %r14
  4018bb:	49 89 f6             	mov    %rsi,%r14
  4018be:	41 55                	push   %r13
  4018c0:	41 89 fd             	mov    %edi,%r13d
  4018c3:	41 54                	push   %r12
  4018c5:	4c 8d 25 34 15 20 00 	lea    0x201534(%rip),%r12        # 602e00 <__frame_dummy_init_array_entry>
  4018cc:	55                   	push   %rbp
  4018cd:	48 8d 2d 34 15 20 00 	lea    0x201534(%rip),%rbp        # 602e08 <__init_array_end>
  4018d4:	53                   	push   %rbx
  4018d5:	4c 29 e5             	sub    %r12,%rbp
  4018d8:	48 83 ec 08          	sub    $0x8,%rsp
  4018dc:	e8 37 f2 ff ff       	callq  400b18 <_init>
  4018e1:	48 c1 fd 03          	sar    $0x3,%rbp
  4018e5:	74 1f                	je     401906 <__libc_csu_init+0x56>
  4018e7:	31 db                	xor    %ebx,%ebx
  4018e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  4018f0:	4c 89 fa             	mov    %r15,%rdx
  4018f3:	4c 89 f6             	mov    %r14,%rsi
  4018f6:	44 89 ef             	mov    %r13d,%edi
  4018f9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4018fd:	48 83 c3 01          	add    $0x1,%rbx
  401901:	48 39 dd             	cmp    %rbx,%rbp
  401904:	75 ea                	jne    4018f0 <__libc_csu_init+0x40>
  401906:	48 83 c4 08          	add    $0x8,%rsp
  40190a:	5b                   	pop    %rbx
  40190b:	5d                   	pop    %rbp
  40190c:	41 5c                	pop    %r12
  40190e:	41 5d                	pop    %r13
  401910:	41 5e                	pop    %r14
  401912:	41 5f                	pop    %r15
  401914:	c3                   	retq   

0000000000401915 <.annobin___libc_csu_fini.start>:
  401915:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  40191c:	00 00 00 00 

0000000000401920 <__libc_csu_fini>:
  401920:	f3 0f 1e fa          	endbr64 
  401924:	c3                   	retq   

Disassembly of section .fini:

0000000000401928 <_fini>:
  401928:	f3 0f 1e fa          	endbr64 
  40192c:	48 83 ec 08          	sub    $0x8,%rsp
  401930:	48 83 c4 08          	add    $0x8,%rsp
  401934:	c3                   	retq   
